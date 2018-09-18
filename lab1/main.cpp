#include<iostream>
#include"Stack.h"
#include<vector>
using namespace std;

int main()
{
	Stack<int> s;
	s.set_state(1);
	s.push_back(1);
	s.push_back(2);
	s.push_back(0);
	s.show();
	vector<int> vec;
	system("pause");
	return 0;
}