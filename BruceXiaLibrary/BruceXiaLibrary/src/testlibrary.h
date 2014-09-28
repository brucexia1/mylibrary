#ifndef __BRUCEXIALIBRARY_TESTLIBRARY_C_H_
#define __BRUCEXIALIBRARY_TESTLIBRARY_C_H_


#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

int delete_sub_str(const char *str, const char *sub_str, char *result_str);
bool isequal_substr(const char *sub_str1, const char *sub_str2, int sub_str_len);
inline int mystrlen(const char *str);

int maxucharnum(const char *str1, const char *str2);

int passLine(float score[], size_t n);
template<typename T> void mysort(T a[], size_t n); //小数在前

int lightnum(int N);
void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr);
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);

int char2int(std::string s);


#endif