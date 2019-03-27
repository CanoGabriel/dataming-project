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


class AprioriBundle;

class ItemsetModel {
   std::list<Itemset> data_map;
protected:
   std::list<Data<std::string>> data_container;
public:
	void apriori();
   void insert(Data<std::string>& data);
	void get_support(Itemset& itemset)const;
   std::list<Itemset>::iterator search(uint32_t id);
   std::list<Itemset>::iterator end();
   std::list<Itemset>::const_iterator end()const;
   uint32_t size()const;

	void clear();

   friend std::ostream &operator<<(std::ostream &os, ItemsetModel const &m);

	friend class AprioriBundle;
};
std::ostream &operator<<(std::ostream &os, ItemsetModel const &m);
std::ostream &operator<<(std::ostream &os, std::vector<Itemset> const &v);
#endif
