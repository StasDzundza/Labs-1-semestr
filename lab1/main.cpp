#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include"Deque.h"
#include"Book.h"
#include<Windows.h>
#include"Serie.h"
using namespace std;

//bool in_serie(const Book&book1, const Book&book2)
//{
//	return true;
//}
//
//Stack<Serie> create_series(Stack<Book>& books)
//{
//	//зробити стек персонажів і по них створювати серії
//	Stack<Serie> series;
//	int size = books.size();
//	for (int i = 0; i < size; i++)
//	{
//		Serie current_serie;
//		current_serie.add_book(books[i]);
//		for (int j = i+1; j < size; j++)
//		{
//			if (i != j)
//			{
//				if (in_serie(books[i], books[j]))
//				{
//					current_serie.add_book(books[j]);
//				}
//			}
//		}
//		current_serie.sort_serie();
//		series.push_front(current_serie);
//	}
//	return series;
//}


Stack<Serie> create_series(Stack<Book>& books)
{
	Stack<Serie> series;
	Stack<Character> characters;
	int size = books.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < books[i].get_size_characters(); j++)
		{
			
		}
	}
	return series;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Stack<Book> books;
	system("pause");
	return 0;
}