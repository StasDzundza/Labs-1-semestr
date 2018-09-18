#include<iostream>
#include"Stack.h"
using namespace std;

int main()
{
	Stack<int> s(5);
	s.set_state(2);
	s.push_back(1);
	s.push_back(2);
	s.push_back(0);
	s.push_back(5);
	s.show();
	cout << s.size();
	system("pause");
	return 0;
}