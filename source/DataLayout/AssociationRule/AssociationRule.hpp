#ifndef ASSOCIATION_RULE
#define ASSOCIATION_RULE


class Itemset;
class AssociationRule {
	long double lift;
	long double confidence;
	const Itemset& cause;
	const Itemset& consequence;
	AssociationRule(const Itemset& _cause, const Itemset& _consequence );
};
#endif
