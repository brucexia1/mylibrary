#include "xsSort.h"


template<typename T>
void PrintVector(const std::vector<T> &vec)
{
	if (vec.empty()) return;
	std::vector<T>::const_iterator cit;
	for (cit = vec.begin(); cit != vec.end(); ++cit)
	{
		std::cout << *cit << ' ';
	}
	std::cout << endl;

	for (int i = 0; i<vec.size() - 1; ++i){
		if (vec[i]>vec[i + 1]){
			std::cout << "The sort algorithm has error!" << endl;
			return;
		}
	}
}

//�򵥲������� [������ ������]
template<typename T>
void InsertSort(std::vector<T> &vec)
{
	if (vec.empty()) return;
	T tmp;
	int i, j;
	for (i = 0; i < vec.size(); ++i)
	{
		tmp = vec[i];
		j = i - 1;
		while (j >= 0 && tmp < vec[j])
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = tmp;
	}
}

//���ֲ������� [������ ������]����������ÿ��Ԫ����
//�ö��ֲ��ҵ���ʽ�ҵ��Ĳ����λ��
template<typename T>
void InsertSortB(std::vector<T> &vec)
{
	if (vec.empty()) return;
	T tmp;
	int i, j, low, mid, high;
	for (i = 0; i<vec.size(); ++i)
	{
		tmp = vec[i];
		low = 0;	high = i - 1;
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (vec[mid]>tmp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; j--)
			vec[j + 1] = vec[j];
		vec[high + 1] = tmp;
	}
}

//ϣ�������������Ϊ1
template<typename T>
void ShellSort(std::vector<T> &vec)
{
	if (vec.empty()) return;
	int i, j, gap;
	T tmp;
	gap = vec.size() / 2;
	while (gap > 0)
	{
		for (i = gap; i<vec.size(); ++i)
		{
			tmp = vec[i];
			j = i - gap;
			while (j >= 0 && vec[j]>tmp)
			{
				vec[j + gap] = vec[j];
				j = j - gap;
			}
			vec[j + gap] = tmp;
		}
		gap = gap / 2;
	}
}

//ð������
template<typename T>
void BubbleSort(std::vector<T> &vec)
{
	if (vec.empty()) return;
	int i, j;
	T tmp;
	for (i = 0; i<vec.size() - 1; ++i)
	{
		for (j = vec.size() - 1; j>i; j--)
		{
			if (vec[j] < vec[j - 1])
			{
				tmp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = tmp;
			}
		}
	}
}

//���������һ�λ���
template<typename T>
int Partition(std::vector<T> &vec, int bg, int ed)
{
	if (bg<0 || ed>vec.size() - 1 || bg > ed) return -1;
	int i(bg), j(ed);
	T tmp(vec[ed]);	//�����һ��Ԫ����Ϊ���ջ���
	while (i < j) //or i!=j
	{
		while (i < j && vec[i] <= tmp)	i++;
		vec[j] = vec[i];
		while (i < j && vec[j] >= tmp) j--;
		vec[i] = vec[j];
	}
	vec[i] = tmp;
	return i;
}
//��������
template<typename T>
void QSort(std::vector<T> &vec, int bg, int ed)
{
	if (bg < ed){
		int i = Partition(vec, bg, ed);
		QSort(vec, bg, i - 1);
		QSort(vec, i + 1, ed);
	}
}
//��������
template<typename T>
void QuickSort(std::vector<T> &vec)
{
	if (vec.empty()) return;
	srand(unsigned(time(NULL)));
	int idx = rand() % vec.size();
	swap(vec[idx], vec[vec.size() - 1]);
	QSort(vec, 0, vec.size() - 1);
}

//ֱ��ѡ������
template<typename T>
void SelectSort(std::vector<T> &vec)
{
	if (vec.empty()) return;
	int i, j, k;
	T tmp;
	for (i = 0; i < vec.size() - 1; ++i)
	{
		k = i;
		for (j = i + 1; j < vec.size(); ++j)
		if (vec[j]<vec[k])
			k = j;
		if (k != i) swap(vec[k], vec[i]);
	}
}

