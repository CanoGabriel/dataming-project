#include "Itemset.hpp"

Itemset::Itemset():Tuple(){}

Itemset::Itemset(uint32_t _id):Tuple(_id){}

void Itemset::insert(Data<std::string> * value){
   if(values.empty()){
      //Insert directly if the container is empty.
      values.push_back(value);
   }
   else{
      std::list<Data<std::string>*>::iterator it;
      //Search the right place to insert this new element
      for(it = values.begin() ; it != values.end() ; it++){
         if(Data<std::string>::compare_value(*value, **it) <= 0){
            break;
         }
      }
      //Insert at the end if it is the greater value.
      if( it == values.end()){
         values.push_back(value);
      } // Avoid duplicata
      else if( Data<std::string>::compare_value(*value, **it) != 0 ){
         values.insert(it,value);
      }
   }
}

std::list<Data<std::string>* >& Itemset::get_values(void){
   return values;
}
