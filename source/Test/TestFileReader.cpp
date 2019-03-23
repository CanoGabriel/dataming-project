#include <gtest/gtest.h>
#include "FileReader.hpp"
#include "ItemsetModel.hpp"

class TestFileReader : public ::testing::Test {
protected:
	virtual void SetUp() {
	}

	virtual void TearDown() {
	}
};

TEST_F(TestFileReader,test_trim){
   std::string str("  my string  ");
   FileReader::trim(str);
   ASSERT_STREQ(str.c_str(),"my string");
}

TEST_F(TestFileReader,test_split){
	std::vector<std::string> v;
   std::string str("my string to split");
   FileReader::split(v,str," ");
   ASSERT_TRUE(v.size() == 4);
	ASSERT_STREQ(v.at(0).c_str(),"my");
	ASSERT_STREQ(v.at(1).c_str(),"string");
	ASSERT_STREQ(v.at(2).c_str(),"to");
	ASSERT_STREQ(v.at(3).c_str(),"split");
}

TEST_F(TestFileReader,test_read_itemset_file){
	ItemsetModel model;
   FileReader fr("./bin/sample.csv");
   fr.read_itemset_file(",",model);
	ASSERT_TRUE(model.get_size() == 100);
}
