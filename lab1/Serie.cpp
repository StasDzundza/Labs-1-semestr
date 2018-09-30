#include"serie.h"

using std::cout;
using std::cin;
using std::endl;

Serie& Serie:: operator=(Serie& other_serie)
{
	this->serie_of_books.clear();
	for (int i = 0; i < other_serie.serie_of_books.size(); i++)
	{
		this->serie_of_books.push(other_serie.serie_of_books[i]);
	}
	return *this;
}



bool Serie::operator==(Serie other_serie)
{
	if (this->serie_of_books.size() != other_serie.serie_of_books.size())
		return false;
	if (this->serie_of_books.size() == 0 && other_serie.serie_of_books.size() == 0)
		return true;
	for (int i = 0; i < serie_of_books.size(); i++)
	{
		if (!(this->serie_of_books[i] == other_serie.serie_of_books[i]))
		{
			return false;
		}
	}
	return true;
}

ostream & operator<<(ostream & os, Serie &current_serie)
{
	for (int i = 0; i < current_serie.serie_of_books.size(); i++)
	{
		os << current_serie.serie_of_books[i];
	}
	os << endl;
	return os;
}

void Serie::add_book(Book book)
{
	serie_of_books.push(book);
}

void Serie::sort_serie()
{
	serie_of_books.sort();
}

void Serie::show_serie()
{
	serie_of_books.show();
}













////////////////////////////////////////////////////
bool Serie::operator>(const Serie & other_serie)
{
	return false;
}

bool Serie::operator<(const Serie & other_serie)
{
	return false;
}