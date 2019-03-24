#include "ItemsetModel.hpp"

void ItemsetModel::insert(Data<std::string>& data){
	//Saving data in container
	data_container.push_back(Data<std::string>(data));
	//Retreiving the reference to it from the container
	Data<std::string> * data_pt = &(data_container.back());
	std::list<Itemset>::iterator it = search(data_pt->get_id_tuple());

	if(it == data_map.end()){
		data_map.push_back(Itemset(data_pt->get_id_tuple()));
		data_map.back().insert(data_pt);
	}
	else{
		it->insert(data_pt);
	}
}

std::list<Itemset>::iterator ItemsetModel::search(uint32_t id){
	std::list<Itemset>::iterator it = data_map.begin();
	while(it != data_map.end() ){
		if(it->get_id() == id){
			break;
		}
		it++;
	}
	return it;
}

uint32_t ItemsetModel::get_size()const{
	return data_map.size();
}


uint32_t ItemsetModel::get_minsup()const{
	return minsup;
}
void ItemsetModel::set_minsup(uint32_t _minsup){
	minsup=_minsup;
}

void ItemsetModel::clear(){
	data_map.clear();
	frequent_itemset.clear();
}

void ItemsetModel::calculate_frequent_itemset(){
	//frequent_itemset.clear();
	std::vector< std::set<Itemset,Itemset::CompareItemset> > sized_itemsets;
	std::set<Itemset,Itemset::CompareItemset> temp;
	uint32_t n = -1;
	do{
		n++;
		temp.clear();
		sized_itemsets.push_back(std::set<Itemset,Itemset::CompareItemset>());
		if( 0 == n ){
			for(std::list<Itemset>::iterator model_itemset = data_map.begin() ; model_itemset != data_map.end() ; model_itemset++){
				for(std::list<Data<std::string>*>::iterator data_pt = model_itemset->begin() ; data_pt != model_itemset->end() ; data_pt++){
					Itemset i;
					i.insert(*data_pt);
					temp.insert(i);
				}
			}
		}
		else{
			//merge k-1 itemset into k itemset
			std::set<Itemset,Itemset::CompareItemset>& set_ref = sized_itemsets.at(n-1);
			for(std::set<Itemset,Itemset::CompareItemset>::const_iterator i = set_ref.begin() ; i != set_ref.end() ; i++){
				for(std::set<Itemset,Itemset::CompareItemset>::const_iterator j = set_ref.begin() ; j != set_ref.end() ; j++){
					Itemset merged_itemset;
					if(Itemset::merge(*i,*j,merged_itemset)){
						temp.insert(merged_itemset);
					}
				}
			}
		}

		//Determine the support for each built itemset
		for(std::set<Itemset,Itemset::CompareItemset>::iterator i = temp.begin() ; i != temp.end() ; i++ ){
			uint32_t count = 0;
			Itemset itemset = *i;
			for(std::list<Itemset>::iterator j = data_map.begin() ; j != data_map.end() ; j++ ){
				//Itemset it(*i), jt(*j);
				if( i->in(*j)) count++;
			}
			//Prune itemset that the support is less than minsup
			if(count >= minsup){
				itemset.set_support(count);
				sized_itemsets.at(n).insert(itemset);
			}
		}
	}while(!sized_itemsets.at(n).empty());
	temp.clear();
	std::vector<Itemset> test;
	for(auto set = sized_itemsets.begin() ; set != sized_itemsets.end() ; set++ ){
		for(auto itemset = set->begin() ; itemset != set->end() ; itemset++ ){
			frequent_itemset.push_back(Itemset(*itemset));
		}
	}
}

std::list<Itemset>::iterator ItemsetModel::end(){
	return static_cast<std::list<Itemset>::iterator>(data_map.end());
}

std::list<Itemset>::const_iterator ItemsetModel::end()const{
	return data_map.end();
}

std::ostream &operator<<(std::ostream &os, std::vector<Itemset> const &v) {
	for(auto it = v.begin(); it != v.end();it++){
		os << *it << std::endl;
	}
	return os;
}
std::ostream &operator<<(std::ostream &os, ItemsetModel const &m) {

	os << "----Displaying itemset model----" << std::endl;
	for(std::list<Itemset>::const_iterator it = m.data_map.begin() ; it != m.data_map.end() ; it++){
		os << *it << std::endl;
	}
	os << "----End of itemset from data----" << std::endl;
	os << "--Displaying frequent itemsets--" << std::endl;
	for(auto it = m.frequent_itemset.begin(); it != m.frequent_itemset.end();it++){
		os << *it << std::endl;
	}
	os << "----End of frequent itemsets----";
	return os;
}
