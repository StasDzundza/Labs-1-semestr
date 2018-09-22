#pragma once
#include<string>
#include<vector>
#include"Character.h"
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
	Book& operator=(const Book&other_book);
private:
	string book_name;
	std::vector <string> authors;
	int Date;
	int List_count;
	string summary;
	std::vector<Character> characters;
	friend ostream&operator<<(ostream&os, const Book& book);
};
Book::Book() :book_name(""), Date(0), List_count(0), summary("") {}
ostream&operator<<(ostream&os, const Book& book)
{
	os << "Назва книги : " << book.book_name << endl;
	os << "Автори : " << endl;

	for (int i = 0; i < book.authors.size(); i++)
	{
		os << book.authors.at(i) << " , ";
	}
	os << endl;
	os << "Дата видання : " << book.Date << endl;
	os << "Кількість сторінок : " << book.List_count << endl;
	os << "Герої : " << endl;

	for (int i = 0; i < book.authors.size(); i++)
	{
		os << book.characters.at(i);
	}
	os << "Короткий опис : " << endl;
	os << book.summary;
	return os;
}

Book& Book::operator=(const Book& other_book)
{
	this->book_name = other_book.book_name;
	this->authors.clear();
	for (int i = 0; i < other_book.authors.size(); i++)
		this->authors[i] = other_book.authors[i];
	this->Date = other_book.Date;
	this->List_count = other_book.List_count;
	this->summary = other_book.summary;
	this->characters.clear();
	for (int i = 0; i < other_book.characters.size(); i++)
		this->characters[i] = other_book.characters[i];
	return *this;
}
void Book::book_info()
{
	cout << "Назва книги : " << book_name << endl;
	cout << "Автори : " << endl;

	for (int i = 0; i < authors.size(); i++)
	{
		cout << authors.at(i) << " , ";
	}
	cout << endl;
	cout << "Дата видання : " << Date << endl;
	cout << "Кількість сторінок : " << List_count << endl;
	cout << "Герої : " << endl;

	for (int i = 0; i < authors.size(); i++)
	{
		cout << characters.at(i);
	}
	cout << "Короткий опис : " << endl;
	cout << summary;
}