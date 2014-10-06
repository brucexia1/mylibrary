#include <tchar.h>
#include "Test/Test.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//testing::GTEST_FLAG(output) = "xml:";
	testing::AddGlobalTestEnvironment(new MyTestEnvironment);
	testing::AddGlobalTestEnvironment(new FooEnvironment);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
