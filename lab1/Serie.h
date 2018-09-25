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
	bool operator==(Serie other_serie);
	friend ostream& operator<<(ostream&os,Serie& SERIE);
private:
	Stack<Book> serie;
};


