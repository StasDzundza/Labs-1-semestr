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


template<typename T>
void sqd_list<T>::add_stack(T a)
{
	if (!head)
	{
		head = new Node<T>(a);
	}
	else
	{
		Node<T>*tmp = new Node<T>(a);
		tmp->next = this->head;
		this->head = tmp;
	}
	Size++;
}

template<typename T>
T sqd_list<T>::back()
{
	if (!this->is_empty())
	{
		Node<T>*tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		return tmp->data;
	}
	else exit(1);
}


template<typename T>
T sqd_list<T>::front()
{
	if (head)
		return head->data;
	else exit(1);
}

template<typename T>
void sqd_list<T>::pop_front()
{
	if (head)
	{
		Node<T>*tmp = head;
		head = head->next;
		Size--;
		delete tmp;
	}
}


template<typename T>
bool sqd_list<T>::erase_from_position(int position)
{
	if (position <= Size && head!=nullptr)
	{
		if (position == 1)
		{
			this->pop_front();
			return true;
		}
		else
		{
			Node<T>*tmp = head;
			while (position-2)
			{
				tmp = tmp->next;
				position--;
			}
			Node<T>*next_el = tmp->next;
			tmp->next = next_el->next;
			delete next_el;
			Size--;
			return true;
		}
	}
	else
		return false;
}

template<typename T>
bool sqd_list<T>::delete_data(T data)
{
	if (head)
	{
		if (head->data == data)
		{
			this->pop_front();
			return true;
		}
		else
		{
			Node<T>*tmp = head;
			while (!(tmp->next->data==data))//щоб не перегружати !=
			{
				tmp = tmp->next;
			}
			Node<T>*next_el = tmp->next;
			tmp->next = next_el->next;
			Size--;
			delete next_el;
			return true;
		}
	}
	return false;
}

template<typename T>
int sqd_list<T>::size() const
{
	return Size;
}



/////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void sqd_list<T>::add_queue(T a)
{
	if (!head)
	{
		head = new Node<T>(a);
	}
	else
	{
		Node<T>*current = this->head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node<T>(a);
	}
	Size++;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void sqd_list<T>::show()
{
	Node<T>*tmp = head;
	while (tmp)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

template<typename T>
bool sqd_list<T>::is_empty()
{
	return head == nullptr;
}

template<typename T>
void sqd_list<T>::push_back(T a)
{
	this->add_queue(a);
}

template<typename T>
void sqd_list<T>::push_front(T a)
{
	this->add_stack(a);
}

template<typename T>
void sqd_list<T>::pop_back()
{
	if (head)
	{
		if (head->next == nullptr)
			return this->pop_front();
		else
		{
			Node<T>*tmp = head;
			while (tmp->next->next)//шукаємо передостанній
				tmp = tmp->next;
			delete tmp->next;//видаляємо останній
			Size--;
			tmp->next = nullptr;
		}
	}
}

template<typename T>
void sqd_list<T>::clear()
{
	while (Size)
	{
		this->pop_front();
	}
}

template<typename T>
T sqd_list<T>::operator[](int index)
{
	if (Size > 0 && index < Size && index >= 0)
	{
		Node<T>*tmp = head;
		while (index)
		{
			index--;
			tmp = tmp->next;
		}
		return tmp->data;
	}
	else exit(1);
}

template<typename T>
void sqd_list<T>::sort()
{
	for (int i = 0; i < Size; i++)
	{
		Node<T>*t = head;
		Node<T>*t1 = head->next;
		for (int j = 1; j < Size - i; j++)
		{
			if (t1->data < t->data)
			{
				T tmp = t->data;
				t->data = t1->data;
				t1->data = tmp;
			}
			t = t->next;
			t1 = t1->next;
		}
	}
}