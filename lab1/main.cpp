#include<iostream>
//#include"Stack.h"
#include"Queue.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");
	Queue<int> s;
	s.set_mode(2);
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	s.show();
	s.pop_front();
	s.show();
	cout << s.size();
	system("pause");
	return 0;
}