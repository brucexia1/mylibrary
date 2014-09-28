#ifndef __BRUCEXIALIBRARY_XSSORT_C_H_
#define __BRUCEXIALIBRARY_XSSORT_C_H_


#include <vector>
#include <iostream>
#include <time.h>
#include "baseStructures.h"

template<typename T>
void PrintVector(const std::vector<T> &vec);

//简单插入排序 [有序区 无序区]
template<typename T>
void InsertSort(std::vector<T> &vec);

//二分插入排序 [有序区 无序区]，无序区的每个元素是
//用二分查找的形式找到改插入的位置
template<typename T>
void InsertSortB(std::vector<T> &vec);

//希尔排序，增量最后为1
template<typename T>
void ShellSort(std::vector<T> &vec);

//冒泡排序
template<typename T>
void BubbleSort(std::vector<T> &vec);

//快速排序的一次划分
template<typename T>
int Partition(std::vector<T> &vec, int bg, int ed);
//快速排序
template<typename T>
void QSort(std::vector<T> &vec, int bg, int ed);
//快速排序
template<typename T>
void QuickSort(std::vector<T> &vec);

//直接选择排序
template<typename T>
void SelectSort(std::vector<T> &vec);

//堆排序的建堆/调堆算法 (大根堆)
template<typename T>
void Sift(std::vector<T> &vec, int low, int high);
//堆排序算法 (大根堆)
template<typename T>
void HeapSort(std::vector<T> &vec);

//归并排序(将2个已有序的表vec[low..mid],[mid+1..high]合并
//为新的有序表[low...high])
template<typename T>
void Merge(std::vector<T> &vec, int low, int mid, int high);

//归并排序(进行一趟归并)
template<typename T>
void MergePass(std::vector<T> &vec, int length);

//归并排序 对[low...high]进行自顶向下的二路归并排序
template<typename T>
void MeSort(std::vector<T> &vec, int low, int high);
//自顶向下二路归并排序算法
template<typename T> void MergeSort(std::vector<T> &vec);

//自底向上二路归并排序算法
template<typename T> void MergeSortB(std::vector<T> &vec);

/************************************************************************\
	计数排序
	要求n个元素中每个元素都是介于0-max之间的正整数。当k=O(n)，计数排序的运行时间为theta(n)
	算法需要2个数组，辅助空间tmp[1..n]，和临时存储区C[0..k]
	\************************************************************************/
void CountSort(std::vector<int> &vec, int max);

/************************************************************************\
基数排序 只能对正整数排序
d:元素是几位数   r:基数，如对于10进制是r=10
如可这样调用：RadixSort(vec,3,10);
\************************************************************************/
void RadixSort(std::vector<int> &vec, int d, int r);


#endif