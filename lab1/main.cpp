#include<iostream>
#include"Stack.h"
#include<deque>
using namespace std;

int main()
{
	Stack<int> s;
	s.set_state(1);
	s.push_back(1);
	s.push_back(2);
	s.push_back(0);
	s.show();
	system("pause");
	return 0;
}