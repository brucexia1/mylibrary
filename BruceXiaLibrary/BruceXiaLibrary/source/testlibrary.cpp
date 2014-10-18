#include "../include/testlibrary.h"


/******************************\
[function] 在给定字符串中查找所有特定子串并删除，如果没有找到相应字串，则不作任何操作
[input] str:输入的被操作字符串
sub_str:需要查找并删除的特定子字符串
[output] result_str：在str字符串中删除所有sub_str子字符串的结果
[return] 删除的子字符串的个数
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

//注：字符串必须以'\0'结尾的c格式的字符串
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
[function] 比较2个无符位数字字符串的大小,字符串必须以'\0'结尾
【return】0:str1=str2 1:str1>str2  2:str2>str1
【注】"0012"不会出现，即最高位一定不为0
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
从考试成绩中划出及格线
10个学生考完期末考试评卷完成后，A老师需要划出及格线，要求如下：
(1) 及格线是10的倍数；
(2) 保证至少有60%的学生及格；
(3) 如果所有的学生都高于60分，则及格线为60分
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
template<typename T> void MySort(T a[], size_t n) //小数在前
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
亮着电灯的盏数
一条长廊里依次装有n(1 ≤ n ≤ 65535)盏电灯，从头到尾编号1、2、3、…n-1、n。每盏电灯由一个拉线开关控制。开始，电灯全部关着。
有n个学生从长廊穿过。第一个学生把号码凡是1的倍数的电灯的开关拉一下；
接着第二个学生把号码凡是2的倍数的电灯的开关拉一下；接着第三个学生把号码凡是3的倍数的电灯的开关拉一下；
如此继续下去，最后第n个学生把号码凡是n的倍数的电灯的开关拉一下。n个学生按此规定走完后，长廊里电灯有几盏亮着。
注：电灯数和学生数一致。
\*********************************************************************************/
//返回最后有几盏亮着的灯
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
通过键盘输入100以内正整数的加、减运算式，请编写一个程序输出运算结果字符串。
输入字符串的格式为：“操作数1 运算符 操作数2”，“操作数”与“运算符”之间以一个空格隔开。
补充说明：
1、操作数为正整数，不需要考虑计算结果溢出的情况。
2、若输入算式格式错误，输出结果为“0”。
【输入】 pInputStr：  输入字符串
lInputLen：  输入字符串长度
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；
【注意】只需要完成该函数功能算法，中间不需要有任何IO的输入输出
示例
输入：“4 + 7”  输出：“11”
输入：“4 - 7”  输出：“-3”
输入：“9 ++ 7”  输出：“0” 注：格式错误
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
通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串过滤程序，
若字符串中出现多个相同的字符，将非首次出现的字符过滤掉。
比如字符串“abacacde”过滤结果为“abcde”
【输入】 pInputStr：  输入字符串
lInputLen：  输入字符串长度
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；
【注意】只需要完成该函数功能算法，中间不需要有任何IO的输入输出
示例
输入：“deefd”        输出：“def”
输入：“afafafaf”     输出：“af”
输入：“pppppppp”     输出：“p”
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
通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串压缩程序，
将字符串中连续出席的重复字母进行压缩，并输出压缩后的字符串。
压缩规则：
1、仅压缩连续重复出现的字符。比如字符串"abcbc"由于无连续重复字符，压缩后的字符串还是"abcbc"。
2、压缩字段的格式为"字符重复的次数+字符"。例如：字符串"xxxyyyyyyz"压缩后就成为"3x6yz"。
【输入】 pInputStr：  输入字符串
lInputLen：  输入字符串长度
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；

【注意】只需要完成该函数功能算法，中间不需要有任何IO的输入输出

示例
输入：“cccddecc”   输出：“3c2de2c”
输入：“adef”     输出：“adef”
输入：“pppppppp” 输出：“8p”
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
				_itoa_s(k, buffer, 10); //将整数按10进制转换为字符串
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
		_itoa_s(k, buffer, 10); //将整数按10进制转换为字符串
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
高级题：地铁换乘
已知2条地铁线路，其中A为环线，B为东西向线路，线路都是双向的。经过的站点名分别如下，
两条线交叉的换乘点用T1、T2表示。编写程序，任意输入两个站点名称，
输出乘坐地铁最少需要经过的车站数量（含输入的起点和终点，换乘站点只计算一次）。
地铁线A（环线）经过车站：A1 A2 A3 A4 A5 A6 A7 A8 A9 T1 A10 A11 A12 A13 T2 A14 A15 A16 A17 A18
地铁线A（直线）经过车站：B1 B2 B3 B4 B5 T1 B6 B7 B8 B9 B10 T2 B11 B12 B13 B14 B15
\*********************************************************************************/
//站名字符串转节点编号       
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



