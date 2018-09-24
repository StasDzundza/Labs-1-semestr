#pragma once
#include"Stack.h"
#include"Book.h"
#include<iostream>
class Serie 
{
public:
	void add_book(Book book);
	void sort_serie();
	void show_serie();
	Serie& operator=(Serie& other_serie);
	bool operator>(const Serie& other_serie);
	bool operator<(const Serie& other_serie);
	bool operator==(Serie& other_serie);
	friend ostream& operator<<(ostream&os,const Serie& SERIE);
private:
	Stack<Book> serie;
};

Serie& Serie:: operator=(Serie& other_serie)
{
	this->serie.clear();
	for (int i = 0; i < other_serie.serie.size(); i++)
	{
		this->serie.push_front(other_serie.serie[i]);
	}
	return *this;
}

//ми не будемо ніколи використовувати,але мусимо перегрузити,щоб створити стек об'єктів
bool Serie::operator>(const Serie & other_serie)
{
	return false;
}

//ми не будемо ніколи використовувати,але мусимо перегрузити,щоб створити стек об'єкті
bool Serie::operator<(const Serie & other_serie)
{
	return false;
}

bool Serie::operator==(Serie & other_serie)
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

ostream & operator<<(ostream & os, const Serie & SERIE)
{
	/*for (int i = 0; i < SERIE.serie.size(); i++)
	{
		cout << SERIE.serie[i];
	}*/
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
