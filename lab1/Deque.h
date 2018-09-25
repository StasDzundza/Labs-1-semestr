#pragma once
#include"sqd_list.h"
#include"sqd_arr.h"
#include"sqd_deque.h"
#include"sqd_vector.h"
#include"SQD.h"

//enum MODE
//{
//	list,
//	arr,
//	deque,
//	vector
//};

template<typename T>
class Deque :public SQD<T>
{
public:

	Deque() { impl = new sqd_list<T>; }
	Deque(int size)
	{
		if (size > 0)
			this->SIZE = size;
		impl = new sqd_list<T>;
	}
	T operator[](const int index);
	void push_back(T a) override;
	void push_front(T a) override;
	void push(T a);
	void pop_back() override;
	void pop_front() override;
	void show() override;
	void set_mode(int mode);
	bool is_empty() override;
	T back() override;
	T front() override;
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size() const override;
	void clear()override;
	void sort()override;
	void random_push(int N);
private:
	MODE mode = list;
	int SIZE = 0;//для масиву
	SQD<T>*impl;
};

template<typename T>
void Deque<T>::set_mode(int mode)
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
	else if(mode == 3)
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
void Deque<T>::random_push(int N)
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