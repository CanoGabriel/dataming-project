#ifndef TEST
#define TEST

#define ASSER(boolean,condition,msg_ok,msg_ko) boolean &= condition; \
if(boolean) std::cerr << msg_ok; \
else std::cerr << msg_ko;

#include <string>
#include <vector>
#include "FileReader.hpp"
#include "ItemsetModel.hpp"

namespace Test {
   class TestFileReader{
      static bool test_trim();
      static bool test_split();
      static bool test_read_itemset_file();
   public:
      static bool test_class();
   };
   class TestItemsetModel{
   public:
      static bool test_class();
   };
}

#endif
