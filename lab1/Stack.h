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
