#ifndef FILE_READER
#define FILE_READER


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

#include "ItemsetModel.hpp"
#include "Itemset.hpp"

#define WHITESPACE " \f\t\v\r"

class FileReader {
   std::string path;
   std::ifstream input;
public:
   FileReader(std::string _path);
   bool get_line(std::string& line);
   static void split(std::vector<std::string>& result,std::string& line, std::string delim);
   static void trim(std::string& str);
   void read_itemset_file(std::string item_delimitor, ItemsetModel& model);
};

#endif
