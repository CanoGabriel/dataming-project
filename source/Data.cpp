#include "Data.hpp"

Data::Data(uint_32_t _id_tuple, _id_column, std::string value)
: str_value(value), id_tuple(_id_tuple), id_column(_id_column){}

std::string Data::get_str_value(void)const{
   return str_value;
}

void Data::set_str_value(std::string value){
   str_value = _value;
}

uint32_t get_id_tuple(void)const{
   return id_tuple;
}

uint32_t get_id_column(void)const{
   return id_column;
}
