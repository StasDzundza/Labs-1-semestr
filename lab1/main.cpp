#include<iostream>
#include"Stack.h"
using namespace std;

int main()
{
	Stack<int> s;
	s.set_state(1);
	s.push_back(1);
	s.push_back(2);
	s.push_back(0);
	s.push_back(5);
	s.show();
	s.delete_data(1);
	s.show();
	system("pause");
	return 0;
}