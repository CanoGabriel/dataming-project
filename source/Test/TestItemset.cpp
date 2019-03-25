#include <gtest/gtest.h>
#include <Data.hpp>
#include "Itemset.hpp"

class TestItemset : public ::testing::Test {
protected:
	Data<std::string> d1,d2,d3,d4,d5;
	TestItemset():
	d1(0,0,"item 1"),
	d2(0,0,"item 2"),
	d3(0,0,"item 3"),
	d4(0,0,"item 4"),
	d5(0,0,"item 5"){}

	virtual void SetUp() {
	}

	virtual void TearDown() {
	}
};


TEST_F(TestItemset,test_insert){
	Itemset itemset;
	itemset.insert(&d1);
	itemset.insert(&d2);
	itemset.insert(&d2);
	itemset.insert(&d3);
	ASSERT_TRUE( 3 == itemset.get_size());
}

TEST_F(TestItemset,test_pop_by_value){
	Data<std::string> d6(0,0,"item 3");
	Itemset itemset;
	itemset.insert(&d1);
	itemset.insert(&d2);
	itemset.insert(&d3);
	itemset.insert(&d4);
	itemset.insert(&d5);
	ASSERT_TRUE( 5 == itemset.get_size());
	Itemset poped_value,remaining_value;
	ASSERT_TRUE( 0 == poped_value.get_size());
	ASSERT_TRUE( 0 == remaining_value.get_size());
	itemset.pop_by_value(&d1,poped_value,remaining_value);

	ASSERT_TRUE( 5 == itemset.get_size() );
	ASSERT_TRUE( 1 == poped_value.get_size() );
	ASSERT_TRUE( 4 == remaining_value.get_size() );

	remaining_value.clear();
	itemset.pop_by_value(&d6,poped_value,remaining_value);

	ASSERT_TRUE( 5 == itemset.get_size() );
	ASSERT_TRUE( 2 == poped_value.get_size() );
	ASSERT_TRUE( 4 == remaining_value.get_size() );
}

TEST_F(TestItemset,test_clear){
	Itemset itemset;
	itemset.insert(&d1);
	ASSERT_TRUE( 1 == itemset.get_size());
	itemset.clear();
	ASSERT_TRUE( 0 == itemset.get_size());
}

TEST_F(TestItemset,test_merge){
	Itemset i,j,k,l,res;
	i.insert(&d1);	i.insert(&d2);	i.insert(&d3);
	j.insert(&d1);	j.insert(&d2);	j.insert(&d4);
	k.insert(&d1);	k.insert(&d3);	k.insert(&d4);
	l.insert(&d1);
	ASSERT_TRUE(Itemset::merge(i,j,res));
	ASSERT_TRUE( 4 == res.get_size() );
	res.clear();
	ASSERT_FALSE( Itemset::merge(i,k,res) );
	ASSERT_TRUE( 0 == res.get_size() );
	ASSERT_FALSE( Itemset::merge(i,l,res) );
}


TEST_F(TestItemset,test_in){
	Itemset i,j,k,l,res;
	i.insert(&d1);	i.insert(&d2);	i.insert(&d3);
	j.insert(&d1);	j.insert(&d2);
	k.insert(&d1);	k.insert(&d3);	k.insert(&d4);
	l.insert(&d1);	l.insert(&d4);
	ASSERT_TRUE(i.in(i));
	ASSERT_FALSE(i.in(j));
	ASSERT_TRUE(j.in(i));
	ASSERT_TRUE(l.in(k));

}
