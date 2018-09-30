#include"input_information.h"
#include"stack.h"
#include"queue.h"
#include"deque.h"
#include"book.h"
#include"serie.h"

#include<iostream>
#include<Windows.h>
#include<string>
#include<cstdlib>
#include<ctime>
#include<conio.h>

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
	Stack<Serie> *series = new Stack<Serie>;
	Queue<Character> *characters = new Queue<Character>;
	int size = books.size();

	//create queue with main and secondary characters
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < books[i].get_size_characters(); j++)
		{
			Character current = books[i].get_I_character(j);
			string role = current.get_role();
			if (role == role1 || role == role2)
			{
				characters->push_back(current);
			}
		}
	}

	//delete the same characters
	for (int i = 0; i < characters->size(); i++)
	{
		for (int j = i+1; j < characters->size(); j++)
		{
			bool deleted = false;
			if (characters->operator[](i) == characters->operator[](j))
			{
				characters->erase_from_position(j + 1);
				deleted = true;
			}
			if (deleted)
				j--;
		}
	}


	//creating stack with series
	for (int i = 0; i < characters->size(); i++)
	{
		Serie current_serie;
		Character current = characters->operator[](i);
		for (int j = 0; j < books.size(); j++)
		{
			if (book_in_serie(books[j], current))
			{
				current_serie.add_book(books[j]);
			}
		}
		series->push_front(current_serie);
	}


	//delete the same series
	for (int i = 0; i < series->size(); i++)
	{
		for (int j = i + 1; j < series->size(); j++)
		{
			bool deleted = false;
			Serie a = series->operator[](i);
			Serie b = series->operator[](j);
			if (a == b)
			{
				series->erase_from_position(j + 1);
				deleted = true;
			}
			if (deleted)
				j--;
		}

	}

	//We are sorting series
	for (int i = 0; i < series->size(); i++)
	{
		series->operator[](i).sort_serie();
	}
	return *series;
}


int main()
{
	srand(time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//Example with My Class Book

	/*Stack<Book> books;
	Character a("a", "main");
	Character a1("a", "secondary");
	Character b("b", "main");
	Character c("c", "secondary");
	Character d("d", "episodic");
	Book b1("first","author1",1225,1000,"good book",a); 
	b1.add_author("Stas Dzundza");
	Book b2("second", "author2", 1900, 586, "super book", b);
	Book b3("third", "author3", 2018, 200, "normal book", a);
	b3.add_character(b);
	Book b4("four", "author4", 1945, 2000, "info book", a1);
	b4.add_character(c);
	Book b5("five", "author5", 2019, 5001, "enciclopedy", b);
	b5.add_character(c);
	b5.add_character(d);

	books.push(b1);
	books.push(b2);
	books.push(b3);
	books.push(b4);
	books.push(b5);

	Stack<Serie> series = create_series(books);
	for (int i = 0; i < series.size(); i++)
	{
		cout << "SERIE # " << i + 1 << endl;
		series[i].show_serie();
		cout << endl << endl << endl << endl;
	}
*/




	//Constructor copy
	/*Book *b6 = new Book("first", "author1", 1225, 1000, "good book", a);
	Book b7(*b6);
	delete b6;
	cout << b7;*/

	

	//You also can input data by yourself

	//Stack<Book> books;
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















	//Random Example
	/*int precision;
	cout << "Введіть к-сть цифр після коми(max 5,min 1) : " << endl;
	do {
		precision = correct_input_positive_int();
	} while (precision > 5 || precision == 0);
	Queue<double> st;
	st.random_push(10,precision);
	st.show();*/






	//Deque by list
	/*Deque<int> deq;
	deq.set_mode(1);//list
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


	//Example with string class

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

	
	
	

	// Array overflow
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
