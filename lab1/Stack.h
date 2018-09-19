#pragma once
#include"sqd_list.h"
#include"sqd_arr.h"
#include"SQD.h"
enum MODE
{
	list,
	arr
};
//template<typename T>
//class stack
//{
//public:
//	virtual void push(T a) = 0;
//	virtual void show() = 0;
//	virtual bool is_empty() = 0;
//	virtual T back() = 0;
//	virtual T front() = 0;
//	virtual T pop() = 0;//delete from begin
//	virtual bool erase_from_position(int position) = 0;
//	virtual bool delete_data(T a) = 0;
//	virtual int size() = 0;
//};

template<typename T>
class Stack:public SQD<T>
{
public :
	
	Stack() {}
	Stack(int size)
	{
		if(size > 0)
			this->SIZE = size;
	}
	
	void push_front(T a) override;
	void show() override;
	void set_mode(int st);
	bool is_empty() override;
	T back() override;
	T front() override;
	T pop() override;//delete from begin
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size() override;
private:
	MODE mode;
	int SIZE = 0;//для масиву
	SQD<T>*impl;
	void push_back(T a) override;
	bool pop_back() override;
	bool pop_front() override;
};

template<typename T>
void Stack<T>::set_mode(int mode)
{
	if (mode == 1)
	{
		impl = new sqd_list<T>;
	}
	else
	{
		if(SIZE > 0)
			impl = new sqd_arr<T>(SIZE);
		else
			impl = new sqd_arr<T>;
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
T Stack<T>::pop()
{
	return impl->pop();
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
int Stack<T>::size()
{
	return impl->size();
}




template<typename T>
void Stack<T>::push_back(T a)
{
}
template<typename T>
bool Stack<T>::pop_back()
{
	return false;
}
template<typename T>
bool Stack<T>::pop_front()
{
	return false;
}