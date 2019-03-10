#ifndef DATA
#define DATA

#include <cstdint>
#include <string>


/*
using value_type = typename std::enable_if<
std::is_same<My_type, std::string>
|| std::is_same<My_type, long double>, My_type>::type;
*/


template <class T>
class Data {
   public :
   Data(uint32_t _id_tuple,uint32_t _id_column, T value);
   T get_value(void)const;
   void set_value(T value);
   uint32_t get_id_tuple(void)const;
   uint32_t get_id_column(void)const;
   static bool compare_order(Data<T> &d1, Data<T> &d2);
   static int compare_value(Data<T> &d1, Data<T> &d2);
   protected :
   T str_value;
   uint32_t id_tuple, id_column;
};

#endif
