#pragma once
#include<vector>
template<typename T>
class sqd_list//покищо лише стек і черга
{
public:
	sqd_list() { Size = 0; }
	void add_stack(T a);
	T back_stack();
	void show_stack();
	T front_stack();
	T pop_stack();
	bool is_empty_stack();




	void add_queue(T a);
	void show_queue();
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
template<typename T>
class sqd_arr//покищо лише стек і черга
{
public:

	sqd_arr();
	void add_st(T a);
	void add_qu(T a);
	void show_st();
	void show_qu();
	~sqd_arr()
	{
		delete[]arr;
	}

private:
	int Max;
	int Index;
	T*arr = nullptr;
	int Size;

};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
bool sqd_list<T>::is_empty_stack()
{
	return head == NULL;
}


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
T sqd_list<T>::back_stack()
{
	if (!this->is_empty_stack())
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
T sqd_list<T>::front_stack()
{
	if (head)
		return head->data;
	else
		return;
}

template<typename T>
T sqd_list<T>::pop_stack()
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
template<typename T>
void sqd_list<T>::show_stack()
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
void sqd_list<T>::show_queue()
{
	Node<T>*tmp = head;
	while (tmp)
	{
		std::cout << tmp->data << " ";
	}
	std::cout << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////

template<typename T>
sqd_arr<T>::sqd_arr()
{
	Max = 1000;
	Index = 0;
	arr = new T[Max];
	Size = 0;
}
template<typename T>
void sqd_arr<T>::add_qu(T a)
{
	if (Index < Max)
	{
		arr[Index++] = a;
		Size++;
	}
	else
		std::cout << "Переповнення." << std::endl;
}

template<typename T>
void sqd_arr<T>::add_st(T a)
{
	if (Index < Max)
	{
		for (int i = Index; i >= 1; i--)
			arr[i] = arr[i - 1];

		arr[0] = a;
		Size++;
		Index++;
	}
	else
		std::cout << "Переповнення." << std::endl;
}

template<typename T>
void sqd_arr<T>::show_st()
{
	for (int i = 0; i < Index; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void sqd_arr<T>::show_qu()
{
	for (int i = 0; i < Index; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////