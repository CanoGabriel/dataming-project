#include "AprioriBundle.hpp"

AprioriBundle::AprioriBundle(const ItemsetModel& _model, long double _minsup, long double _minconf)
: minsup(_minsup),minconf(_minconf),model(_model){}

long double AprioriBundle::get_minsup()const{
	return minsup;
}

void AprioriBundle::set_minsup(uint32_t _minsup){
	minsup= (long double)_minsup/model.data_map.size();
}

void AprioriBundle::set_minsup(long double _minsup){
	if(_minsup > 0 ) minsup = ((_minsup < 1 )?_minsup:1);
	else minsup = ((_minsup > 0 )?_minsup:0);
}

long double AprioriBundle::get_minconf()const{
	return minconf;
}

void AprioriBundle::set_minconf(long double _minconf){
	if(_minconf > 0 ) minconf = ((_minconf < 1 )?_minconf:1);
	else minconf = ((_minconf > 0 )?_minconf:0);
}

void AprioriBundle::apriori(){
	//frequent_itemset.clear();
	std::vector< std::set<Itemset,Itemset::Compare> > sized_itemsets;
	std::set<Itemset,Itemset::Compare> temp;
	uint32_t n = -1;
	do{
		n++;
		temp.clear();
		sized_itemsets.push_back(std::set<Itemset,Itemset::Compare>());
		if( 0 == n ){
			for(std::list<Itemset>::const_iterator model_itemset = model.data_map.begin() ; model_itemset != model.data_map.end() ; model_itemset++){
				for(std::list<Data<std::string>*>::const_iterator data_pt = model_itemset->begin() ; data_pt != model_itemset->end() ; data_pt++){
					Itemset i;
					i.insert(*data_pt);
					temp.insert(i);
				}
			}
		}
		else{
			//merge k-1 itemset into k itemset
			std::set<Itemset,Itemset::Compare>& set_ref = sized_itemsets.at(n-1);
			for(std::set<Itemset,Itemset::Compare>::const_iterator i = set_ref.begin() ; i != set_ref.end() ; i++){
				for(std::set<Itemset,Itemset::Compare>::const_iterator j = set_ref.begin() ; j != set_ref.end() ; j++){
					Itemset merged_itemset;
					if(Itemset::merge(*i,*j,merged_itemset)){
						temp.insert(merged_itemset);
					}
				}
			}
		}

		//Determine the support for each built itemset
		for(std::set<Itemset,Itemset::Compare>::iterator i = temp.begin() ; i != temp.end() ; i++ ){
			uint32_t count = 0;
			Itemset itemset = *i;
			for(std::list<Itemset>::const_iterator j = model.data_map.begin() ; j != model.data_map.end() ; j++ ){
				//Itemset it(*i), jt(*j);
				if( i->in(*j)) count++;
			}
			//Prune itemset that the support is less than minsup
			if(count/model.data_map.size() >= minsup){
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

void AprioriBundle::calcule_association_rules(){
	for(std::vector<Itemset>::const_iterator i = frequent_itemset.begin() ; i != frequent_itemset.end() ; i++){
		for(std::vector<Itemset>::const_iterator j = frequent_itemset.begin() ; j != frequent_itemset.end() ; j++){
			// check i => j rule
			if(!i->in(*j)){
				Itemset k = *i + *j;
				model.get_support(k);
				long double confidence = static_cast<long double>(k.get_support())/i->get_support();
				if(confidence > minconf){
					long double lift = confidence/j->get_support();
					AssociationRule ar(*i,*j);
					ar.confidence = confidence;
					ar.lift = lift;
					rules.push_back(ar);
				}
			}
		}
	}
}
