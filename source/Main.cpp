#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "Test.hpp"

int main(int argc, char ** argv){
   bool check = true;
   check &= Test::TestFileReader::test_class();;
   if(check) std::cerr << "Test class FileReader ok\n\n";
   else std::cerr << "Test class FileReader ko\n\n";
   check &= Test::TestItemsetModel::test_class();;
   if(check) std::cerr << "Test class ItemsetModel ok\n\n";
   else std::cerr << "Test class ItemsetModel ko\n\n";
   if(check) return EXIT_SUCCESS;
   else return EXIT_FAILURE;
}
