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
#include<conio.h>
#include"input_information.h"
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

Stack<Serie> create_series(Stack<Book> &books)
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
			bool deleted = false;
			if (series[i]==series[j])
			{
				series.erase_from_position(j + 1);
				deleted = true;
			}
			if (deleted)
				j--;
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
	//тест програми на прикладі власного класу книга зі створенням серій і виводом на екран

	/*Stack<Book> books;
	Book b1; Book b2; Book b3; Book b4; Book b5;
	cin >> b1;
	cin >> b2;
	cin >> b3;
	//cin >> b4; 
	//cin >> b5;
	books.push_front(b1);
	books.push_front(b2);
	books.push_front(b3);
	//books.push_front(b4);
	//books.push_front(b5);

	Stack<Serie> series = create_series(books);
	for (int i = 0; i < series.size(); i++)
	{
		cout << "SERIE # " << i + 1 << endl;
		series[i].show_serie();
		cout << endl << endl << endl << endl;
	}*/





	//приклад заповнення структури даних випадковими даними(int or double)

	/*Queue<double> st;
	st.random_push(10);
	st.show();*/






	//приклад роботи програми на примітивних типах даних(deque на списку)

	/*Deque<int> deq;
	deq.set_mode(1);//список
	deq.push_back(1);
	deq.push_back(2);
	deq.push_front(3);
	deq.push_front(4);
	deq.push_front(5);
	deq.show();
	cout << "Введіть елемент , який хочете видалити : ";
	int elem = correct_input_positive_int();
	bool deleted = deq.delete_data(elem);
	if (deleted)
		cout << "Deleted" << endl;
	else
		cout << "Немає такого елемента" << endl;
	deq.show();
	cout << "Сортування : ";
	deq.sort();
	deq.show();*/


	//приклад роботи на бібліотечному типі даних string(Stack на масиві)

	/*Stack<string> st;
	st.set_mode(2);
	st.push("hello");
	st.push("my");
	st.push("name");
	st.push("is");
	st.push("Stas");
	cout << "Елементи в оберненому порядку : " << endl;
	for (int i = st.size()-1; i >=0; i--)
	{
		cout << st[i] << " ";
	}
	cout << endl;
	cout << "Елементи в стеці : " << endl;
	st.show();
	cout << "Введіть порядковий номер слова , яке хочете видалити : ";
	int num = correct_input_positive_int();
	bool deleted = st.erase_from_position(num);
	if (deleted)
		cout << "Deleted" << endl;
	else
		cout << "Така позиція відсутня" << endl;
	st.show();
	cout << "Стек є пустим? " << endl;
	cout << boolalpha << st.is_empty() << endl;
	cout << "Очистимо стек" << endl;
	st.clear();
	st.show();
	cout << "Стек є пустим? " << endl;
	cout << boolalpha << st.is_empty() << endl;*/

	
	
	

	// Приклад переповнення на масиві
	/*Stack<int> st(5);
	st.set_mode(2);
	st.push(1);
	st.push(1);
	st.push(1);
	st.push(1);
	st.push(1);
	st.show();
	st.push(1);*/


	system("pause");
	return 0;
}
