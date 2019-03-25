#include "Itemset.hpp"

Itemset::Itemset():Tuple(),support(0){}

Itemset::Itemset(uint32_t _id):Tuple(_id),support(0){}

void Itemset::insert(Data<std::string> * value){
	if(values.empty()){
		//Insert directly if the container is empty.
		values.push_back(value);
	}
	else{
		std::list<Data<std::string>*>::iterator it;
		//Search the right place to insert this new element
		for(it = values.begin() ; it != values.end() ; it++){
			if(Data<std::string>::compare(*value, **it) <= 0){
				break;
			}
		}
		//Insert at the end if it is the greater value.
		if( it == values.end()){
			values.push_back(value);
		} // Avoid duplicata
		else if( Data<std::string>::compare(*value, **it) != 0 ){
			values.insert(it,value);
		}
	}
}

std::list<Data<std::string>* >& Itemset::get_values(void){
	return values;
}
const std::list<Data<std::string>* >& Itemset::get_values(void)const{
	return values;
}

uint32_t Itemset::size()const{
	return values.size();
}
std::ostream &operator<<(std::ostream &os, Itemset const &itemset){
	uint32_t n = 0;
	os << "{ ";
	for(Itemset::const_iterator it = itemset.values.begin() ; it != itemset.values.end(); it++,n++){
		if( n == itemset.size()-1 ){
			os << (*it)->get_value() << " ";
		}
		else{
			os << (*it)->get_value() << ", ";
		}
	}
	os << "} ("<< itemset.get_support() <<")";
	//os << std::endl;
	return os;
}


uint32_t Itemset::get_support()const{return support;}
void Itemset::set_support(uint32_t _support){
	support = _support;
}

bool Itemset::CompareDataPt::operator()(Data<std::string>* lhs, Data<std::string>* rhs){
	return Data<std::string>::compare(*lhs,*rhs) < 0;
}

bool Itemset::CompareItemset::operator()(const Itemset& lhs, const Itemset& rhs){
	return lhs < rhs;
}
/*
*/

void Itemset::clear(){
	values.clear();
}

bool Itemset::merge(const Itemset& i, const Itemset& j, Itemset& res){
	//Check if the k-1 first element are the same, if yes merge else return false
	//std::cout << "Merge : " << i << " " << j << " = "  << std::endl;
	res.clear();
	if( i.size() != j.size() ) return false;
	uint32_t n = 0;
	const std::list<Data<std::string>*>& i_values = i.get_values();
	const std::list<Data<std::string>*>& j_values = j.get_values();
	std::list<Data<std::string>*>::const_iterator it = i_values.begin();
	std::list<Data<std::string>*>::const_iterator jt = j_values.begin();
	bool check = true;
	for(;it != i_values.end() && jt != j_values.end();it++,jt++,n++){
		if(n < i.size() - 1){
			check &= Data<std::string>::compare(**it,**jt) == 0;
		}
		else{
			check &= Data<std::string>::compare(**it,**jt) != 0;
		}
	}
	if(!check) return false;
	res.insert(j_values.back());
	for(it = i_values.begin(); it != i_values.end() ; it++){
		res.insert(*it);
	}
	//std::cout << res << std::endl;
	return true;
}

bool Itemset::in(Itemset& other)const{
	std::list<Data<std::string>*>& other_values = other.get_values();
	auto it_other = other_values.begin();
	//std::cout << "Itemset::in\n";
	bool result = true;
	int comp;
	auto jt = other_values.begin();
	for(auto it = values.begin() ; it != values.end() ; it++){
		for( ; jt != other_values.end() ; jt++){
			//std::cout << (*it)->get_value() << " == ";
			comp = Data<std::string>::compare(**it,**jt);
			//std::cout << (*jt)->get_value() << " : ";
			//std::cout << comp << std::endl;
			if(comp < 0) return false;
			else if(comp == 0) {
				break;
			}
		}
		if(jt == other_values.end() && it != other_values.end()) return false;
	}
	return true;
}

bool operator==(const Itemset& lhs, const Itemset& rhs){
	if(lhs.size() == rhs.size()){
		std::list<Data<std::string>*>::const_iterator l = lhs.begin();
		std::list<Data<std::string>*>::const_iterator r = rhs.begin();
		bool check = true;
		while( check && (l != lhs.end() || r != rhs.end()) ){
			check &= Data<std::string>::compare(**l,**r) == 0;
			l++,r++;
		}
		return check;
	}
	return false;
}

bool operator<(const Itemset& lhs, const Itemset& rhs){
	if(lhs.size() < rhs.size()){
		return true;
	}
	std::list<Data<std::string>*>::const_iterator l = lhs.begin();
	std::list<Data<std::string>*>::const_iterator r = rhs.begin();
	while( l != lhs.end() || r != rhs.end() ){
		int comp = Data<std::string>::compare(**l,**r);
		if( comp < 0) return true;
		else if( comp == 0 ) l++,r++;
		else return false;
	}
	return false;
}

void Itemset::extract_rules(const Itemset& itemset, std::vector<Rule>& res){
	res.clear();
	if(itemset.size() < 2) return;
	std::set<Itemset,Itemset::CompareItemset> itemsets;

}

bool Itemset::pop_by_value(const Data<std::string>* data, Itemset& poped_value, Itemset& remaining_value)const{
	bool value_found = false;
	for(std::list<Data<std::string>* >::const_iterator it = values.begin() ; it != values.end() ; it++){
		if(Data<std::string>::compare(*data,**it) == 0){
			poped_value.insert(*it);
			value_found = true;
		}
		else{
			remaining_value.insert(*it);
		}
	}
	return value_found;
}

Itemset::iterator Itemset::begin(){return values.begin();}
Itemset::iterator Itemset::end(){return values.end();}
Itemset::const_iterator Itemset::begin()const{return values.begin();}
Itemset::const_iterator Itemset::end()const{return values.end();}
