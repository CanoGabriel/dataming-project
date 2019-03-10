#ifndef ITEMSET
#define ITEMSET

#include "Tuple.hpp"
#include "Data.hpp"

#include <list>
#include <string>
#include <cstdint>

class Itemset : public Tuple {
public:
   Itemset();
   Itemset(uint32_t id);
   /*
   "values" is the container of the class Itemset.
   This field will contains the value.
   */
   std::list<Data<std::string>* > values;

   /*
   The purpose of this function is to insert an element into the container.
   "value" is the value to insert into the container.
   */
   void insert(Data<std::string>* value);
   std::list<Data<std::string>* >& get_values(void);
};

#endif
