#pragma once
#include<string>
#include<vector>
#include"Character.h"
using std::string;
using std::vector;

class Book
{


public:

	Book();
	Book(string name, string author, int date, int list_count, string summary, Character character) :
		book_name(name), Date(date), List_count(list_count), summary(summary)
	{
		authors.push_back(author);
		characters.push_back(character);
	}
private:
	string book_name;
	vector <string> authors;
	const int Date;
	const int List_count;
	string summary;
	vector<Character> characters;
};
Book::Book() :book_name(""), Date(0), List_count(0), summary("") {}