#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include"Deque.h"
using namespace std;

int main()
{
	Deque<int> s;
	s.set_state(1);
	s.push_back(1);
	s.push_front(2);
	s.push_back(0);
	s.push_front(5);
	s.show();
	cout << s.size();
	system("pause");
	return 0;
}