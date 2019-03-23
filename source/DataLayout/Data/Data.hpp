#ifndef DATA
#define DATA

#include <cstdint>
#include <string>
#include <iostream>


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
   bool operator< (const Data<T>& rhs);
   protected :
   T str_value;
   uint32_t id_tuple, id_column;
};

template <class T>
Data<T>::Data(uint32_t _id_tuple, uint32_t _id_column, T value)
: str_value(value), id_tuple(_id_tuple), id_column(_id_column){}

template <class T>
T Data<T>::get_value(void)const{
   return str_value;
}

template<class T>
void Data<T>::set_value(T value){
   str_value = value;
}

template <class T>
uint32_t Data<T>::get_id_tuple(void)const{
   return id_tuple;
}


template <class T>
uint32_t Data<T>::get_id_column(void)const{
   return id_column;
}

template <class T>
bool Data<T>::compare_order(Data<T> &d1, Data<T> &d2){
   if(d1.id_tuple != d2.id_tuple){
      return d1.id_tuple < d2.id_tuple;
   }
   return d1.id_column <= d2.id_column;
}

template <class T>
int Data<T>::compare_value(Data<T>& d1, Data<T>& d2){
   return d1.get_value() - d2.get_value();
}

template<>
int Data<std::string>::compare_value(Data<std::string>& d1, Data<std::string>& d2);

template <class T>
bool Data<T>::operator< (const Data<T>& rhs){
   return Data<T>::compare_value(*this,rhs) < 0;
}

//Missing : specialization for Date and nominal data type. (TO DO)


#endif
