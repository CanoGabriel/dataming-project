#ifndef ASSOCIATION_RULE
#define ASSOCIATION_RULE


class Itemset;
class AssociationRule {
public:
	const Itemset& cause;
	const Itemset& consequence;
	long double lift;
	long double confidence;
	AssociationRule(const Itemset& _cause, const Itemset& _consequence );
};
#endif
