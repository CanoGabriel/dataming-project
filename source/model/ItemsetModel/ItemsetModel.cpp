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

void ItemsetModel::generate_itemset(uint32_t k){
	std::set<Itemset,Itemset::CompareItemset> s,t;
	for(std::list<Itemset>::iterator itemset_ref = data_map.begin() ; itemset_ref != data_map.end() ; itemset_ref++){
		for(std::list<Data<std::string>*>::iterator data_pt = itemset_ref->begin() ; data_pt != itemset_ref->end() ; data_pt++){
			Itemset i;
			i.insert(*data_pt);
			s.insert(i);
		}
		//std::cout << std::endl;
	}
	for(std::set<Itemset,Itemset::CompareItemset>::iterator i = s.begin() ; i != s.end() ; i++ ){
		uint32_t n = 0;
		Itemset temp = *i;
		for(std::list<Itemset>::iterator j = data_map.begin() ; j != data_map.end() ; j++ ){
			//Itemset it(*i), jt(*j);
			if( i->in(*j)) n++;
		}
		temp.set_support(n);
		t.insert(temp);
		std::cout << temp << std::endl;
	}
}

std::list<Itemset>::iterator ItemsetModel::end(){
	return static_cast<std::list<Itemset>::iterator>(data_map.end());
}

std::list<Itemset>::const_iterator ItemsetModel::end()const{
	return data_map.end();
}

std::ostream &operator<<(std::ostream &os, ItemsetModel const &m) {
	os << "--Displaying itemset model--" << std::endl;
	for(std::list<Itemset>::const_iterator it = m.data_map.begin() ; it != m.data_map.end() ; it++){
		os << *it << std::endl;
	}
	os << "----End of itemset model----";
	return os;
}
