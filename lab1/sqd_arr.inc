#include"sqd_arr.h"

#include<cstdlib>//exit
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

template<typename T>
sqd_arr<T>::sqd_arr()
{
	Max = 1000;
	Index = 0;
	arr = new T[Max];
}

template<typename T>
sqd_arr<T>::sqd_arr(int size)
{
	if (size < Max && size > 0)
	{
		Max = 1000;
		Index = 0;
		arr = new T[size];
		Max = size;
	}
	else
	{
		std::cout << "Завеликий розмір або введене від'ємне число. Виділено масив на 1000 елементів" << std::endl;
		Max = 1000;
		Index = 0;
		arr = new T[Max];
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void sqd_arr<T>::add_stack(T a)
{
	if (Index < Max)
	{
		for (int i = Index; i >= 1; i--)
			arr[i] = arr[i - 1];

		arr[0] = a;
		Index++;
	}
	else
		std::cout << "Переповнення." << std::endl;
}

template<typename T>
bool sqd_arr<T>::is_empty()
{
	return Index == 0;
}

template<typename T>
T sqd_arr<T>::back()
{
	if (Index > 0)
		return arr[Index - 1];
	else exit(1);
}

template<typename T>
T sqd_arr<T>::front()
{
	if (Index > 0)
		return arr[0];
	else exit(1);
}

template<typename T>
void sqd_arr<T>::pop_front()
{
	if (Index > 0)
	{
		Index--;// we delete element
		for (int i = 0; i < Index; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
}

template<typename T>
bool sqd_arr<T>::erase_from_position(int position)
{
	if (Index > 0 && position <= Index && position > 0)
	{
		if (position == 1)
		{
			this->pop_front();
			return true;
		}
		else
		{
			Index--;// we delete element
			position--;//because 0 == 1 position for user
			for (int i = position; i < Index; i++)
			{
				arr[i] = arr[i + 1];
			}
			return true;
		}
	}
	else
		return false;
}

template<typename T>
bool sqd_arr<T>::delete_data(T a)
{
	if (Index > 0)
	{
		if (arr[0]==a)
		{
			this->pop_front();
			return true;
		}
		else
		{
			int position = -1;
			for (int i = 1; i < Index; i++)
			{
				if (arr[i] == a)
				{
					position = i;
				}
			}
			if (position != -1)//we found this element
			{
				Index--;
				for (int i = position; i < Index; i++)
				{
					arr[i] = arr[i + 1];
				}
				return true;
			}
		}
	}
	return false;
}

template<typename T>
int sqd_arr<T>::size() const
{
	return Index;
}

template<typename T>
void sqd_arr<T>::add_queue(T a)
{
	if (Index < Max)
	{
		arr[Index++] = a;
	}
	else
		std::cout << "Переповнення." << std::endl;
}

template<typename T>
void sqd_arr<T>::push_front(T a)
{
	this->add_stack(a);
}

template<typename T>
void sqd_arr<T>::push_back(T a)
{
	this->add_queue(a);
}

template<typename T>
void sqd_arr<T>::pop_back()
{
	if (Index > 0)
	{
		Index--;
	}
}

template<typename T>
void sqd_arr<T>::show()
{
	for (int i = 0; i < Index; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void sqd_arr<T>::clear()
{
	Index = 0;//псевдоочищення
}

template<typename T>
sqd_arr<T>& sqd_arr<T>::operator =(const sqd_arr&other_class)
{
	if (arr != nullptr)
		delete arr;
	arr = new T[other_class.Max];
	Max = other_class.Max;
	Index = other_class.Index;
	for (int i = 0; i < other_class.Index; i++)
	{
		arr[i] = other_class.arr[i];
	}
	return *this;
}

template<typename T>
T sqd_arr<T>::operator[](int index)
{
	if (Index > 0 && index < Index && index >= 0)
	{
		return arr[index];
	}
	else exit(1);
}

template<typename T>
void sqd_arr<T>::sort()
{
	for (int i = 0; i < Index; i++)
	{
		bool swapped = false;
		for (int j = 1; j < Index - i; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				T tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

