#pragma once
#include"sqd_list.h"
#include"sqd_arr.h"
enum MODE
{
	list,
	arr
};
template<typename T>
class stack
{
public:
	virtual void push_back(T a) = 0;
	virtual void show() = 0;
	virtual bool is_empty() = 0;
	virtual T back() = 0;
	virtual T front() = 0;
	virtual T pop() = 0;//delete from begin
	virtual bool erase_from_position(int position) = 0;
	virtual bool delete_data(T a) = 0;
	//virtual int size() = 0;
};

template<typename T>
class Stack:public stack<T>
{
public :
	
	Stack() {}
	void push_back(T a) override;
	void show() override;
	void set_state(int st);
	bool is_empty();
	T back();
	T front();
	T pop();//delete from begin
	bool erase_from_position(int position);
	bool delete_data(T a);
	//int size();
private:
	MODE mode;
	sqd_list<T> lst;
	sqd_arr<T> arrr;
};

template<typename T>
void Stack<T>::set_state(int state)
{
	if (state == 1)
		mode = MODE::list;
	else
		mode = MODE::arr;
}
template<typename T>
void Stack<T>::push_back(T a)
{
	if (mode == MODE::list)
		lst.add_stack(a);
	else
		arrr.add_st(a);
}

template<typename T>
void Stack<T>::show()
{
	if (mode == MODE::list)
		lst.show();
	else
		arrr.show();
}
template<typename T>
bool Stack<T>::is_empty()
{
	if (mode == MODE::list)
		return lst.is_empty();
	else
		return arrr.is_empty();
}
template<typename T>
T Stack<T>::back()
{
	if (mode == MODE::list)
		return lst.back();
	else
		return arrr.back();
}
template<typename T>
T Stack<T>::front()
{
	if (mode == MODE::list)
		return lst.front();
	else
		return arrr.front();
}
template<typename T>
T Stack<T>::pop()
{
	if (mode == MODE::list)
		return lst.pop();
	else
		return arrr.pop();
}

template<typename T>
bool Stack<T>::erase_from_position(int position)
{
	if (mode == MODE::list)
		return lst.erase_position(position);
	else
		return arrr.erase_position(position);
}

template<typename T>
bool Stack<T>::delete_data(T a)
{
	if (mode == MODE::list)
		return lst.delete_data(a);
	else
		return arrr.delete_data(a);
}
