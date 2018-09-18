#pragma once
template<typename T>
class sqd_arr//покищо лише стек і черга
{
public:

	sqd_arr();
	sqd_arr(int size);


	//functions for stack in arr
	void add_st(T a);


	//functions for queue in arr
	void add_qu(T a);


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
	void operator =(const sqd_arr&other_class)
	{
		if (arr != nullptr)
			delete arr;
		arr = new T[other_class.Max];
		Max = other_class.Max;
		Index = other_class.Index;
		for (int i = 0; i < other_class.Index; i++)
		{
			arr[i] = other_class.arr[i];
		}
	}
	~sqd_arr()
	{
		delete[]arr;
	}

private:
	int Max = 1000;
	int Index;
	T*arr = nullptr;
};
/////////////////////////////////////////////////////
template<typename T>
sqd_arr<T>::sqd_arr()
{
	Max = 1000;
	Index = 0;
	arr = new T[Max];
}
template<typename T>
sqd_arr<T>::sqd_arr(int size)
{
	if (size < Max)
	{
		Max = 1000;
		Index = 0;
		arr = new T[size];
		Max = size;
	}
	else
	{
		std::cout << "Завеликий розмір. Виділено масив на 1000 елементів" << std::endl;
		Max = 1000;
		Index = 0;
		arr = new T[Max];
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void sqd_arr<T>::add_st(T a)
{
	if (Index < Max)
	{
		for (int i = Index; i >= 1; i--)
			arr[i] = arr[i - 1];

		arr[0] = a;
		Index++;
	}
	else
		std::cout << "Переповнення." << std::endl;
}

template<typename T>
bool sqd_arr<T>::is_empty()
{
	return Index == 0;
}

template<typename T>
T sqd_arr<T>::back()
{
	if (Index > 0)
		return arr[Index - 1];
	else
		return 0;
}

template<typename T>
T sqd_arr<T>::front()
{
	if (Index > 0)
		return arr[0];
	else
		return 0;
}

template<typename T>
T sqd_arr<T>::pop()
{
	int first_element = arr[0];
	if (Index > 0)
	{
		Index--;// we delete element
		for (int i = 0; i < Index; i++)
		{
			arr[i] = arr[i + 1];
		}
		return first_element;
	}
	else
		return 0;
}

template<typename T>
bool sqd_arr<T>::erase_position(int position)
{
	if (Index > 0 && position <= Index)
	{
		if (position == 1)
		{
			this->pop();
			return true;
		}
		else
		{
			Index--;// we delete element
			position--;//because 0 == 1 position for user
			for (int i = position; i < Index; i++)
			{
				arr[i] = arr[i + 1];
			}
			return true;
		}
	}
	else
		return false;
}
template<typename T>
bool sqd_arr<T>::delete_data(T a)
{
	if (Index > 0)
	{
		if (arr[0]==a)
		{
			this->pop();
			return true;
		}
		else
		{
			int position = -1;
			for (int i = 1; i < Index; i++)
			{
				if (arr[i] == a)
				{
					position = i;
				}
			}
			if (position != -1)//we found this element
			{
				Index--;
				for (int i = position; i < Index; i++)
				{
					arr[i] = arr[i + 1];
				}
				return true;
			}
		}
	}
	return false;
}

template<typename T>
int sqd_arr<T>::size()
{
	return Index;
}


template<typename T>
void sqd_arr<T>::add_qu(T a)
{
	if (Index < Max)
	{
		arr[Index++] = a;
	}
	else
		std::cout << "Переповнення." << std::endl;
}
template<typename T>
void sqd_arr<T>::push_front(T a)
{
	this->add_st(a);
}
template<typename T>
void sqd_arr<T>::push_back(T a)
{
	this->add_qu(a);
}
template<typename T>
bool sqd_arr<T>::pop_front()
{
	if (Index > 0)
	{
		this->pop();
		return true;
	}
	return false;
}
template<typename T>
bool sqd_arr<T>::pop_back()
{
	if (Index > 0)
	{
		this->erase_position(Index);
		return true;
	}
	return false;
}
template<typename T>
void sqd_arr<T>::show()
{
	for (int i = 0; i < Index; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
