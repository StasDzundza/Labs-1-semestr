#pragma once
#include"Character.h"
#include"input_information.h"

#include<string>
#include<vector>

using std::string;
using std::cin;
using std::cout;

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
	Book(const Book&other_book);
	void book_info();
	void set_name(string book_name);
	void add_author(string author);
	void set_date(int date);
	void set_lists_count(int count);
	void add_summary(string summary);
	void add_character(const Character&character);
	Book& operator=(const Book&other_book);
	bool operator==(const Book&other_book);
	bool operator>=(const Book&other_book);
	bool operator<=(const Book&other_book);
	bool operator>(const Book&other_book);
	bool operator<(const Book&other_book);
	int get_size_characters();
	Character get_I_character(int i);
	friend ostream&operator<<(ostream&os, const Book& book);
	friend std::istream&operator>>(std::istream&is, Book&book);
	~Book()
	{
		authors.clear();
		characters.clear();
	}
private:
	string book_name;
	std::vector <string> authors;
	int Date;
	int List_count;
	string summary;
	std::vector<Character> characters;
	
};

