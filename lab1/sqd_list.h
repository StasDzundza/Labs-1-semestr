#pragma once
#include"SQD.h"
template<typename T>
class sqd_list:public SQD<T>
{
public:
	sqd_list() { Size = 0; head = nullptr; }
	T operator[](int index);
	//functions for stack in list
	void add_stack(T a);
	
	//functions for queue in list
	void add_queue(T a);
	
	//functions for deque in list
	void push_front(T a)override;
	void push_back(T a)override;
	void pop_front()override;
	void pop_back()override;

	//same functions for all 
	void show()override;
	bool is_empty()override;
	T back()override;
	T front()override;
	bool erase_from_position(int position)override;
	bool delete_data(T a)override;
	int size()const override;
	void clear()override;
	void sort()override;
private:
	template<typename T>
	class Node
	{
	public:
		Node*next;
		T data;
		Node(T data = T(), Node*next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int Size;
	Node<T> *head;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


