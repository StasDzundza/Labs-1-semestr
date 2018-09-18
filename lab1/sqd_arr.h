#pragma once
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
