#include "Data.hpp"


template<>
int Data<std::string>::compare_value(Data<std::string>& d1, Data<std::string>& d2){
   return d1.get_value().compare(d2.get_value());
}
