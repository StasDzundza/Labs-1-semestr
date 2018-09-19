#pragma once
template<typename T>
class SQD
{
public:
	virtual void push_back(T a) = 0;
	virtual void push_front(T a) = 0;
	virtual bool pop_back() = 0;
	virtual bool pop_front() = 0;
	virtual void push(T a) = 0;
	virtual void show() = 0;
	virtual bool is_empty() = 0;
	virtual T back() = 0;
	virtual T front() = 0;
	virtual T pop() = 0;//delete from begin
	virtual bool erase_from_position(int position) = 0;
	virtual bool delete_data(T a) = 0;
	virtual int size() = 0;
};
