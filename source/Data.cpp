#include "Data.hpp"

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
int Data<std::string>::compare_value(Data<std::string>& d1, Data<std::string>& d2){
   return d1.get_value().compare(d2.get_value());
}

//Missing : specialization for Date and nominal data type. (TO DO)
