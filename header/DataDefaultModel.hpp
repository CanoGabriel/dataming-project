#ifndef DATA_DEFAULT_MODEL
#define DATA_DEFAULT_MODEL

#include "Data.hpp"

#include <list>
#include <vector>



class DataDefaulModel {
   std::list<Data> data_container;
   std::list< std::vector<Data*> > data_map;
   void addData(Data data);
};

#endif
