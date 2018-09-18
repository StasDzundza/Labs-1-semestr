#pragma once
#include<vector>
template<typename T>
class sqd_list//покищо лише стек і черга
{
public:
	sqd_list() { Size = 0; }

	//functions for stack in list
	void add_stack(T a);
	
	
	
	
	//functions for queue in list
	void add_queue(T a);
	


	//functions for deque in list
	void push_front(T a);
	void push_back(T a);
	bool pop_front();
	bool pop_back();



	//same functions for all 
	void show();
	bool is_empty();
	T back();
	T front();
	T pop();//delete from begin
	bool erase_position(int position);
	bool delete_data(T a);
	int size();
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
	if (position < Size && head!=nullptr)
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
	return head == NULL;
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
bool sqd_list<T>::pop_front()
{
	if (head)
	{
		this->pop();
		return true;
	}
	return false;
}
template<typename T>
bool sqd_list<T>::pop_back()
{
	if (head)
	{
		this->erase_position(Size);
		return true;
	}
	return false;
}

