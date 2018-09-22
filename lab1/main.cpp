#include<iostream>
#include"Stack.h"
#include"Book.h"
#include"Character.h"
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

		Stack<Book> s;
		s.set_mode(4);
		//Character c("hero", "first book", "main role");
		//Book b("name", "author", 1896, 200, "summary", c);
		//Character c1("hero2", "second book", "not main role");
		//Book b1("name2", "author2", 2000, 289, "summary2", c1);
		//s.push_front(b);
		//s.push_front(b1);
		//s.show();
		s.front();
	system("pause");
	return 0;
}