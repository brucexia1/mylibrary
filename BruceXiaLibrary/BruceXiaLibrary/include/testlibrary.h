#ifndef __BRUCEXIALIBRARY_TESTLIBRARY_C_H_
#define __BRUCEXIALIBRARY_TESTLIBRARY_C_H_


#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

int DeleteSubStr(const char *str, const char *sub_str, char *result_str);
bool IsEqualSubstr(const char *sub_str1, const char *sub_str2, int sub_str_len);
inline int MyStrLen(const char *str);

int NumStringCompare(const char *str1, const char *str2);

int PassLine(float score[], size_t n);
template<typename T> void MySort(T a[], size_t n); //小数在前

int Lights(int N);
void CharIntegerOperation(const char *pInputStr, long lInputLen, char *pOutputStr);
void StringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
void StringZip(const char *pInputStr, long lInputLen, char *pOutputStr);

int Char2Int(std::string s);


#endif