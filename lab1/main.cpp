#include<iostream>
#include"Stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");
	Stack<int> s;
	s.set_mode(4);
	s.push_front(1);
	s.push_front(2);
	s.show();
	cout << s.size();
	system("pause");
	return 0;
}