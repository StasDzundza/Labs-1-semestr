#include<iostream>
#include"Stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");
	Stack<int> s;
	s.set_state(2);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.show();
	s.push(5);
	s.show();
	cout << s.size();
	system("pause");
	return 0;
}