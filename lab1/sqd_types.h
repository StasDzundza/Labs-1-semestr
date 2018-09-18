#pragma once
template<typename T>
class sqd_list//покищо лише стек і черга
{
public:
	sqd_list() { Size = 0; }
	void add_st(T a);
	void add_qu(T a);
	void show_st();
	void show_qu();
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
