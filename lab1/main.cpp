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

	//��������� ����� � �������� �� ����������� ����� ��� ����
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

	//��������� ��������� �����
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


	//�������� ���� ����
	for (int i = 0; i < characters.size(); i++)
	{
		Serie current_serie;
		Character current = characters[i];//����� ������ ��������� � ����������� �� ������
		for (int j = 0; j < books.size(); j++)
		{
			if (book_in_serie(books[j], current))
			{
				current_serie.add_book(books[j]);
			}
		}
		series.push_front(current_serie);
	}


	//��������� ������� ���,���� ���� �
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

	//������� ����� ���� �� ����� ������� ����
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
	//���� �������� �� ������� �������� ����� ����� � ���������� ���� � ������� �� �����

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





	//������� ���������� ��������� ����� ����������� ������(int or double)

	/*Queue<double> st;
	st.random_push(10);
	st.show();*/






	//������� ������ �������� �� ���������� ����� �����(deque �� ������)

	/*Deque<int> deq;
	deq.set_mode(1);//������
	deq.push_back(1);
	deq.push_back(2);
	deq.push_front(3);
	deq.push_front(4);
	deq.push_front(5);
	deq.show();
	cout << "������ ������� , ���� ������ �������� : ";
	int elem = correct_input_positive_int();
	bool deleted = deq.delete_data(elem);
	if (deleted)
		cout << "Deleted" << endl;
	else
		cout << "���� ������ ��������" << endl;
	deq.show();
	cout << "���������� : ";
	deq.sort();
	deq.show();*/


	//������� ������ �� ����������� ��� ����� string(Stack �� �����)

	/*Stack<string> st;
	st.set_mode(2);
	st.push("hello");
	st.push("my");
	st.push("name");
	st.push("is");
	st.push("Stas");
	cout << "�������� � ���������� ������� : " << endl;
	for (int i = st.size()-1; i >=0; i--)
	{
		cout << st[i] << " ";
	}
	cout << endl;
	cout << "�������� � ����� : " << endl;
	st.show();
	cout << "������ ���������� ����� ����� , ��� ������ �������� : ";
	int num = correct_input_positive_int();
	bool deleted = st.erase_from_position(num);
	if (deleted)
		cout << "Deleted" << endl;
	else
		cout << "���� ������� �������" << endl;
	st.show();
	cout << "���� � ������? " << endl;
	cout << boolalpha << st.is_empty() << endl;
	cout << "�������� ����" << endl;
	st.clear();
	st.show();
	cout << "���� � ������? " << endl;
	cout << boolalpha << st.is_empty() << endl;*/

	
	
	

	// ������� ������������ �� �����
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
