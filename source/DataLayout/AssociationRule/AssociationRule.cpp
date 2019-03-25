#include "AssociationRule.hpp"
AssociationRule::AssociationRule(const Itemset& _cause, const Itemset& _consequence )
:cause(_cause),consequence(_consequence),lift(0),confidence(0)
{}
