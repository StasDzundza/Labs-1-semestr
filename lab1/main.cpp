#include<iostream>
#include"Stack.h"
//#include"Queue.h"
//#include"Deque.h"
#include"Book.h"
#include"Character.h"
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

		Stack<int> s;
		s.set_mode(1);
		s.push_front(1);
		s.push_front(2);
		s.push_front(3);
		s.push_front(4);
		s.show();
		s.sort();
		s.show();
	system("pause");
	return 0;
}