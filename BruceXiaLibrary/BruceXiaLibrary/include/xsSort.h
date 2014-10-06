#ifndef __BRUCEXIALIBRARY_XSSORT_C_H_
#define __BRUCEXIALIBRARY_XSSORT_C_H_


#include <vector>
#include <iostream>
#include <time.h>
#include "baseStructures.h"

template<typename T>
void PrintVector(const std::vector<T> &vec);

//�򵥲������� [������ ������]
template<typename T>
void InsertSort(std::vector<T> &vec);

//���ֲ������� [������ ������]����������ÿ��Ԫ����
//�ö��ֲ��ҵ���ʽ�ҵ��Ĳ����λ��
template<typename T>
void InsertSortB(std::vector<T> &vec);

//ϣ�������������Ϊ1
template<typename T>
void ShellSort(std::vector<T> &vec);

//ð������
template<typename T>
void BubbleSort(std::vector<T> &vec);

//���������һ�λ���
template<typename T>
int Partition(std::vector<T> &vec, int bg, int ed);
//��������
template<typename T>
void QSort(std::vector<T> &vec, int bg, int ed);
//��������
template<typename T>
void QuickSort(std::vector<T> &vec);

//ֱ��ѡ������
template<typename T>
void SelectSort(std::vector<T> &vec);

//������Ľ���/�����㷨 (�����)
template<typename T>
void Sift(std::vector<T> &vec, int low, int high);
//�������㷨 (�����)
template<typename T>
void HeapSort(std::vector<T> &vec);

//�鲢����(��2��������ı�vec[low..mid],[mid+1..high]�ϲ�
//Ϊ�µ������[low...high])
template<typename T>
void Merge(std::vector<T> &vec, int low, int mid, int high);

//�鲢����(����һ�˹鲢)
template<typename T>
void MergePass(std::vector<T> &vec, int length);

//�鲢���� ��[low...high]�����Զ����µĶ�·�鲢����
template<typename T>
void MeSort(std::vector<T> &vec, int low, int high);
//�Զ����¶�·�鲢�����㷨
template<typename T> void MergeSort(std::vector<T> &vec);

//�Ե����϶�·�鲢�����㷨
template<typename T> void MergeSortB(std::vector<T> &vec);

/************************************************************************\
	��������
	Ҫ��n��Ԫ����ÿ��Ԫ�ض��ǽ���0-max֮�������������k=O(n)���������������ʱ��Ϊtheta(n)
	�㷨��Ҫ2�����飬�����ռ�tmp[1..n]������ʱ�洢��C[0..k]
	\************************************************************************/
void CountSort(std::vector<int> &vec, int max);

/************************************************************************\
�������� ֻ�ܶ�����������
d:Ԫ���Ǽ�λ��   r:�����������10������r=10
����������ã�RadixSort(vec,3,10);
\************************************************************************/
void RadixSort(std::vector<int> &vec, int d, int r);


#endif