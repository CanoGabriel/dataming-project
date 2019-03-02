#ifndef DATA_LOADER
#define DATA_LOADER

#include <string>
#include <filesystem>
#include <vector>
#include <ifstream>

namespace fs = std::filesystem;

enum class Format: std::string {ARFF=".arff", CSV="Character Separated Values"};

class DataLoader {

   Format format;
   fs::path filePath;
   boolean ignoreFirstLine = false;
   std::string separator;
   int lineCount;

   void loadCSV(std::string str);


   public :

   DataLoader(Format _format, fs::path _path);
   vector<string> DataLoader::split(string s,string delimiter);
   //void setFormat(Format _format){format = _format;}
   //std::string getFormat(void){return format;}
   //void setFilePath(fs::path _path){filePath=_path;}
   //fs::path getFilePath(void){return filePath;}
};


#endif
