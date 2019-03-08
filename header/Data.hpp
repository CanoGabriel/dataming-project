#ifndef DATA
#define DATA

#include <string>

class Data {
   public :
   Data(std::string value = "?");
   std::string get_str_value(void)const;
   void set_str_value(std::string value);
   protected :
   std::string str_value;
};

#endif
