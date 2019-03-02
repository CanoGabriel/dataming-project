#include "Dataloader.hpp"

DataLoader::DataLoader(Format _format, fs::path _path)
: format(_format),filePath(_path),lineCount(0)
{
   //If CSV ask for separator
   //Console
   if(format == Format::ARFF){

      std::cout << "Choose a charracter as separator : ";
      std::cin >> separator;
      //GUI
   }
}

//DataLoader::std::string getFormat(void){return format;}
void DataLoader::load(std::string str){
   switch (format) {
      case Format::CSV:
      ifstream in(filename);
      //Declare container for data to load here ???
      while(getCSVLine(in)){
         //itemset.clear();
      }
      break;
      case Format::ARFF:
      break;
      default:
      //Throw exception
   }
}

vector<string> DataLoader::split(std::string s){
   vector<string> data;
   size_t pos = 0;
   string value;
   while ((pos = s.find(separator)) != string::npos) {
      value = s.substr(0, pos);
      data.push_back(value);
      s.erase(0, pos + separator.length());
   }
   data.push_back(s);
   return data;
}

bool DataLoader::getCSVLine(std::ifstream& in){
   if (in.is_open()){
      if( (ignoreFirstLine && lineCount != 0) || (!ignoreFirstLine) ){
         lineCount++;
         string line;
         if ( std::getline (in,line) ){
            vector<string> v = split(line,separator);
            for(auto item = v.begin() ; item != v.end() ; item++ ){
               //Loading data
            }
            return true;
         }
         return false;
      }
   }
   else cerr << "Unable to read file"; //Throw exception !!!
   return false;
}
