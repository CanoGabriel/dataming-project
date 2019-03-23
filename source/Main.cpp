#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <gtest/gtest.h>
#include <cstdlib>
#include <climits>

int main(int argc, char ** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
