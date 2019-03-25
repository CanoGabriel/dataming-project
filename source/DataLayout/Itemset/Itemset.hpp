#ifndef ITEMSET
#define ITEMSET
/*!
   \file Itemset.hpp
   \brief Declaration of the Itemset class
   \author "Your name"
   \date "DD"/"Month"/"Year"
*/

#include "Tuple.hpp"
#include "Data.hpp"

#include <list>
#include <vector>
#include <set>
#include <string>
#include <cstdint>

class Itemset;
typedef std::pair<Itemset,Itemset> Rule;

//! The Itemset class is a  data layout.
/*!
The Itemset class is a container design for mapping Data clas instance.
This container store pointer pointing to Data class instance to avoid data duplication.
In this container Data are stored as if it is a set but it's the value of Data that are compared not the pointer.
We assume that each Data instance mapped by this container store string.
*/
class Itemset : public Tuple {

   std::list<Data<std::string>* > values; /*!< The container behind the Itemset class container */
   uint32_t support; /*!< The support of the Itemset instance */
public:
	typedef std::list<Data<std::string>* >::iterator iterator;
	typedef std::list<Data<std::string>* >::const_iterator const_iterator;
	/*!
	   \brief A constructor of the Itemset class
	   \pre No Pre-conditions
	   \post  No Post-conditions
	   \return No return, it's a constructor
	*/
   Itemset();

	/*!
	\brief A constructor of the Itemset class
	\param id is the id of the tuple associated with all Data instance mapped by this container
	\pre No Pre-conditions
	\post  No Post-conditions
	\return No return, it's a constructor
	*/
   Itemset(uint32_t id);

	/*!
	   \brief This function insert an new element in the container if it is not already in it. If the tried value is already in the container
	   \brief If the tried value is already in the statement have no effect.
	   \param values is the pointer pointing to the value that you want to map in this Itemset instance.
	   \pre No pre-conditions
	   \post No post-conditions
	   \return No return
	*/
   void insert(Data<std::string>* value);

	/*!
	   \brief The getter for the values field.
	   \pre No pre-conditions
	   \post No post-conditions
	   \return This function return a reference to the values container.
	*/
   std::list<Data<std::string>* >& get_values(void);

	/*!
	\brief The getter for the values field.
	\pre No pre-conditions
	\post No post-conditions
	\return This function return a const reference to the values container.
	*/
	const std::list<Data<std::string>* >& get_values(void)const;

	/*!
	   \brief This function return the number of Data mapped by the Itemset
	   \pre No pre-conditions
	   \post No post-conditions
	   \return This method return an unsigned int corresponding to the size of the Itemset.
	*/
   uint32_t size()const;

	/*!
	   \brief This function search for the data provided in the Itemset.
	   \brief The searched data, if it's found, the value is inserted into the poped_value Itemset.
		\brief Whatever the searched succeed or not, the others values are inserted into the remaining_value Itemset.
	   \param data is the data searched for.
	   \param poped_value is the Itemset in whitch we want to insert the searched value if this value is in the current instance.
	   \param remaining_value is the Itemset in whitch all the other values will be inserted.
	   \pre No pre-conditions
	   \post No post-conditions
	   \return If the searched value is found, the return value is true, false else.
	*/
	bool pop_by_value(const Data<std::string>* data, Itemset& poped_value, Itemset& remaining_value)const;

	/*!
	   \brief The getter of the support field
	   \pre No pre-conditions
	   \post No post-conditions
	   \return The support value.
	*/
   uint32_t get_support()const;

	/*!
	   \brief The setter of the support field
	   \pre No pre-conditions
	   \post No post-conditions
	   \return No return
	*/
   void set_support(uint32_t _support);

	/*!
	   \brief This function remove all mapped element of this container.
	   \pre No pre-conditions
	   \post No post-conditions
	   \return No return
	*/
   void clear();

	iterator begin();
	const_iterator begin()const;
	iterator end();
	const_iterator end()const;

   static bool  merge(const Itemset& i, const Itemset& j, Itemset& res);
   static void extract_rules(const Itemset& itemset, std::vector<Rule>& res);
   bool in(Itemset& other)const;

   friend std::ostream &operator<<(std::ostream &os, Itemset const &itemset);
   struct CompareDataPt{
      bool operator()( Data<std::string>* lhs, Data<std::string>* rhs);
   };
   struct CompareItemset{
      bool operator()(const Itemset& lhs,const Itemset& rhs);
   };
};

bool operator==(const Itemset& lhs, const Itemset& rhs);
bool operator<(const Itemset& lhs, const Itemset& rhs);
std::ostream &operator<<(std::ostream &os, Itemset const &itemset);
#endif
