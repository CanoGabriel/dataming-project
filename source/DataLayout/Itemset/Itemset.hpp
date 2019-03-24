#ifndef ITEMSET
#define ITEMSET

#include "Tuple.hpp"
#include "Data.hpp"

#include <list>
#include <string>
#include <cstdint>

class Itemset;
class Itemset : public Tuple {
   std::list<Data<std::string>* > values;
   uint32_t support;
public:
   Itemset();
   Itemset(uint32_t id);
   /*
   "values" is the container of the class Itemset.
   This field will contains the value.
   */
   /*
   The purpose of this function is to insert an element into the container.
   "value" is the value to insert into the container.
   */
   void insert(Data<std::string>* value);
   std::list<Data<std::string>* >& get_values(void);
	const std::list<Data<std::string>* >& get_values(void)const;
   uint32_t get_size()const;
   uint32_t get_support()const;
   void set_support(uint32_t _support);
   void clear();
	std::list<Data<std::string>* >::iterator begin();
	std::list<Data<std::string>* >::const_iterator begin()const;
	std::list<Data<std::string>* >::iterator end();
	std::list<Data<std::string>* >::const_iterator end()const;

   static bool  merge(const Itemset& i, const Itemset& j, Itemset& res);
   bool in(Itemset& other)const;

   friend std::ostream &operator<<(std::ostream &os, Itemset const &itemset);
   struct CompareDataPt{
      bool operator()( Data<std::string>* lhs, Data<std::string>* rhs);
   };
   struct CompareItemset{
      bool operator()(const Itemset& lhs,const Itemset& rhs);
   };
};

bool operator==(const Itemset& lhs, const Itemset& rhs);
bool operator<(const Itemset& lhs, const Itemset& rhs);
std::ostream &operator<<(std::ostream &os, Itemset const &itemset);
#endif
