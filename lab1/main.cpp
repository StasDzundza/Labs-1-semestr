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


int main()
{

	srand(time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//Example with My Class Book

	Stack<Book> books;
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
	deq.set_mode(MODE::arr);//list
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
	st.set_mode(MODE::arr);
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
	cout << std::boolalpha << st.is_empty() << endl;
	cout << "Очистимо стек" << endl;
	st.clear();
	st.show();
	cout << "Стек є пустим? " << endl;
	cout << std::boolalpha << st.is_empty() << endl;*/

	
	
	

	// Array overflow
	/*Stack<int> st(5);
	st.set_mode(MODE::list);
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
