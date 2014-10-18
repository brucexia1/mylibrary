#include "../include/testlibrary.h"


/******************************\
[function] �ڸ����ַ����в��������ض��Ӵ���ɾ�������û���ҵ���Ӧ�ִ��������κβ���
[input] str:����ı������ַ���
sub_str:��Ҫ���Ҳ�ɾ�����ض����ַ���
[output] result_str����str�ַ�����ɾ������sub_str���ַ����Ľ��
[return] ɾ�������ַ����ĸ���
\******************************/
int DeleteSubStr(const char *str, const char *sub_str, char *result_str)
{
	int n = MyStrLen(str);
	int sn = MyStrLen(sub_str);
	int count(0);
	bool isequal(false);
	const char *s = str;
	int i(0), j(0);
	for (i = 0; i <= n - sn; ++i, ++s){
		isequal = IsEqualSubstr(s, sub_str, sn);
		if (isequal) {
			++count, i += sn - 1, s += sn - 1;
		}
		else
		{
			result_str[j] = str[i];
			++j;
		}
	}
	for (; i<n; ++i, ++j)
	{
		result_str[j] = str[i];
	}
	result_str[j] = '\0';
	return count;
}
bool IsEqualSubstr(const char *sub_str1, const char *sub_str2, int sub_str_len)
{
	for (int i = 0; i<sub_str_len; ++i, ++sub_str1, ++sub_str2)
	{
		if (*sub_str1 != *sub_str2) return false;
	}
	return true;
}

//ע���ַ���������'\0'��β��c��ʽ���ַ���
inline int MyStrLen(const char *str)
{
	int i(0);
	while (*str != '\0') {
		++i;
		++str;
	}
	return i;
}

/************************************************************************\
[function] �Ƚ�2���޷�λ�����ַ����Ĵ�С,�ַ���������'\0'��β
��return��0:str1=str2 1:str1>str2  2:str2>str1
��ע��"0012"������֣������λһ����Ϊ0
\************************************************************************/
int NumStringCompare(const char *str1, const char *str2)
{
	int l1(MyStrLen(str1));
	int l2(MyStrLen(str2));
	if (l1>l2) return 1;
	else if (l1<l2) return 2;
	else{
		for (int i = 0; i<l1; ++i, ++str1, ++str2)
		{
			if (*str1>*str2){
				return 1;
			}
			else if (*str1<*str2)
			{
				return 2;
			}
		}
	}
	return 0;
}

