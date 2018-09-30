#include"stack.h"
#include<iostream>
#include<cmath>
template<typename T>
void Stack<T>::set_mode(int mode)
{
	if (mode == 1)
	{
		impl = new sqd_list<T>;
		this->mode = MODE::list;
	}
	else if (mode == 2)
	{
		if (SIZE > 0)
			impl = new sqd_arr<T>(SIZE);
		else
			impl = new sqd_arr<T>;
		this->mode = MODE::arr;
	}
	else if (mode == 3)
	{
		impl = new sqd_deque<T>;
		this->mode = MODE::deque;
	}
	else
	{
		impl = new sqd_vector<T>;
		this->mode = MODE::vector;
	}
}

template<typename T>
void Stack<T>::push_front(T a)
{
	impl->push_front(a);
}

template<typename T>
void Stack<T>::show()
{
	impl->show();
}

template<typename T>
bool Stack<T>::is_empty()
{
	return impl->is_empty();
}

template<typename T>
T Stack<T>::back()
{
	return impl->back();
}

template<typename T>
T Stack<T>::front()
{
	return impl->front();
}

template<typename T>
void Stack<T>::pop_front()
{
	impl->pop_front();
}

template<typename T>
bool Stack<T>::erase_from_position(int position)
{
	return impl->erase_from_position(position);
}

template<typename T>
bool Stack<T>::delete_data(T a)
{
	return impl->delete_data(a);
}

template<typename T>
int Stack<T>::size() const
{
	return impl->size();
}

template<typename T>
void Stack<T>::clear()
{
	impl->clear();
}

template<typename T>
void Stack<T>::push(T a)
{
	impl->push_front(a);
}

template<typename T>
T Stack<T>::operator[](const int index)
{
	return impl->operator[](index);
}

template<typename T>
void Stack<T>::sort()
{
	impl->sort();
}

template<typename T>
inline void Stack<T>::random_push(int N,int precision)
{
}


template<>
inline void Stack<int>::random_push(int N, int precision)
{
	for (int i = 0; i < N; i++)
	{
		int rand_number = rand() % 100;
		impl->push_front(rand_number);
	}
}

template<>
inline void Stack<double>::random_push(int N, int precision)
{
	for (int i = 0; i < N; i++)
	{
		int num = pow(10, precision);
		int int_part = rand() % 100;
		int drob_part = rand() % num;
		double a = double(drob_part) / 10;//rand drob_part
		double res = double(int_part) + a;
		impl->push_front(res);
	}
}
















///////////////////////////////////
template<typename T>
void Stack<T>::push_back(T a)
{
}

template<typename T>
void Stack<T>::pop_back()
{
}