VC++目录：
	包含目录下添加：D:\mytools\gtest\include;	//你的gtest include目录
	库目录下添加：D:\mytools\gtest\lib;		//你的编译好的gtest的lib目录位置

链接器：gtestd.lib（debug版），gtest.lib（release版）

修改C/C++ -〉代码生成  -〉 运行库为 “多线程调试（/MTd）”（debug版）
注：即这里使用的时静态库，这是由于我们编译的gtest是静态库。
要想使用默认的“多线程调试DLL（/MDd）”，必须在编译gtest的时候也使用这个编译，来生成lib和dll两个文件。
并把生成的dll目录位置加入到系统环境变量，lib库模仿上面操作即可。
	