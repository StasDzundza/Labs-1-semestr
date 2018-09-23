#pragma once
#include"Stack.h"
#include"Book.h"

class Serie 
{
public:
	void add_book(Book book);
	void sort_serie();
	void show_serie();
	Serie& operator=(Serie& other_serie);
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
