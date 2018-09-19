#pragma once
#include"SQD.h"
#include<deque>
#include<vector>
#include<iterator>
using namespace std;
template<typename T>
class sqd_deque :public SQD<T>//покищо лише стек і черга
{
public:
	sqd_deque() { }
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
	void clear() override;
private:
	deque<T> DEQUE;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////



template<typename T>
T sqd_deque<T>::back()
{
	return DEQUE.back();
}


template<typename T>
T sqd_deque<T>::front()
{
	return DEQUE.front();
}

template<typename T>
T sqd_deque<T>::pop_front()
{
	T tmp = DEQUE.front();
	DEQUE.pop_front();
	return tmp;
}


template<typename T>
bool sqd_deque<T>::erase_from_position(int position)
{
	if (position <= DEQUE.size() && position>=1)
	{
		auto it = DEQUE.begin();
		advance(it, position-1);
		DEQUE.erase(it);
		return true;
	}
	else return false;
}
template<typename T>
bool sqd_deque<T>::delete_data(T data)
{
	if (DEQUE.size() > 0)
	{
		int position = -1;
		for (int i = 0; i < DEQUE.size(); i++)
		{
			if (data == DEQUE[i])
			{
				position = i;
				break;
			}
		}
		if (position != -1)//знайшли такий елемент
		{
			auto it = DEQUE.begin();
			advance(it, position);
			DEQUE.erase(it);
			return true;
		}
		else
			return false;
	}
	else return false;
}
template<typename T>
int sqd_deque<T>::size()
{
	return DEQUE.size();
}

/////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void sqd_deque<T>::show()
{
	for (int i = 0; i < DEQUE.size(); i++)
	{
		std::cout << DEQUE[i] << " ";
	}
	std::cout << endl;
}

template<typename T>
bool sqd_deque<T>::is_empty()
{
	return DEQUE.empty();
}

template<typename T>
void sqd_deque<T>::push_back(T a)
{
	DEQUE.push_back(a);
}
template<typename T>
void sqd_deque<T>::push_front(T a)
{
	DEQUE.push_front(a);
}
template<typename T>
T sqd_deque<T>::pop_back()
{
	T tmp = DEQUE.back();
	DEQUE.pop_back();
	return tmp;
}

template<typename T>
void sqd_deque<T>::clear()
{
	DEQUE.clear();
}
