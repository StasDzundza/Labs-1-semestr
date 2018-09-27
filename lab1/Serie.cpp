#include"Serie.h"

Serie& Serie:: operator=(Serie& other_serie)
{
	this->serie.clear();
	for (int i = 0; i < other_serie.serie.size(); i++)
	{
		this->serie.push_front(other_serie.serie[i]);
	}
	return *this;
}

//ми не будемо ніколи використовувати,але мусимо перегрузити,щоб створити стек об'єктів цього класу
bool Serie::operator>(const Serie & other_serie)
{
	return false;
}

//ми не будемо ніколи використовувати,але мусимо перегрузити,щоб створити стек об'єктів цього класу
bool Serie::operator<(const Serie & other_serie)
{
	return false;
}

bool Serie::operator==(Serie other_serie)
{
	if (this->serie.size() != other_serie.serie.size())
		return false;
	if (this->serie.size() == 0 && other_serie.serie.size() == 0)
		return true;
	for (int i = 0; i < serie.size(); i++)
	{
		if (!(this->serie[i] == other_serie.serie[i]))
		{
			return false;
		}
	}
	return true;
}

ostream & operator<<(ostream & os, Serie &SERIE)
{
	for (int i = 0; i < SERIE.serie.size(); i++)
	{
		os << SERIE.serie[i];
	}
	os << endl;
	return os;
}

void Serie::add_book(Book book)
{
	serie.push_front(book);
}

void Serie::sort_serie()
{
	serie.sort();
}

void Serie::show_serie()
{
	serie.show();
}
