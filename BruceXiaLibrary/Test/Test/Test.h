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
gtest�ṩ�˶����¼����ƣ��ǳ����������ڰ���֮ǰ��֮����һЩ�������ܽ�һ��gtest��
�¼�һ����3�֣�
1.ȫ�ֵģ����а���ִ��ǰ��
2.TestSuite����ģ���ĳһ�������е�һ������ǰ�����һ������ִ�к�
3.TestCase����ģ�ÿ��TestCaseǰ��
\*******************************************************************************/

/*
ȫ���¼�
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
TestSuite�¼�
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
TestCase�¼�
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

/*������*/
class IsPrimeParamTest : public::testing::TestWithParam<int>
{

};

/*���Ͳ����� */
//template <typename T>
//class CFooTest : public testing::Test {
//public:
//	typedef std::list<T> List;
//	static T shared_;
//	T value_;
//};

#endif