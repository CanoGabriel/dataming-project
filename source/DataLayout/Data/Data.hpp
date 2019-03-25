#ifndef DATA
#define DATA
/*!
\file Data.hpp
\brief Declaration of the Data class
\author Gabriel Cano
*/

#include <cstdint>
#include <string>
#include <iostream>


//! The Data class template is a generic container for data
/*!
The Data class template let data to be stored independently from the mapping used for the analysis of these data.
T is the type of the stored data.
*/
template <class T>
class Data {
   public :

	/*!
	   \brief A constructor of Data class template
	   \param _id_tuple is the id of the tuple of the instance
	   \param _id_column is the id of the column/dimension of the instance
	   \param value is the value that will be stored into the Data instance.
	   \pre No pre conditions
	   \post No post conditions
	   \return No return, it's a constructor
	*/
   Data(uint32_t _id_tuple,uint32_t _id_column, T value);

	/*!
	   \brief The value getter
	   \pre No pre conditions
	   \post The current instance is not modified.
	   \return A const reference to the value stored into the current Data instance
	*/
	const T& get_value(void)const;

	/*!
	   \brief The value setter
	   \param _value is the new value stored by the current Data instance.
	   \pre No pre conditions
	   \post The current Data instance stored the provided value.
	   \return No return
	*/
   void set_value(T _value);

	/*!
	   \brief The id_tuple getter
	   \pre No pre conditions
	   \post No post conditions
	   \return Return a copy of the id_tuple of the current instance.
	*/
   uint32_t get_id_tuple(void)const;

	/*!
	\brief The id_column getter
	\pre No pre conditions
	\post No post conditions
	\return Return a copy of the id_tuple of the current instance.
	*/
   uint32_t get_id_column(void)const;

	/*!
	   \brief The function compare let compare 2 Data instances by their values
	   \param d1 is the first data evaluated
	   \param d2 is the second data evaluated
	   \pre No pre-conditions
	   \post No Post-conditions
	   \return This function return an integer.
		\return The returned value is :
		\return 	\li > 0 if d1 is lesser then d2
		\return 	\li 0 if d1 equals to d2
		\return 	\li > 0 if d1 is greater than d2
	*/
   static int compare(const Data<T> &d1, const Data<T> &d2);

	/*!
	   \brief The overload of the "<" operator for Data
	   \param The rigth hand side of the comparison operation
	   \pre No pre-conditions
	   \post No post-conditions
	   \return This overload return a boolean
		\return \li true if d1 < d2
	*/
   bool operator< (const Data<T>& rhs)const;
   protected :
   T value; /*!< value is the field storing the value */
   uint32_t id_tuple; /*!< id_tuple is the id of the tuple owning the current Data instance */
   uint32_t id_column; /*!< id_column is the id of the column/dimension corresponding the current Data instance */
};

template <class T>
Data<T>::Data(uint32_t _id_tuple, uint32_t _id_column, T value)
: value(value), id_tuple(_id_tuple), id_column(_id_column){}

template <class T>
const T& Data<T>::get_value(void)const{
   return value;
}

template<class T>
void Data<T>::set_value(T _value){
   value = _value;
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
int Data<T>::compare(const Data<T>& d1, const Data<T>& d2){
   return d1.get_value() - d2.get_value();
}

/*!
   \brief The spcialization of the function compare(const Data<T>&,const Data<T>&) for the Data instance storing std::string
	\param d1 is the first data evaluated
	\param d2 is the second data evaluated
	\pre No pre-conditions
	\post No Post-conditions
	\return This function return an integer. This function return the same value as the std::string::compare function (See std::string documentation for more detail)
*/
template<>
int Data<std::string>::compare(const Data<std::string>& d1, const Data<std::string>& d2);

template <class T>
bool Data<T>::operator< (const Data<T>& rhs)const{
   return Data<T>::compare(*this,rhs) < 0;
}

//Missing : specialization for Date and nominal data type. (TO DO)


#endif
