#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include"Deque.h"
#include"Book.h"
#include<Windows.h>
#include"Serie.h"
#include<string>
using namespace std;

bool book_in_serie(Book book,Character current)
{
	for (int i = 0; i < book.get_size_characters(); i++)
	{
		Character a = book.get_I_character(i);
		if (a == current)
		{
			string role = a.get_role();
			string role1 = "main";
			string role2 = "secondary";
			if (role == role1 || role == role2)
			{
				return true;
			}
		}		
	}
	return false;
}



Stack<Serie> create_series(Stack<Book> &books)
{
	Stack<Serie> series;
	Queue<Character> characters;
	int size = books.size();

	//створюємо чергу з головних та другорядних героїв усіх книг
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < books[i].get_size_characters(); j++)
		{
			Character current = books[i].get_I_character(i);
			string role = current.get_role();
			string role1 = "main";
			string role2 = "secondary";
			if (role == role1 || role == role2)
			{
				characters.push_back(current);
			}
		}
	}

	//Видаляємо однакових героїв
	for (int i = 0; i < characters.size(); i++)
	{
		for (int j =  i+1; j < characters.size(); j++)
		{
			if (characters[i] == characters[j])
			{
				characters.erase_from_position(j + 1);
			}
		}
	}


	//створили стек серій
	for (int i = 0; i < characters.size(); i++)
	{
		Serie current_serie;
		Character current = characters[i];//взяли одного персонажа і проходимося по книгах
		for (int j = 0; j < books.size(); j++)
		{
			if (book_in_serie(books[j], current))
			{
				current_serie.add_book(books[j]);
			}
		}
		series.push_front(current_serie);
	}


	//видаляємо однакові серії,якщо вони є
	for (int i = 0; i < series.size(); i++)
	{
		for (int j = i + 1; j < series.size(); j++)
		{
			if (series[i]==series[j])
			{
				series.erase_from_position(j + 1);
			}
		}
	}

	//сортуємо кожну серію за датою видання книг
	for (int i = 0; i < series.size(); i++)
	{
		series[i].sort_serie();
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