#include"Stack.h"
#include"Book.h"
#include"Character.h"
#include"Serie.h"
template class Stack<int>;
template class Stack<double>;
template class Stack<string>;
template class Stack<Book>;
template class Stack<Character>;
template class Stack<Serie>;

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
void Stack<T>::random_push(int N)
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
			int int_part = rand() % 100;
			int drob_part = rand() % 10;
			double a = double(drob_part) / 10;//створили рандомну дробову частину
			double res = double(int_part) + a;
			impl->push_front(res);

		}
	}
}
///////////////////////////////////Функції які ми унаслідували і мусили створити реалізацію(але їх не будемо використовувати)
template<typename T>
void Stack<T>::push_back(T a)
{
}

template<typename T>
void Stack<T>::pop_back()
{
}