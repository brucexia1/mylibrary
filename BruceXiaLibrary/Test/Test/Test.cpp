#include "Test.h"



/*******************************************************************************\
gtest中，断言的宏可以理解为分为两类，一类是ASSERT系列，一类是EXPECT系列。
	1.ASSERT_* 系列的断言，当检查点失败时，退出当前函数（注意：并非退出当前案例）。
	2.EXPECT_* 系列的断言，当检查点失败时，继续往下执行。
\*******************************************************************************/


TEST(FooTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
	EXPECT_ANY_THROW(Foo(10, 0));
	EXPECT_THROW(Foo(0, 5), char*);
}

TEST(StringCmpTest, Demo)
{
	char* pszCoderZh = "CoderZh";
	wchar_t* wszCoderZh = L"CoderZh";
	std::string strCoderZh = "CoderZh";
	std::wstring wstrCoderZh = L"CoderZh";

	EXPECT_STREQ("CoderZh", pszCoderZh);
	EXPECT_STREQ(L"CoderZh", wszCoderZh);
	EXPECT_STRNE("CnBlogs", pszCoderZh);
	EXPECT_STRNE(L"CnBlogs", wszCoderZh);
	EXPECT_STRCASEEQ("coderzh", pszCoderZh);
	//EXPECT_STRCASEEQ(L"coderzh", wszCoderZh);    不支持
	EXPECT_STREQ("CoderZh", strCoderZh.c_str());
	EXPECT_STREQ(L"CoderZh", wstrCoderZh.c_str());
}

//TEST(ExplicitTest, Demo)
//{
//	ADD_FAILURE() << "Sorry"; // None Fatal Asserton，继续往下执行。
//	//FAIL(); // Fatal Assertion，不往下执行该案例。
//	SUCCEED();
//}

/*
Predicate Assertions
*/
TEST(PredicateAssertionTest, Demo)
{
	int m = 5, n = 6;
	EXPECT_PRED2(MutuallyPrime, m, n);
}

testing::AssertionResult AssertFoo(const char* m_expr, const char* n_expr,
	const char *k_expr, int m, int n, int k)
{
	if (Foo(m, n) == k)
		return testing::AssertionSuccess();
	testing::Message msg;
	msg << m_expr << " 和 " << n_expr << " 的最大公约数应该是：" << Foo(m, n) << " 而不是：" << k_expr;
	return testing::AssertionFailure(msg);
}
TEST(AssertFooTest, HandleFail)
{
	EXPECT_PRED_FORMAT3(AssertFoo, 3, 6, 3);
}

/*
类型检查
*/
template <typename T> class FooType
{
public:
	void Bar() { testing::StaticAssertTypeEq<int, T>(); }
};
TEST(TypeAssertionTest, Demo)
{
	FooType<int/*不是int型代码直接编译不通过*/> fooType;
	fooType.Bar();
}

/*
TestSuite事件
*/
//TEST_F(FooTest, Test1)
//{
//	// you can refer to shared_resource here 
//}
//
//TEST_F(FooTest, Test2)
//{
//	// you can refer to shared_resource here 
//}

/*
TestCase事件
*/
//TEST_F(FooCalcTest, HandleNoneZeroInput)
//{
//	EXPECT_EQ(4, m_foo.Calc(12, 16));
//}
//
//TEST_F(FooCalcTest, HandleNoneZeroInput_Error)
//{
//	EXPECT_EQ(5, m_foo.Calc(12, 16));
//}

/*参数化*/
TEST_P(IsPrimeParamTest, HandleTrueReturn)
{
	int n = GetParam();
	EXPECT_TRUE(IsPrime(n));
}
INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Values(3, 5, 11, 23, 17));


/*类型参数化 */
//typedef testing::Types<char, int, unsigned int> MyTypes;
//TYPED_TEST_CASE(CFooTest, MyTypes);
//TYPED_TEST(CFooTest, DoesBlah) {
//	// Inside a test, refer to the special name TypeParam to get the type
//	// parameter.  Since we are inside a derived class template, C++ requires
//	// us to visit the members of FooTest via 'this'.
//	TypeParam n = this->value_;
//
//	// To visit static members of the fixture, add the 'TestFixture::'
//	// prefix.
//	n += TestFixture::shared_;
//
//	// To refer to typedefs in the fixture, add the 'typename TestFixture::'
//	// prefix.  The 'typename' is required to satisfy the compiler.
//	typename TestFixture::List values;
//	values.push_back(n);
//}

TEST(FooDeathTest, Demo)
{
	EXPECT_DEATH(DeathFun(), "");
}


