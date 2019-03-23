#include "FileReader.hpp"
FileReader::FileReader(std::string _path): path(_path){
   input = std::ifstream(path,std::ifstream::in);
}

bool FileReader::get_line(std::string& line){
   if(!input.is_open()){
      return false;
   }
   line.clear();
   if ( std::getline(input,line) ){
     return true;
   }
   if(input.eof()){return false;}
   else std::cerr << "Unable to read file";
   return false;
}

void FileReader::split(std::vector<std::string>& result, std::string& line, std::string delim){
   std::string s(line);
   size_t pos = 0;
   std::string token;
   while ((pos = s.find(delim)) != std::string::npos) {
     token = s.substr(0, pos);
     result.push_back(token);
     s.erase(0, pos + delim.length());
   }
   result.push_back(s);
}

void FileReader::trim(std::string& str){
   size_t first = str.find_first_not_of(WHITESPACE);
   if (std::string::npos == first){
      return ;
   }
   size_t last = str.find_last_not_of(WHITESPACE);
   str = str.substr(first, (last - first + 1));
}


void FileReader::read_itemset_file(std::string item_delimitor, ItemsetModel& model){
   std::string line;
   while(get_line(line)){
      std::vector<std::string> items;
      split(items,line,item_delimitor);
      uint32_t id = Itemset::get_new_id();
      for(std::vector<std::string>::iterator it = items.begin() ; it != items.end() ; it++){
         Data<std::string> item(id,0,*it);
         model.insert(item);
      }
   }
}
