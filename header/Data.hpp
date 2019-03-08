#ifndef DATA
#define DATA

#include <cstdint>
#include <string>

class Data {
   public :
   Data(uint_32_t _id_tuple, _id_column, std::string value = "?");
   std::string get_str_value(void)const;
   void set_str_value(std::string value);
   uint32_t get_id_tuple(void)const;
   uint32_t get_id_column(void)const;
   protected :
   std::string str_value;
   uint32_t id_tuple, id_column;
};

#endif
