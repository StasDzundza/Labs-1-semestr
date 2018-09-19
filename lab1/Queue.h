#pragma once
#include"sqd_arr.h"
#include"sqd_list.h"
#include"SQD.h"
enum MODE
{
	list,
	arr
};
template<typename T>
class Queue :public SQD<T>
{
public:

	Queue() {impl = new sqd_list<T>;}
	Queue(int size)
	{
		if (size > 0)
			this->SIZE = size;
	}
	void show() override;
	void set_mode(int mode);
	bool is_empty() override;
	T back() override;
	T front() override;
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size() override;
	void push_back(T a) override;
	T pop_front() override;//delete from begin
private:
	MODE mode = list;
	int SIZE = 0;//��� ������
	SQD<T>*impl;
	void push_front(T a) override;
	T pop_back() override;
};

template<typename T>
void Queue<T>::set_mode(int mode)
{
	if (mode == 1)
		impl = new sqd_list<T>;
	else if (mode == 2)
	{
		if (SIZE > 0)
			impl = new sqd_arr<T>(SIZE);
		else
			impl = new sqd_arr<T>;
	}
	else
	{

	}
}
template<typename T>
void Queue<T>::push_back(T a)
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
int Queue<T>::size()
{
	return impl->size();
}
template<typename T>
T Queue<T>::pop_front()
{
	return impl->pop_front();
}
////////////////////////////������� �� �� ����������� � ������ �������� ���������(��� �� �� ������ ���������������)
template<typename T>
void Queue<T>::push_front(T a)
{
}
template<typename T>
T Queue<T>::pop_back()
{
	return false;
}
