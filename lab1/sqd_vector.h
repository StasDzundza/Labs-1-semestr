#pragma once
#include"SQD.h"
#include<vector>
using namespace std;
template<typename T>
class sqd_vector :public SQD<T>//покищо лише стек і черга
{
public:
	sqd_vector() { }
	//functions for stack in list
	void add_stack(T a);

	//functions for queue in list
	void add_queue(T a);

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
private:
	vector<T> VECTOR;
};


template<typename T>
void sqd_vector<T>::add_stack(T a)/////////////////
{
	//VECTOR.insert(0);
}


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
T sqd_vector<T>::pop_front()/////////////////
{
	T tmp = VECTOR.front();
	//VECTOR.erase(0);
	return tmp;
}


template<typename T>
bool sqd_vector<T>::erase_from_position(int position)//////////////////////???????????
{
	//deque<T> ::iterator;
	return true;
}
template<typename T>
bool sqd_vector<T>::delete_data(T data)/////////////////?????????????
{
	return true;
}
template<typename T>
int sqd_vector<T>::size()
{
	return VECTOR.size();
}


/////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void sqd_vector<T>::add_queue(T a)
{
	VECTOR.push_back(a);
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
void sqd_vector<T>::push_front(T a)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!&????????????
{
	//VECTOR.push_front(a);
}
template<typename T>
T sqd_vector<T>::pop_back()
{
	T tmp = VECTOR.back();
	VECTOR.pop_back();
	return tmp;
}

