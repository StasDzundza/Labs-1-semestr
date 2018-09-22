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
	void set_name(string name);
	void add_book_and_role(string book,string role);
	Character& operator=(const Character& other_character);
	bool operator==(const Character& other_character);
private:
	string name;
	std::vector<string> characters_books;
	std::vector <string> role_in_book;
	
	friend ostream&operator<<(ostream&os, const Character& p);
	friend istream&operator>>(istream&is, Character& p);
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
istream&operator>>(istream&is, Character& p)
{
	cout << "¬вед≥ть ≥м'€ персонажа : " << endl;
	is >> p.name;
	cout << "¬вед≥ть книгу де в≥н зустр≥чаЇтьс€ : " << endl;
	string book;
	is >> book;
	p.characters_books.push_back(book);
	cout << "¬каж≥ть його роль у ц≥й книз≥ : " << endl;
	string role;
	is >> role;
	p.role_in_book.push_back(role);
	return is;
}
Character& Character::operator=(const Character& other_character)
{
	this->name = other_character.name;
	this->characters_books.clear();
	for (int i = 0; i < other_character.characters_books.size(); i++)
		this->characters_books.push_back(other_character.characters_books[i]);
	this->role_in_book.clear();
	for (int i = 0; i < other_character.role_in_book.size(); i++)
		this->role_in_book.push_back(other_character.role_in_book[i]);
	return *this;
}
bool Character::operator==(const Character& other_character)
{
	if (this->name == other_character.name)
	{
		if (this->characters_books.size() == other_character.characters_books.size())
		{
			for (int i = 0; i < this->characters_books.size(); i++)
				if (this->characters_books[i] != other_character.characters_books[i])
					return false;
			if (this->role_in_book.size() == other_character.role_in_book.size())
			{
				for (int i = 0; i < this->role_in_book.size(); i++)
					if (this->role_in_book[i] != other_character.role_in_book[i])
						return false;
				return true;//€кщо все однакове
			}
			else return false;
		}
		else return false;
	}
	else
		return false;
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
void Character::set_name(string name)
{
	this->name = name;
}
void Character::add_book_and_role(string book, string role)
{
	this->characters_books.push_back(book);
	this->role_in_book.push_back(role);
}
