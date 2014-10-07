#ifndef __BRUCEXIALIBRARY_COM_C_H_
#define __BRUCEXIALIBRARY_COM_C_H_

#include <iostream>
#include <vector>

template <typename T>
inline void PrintVector(const std::vector<T> &vec)
{
	for (std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}



#endif
