#pragma once
#include<string>
#include<vector>
#include"Character.h"
#include"input_information.h"
using std::string;

class Book
{
public:
	friend Character;
	Book();
	Book(string name, string author, int date, int list_count, string summary, Character character) :
		book_name(name), Date(date), List_count(list_count), summary(summary)
	{
		authors.push_back(author);
		characters.push_back(character);
	}
	void book_info();
	void set_name(string book_name);
	void add_author(string author);
	void set_date(int date);
	void set_lists_count(int count);
	void add_summary(string summary);
	void add_character(const Character&character);
	Book& operator=(const Book&other_book);
	bool operator==(const Book&other_book);
	bool operator>=(const Book&other_book);
	bool operator<=(const Book&other_book);
	bool operator>(const Book&other_book);
	bool operator<(const Book&other_book);
	int get_size_characters();
	Character get_I_character(int i);
	friend ostream&operator<<(ostream&os, const Book& book);
	friend istream&operator>>(istream&is, Book&book);
private:
	string book_name;
	std::vector <string> authors;
	int Date;
	int List_count;
	string summary;
	std::vector<Character> characters;
	
};

ostream&operator<<(ostream&os, const Book& book)
{
	os << "Назва книги : " << book.book_name << endl;
	os << "Автори : ";

	for (int i = 0; i < book.authors.size(); i++)
	{
		os << book.authors.at(i) << "  ";
	}
	os << endl;
	os << "Дата видання : " << book.Date << endl;
	os << "Кількість сторінок : " << book.List_count << endl;
	os << "Герої : " << endl;

	for (int i = 0; i < book.authors.size(); i++)
	{
		os << book.characters.at(i) << "  ";
	}
	os << "Короткий опис : " << endl;
	os << book.summary << endl;
	os << "----------------------------------------------------------------------------" << endl;
	return os;
}

istream&operator>>(istream&is, Book&book)
{
	cout << "Введіть назву книги : " << endl;
	getline(is, book.book_name);
	cout << "Вкажіть кількість авторів(максимум 5,мінімум 1) : ";
	int count_authors;
	do {
		count_authors = correct_input_positive_int();
	} while (count_authors > 5 || count_authors == 0);
	for (int i = 0; i < count_authors; i++)
	{
		cout << "Вкажіть автора книги : " << endl;
		string author;
		getline(is, author);
		book.authors.push_back(author);
	}
	cout << "Вкажіть дату написання : " << endl;
	is >> book.Date;
	cout << "Вкажіть  кількість сторінок : " << endl;
	is >> book.List_count;
	cout << "Введіть короткий опис : " << endl;
	cin.get();
	getline(is, book.summary);
	cout << "Вкажіть кількість персонажів : ";
	int count_heroes;
	do {
		count_heroes = correct_input_positive_int();
	} while (count_heroes > 10 || count_heroes == 0);
	for (int i = 0; i < count_heroes; i++)
	{
		cout << "№ " << i + 1 << endl;
		Character a;
		is >> a;
		book.characters.push_back(a);
	}
	system("cls");
	return is;
}
