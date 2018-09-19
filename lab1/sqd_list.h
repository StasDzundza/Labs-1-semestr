#pragma once
#include"SQD.h"
template<typename T>
class sqd_list:public SQD<T>//покищо лише стек і черга
{
public:
	sqd_list() { Size = 0; head = nullptr; }
	//functions for stack in list
	void add_stack(T a);
	
	
	
	
	//functions for queue in list
	void add_queue(T a);
	


	//functions for deque in list
	void push_front(T a)override;
	void push_back(T a)override;
	T pop_front()override;
	T pop_back()override;



	//same functions for all 
	void show()override;
	bool is_empty()override;
	T back()override;
	T front()override;
	bool erase_from_position(int position)override;
	bool delete_data(T a)override;
	int size()override;
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
	else
		return 0;
}


template<typename T>
T sqd_list<T>::front()
{
	if (head)
		return head->data;
	else
		return 0;
}

template<typename T>
T sqd_list<T>::pop_front()
{
	if (head)
	{
		Node<T>*tmp = head;
		T a = tmp->data;
		head = head->next;
		Size--;
		delete tmp;
		return a;
	}
	else return 0;
}


template<typename T>
bool sqd_list<T>::erase_from_position(int position)
{
	if (position < Size && head!=nullptr)
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
			while (tmp->next->data!=data)
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
int sqd_list<T>::size()
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
T sqd_list<T>::pop_back()
{
	if (head)
	{
		if (head->next == nullptr)
			return this->pop_front();
		else
		{
			T element;
			Node<T>*tmp = head;
			while (tmp->next->next)//шукаємо передостанній
				tmp = tmp->next;
			element = tmp->next->data;
			delete tmp->next;//видаляємо останній
			Size--;
			tmp->next = nullptr;
			return element;
		}
	}
	return 0;
}

