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
	bool operator==(const Book&other_book);
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
	os << "Автори : ";

	for (int i = 0; i < book.authors.size(); i++)
	{
		os << book.authors.at(i) << "  ";
	}
	os << endl;
	os << "Дата видання : " << book.Date << endl;
	os << "Кількість сторінок : " << book.List_count << endl;
	os << "Герої : "<<endl;

	for (int i = 0; i < book.authors.size(); i++)
	{
		os << book.characters.at(i) << "  ";
	}
	os << "Короткий опис : " << endl;
	os << book.summary << endl;
	os << "----------------------------------------------------------------------------" << endl;
	return os;
}

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
					if (this->summary == other_book.summary)
					{
						if (this->characters.size() == other_book.characters.size())
						{
							for (int i = 0; i < this->characters.size(); i++)
								if (!(this->characters[i] == other_book.characters[i]))//щоб не перегружати !=
									return false;
							return true;//якщо рівні
						}
						else return false;
					}
					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
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

	for (int i = 0; i < authors.size(); i++)
	{
		cout << characters.at(i);
	}
	cout << "Короткий опис : " << endl;
	cout << summary;
	cout << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}