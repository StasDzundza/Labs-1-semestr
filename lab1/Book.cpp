#include"Book.h"

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

