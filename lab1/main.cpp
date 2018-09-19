#include<iostream>
#include"Stack.h"
#include<deque>
using namespace std;

template<typename T>
class My
{
public:
	void remove(int pos);
	void add(T a);
	void show();
private:
	std::deque<T> a;
};
template<typename T>
void My<T>::show()
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
template<typename T>
void My<T>::add(T b)
{
	a.push_back(b);
}
template<typename T>
void My<T>::remove(int pos)
{
	std::deque<T>::iterator;
	std::deque<int>::iterator;
}
int main()
{
	setlocale(LC_ALL, "ukr");

		Stack<int> s;
		s.set_mode(4);
		s.push_front(1);
		s.push_front(2);
		s.push_front(3);
		s.push_front(4);
		s.show();
		s.delete_data(4);
		s.show();
		cout << s.size();

	system("pause");
	return 0;
}