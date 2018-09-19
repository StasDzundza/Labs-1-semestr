#include<iostream>
//#include"Stack.h"
#include"Stack.h"
#include<string>
#include<deque>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");
	Stack<int> s;
	s.set_mode(3);
	s.push_front(1);
	s.push_front(2);
	s.show();
	cout << s.size();
	system("pause");
	return 0;
}