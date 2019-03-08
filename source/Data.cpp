#include "Data.hpp"

Data::Data(std::string value){
   str_value = value;
}

std::string Data::get_str_value(void)const{
   return str_value;
}

void Data::set_str_value(std::string value){
   str_value = _value;
}