TEST(HashMapClassTest, Demo)
{
	std::hash_map<CString, int, CString_hash_compare> CStringHash;
	CStringHash["aaa"] = 123;
	CStringHash["bbb"] = 456;

	EXPECT_EQ(123, CStringHash["aaa"]);
	EXPECT_EQ(456, CStringHash["bbb"]);
}

TEST(CSubHashTest, Demo)
{
	CSubHash test;
	test.m_value = 123;
	test.m_message = "This is a test.";
	std::hash_map<CSubHash, int, MyHashCompare<CSubHash> > MyHash;
	MyHash[test] = 2005;

	EXPECT_EQ(2005, MyHash[test]);
}

TEST(DeleteSubStringTest, Demo)
{
	char *str = "abcde123abcd123";
	char *sub_str = "123";
	char *res_str = new char[100];
	int subnum = DeleteSubStr(str, sub_str, res_str);

	EXPECT_EQ(2, subnum);
	EXPECT_STREQ("abcdeabcd", res_str);
}

TEST(PassLineTest, Demo)
{
	float a1[10] = { 73.6, 85.5, 97.3, 30.2, 40.3, 50.4, 60.5, 70.6, 80.5, 90.3};
	float a2[10] = { 3.6, 5.5, 7.3, 0.2, 0.3, 0.4, 0.5, 0.6, 0.5, 0.3};
	float a3[10] = { 13.6, 15.5, 17.3, 10.2, 10.3, 10.4, 60.5, 70.6, 80.5, 10.3};
	float a4[10] = { 73.6, 85.5, 97.3, 63.2, 85.3, 64.4, 60.5, 70.6, 80.5, 90.3};
	float a5[10] = { 50,50,50,50,50,30,30,40,40,50};

	EXPECT_EQ(70, PassLine(a1, 10));
	EXPECT_EQ(0, PassLine(a2, 10));
	EXPECT_EQ(10, PassLine(a3, 10));
	EXPECT_EQ(60, PassLine(a4, 10));
	EXPECT_EQ(50, PassLine(a5, 10));
}

TEST(LineNumTest, Demo)
{
	EXPECT_EQ(1, Lights(3));
	EXPECT_EQ(2, Lights(5));
	EXPECT_EQ(3, Lights(10));
	EXPECT_EQ(10, Lights(100));
}

TEST(StringFilterTest, Demo)
{
	char pInputStr1[] = { "afafafafpppppppppppppp" };
	char pInputStr2[] = { "cccdppppppppppppppppdecccccccccccccccccccccc" };
	char pInputStr3[] = { "355 - 4555" };
	char pOutputStr1[256] = { 0 };
	char pOutputStr2[256] = { 0 };
	char pOutputStr3[256] = { 0 };
	StringFilter(pInputStr1, strlen(pInputStr1), pOutputStr1);
	StringZip(pInputStr2, strlen(pInputStr2), pOutputStr2);
	CharIntegerOperation(pInputStr3, strlen(pInputStr3), pOutputStr3);

	EXPECT_STREQ("afp", pOutputStr1 );
	EXPECT_STREQ("3cd16pde22c", pOutputStr2 );
	//EXPECT_STREQ("0", pOutputStr3 );
}

