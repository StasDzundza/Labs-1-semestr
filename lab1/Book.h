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

Book::Book() :book_name(""), Date(0), List_count(0), summary("") {}


Book& Book::operator=(const Book& other_book)
{
	this->book_name = other_book.book_name;
	this->authors.clear();
	for (int i = 0; i < other_book.authors.size(); i++)
		this->authors.push_back(other_book.authors[i]);
	this->Date = other_book.Date;
	this->List_count = other_book.List_count;
	this->summary = other_book.summary;
	this->characters.clear();
	for (int i = 0; i < other_book.characters.size(); i++)
		this->characters.push_back(other_book.characters[i]);
	return *this;
}

bool Book::operator==(const Book& other_book)
{
	if (this->book_name == other_book.book_name)
	{
		if (this->authors.size() == other_book.authors.size())
		{
			for (int i = 0; i < this->authors.size(); i++)
				if (this->authors[i] != other_book.authors[i])
					return false;
			if (this->Date == other_book.Date)
			{
				if (this->List_count == other_book.List_count)
				{
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool Book::operator<(const Book&other_book)
{
	return this->Date < other_book.Date;
}

int Book::get_size_characters()
{
	return this->characters.size();
}

Character Book::get_I_character(int i)
{
	return characters[i];
}

bool Book::operator>(const Book&other_book)
{
	return this->Date > other_book.Date;
}

bool Book::operator<=(const Book&other_book)
{
	return this->Date <= other_book.Date;
}

bool Book::operator>=(const Book&other_book)
{
	return this->Date >= other_book.Date;
}

void Book::book_info()
{
	cout << "Назва книги : " << book_name << endl;
	cout << "Автори : ";

	for (int i = 0; i < authors.size(); i++)
	{
		cout << authors.at(i) << "  ";
	}
	cout << endl;
	cout << "Дата видання : " << Date << endl;
	cout << "Кількість сторінок : " << List_count << endl;
	cout << "Герої : " << endl;

	for (int i = 0; i < characters.size(); i++)
	{
		cout << characters.at(i);
	}
	cout << "Короткий опис : " << endl;
	cout << summary;
	cout << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}

void Book::set_name(string book_name)
{
	this->book_name = book_name;
}

void Book::add_author(string author)
{
	this->authors.push_back(author);
}

void Book::set_date(int date)
{
	this->Date = date;
}

void Book::set_lists_count(int count)
{
	this->List_count = count;
}

void Book::add_summary(string summary)
{
	this->summary = summary;
}

void Book::add_character(const Character & character)
{
	this->characters.push_back(character);
}

