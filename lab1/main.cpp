#include<iostream>
#include"Stack.h"
#include"Queue.h"
#include"Deque.h"
#include"Book.h"
#include<Windows.h>
#include"Serie.h"
#include<string>
#include<cstdlib>
#include<ctime>


using std::cout;
using std::cin;
using std::endl;
using std::string;



bool book_in_serie(Book book,Character current)
{
	const string role1 = "main";
	const string role2 = "secondary";
	for (int i = 0; i < book.get_size_characters(); i++)
	{
		Character a = book.get_I_character(i);
		if (a == current)
		{
			string role = a.get_role();
			if (role == role1 || role == role2)
			{
				return true;
			}
		}		
	}
	return false;
}

Stack<Serie>& create_series(Stack<Book> &books)
{
	const string role1 = "main";
	const string role2 = "secondary";
	Stack<Serie> series;
	Queue<Character> characters;
	int size = books.size();

	//створюємо чергу з головних та другорядних героїв усіх книг
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < books[i].get_size_characters(); j++)
		{
			Character current = books[i].get_I_character(j);
			string role = current.get_role();
			if (role == role1 || role == role2)
			{
				characters.push_back(current);
			}
		}
	}

	//Видаляємо однакових героїв
	for (int i = 0; i < characters.size(); i++)
	{
		for (int j = i+1; j < characters.size(); j++)
		{
			bool deleted = false;
			if (characters[i] == characters[j])
			{
				characters.erase_from_position(j + 1);
				deleted = true;
			}
			if (deleted)
				j--;
		}
	}


	//створили стек серій
	for (int i = 0; i < characters.size(); i++)
	{
		Serie current_serie;
		Character current = characters[i];//взяли одного персонажа і проходимося по книгах
		for (int j = 0; j < books.size(); j++)
		{
			bool deleted = false;
			if (book_in_serie(books[j], current))
			{
				current_serie.add_book(books[j]);
				deleted = true;
			}
			if (deleted)
				j--;
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
	srand(time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//Stack<Book> books;
	//Book b1; Book b2; Book b3; Book b4; Book b5;
	//cin >> b1;
	//cin >> b2;
	//cin >> b3;
	//cin >> b4; 
	//cin >> b5;
	//books.push_front(b1);
	//books.push_front(b2);
	//books.push_front(b3);
	//books.push_front(b4);
	//books.push_front(b5);
	//Stack<Serie> series = create_series(books);
	//for (int i = 0; i < series.size(); i++)
	//{
	//	cout << "SERIE # " << i + 1 << endl;
	//	series[i].show_serie();
	//	cout << endl << endl << endl << endl;
	//}


	Queue<double> st;
	st.random_push(10);
	st.show();
	system("pause");
	return 0;
}