TEST(TreeTest, Demo)
{
	BTNode *b;
	CreateBTNode(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("层次遍历:");  TravLevel(b);
	printf("先序遍历:");  PreOrder(b);
	printf("中序遍历:");  InOrder(b);
	printf("后序遍历:");  PostOrder(b);
	printf("二叉树b的宽度:%d\n", BTWidth(b));
	vector<ElemType> path;
	vector<ElemType> longpath;
	AllPathRecursion(b, path);
	AllPath(b);
	LongPath(b, path, longpath);
	printf("\n第一条最长路径长度：%d\n", longpath.size());
	printf("第一条最长路径:");
	for (int i = longpath.size() - 1; i >= 0; i--)
		printf("%c ", longpath[i]);
	printf("\n");

	EXPECT_EQ(4, BTWidth(b));
	EXPECT_EQ(7, longpath.size() );
}

TEST(DFSBFSTest, Demo)
{
	size_t i, j;
	MGraph g;
	ALGraph *G = new ALGraph;
	int A[MAXV][6] = {
		{ 0, 5, 0, 7, 0, 0 },
		{ 0, 0, 4, 0, 0, 0 },
		{ 8, 0, 0, 0, 0, 9 },
		{ 0, 0, 5, 0, 0, 6 },
		{ 0, 0, 0, 5, 0, 0 },
		{ 3, 0, 0, 0, 1, 0 }
	};
	g.n = 6;
	g.e = 10;
	for (i = 0; i<g.n; ++i)
	for (j = 0; j<g.n; ++j)
		g.edges[i][j] = A[i][j];
	printf(" 有向图G的邻接矩阵：\n");	DispMat(g);
	MatToList(g, G);
	printf(" 有向图G的邻接矩阵转换为邻接表：\n");	DispAdj(G);
	printf("从顶点0开始的DFS:\n");
	DFS(G, 0); printf("\n");
	printf("从顶点0开始的DFS1:\n");
	DFS1(G, 0); printf("\n");
	printf("从顶点0开始的BFS:\n");
	BFS(G, 0); printf("\n");
}

TEST(DijkstraTest, Demo)
{
	//总是弹出栈溢出，有待解决

	//int i, j, u(0);
	//MGraph g;
	//int A[MAXV][6] = {
	//	{ INF, 5, INF, 7, INF, INF },
	//	{ INF, INF, 4, INF, INF, INF },
	//	{ 8, INF, INF, INF, INF, 9 },
	//	{ INF, INF, 5, INF, INF, 6 },
	//	{ INF, INF, INF, 5, INF, INF },
	//	{ 3, INF, INF, INF, 1, INF },
	//};
	//g.n = 6;
	//g.e = 10;
	//for (i = 0; i<g.n; ++i)
	//for (j = 0; j<g.n; ++j)
	//	g.edges[i][j] = A[i][j];
	//printf("\n");
	//printf("有向图G的邻接矩阵：\n");
	//DispMat(g);
	//Dijkstra(g, u);
	////Flyod(g);
	//printf("\n");
}


TEST(FlyodTest, Demo)
{
	MGraph g;
	g.n = 35;
	g.e = 35;
	for (int i = 0; i < g.n; ++i)
	for (int j = 0; j < g.n; ++j){
		if (i == j) g.edges[i][j] = 0;
		else g.edges[i][j] = INF;
	}
	//输入A环线个点相连情况 每个边权重都为1
	int a[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 33, 9, 10, 11, 12, 34, 13, 14, 15, 16, 17, 0 };
	for (int i = 0; i < 20; ++i){
		g.edges[a[i]][a[i + 1]] = 1;
		g.edges[a[i + 1]][a[i]] = 1;
	}
	//输入B线个点相连情况 每个边权重都为1
	int b[17] = { 18, 29, 20, 21, 22, 33, 23, 24, 25, 26, 27, 34, 28, 29, 30, 31, 32 };
	for (int i = 0; i < 16; i++){
		g.edges[b[i]][b[i + 1]] = 1;
		g.edges[b[i + 1]][b[i]] = 1;
	}
	std::vector<std::vector<int> > A(MAXV, std::vector<int>(MAXV, 0));
	Flyod(g, A);
	//string startport, endport;
	//while (true)
	//{
	//	cout << "输入起点和终点站，如(A1 B10):";
	//	cin >> startport >> endport;
	//	if (char2int(startport) != -1 && char2int(endport) != -1)
	//		cout << A[char2int(startport)][char2int(endport)] << endl;
	//	else cout << "Input Error!" << endl;
	//}

	EXPECT_EQ(7, A[Char2Int("A1")][Char2Int("B10")]);
	EXPECT_EQ(8, A[Char2Int("A1")][Char2Int("B12")]);
}

TEST(KruskalTest, Demo)
{
	int i, j;
	MGraph g;
	Edge E[MAXE];
	int A[MAXV][11];
	g.n = 6;
	g.e = 10;
	for (i = 0; i<g.n; i++)
	for (j = 0; j<g.n; j++)
		A[i][j] = INF;
	A[0][1] = 5; A[0][2] = 8; A[0][3] = 7; A[0][5] = 3;
	A[1][2] = 4;
	A[2][3] = 5; A[2][5] = 9;
	A[3][4] = 5;
	A[4][5] = 1;
	for (i = 0; i<g.n; i++)
	for (j = 0; j<g.n; j++)
		A[j][i] = A[i][j];
	for (i = 0; i<g.n; i++)
	for (j = 0; j<g.n; j++)
		g.edges[i][j] = A[i][j];
	SortEdge(g, E);

	cout << endl;
	cout << "图的邻接矩阵:" << endl;
	DispMat(g);
	cout << "克鲁斯卡尔算法求解结果：" << endl;
	Kruskal(E, g.n, g.e);
	cout<<endl;
}
