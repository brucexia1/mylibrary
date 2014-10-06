#ifndef __BRUCEXIALIBRARY_DEMO_C_H_
#define __BRUCEXIALIBRARY_DEMO_C_H_


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <hash_map>
#include <atlstr.h>


int Foo(int a, int b);
bool MutuallyPrime(int m, int n);
bool IsPrime(int n);

/*判断传入的数值是否为质数*/
template <typename T> T Add(T a, T b);

void DeathFun();

typedef struct {
	int i;
	std::string str;
}TEST_STRUCT;


inline size_t CString_hash_value(const CString& str)
{
	size_t value = _HASH_SEED;
	size_t size = str.GetLength();
	if (size > 0) {
		size_t temp = (size / 16) + 1;
		size -= temp;
		for (size_t idx = 0; idx <= size; idx += temp) {
			value += (size_t)str[(int)idx];
		}
	}
	return(value);
}
class CString_hash_compare : public std::hash_compare<CString>
{
public:
	size_t operator()(const CString& _Key) const {
		return((size_t)CString_hash_value(_Key));
	}
	bool operator()(const CString& _Keyval1, const CString& _Keyval2) const {
		return _Keyval1.Compare(_Keyval2);
	}
};
struct IHashable{
	virtual unsigned long hash_value() const = 0;
	virtual bool operator < (const IHashable& val) const = 0;
	virtual IHashable& operator = (const IHashable& val) = 0;
};
class CSubHash :public IHashable
{
public:
	int m_value;
	CString m_message;

public:
	CSubHash() :m_value(0){}
	CSubHash(const CSubHash& obj){
		m_value = obj.m_value;
		m_message = obj.m_message;
	}

public:
	virtual IHashable& operator = (const IHashable& val) {
		//m_value   = ((CSubHash&)val).m_value;
		//m_message = ((CSubHash&)val).m_message;
		m_value = (dynamic_cast<CSubHash&>(const_cast<IHashable&>(val))).m_value;
		m_message = (dynamic_cast<CSubHash&>(const_cast<IHashable&>(val))).m_message;
		return(*this);
	}

	virtual unsigned long hash_value() const {
		// 这里使用类中的m_value域计算hash值，也可以使用更复杂的函数计算所有域总的hash值  
		return (m_value ^ 0xdeadbeef);
	}

	virtual bool operator < (const IHashable& val) const {
		return (m_value < ((dynamic_cast<CSubHash&>(const_cast<IHashable&>(val))).m_value));
	}
};
template<class _Tkey>
class MyHashCompare : public std::hash_compare<_Tkey>
{
public:
	size_t operator()(const _Tkey& _Key) const {
		return(_Key.hash_value());
	}
	bool operator()(const _Tkey& _Keyval1, const _Tkey& _Keyval2) const {
		//return (comp(_Keyval1, _Keyval2));
		return _Keyval1<_Keyval2;
	}
};


#endif