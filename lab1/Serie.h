#pragma once
#include"stack.h"
#include"book.h"
#include<iostream>

class Serie
{
public:
	Serie() { }
	void add_book(Book book);
	void sort_serie();
	void show_serie();
	Serie& operator=(Serie& other_serie);
	bool operator>(const Serie& other_serie);
	bool operator<(const Serie& other_serie);
	bool operator==(Serie other_serie);
	friend ostream& operator<<(ostream&os, Serie& current_serie);
private:
	Stack<Book> serie_of_books;
};

