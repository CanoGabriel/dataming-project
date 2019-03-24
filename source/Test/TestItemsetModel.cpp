#include <gtest/gtest.h>
#include "ItemsetModel.hpp"
#include "FileReader.hpp"
#include "Data.hpp"

class TestItemsetModel : public ::testing::Test {
protected:
	TestItemsetModel():
	d1(0,0,"val1"),
	d2(0,0,"val2"),
	d3(1,0,"val3"),
	d4(1,0,"val4"),
	d5(0,0,"val5"),
	d6(1,0,"val5")
	{}
	virtual void SetUp() {
	}

	Data<std::string> d1;
	Data<std::string> d2;
	Data<std::string> d3;
	Data<std::string> d4;
	Data<std::string> d5;
	Data<std::string> d6;

	virtual void TearDown() override {
	}
};

TEST_F(TestItemsetModel,simpleInsertTest){
	ItemsetModel model;
	model.insert(d1);
	model.insert(d2);
	model.insert(d3);
	model.insert(d4);
	model.insert(d5);
	model.insert(d6);
	ASSERT_TRUE(model.get_size() == 2);
}

TEST_F(TestItemsetModel,insertAndSearchTest){
	ItemsetModel model;
	model.insert(d1);
	model.insert(d2);
	model.insert(d3);
	model.insert(d4);
	model.insert(d5);
	model.insert(d6);
	ASSERT_TRUE(model.get_size() == 2);
	auto t1 = model.search(0);
	auto t2 = model.search(1);

	ASSERT_TRUE(t1 != model.end() && t1->get_size() == 3);
	ASSERT_TRUE(t2 != model.end() && t2->get_size() == 3);
}

TEST_F(TestItemsetModel,displayTest){
	ItemsetModel model;
	model.insert(d1);
	model.insert(d2);
	model.insert(d3);
	model.insert(d4);
	model.insert(d5);
	model.insert(d6);
	std::cout << model << std::endl;
}

TEST_F(TestItemsetModel,calculateFrequentItemsetTest){
	ItemsetModel model;
	FileReader fr("./bin/grocery.csv");
	fr.read_itemset_file(",",model);
	model.set_minsup(1);
	model.calculate_frequent_itemset();
	std::cout << model << std::endl;
}
