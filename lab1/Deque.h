#pragma once
#include"sqd_list.h"
#include"sqd_arr.h"
#include"sqd_deque.h"
#include"sqd_vector.h"
#include"SQD.h"

enum MODE
{
	list,
	arr,
	deque,
	vector
};

template<typename T>
class Deque :public SQD<T>
{
public:

	Deque() { impl = new sqd_list<T>; }
	Deque(int size)
	{
		if (size > 0)
			this->SIZE = size;
	}
	void push_back(T a) override;
	void push_front(T a) override;
	T pop_back() override;
	T pop_front() override;
	void show() override;
	void set_mode(int mode);
	bool is_empty() override;
	T back() override;
	T front() override;
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size() override;
	void clear()override;
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
T Deque<T>::pop_back()
{
	return impl->pop_back();
}
template<typename T>
void Deque<T>::push_front(T a)
{
	impl->push_front(a);
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
T Deque<T>::pop_front()
{
	return impl->pop_front();
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
int Deque<T>::size()
{
	return impl->size();
}
template<typename T>
void Deque<T>::clear()
{
	impl->clear();
}
