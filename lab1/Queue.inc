#include"Queue.h"

template<typename T>
void Queue<T>::set_mode(int mode)
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
void Queue<T>::push_back(T a)
{
	impl->push_back(a);
}

template<typename T>
void Queue<T>::push(T a)
{
	impl->push_back(a);
}

template<typename T>
void Queue<T>::show()
{
	impl->show();
}

template<typename T>
bool Queue<T>::is_empty()
{
	return impl->is_empty();
}

template<typename T>
T Queue<T>::back()
{
	return impl->back();
}

template<typename T>
T Queue<T>::front()
{
	return impl->front();
}

template<typename T>
bool Queue<T>::erase_from_position(int position)
{
	return impl->erase_from_position(position);
}

template<typename T>
bool Queue<T>::delete_data(T a)
{
	return impl->delete_data(a);
}

template<typename T>
int Queue<T>::size() const
{
	return impl->size();
}

template<typename T>
void Queue<T>::pop_front()
{
	impl->pop_front();
}

template<typename T>
T Queue<T>::operator[](const int index)
{
	return impl->operator[](index);
}

template<typename T>
void Queue<T>::sort()
{
	impl->sort();
}

template<typename T>
void Queue<T>::clear()
{
	impl->clear();
}

template<typename T>
void Queue<T>::random_push(int N,int precision)
{
	T a;
	if (typeid(a) == typeid(int))
	{
		for (int i = 0; i < N; i++)
		{
			int rand_number = rand() % 100;
			impl->push_front(rand_number);
		}
	}
	else if (typeid(a) == typeid(double))
	{
		for (int i = 0; i < N; i++)
		{
			int num = pow(10, precision);
			int int_part = rand() % 100;
			int drob_part = rand() % num;
			double a = double(drob_part) / num;//створили рандомну дробову частину
			double res = double(int_part) + a;
			impl->push_front(res);

		}
	}
}
////////////////////////////Функції які ми унаслідували і мусили створити реалізацію(але їх не будемо використовувати)
template<typename T>
void Queue<T>::push_front(T a)
{
}

template<typename T>
void Queue<T>::pop_back()
{
}
