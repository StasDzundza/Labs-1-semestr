#include<iostream>
//#include"Stack.h"
#include"Deque.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");
	Deque<int> s;
	s.set_mode(2);
	s.push_back(1);
	s.push_front(2);
	s.push_back(3);
	s.push_front(4);
	s.show();
	s.pop_front();
	s.show();
	s.pop_back();
	s.show();
	cout << s.size();
	system("pause");
	return 0;
}