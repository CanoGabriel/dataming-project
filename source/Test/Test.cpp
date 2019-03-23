#include "Test.hpp"

using namespace Test;

bool TestFileReader::test_trim(){
   std::string str("  my string  ");
   FileReader::trim(str);
   if(str.compare("my string") == 0){
      std::cerr << "Test::FileLoader::trim ok" << std::endl;
      return true;
   }
   else{
      std::cerr << "Test::FileLoader::trim ko" << std::endl;
      return false;
   }
}

bool TestFileReader::test_split(){
   std::vector<std::string> v;
   std::string str("my string to split");
   FileReader::split(v,str," ");
   bool check = true;
   check &= v.size() == 4;
   for(std::string i : v){
      std::cerr <<"|"<< i <<"|";
   }
   std::cerr << std::endl;
   if(check) std::cerr << "Test::FileReader::split ok\n";
   else std::cerr << "Test::FileReader::split ko\n";
   return check;
}

bool TestFileReader::test_read_itemset_file(){
   ItemsetModel model;
   FileReader fr("./test/sample.csv");
   fr.read_itemset_file(",",model);
   //std::cerr << model << std::endl;
   bool check = model.get_size() == 100;
   if(check){
      std::cerr << "Test::FileReader::read_itemset_file ok\n";
      return true;
   }
   std::cerr << "Test::FileReader::read_itemset_file ko\n";
   return false;
}

bool TestFileReader::test_class(){
   bool check = true;
   check &= test_trim();
   check &= test_split();
   check &= test_read_itemset_file();
   return check;
}

bool TestItemsetModel::test_class(){
   bool check = true;
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
   //std::cerr << model << std::endl;
   check &= model.get_size() == 2;
   if(!check){
      std::cerr << "Test::ItemsetModel::insert ko" << std::endl;
      return false;
   }
   std::cerr << "Test::ItemsetModel::insert ok" << std::endl;
   auto t1 = model.search(0);
   auto t2 = model.search(1);

   check &= t1 != model.end() && t1->get_size() == 3;
   check &= t2 != model.end() && t2->get_size() == 3;
   if(!check){
      std::cerr << "Test::ItemsetModel::search ko" << std::endl;
      return false;
   }
	model.generate_itemset(0);
   return true;
}
