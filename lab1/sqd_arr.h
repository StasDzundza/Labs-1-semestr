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




	//same functions for all 
	void show();
	bool is_empty();
	T back();
	T front();
	T pop();//delete from begin
	bool erase_position(int position);
	bool delete_data(T a);
	int size();





	~sqd_arr()
	{
		delete[]arr;
	}

private:
	int Max;
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
		return;
}

template<typename T>
T sqd_arr<T>::front()
{
	if (Index > 0)
		return arr[0];
	else
		return;
}

template<typename T>
T sqd_arr<T>::pop()
{
	if (Index > 0)
	{
		Index--;// we delete element
		for (int i = 0; i < Index; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
	else
		return;
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
void sqd_arr<T>::show()
{
	for (int i = 0; i < Index; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
