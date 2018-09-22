#pragma once
#include"SQD.h"
#include<vector>
using namespace std;
template<typename T>
class sqd_vector :public SQD<T>//покищо лише стек і черга
{
public:
	sqd_vector() { }
	T operator[](int index);
	//functions for deque in list
	void push_front(T a)override;
	void push_back(T a)override;
	T pop_front()override;
	T pop_back()override;

	//same functions for all 
	void show()override;
	bool is_empty()override;
	T back()override;
	T front()override;
	bool erase_from_position(int position)override;
	bool delete_data(T a)override;
	int size()override;
	void clear()override;
private:
	std::vector<T> VECTOR;
};


template<typename T>
T sqd_vector<T>::back()
{
	return VECTOR.back();
}


template<typename T>
T sqd_vector<T>::front()
{
	return VECTOR.front();
}

template<typename T>
T sqd_vector<T>::pop_front()
{
	if (VECTOR.size() > 0)
	{
		T tmp = VECTOR.front();
		VECTOR.erase(VECTOR.begin());
		return tmp;
	}
	//else return 0;
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
		if (position != -1)//знайшли такий елемент
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
int sqd_vector<T>::size()
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
T sqd_vector<T>::pop_back()
{
	T tmp = VECTOR.back();
	VECTOR.pop_back();
	return tmp;
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
	//else return 0;
}