/*********************************************************************************\
�ӿ��Գɼ��л���������
10��ѧ��������ĩ����������ɺ�A��ʦ��Ҫ���������ߣ�Ҫ�����£�
(1) ��������10�ı�����
(2) ��֤������60%��ѧ������
(3) ������е�ѧ��������60�֣��򼰸���Ϊ60��
\*********************************************************************************/
int PassLine(float score[], size_t n)
{
	int pl(0);
	MySort(score, n);
	for (size_t i = 0; i<n; ++i){
		std::cout << score[i] << ' ';
	}
	std::cout << std::endl;
	pl = score[int(n*(1 - 0.6) - 1)];
	pl = (int(pl / 10)) * 10;
	if (pl<int(score[int(n*(1 - 0.6))])){
		pl = int(int(score[int(n*(1 - 0.6))]) / 10) * 10;
	}
	if (score[0]>60) pl = 60;
	return pl;
}
template<typename T> void MySort(T a[], size_t n) //С����ǰ
{
	size_t i, j;
	T temp;
	for (i = 0; i<n; ++i)
	{
		for (j = n - 1; j>i; --j)
		{
			if (a[j]<a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

/*********************************************************************************\
���ŵ�Ƶ�յ��
һ������������װ��n(1 �� n �� 65535)յ��ƣ���ͷ��β���1��2��3����n-1��n��ÿյ�����һ�����߿��ؿ��ơ���ʼ�����ȫ�����š�
��n��ѧ���ӳ��ȴ�������һ��ѧ���Ѻ��뷲��1�ı����ĵ�ƵĿ�����һ�£�
���ŵڶ���ѧ���Ѻ��뷲��2�ı����ĵ�ƵĿ�����һ�£����ŵ�����ѧ���Ѻ��뷲��3�ı����ĵ�ƵĿ�����һ�£�
��˼�����ȥ������n��ѧ���Ѻ��뷲��n�ı����ĵ�ƵĿ�����һ�¡�n��ѧ�����˹涨����󣬳��������м�յ���š�
ע���������ѧ����һ�¡�
\*********************************************************************************/
//��������м�յ���ŵĵ�
int Lights(int N)
{
	if (N<1 || N>65535) return -1;
	bool *ln = new bool[N];
	memset(ln, false, N);

	for (size_t i = 0; i<N; ++i){
		for (size_t j = 0; j<N; j++){
			if ((j + 1) % (i + 1) == 0){
				ln[j] = !ln[j];
			}
		}
	}

	int ls(0);
	for (size_t i = 0; i<N; ++i){
		if (true == ln[i]) ++ls;
	}

	return ls;
}


/************************************************************************\
ͨ����������100�����������ļӡ�������ʽ�����дһ����������������ַ�����
�����ַ����ĸ�ʽΪ����������1 ����� ������2���������������롰�������֮����һ���ո������
����˵����
1��������Ϊ������������Ҫ���Ǽ���������������
2����������ʽ��ʽ����������Ϊ��0����
�����롿 pInputStr��  �����ַ���
lInputLen��  �����ַ�������
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���
��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������
ʾ��
���룺��4 + 7��  �������11��
���룺��4 - 7��  �������-3��
���룺��9 ++ 7��  �������0�� ע����ʽ����
\************************************************************************/
void CharIntegerOperation(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i, am(0);
	for (i = 0; i<lInputLen; i++)
	{
		switch (pInputStr[i])
		{
		case '+': am = 1;
			break;
		case '-': am = 2;
			break;
		}
		if (am != 0) break;
	}
	if (pInputStr[i - 1] != ' ' && pInputStr[i + 1] != ' ')
	{
		pOutputStr[0] = '0';
		pOutputStr[1] = '\0';
		return;
	}
	int mid(i), a1(0), a2, b1, b2(lInputLen - 1);
	for (i = 0; i <= mid; i++)
	{
		if (pInputStr[i] == ' '){
			a2 = i - 1;
			break;
		}
	}
	for (i = mid + 1; i<lInputLen; i++)
	{
		if (pInputStr[i] != ' '){
			b1 = i;
			break;
		}
	}

	int n1(0), n2(0);
	for (i = a1; i <= a2; i++)
	{
		if (pInputStr[i] >= '0' && pInputStr[i] <= '9')
			n1 = n1 * 10 + pInputStr[i] - '0';
		else{
			pOutputStr[0] = '0';
			pOutputStr[1] = '\0';
			return;
		}
	}
	for (i = b1; i <= b2; i++)
	{
		if (pInputStr[i] >= '0' && pInputStr[i] <= '9')
			n2 = n2 * 10 + pInputStr[i] - '0';
		else{
			pOutputStr[0] = '0';
			pOutputStr[1] = '\0';
			return;
		}
	}

	int res(0);
	switch (am)
	{
	case 1: res = n1 + n2;
		break;
	case 2: res = n1 - n2;
		break;
	}
	char buffer[20];
	_itoa_s(res, buffer, 10);
	strcpy_s(pOutputStr,10, buffer);
}

/****************************************************************************\
ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ��������дһ���ַ������˳���
���ַ����г��ֶ����ͬ���ַ��������״γ��ֵ��ַ����˵���
�����ַ�����abacacde�����˽��Ϊ��abcde��
�����롿 pInputStr��  �����ַ���
lInputLen��  �����ַ�������
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���
��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������
ʾ��
���룺��deefd��        �������def��
���룺��afafafaf��     �������af��
���룺��pppppppp��     �������p��
\****************************************************************************/
void StringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int k(0);
	bool flag(true);
	pOutputStr[0] = pInputStr[0];
	for (int i = 0; i<lInputLen; i++){
		flag = true;
		for (int j = 0; j <= k; j++)
		{
			if (pOutputStr[j] == pInputStr[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			k++;
			pOutputStr[k] = pInputStr[i];
		}
	}
	pOutputStr[k + 1] = '\0';
}


/****************************************************************************\
ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ��������дһ���ַ���ѹ������
���ַ�����������ϯ���ظ���ĸ����ѹ���������ѹ������ַ�����
ѹ������
1����ѹ�������ظ����ֵ��ַ��������ַ���"abcbc"�����������ظ��ַ���ѹ������ַ�������"abcbc"��
2��ѹ���ֶεĸ�ʽΪ"�ַ��ظ��Ĵ���+�ַ�"�����磺�ַ���"xxxyyyyyyz"ѹ����ͳ�Ϊ"3x6yz"��
�����롿 pInputStr��  �����ַ���
lInputLen��  �����ַ�������
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���

��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO���������

ʾ��
���룺��cccddecc��   �������3c2de2c��
���룺��adef��     �������adef��
���룺��pppppppp�� �������8p��
\****************************************************************************/
void StringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	const char *fp, *ep;
	int i(0), k(0);
	char buffer[20];
	fp = &pInputStr[0];
	ep = &pInputStr[0];
	while (*ep != '\0')
	{
		if (*fp != *ep)
		{
			if (k>1){
				memset(buffer, 0, sizeof(buffer));
				_itoa_s(k, buffer, 10); //��������10����ת��Ϊ�ַ���
				strcpy_s(&pOutputStr[i],10, buffer);
				i += strlen(buffer);
				pOutputStr[i] = *fp;
			}
			else{
				pOutputStr[i] = *fp;
			}
			i++; fp = ep; k = 0;
		}
		else{
			k++; ep++;
		}
	}
	if (k>1){
		memset(buffer, 0, sizeof(buffer));
		_itoa_s(k, buffer, 10); //��������10����ת��Ϊ�ַ���
		strcpy_s(&pOutputStr[i],10, buffer);
		i += strlen(buffer);
		pOutputStr[i] = *fp;
	}
	else{
		pOutputStr[i] = *fp;
	}
	pOutputStr[i + 1] = '\0';
}


/*********************************************************************************\
�߼��⣺��������
��֪2��������·������AΪ���ߣ�BΪ��������·����·����˫��ġ�������վ�����ֱ����£�
�����߽���Ļ��˵���T1��T2��ʾ����д����������������վ�����ƣ�
�����������������Ҫ�����ĳ�վ������������������յ㣬����վ��ֻ����һ�Σ���
������A�����ߣ�������վ��A1 A2 A3 A4 A5 A6 A7 A8 A9 T1 A10 A11 A12 A13 T2 A14 A15 A16 A17 A18
������A��ֱ�ߣ�������վ��B1 B2 B3 B4 B5 T1 B6 B7 B8 B9 B10 T2 B11 B12 B13 B14 B15
\*********************************************************************************/
//վ���ַ���ת�ڵ���       
int Char2Int(std::string s)
{
	std::string s1[35] = {
		"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10",
		"A11", "A12", "A13", "A14", "A15", "A16", "A17", "A18", "B1", "B2",
		"B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12",
		"B13", "B14", "B15", "T1", "T2" };

	for (int i = 0; i <= 34; i++){
		if (s == s1[i])	return i;
	}
	return -1;
}



