#ifndef APRIORI_BUNDLE
#define APRIORI_BUNDLE

#include "ItemsetModel.hpp"
#include "Itemset.hpp"
#include "AssociationRule.hpp"
#include <cstdint>
#include <vector>
#include <set>

class AprioriBundle {
	long double minsup;
	long double minconf;
	std::vector<Itemset> frequent_itemset;
	std::vector<AssociationRule> rules;
	const ItemsetModel& model;
public:
	AprioriBundle(const ItemsetModel& _model, long double _minsup, long double _minconf);
	void apriori();
	void calcule_association_rules();
	long double get_minsup()const;
   void set_minsup(uint32_t _minsup);
   void set_minsup(long double _minsup);
	long double get_minconf()const;
	void set_minconf(long double);

};

#endif
