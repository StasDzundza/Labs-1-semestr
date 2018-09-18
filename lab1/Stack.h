#pragma once
#include"sqd_types.h"
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
};

template<typename T>
class Stack:public stack<T>
{
public :
	
	Stack() {}
	void push_back(T a) override;
	void show() override;
	void set_state(int st);
private:
	MODE mode;
	sqd_list<T> lst;
	sqd_arr<T> arrr;
};

template<typename T>
void Stack<T>::set_state(int st)
{
	if (st == 1)
		mode = MODE::list;
	else
		mode = MODE::arr;
}
template<typename T>
void Stack<T>::push_back(T a)
{
	if (mode == MODE::list)
		lst.add_st(a);
	else
	{
		arrr.add_st(a);
	}
}

template<typename T>
void Stack<T>::show()
{
	if (mode == MODE::list)
		lst.show_st();
	else
		arrr.show_st();
}
