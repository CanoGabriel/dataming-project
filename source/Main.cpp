#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char ** argv){
   long double d = (long double)3;
   cout  << std::setprecision(10) << std::fixed << "Hello World  " << d << endl;
   return EXIT_SUCCESS;
}
