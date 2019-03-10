#ifndef D_DEFAULT_MODEL
#define DATA_DEFAULT_MODEL

#include "Data.hpp"
#include "Tuple.hpp"

#include <list>
#include <vector>
#include <string>

template< class D>
class DataDefaultModel {
   std::list<Data<D>> data_container;
   std::list<Tuple> data_map;
public:
   void insert(Data<D>& data);
   typename std::list<Tuple>::iterator search(uint32_t id);
};

#endif
