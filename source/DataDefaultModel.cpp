#include "DataDefaultModel.hpp"



template<class D>
void DataDefaultModel<D>::insert(Data<D>& data){
   /* Inserting data
      - main vector have the right size ?
         - if not increase the size of the main vector
      - Nested vector have the right size ?
         -
      - Data at the right place already created ?
   */
   //Saving data in container
   data_container.push_back(new Data<D>(data));
   //Retreiving the reference to it from the container
   Data<D> * data_pt = &(data_container.back());
   std::list<Tuple>::iterator it = search(data_pt->get_id_tuple());
   if(it == data_map.end()){
      data_map.push_back((new Data<D>(data_pt->get_id_tuple())).insert(data_pt));
   }
   else{
      it->insert(data_pt);
   }

}

template<class D>
std::list<Tuple>::iterator DataDefaultModel<D>  ::search(uint32_t id){
   std::list<Tuple>::iterator it = data_map.begin();
   while(it != data_map.end() || it->id != id){it++;}
   return it;
}