//������Ľ���/�����㷨 (�����)
template<typename T>
void Sift(std::vector<T> &vec, int low, int high)
{
	if (low>high) return;
	int i(low), j(2 * i);
	T tmp(vec[i - 1]);
	while (j <= high)
	{
		if (j < high && vec[j - 1]<vec[j + 1 - 1]) j++;
		if (vec[j - 1]>tmp){
			vec[i - 1] = vec[j - 1];
			i = j;
			j = i * 2;
		}
		else break;
	}
	vec[i - 1] = tmp;
}
//�������㷨 (�����)
template<typename T>
void HeapSort(std::vector<T> &vec)
{
	if (vec.empty()) return;
	int n = vec.size();
	int i;
	for (i = n / 2; i >= 1; --i)	//ѭ��������ʼ��(�����һ����Ҷ�ӽ�㿪ʼ)
		Sift(vec, i, n);
	for (i = n; i >= 2; i--)
	{
		swap(vec[0], vec[i - 1]);
		Sift(vec, 1, i - 1);
	}
}

//�鲢����(��2��������ı�vec[low..mid],[mid+1..high]�ϲ�
//Ϊ�µ������[low...high])
template<typename T>
void Merge(std::vector<T> &vec, int low, int mid, int high)
{
	if (low > mid || mid > high) return;
	int i(low), j(mid + 1), k(0);
	vector<T> tmp(high - low + 1, 0);
	while (i <= mid && j <= high)
	{
		if (vec[i] < vec[j]){
			tmp[k] = vec[i];
			i++; k++;
		}
		else
		{
			tmp[k] = vec[j];
			j++; k++;
		}
	}
	while (i <= mid){
		tmp[k] = vec[i];
		i++; k++;
	}
	while (j <= high){
		tmp[k] = vec[j];
		j++; k++;
	}
	for (k = 0, i = low; i <= high; ++i, ++k)
		vec[i] = tmp[k];
}

//�鲢����(����һ�˹鲢)
template<typename T>
void MergePass(std::vector<T> &vec, int length)
{
	int i;
	int n = vec.size();
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)	//�鲢length�����������ӱ�
		Merge(vec, i, i + length - 1, i + 2 * length - 1);
	if (i + length - 1 < n)
		Merge(vec, i, i + length - 1, n - 1);
}

//�鲢���� ��[low...high]�����Զ����µĶ�·�鲢����
template<typename T>
void MeSort(std::vector<T> &vec, int low, int high)
{
	int mid;
	if (low < high){
		mid = low + (high - low) / 2;
		MeSort(vec, low, mid);
		MeSort(vec, mid + 1, high);
		Merge(vec, low, mid, high);
	}
}
//�Զ����¶�·�鲢�����㷨
template<typename T>
void MergeSort(std::vector<T> &vec)
{
	MeSort(vec, 0, vec.size() - 1);
}

//�Ե����϶�·�鲢�����㷨
template<typename T>
void MergeSortB(std::vector<T> &vec)
{
	int length;
	for (length = 1; length < vec.size(); length = length * 2)
		MergePass(vec, length);
}

/************************************************************************\
��������
Ҫ��n��Ԫ����ÿ��Ԫ�ض��ǽ���0-max֮�������������k=O(n)���������������ʱ��Ϊtheta(n)
�㷨��Ҫ2�����飬�����ռ�tmp[1..n]������ʱ�洢��C[0..k]
\************************************************************************/
void CountSort(std::vector<int> &vec, int max)
{
	if (vec.empty()) return;
	std::vector<int> tmp(vec.size(), 0);
	swap(vec, tmp);

	std::vector<int> C(max + 1, 0);

	int i(0);
	for (i = 0; i < vec.size(); ++i)
		C[tmp[i]] = C[tmp[i]] + 1;
	for (i = 1; i <= max; i++)
		C[i] = C[i] + C[i - 1];
	for (i = vec.size() - 1; i >= 0; --i){
		vec[C[tmp[i]] - 1] = tmp[i];
		C[tmp[i]] = C[tmp[i]] - 1;
	}
}

/************************************************************************\
�������� ֻ�ܶ�����������
d:Ԫ���Ǽ�λ��   r:�����������10������r=10
����������ã�RadixSort(vec,3,10);
\************************************************************************/
void RadixSort(std::vector<int> &vec, int d, int r)
{
	if (vec.empty() || d <= 0 || r <= 0) return;
	int i, j, k, tmp;
	std::vector<std::vector<int> > buckets(10);
	for (i = 0; i < d; i++){
		//Determine which bucket each element should enter
		for (j = 0; j < vec.size(); j++){
			tmp = (int)(vec[j] / pow((float)r, i)) % r;
			buckets[tmp].push_back(vec[j]);
		}
		//Transfer results of buckets back into main array
		int m(0);
		for (k = 0; k < r; k++){
			for (j = 0; j < buckets[k].size(); j++){
				vec[m] = buckets[k][j];
				m++;
			}
			//Clear previous bucket
			buckets[k].clear();
		}
	}
	buckets.clear();
}
