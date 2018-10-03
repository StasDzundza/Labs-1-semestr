#include"sqd_vector.h"
#include<iterator>
#include<exception>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::exception;

template<typename T>
T sqd_vector<T>::back()
{
	if(VECTOR.size() > 0)
		return VECTOR.back();
	throw exception("No such element");
}


template<typename T>
T sqd_vector<T>::front()
{
	if (VECTOR.size() > 0)
		return VECTOR.front();
	throw exception("No such element");
}

template<typename T>
void sqd_vector<T>::pop_front()
{
	if (VECTOR.size() > 0)
	{
		VECTOR.erase(VECTOR.begin());
	}
}


template<typename T>
bool sqd_vector<T>::erase_from_position(int position)
{
	if (position <= VECTOR.size() && position >= 1)
	{
		auto it = VECTOR.begin();
		advance(it, position - 1);
		VECTOR.erase(it);
		return true;
	}
	else return false;
}

template<typename T>
bool sqd_vector<T>::delete_data(T data)
{
	if (VECTOR.size() > 0)
	{
		int position = -1;
		for (int i = 0; i < VECTOR.size(); i++)
		{
			if (data == VECTOR[i])
			{
				position = i;
				break;
			}
		}
		if (position != -1)//found this element
		{
			auto it = VECTOR.begin();
			advance(it, position);
			VECTOR.erase(it);
			return true;
		}
		else
			return false;
	}
	else return false;
}

template<typename T>
int sqd_vector<T>::size() const
{
	return VECTOR.size();
}

template<typename T>
void sqd_vector<T>::show()
{
	for (int i = 0; i < VECTOR.size(); i++)
	{
		std::cout << VECTOR[i] << " ";
	}
	std::cout << endl;
}

template<typename T>
bool sqd_vector<T>::is_empty()
{
	return VECTOR.empty();
}

template<typename T>
void sqd_vector<T>::push_back(T a)
{
	VECTOR.push_back(a);
}

template<typename T>
void sqd_vector<T>::push_front(T a)
{
	auto it = VECTOR.begin();
	VECTOR.insert(it, a);
}

template<typename T>
void sqd_vector<T>::pop_back()
{
	if (VECTOR.size() > 0)
	{
		VECTOR.pop_back();
	}
}

template<typename T>
void sqd_vector<T>::clear()
{
	VECTOR.clear();
}

template<typename T>
T sqd_vector<T>::operator[](int index)
{
	int SIZE = VECTOR.size();
	if (SIZE > 0 && index < SIZE && index >= 0)
	{
		return VECTOR[index];
	}
	throw exception("Out of range");
}

template<typename T>
void sqd_vector<T>::sort()
{
	for (int i = 0; i < VECTOR.size(); i++)
	{
		bool swapped = false;
		for (int j = 1; j < VECTOR.size() - i; j++)
		{
			if (VECTOR[j-1] > VECTOR[j])
			{
				T tmp = VECTOR[j-1];
				VECTOR[j-1] = VECTOR[j];
				VECTOR[j] = tmp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}