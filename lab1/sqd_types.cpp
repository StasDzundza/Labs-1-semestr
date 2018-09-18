#include"sqd_types.h"
template<typename T>
void sqd_list<T>::add_st(T a)
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
void sqd_list<T>::add_qu(T a)
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
void sqd_list<T>::show_st()
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
void sqd_list<T>::show_qu()
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