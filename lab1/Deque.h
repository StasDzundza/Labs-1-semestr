#pragma once
#include"sqd_list.h"
#include"sqd_arr.h"
#include"sqd_deque.h"
#include"sqd_vector.h"
#include"SQD.h"

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

