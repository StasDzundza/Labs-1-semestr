#include<iostream>
#include"Stack.h"
#include<deque>
#include"Book.h"
#include"Character.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ukr");

		Stack<int> s;
		s.set_mode(1);
		s.push_front(1);
		s.push_front(2);
		s.push_front(3);
		s.push_front(4);
		cout << s[2];

	system("pause");
	return 0;
}