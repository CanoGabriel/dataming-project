#include <gtest/gtest.h>
#include "FileReader.hpp"
#include "ItemsetModel.hpp"

TEST(TestItemsetModel,classTest){
   ItemsetModel model;
   Data<std::string> d1(0,0,"val1");
   Data<std::string> d2(0,0,"val2");
   Data<std::string> d3(1,0,"val3");
   Data<std::string> d4(1,0,"val4");
   Data<std::string> d5(0,0,"val5");
   Data<std::string> d6(1,0,"val5");
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
