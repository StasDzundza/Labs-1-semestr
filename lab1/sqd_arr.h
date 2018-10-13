#pragma once
#include"SQD.h"
template<typename T>
class sqd_arr:public SQD<T>
{
public:
	sqd_arr();
	sqd_arr(int size);
	//functions for stack in arr
	void add_stack(T a);
	T operator[](int index);

	//functions for queue in arr
	void add_queue(T a);

	//functions for deque in list
	void push_front(T a)override;
	void push_back(T a)override;
	void pop_front()override;
	void pop_back()override;
	void clear()override;


	//same functions for all 
	void show()override;
	bool is_empty()override;
	T back()override;
	T front()override;
	bool erase_from_position(int position)override;
	bool delete_data(T a)override;
	int size()const override;
	void sort()override;
	sqd_arr& operator =(const sqd_arr&other_class);
	~sqd_arr() { delete[]arr; }

private:
	int Max = 1000;
	int Index;
	T*arr = nullptr;

};

/////////////////////////////////////////////////////
#include"sqd_arr.inc"