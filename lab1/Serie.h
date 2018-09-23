#pragma once
#include"Stack.h"
#include"Book.h"

class Serie 
{
public:
	void add_book(Book book);
	void sort_serie();
private:
	Stack<Book> serie;
};

void Serie::add_book(Book book)
{
	serie.push_front(book);
}
void Serie::sort_serie()
{

}
