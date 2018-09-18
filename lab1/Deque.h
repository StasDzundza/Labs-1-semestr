#pragma once
#include"sqd_arr.h"
#include"sqd_list.h"
#include"Stack.h"
#include"Queue.h"
template<typename T>
class deque :public queue<T>,public stack<T>
{
public:
	virtual void push_back(T a) = 0;
	virtual void push_front(T a) = 0;
	virtual bool pop_back() = 0;
	virtual bool pop_front() = 0;
};

template<typename T>
class Deque :public deque<T>
{
public:

	Deque() {}
	Deque(int size)
	{
		arrr = sqd_arr<T>(size);
	}
	void push_back(T a) override;
	void push_front(T a) override;
	bool pop_back() override;
	bool pop_front() override;
	void show() override;
	void set_state(int st);
	bool is_empty() override;
	T back() override;
	T front() override;
	T pop() override;//delete from begin
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size() override;
private:
	MODE mode;
	sqd_list<T> lst;
	sqd_arr<T> arrr;
};

template<typename T>
void Deque<T>::set_state(int state)
{
	if (state == 1)
		mode = MODE::list;
	else
		mode = MODE::arr;
}
template<typename T>
void Deque<T>::push_back(T a)
{
	if (mode == MODE::list)
		lst.push_back(T a);
	else
		arrr.push_back(T a);
}
template<typename T>
bool Deque<T>::pop_back()
{
	if (mode == MODE::list)
		return lst.pop_back();
	else
		return arrr.pop_back();
}
template<typename T>
bool Deque<T>::pop_front()
{
	if (mode == MODE::list)
		return lst.pop_front();
	else
		return arrr.pop_front();
}
template<typename T>
void Deque<T>::push_front(T a)
{
	if (mode == MODE::list)
		lst.push_front(T a);
	else
		arrr.push_front(T a);
}

template<typename T>
void Deque<T>::show()
{
	if (mode == MODE::list)
		lst.show();
	else
		arrr.show();
}
template<typename T>
bool Deque<T>::is_empty()
{
	if (mode == MODE::list)
		return lst.is_empty();
	else
		return arrr.is_empty();
}
template<typename T>
T Deque<T>::back()
{
	if (mode == MODE::list)
		return lst.back();
	else
		return arrr.back();
}
template<typename T>
T Deque<T>::front()
{
	if (mode == MODE::list)
		return lst.front();
	else
		return arrr.front();
}
template<typename T>
T Deque<T>::pop()
{
	if (mode == MODE::list)
		return lst.pop();
	else
		return arrr.pop();
}

template<typename T>
bool Deque<T>::erase_from_position(int position)
{
	if (mode == MODE::list)
		return lst.erase_position(position);
	else
		return arrr.erase_position(position);
}

template<typename T>
bool Deque<T>::delete_data(T a)
{
	if (mode == MODE::list)
		return lst.delete_data(a);
	else
		return arrr.delete_data(a);
}

template<typename T>
int Deque<T>::size()
{
	if (mode == MODE::list)
		return lst.size();
	else
		return arrr.size();
}

