#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include"Deque.h"
#include"Book.h"
#include"Character.h"
#include<Windows.h>
#include"SQD.h"
#include"Serie.h"
using namespace std;

bool in_serie(const Book&book1, const Book&book2)
{

}

Stack<Serie> create_series(Stack<Book>& books)
{
	Stack<Serie> series;
	int size = books.size();
	for (int i = 0; i < size; i++)
	{
		Serie current_serie;
		current_serie.add_book(books[i]);
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				if (in_serie(books[i], books[j]))
				{
					current_serie.add_book(books[j]);
				}
			}
		}
		current_serie.sort_serie();
		series.push_front(current_serie);
	}
	return series;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Stack<series>
	system("pause");
	return 0;
}