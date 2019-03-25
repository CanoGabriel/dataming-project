#ifndef ITEMSET_MODEL
#define ITEMSET_MODEL

#include "Itemset.hpp"
#include "ItemsetModel.hpp"
#include "Data.hpp"

#include <list>
#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include <set>

class ItemsetModel {
   std::list<Itemset> data_map;
	uint32_t minsup = 0;
	std::vector<Itemset> frequent_itemset;
	//std::map<uint32_t,std::list< Data<std::string>* >
protected:
   std::list<Data<std::string>> data_container;
public:
	void apriori();
   void insert(Data<std::string>& data);
   std::list<Itemset>::iterator search(uint32_t id);
   std::list<Itemset>::iterator end();
   std::list<Itemset>::const_iterator end()const;
   uint32_t size()const;
   uint32_t get_minsup()const;
   void set_minsup(uint32_t _minsup);
	void clear();

   friend std::ostream &operator<<(std::ostream &os, ItemsetModel const &m);
};
std::ostream &operator<<(std::ostream &os, ItemsetModel const &m);
std::ostream &operator<<(std::ostream &os, std::vector<Itemset> const &v);
#endif
