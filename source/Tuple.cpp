#include "Tuple.hpp"


uint32_t Tuple::last_id = 0;

uint32_t Tuple::get_new_id(){
   return last_id++;
}

Tuple::Tuple(){
   id = get_new_id();
}

Tuple::Tuple(uint32_t _id):id(_id){}
