#include "Data.hpp"


template<>
int Data<std::string>::compare(const Data<std::string>& d1, const Data<std::string>& d2){
   return d1.get_value().compare(d2.get_value());
}
