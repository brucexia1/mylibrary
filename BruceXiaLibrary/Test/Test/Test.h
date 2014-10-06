//#pragma once
#ifndef __BRUCEXIALIBRARY_GTEST_C_H_
#define __BRUCEXIALIBRARY_GTEST_C_H_

#include <gtest/gtest.h>

#include "../../brucexialibrary/include/baseStructures.h"
#include "../../brucexialibrary/include/xsSort.h"
#include "../../brucexialibrary/include/xsSearch.h"
#include "../../brucexialibrary/include/graph.h"
#include "../../brucexialibrary/include/tree.h"
#include "../../brucexialibrary/include/demo.h"
#include "../../brucexialibrary/include/testlibrary.h"

using namespace std;

/*******************************************************************************\
gtest提供了多种事件机制，非常方便我们在案例之前或之后做一些操作。总结一下gtest的
事件一共有3种：
1.全局的，所有案例执行前后。
2.TestSuite级别的，在某一批案例中第一个案例前，最后一个案例执行后。
3.TestCase级别的，每个TestCase前后。
\*******************************************************************************/

/*
全局事件
*/
class FooEnvironment : public testing::Environment
{
public:
	virtual void SetUp()
	{
		std::cout << "Foo FooEnvironment SetUP" << std::endl;
	}

	virtual void TearDown()
	{
		std::cout << "Foo FooEnvironment TearDown" << std::endl;
	}
};

class MyTestEnvironment : public testing::Environment
{
public:
	virtual void SetUp()
	{
		std::cout << "Bruce xia Environment SetUP" << std::endl;
	}

	virtual void TearDown()
	{
		std::cout << "Bruce xia Environment TearDown" << std::endl;
	}
};

/*
TestSuite事件
*/
//class FooTest : public testing::Test {
//protected:
//	static void SetUpTestCase() {
//		shared_resource_ = new TEST_STRUCT;
//	}
//
//	static void TearDownTestCase() {
//		delete shared_resource_;
//		shared_resource_ = NULL;
//	}
//
//	// Some expensive resource shared by all tests.
//	static TEST_STRUCT* shared_resource_;
//};

/*
TestCase事件
*/
//class FooCalcTest :public testing::Test
//{
//protected:
//	virtual void SetUp()
//	{
//		m_foo.Init();
//	}
//
//	virtual void TearDown()
//	{
//		m_foo.Finalize();
//	}
//
//	FooCalc m_foo;
//};

/*参数化*/
class IsPrimeParamTest : public::testing::TestWithParam<int>
{

};

/*类型参数化 */
//template <typename T>
//class CFooTest : public testing::Test {
//public:
//	typedef std::list<T> List;
//	static T shared_;
//	T value_;
//};

#endif