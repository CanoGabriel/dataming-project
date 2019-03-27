#include <gtest/gtest.h>
#include "AprioriBundle.hpp"
#include "FileReader.hpp"

class TestAprioriBundle : public ::testing::Test {
protected:
	TestAprioriBundle():
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

TEST_F(TestAprioriBundle,test_apriori){
	ItemsetModel model;
	AprioriBundle bundle(model,1,0);
	FileReader fr("./bin/grocery.csv");
	fr.read_itemset_file(",",model);
	bundle.apriori();
}
TEST_F(TestAprioriBundle,test_apriori_100_input){
	ItemsetModel model;
	AprioriBundle bundle(model,1,0);
	FileReader fr("./bin/sample_100.csv");
	fr.read_itemset_file(",",model);
	bundle.apriori();
}
