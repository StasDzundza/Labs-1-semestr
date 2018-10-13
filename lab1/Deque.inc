#include"deque.h"
#include<cmath>
#include<exception>

using std::exception;
template<typename T>
void Deque<T>::set_mode(MODE mode)
{
	switch(mode)
	{
		case MODE::list:
		{
			impl = new sqd_list<T>;
			this->mode = MODE::list;
			break;
		}
		case MODE::arr:
		{
			impl = new sqd_arr<T>;
			this->mode = MODE::arr;
			break;
		}
		case MODE::deque:
		{
			impl = new sqd_deque<T>;
			this->mode = MODE::deque;
			break;
		}
		case MODE::vector:
		{
			impl = new sqd_vector<T>;
			this->mode = MODE::vector;
			break;
		}
	}
}

template<typename T>
void Deque<T>::push_back(T a)
{
	impl->push_back(a);
}

template<typename T>
void Deque<T>::pop_back()
{
	impl->pop_back();
}

template<typename T>
void Deque<T>::push_front(T a)
{
	impl->push_front(a);
}

template<typename T>
void Deque<T>::push(T a)
{
	impl->push_back(a);
}

template<typename T>
void Deque<T>::show()
{
	impl->show();
}

template<typename T>
bool Deque<T>::is_empty()
{
	return impl->is_empty();
}

template<typename T>
T Deque<T>::back()
{
	return impl->back();
}

template<typename T>
T Deque<T>::front()
{
	return impl->front();
}

template<typename T>
void Deque<T>::pop_front()
{
	impl->pop_front();
}

template<typename T>
bool Deque<T>::erase_from_position(int position)
{
	return erase_from_position(position);
}

template<typename T>
bool Deque<T>::delete_data(T a)
{
	return impl->delete_data(a);
}

template<typename T>
int Deque<T>::size() const
{
	return impl->size();
}

template<typename T>
void Deque<T>::clear()
{
	impl->clear();
}

template<typename T>
T Deque<T>::operator[](const int index)
{
	return impl->operator[](index);
}

template<typename T>
void Deque<T>::sort()
{
	impl->sort();
}

template<typename T>
inline void Deque<T>::random_push(int N,int precision)
{
}

template<>
inline void Deque<int>::random_push(int N, int precision)
{
	for (int i = 0; i < N; i++)
	{
		int rand_number = rand() % 100;
		impl->push_front(rand_number);
	}
}

template<>
inline void Deque<double>::random_push(int N, int precision)
{
	int num = pow(10, precision);
		for (int i = 0; i < N; i++)
		{
			int int_part = rand() % 100;
			int drob_part = rand() % num;
			double a = double(drob_part) / num;//rand drob_part
			double res = double(int_part) + a;
			impl->push_front(res);
		}
}