#pragma once
#include<string>
#include"Book.h"
#include<iostream>
using std::string;
using std::ostream;
using std::endl;
using std::cout;
class Character
{
public:
	Character();
	Character(string Name, string book, string role) :name(Name)
	{
		characters_books.push_back(book);
		role_in_book.push_back(role);
	}
	void get_info();
private:
	string name;
	vector<string> characters_books;
	vector <string> role_in_book;
	friend ostream&operator<<(ostream&os, const Character& p);
};
Character::Character() :name("") {}
ostream&operator<<(ostream&os, const Character& p)
{
	os << "≤м'€ персонажу : " << p.name << endl;
	os << " ниги, де в≥н зустр≥чаЇтьс€ ≥ роль в цих книгах : " << endl;

	for (int i = 0; i < p.characters_books.size(); i++)
	{
		os << p.characters_books.at(i) << " -> " << p.role_in_book.at(i) << endl;
	}
	return os;
}
void Character::get_info()
{
	cout << "≤м'€ персонажу : " << name << endl;
	cout << " ниги, де в≥н зустр≥чаЇтьс€ ≥ роль в цих книгах : " << endl;

	for (int i = 0; i < characters_books.size(); i++)
	{
		cout << characters_books.at(i) << " -> " << role_in_book.at(i) << endl;
	}
}
