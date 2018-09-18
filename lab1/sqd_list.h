#pragma once
#include<vector>
template<typename T>
class sqd_list//покищо лише стек і черга
{
public:
	//functions for stack in list
	sqd_list() { Size = 0; }
	void add_stack(T a);
	
	
	
	


	//functions for queue in list
	void add_queue(T a);
	


	//same functions for all 
	void show();
	bool is_empty();
	T back();
	T front();
	T pop();
	bool erase_position(int position);
	bool delete_data(T a);
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
		return;
}


template<typename T>
T sqd_list<T>::front()
{
	if (head)
		return head->data;
	else
		return;
}

template<typename T>
T sqd_list<T>::pop()
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
	else return;
}


template<typename T>
bool sqd_list<T>::erase_position(int position)
{
	if (position < Size)
	{
		if (position == 1)
		{
			this->pop();
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
			this->pop();
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
			delete next_el;
			return true;
		}
	}
	else
		return false;
}





















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


/////////////////////////////////////////////////////////////////////////////////////


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
	return head == NULL;
}