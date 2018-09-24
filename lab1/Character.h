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
	Character(string Name, string role) :name(Name), role_in_book(role) {}
	void get_info();
	void set_name(string name);
	void set_role(string role);
	Character& operator=(const Character& other_character);
	bool operator==(const Character& other_character);
	bool operator<(const Character&other_character);
	bool operator>(const Character&other_character);
	friend ostream&operator<<(ostream&os, const Character& p);
	friend istream&operator>>(istream&is, Character& p);
	string get_role();
private:
	string name;
	//std::string characters_books;
	//std::vector <string> role_in_book;
	string role_in_book;

};
Character::Character() :name(""),role_in_book(""){}
ostream&operator<<(ostream&os, const Character& p)
{
	os << "≤м'€ персонажу : " << p.name << endl;
	os << "…ого роль в ц≥й книз≥ : "<< p.role_in_book << endl;
	return os;
}
istream&operator>>(istream&is, Character& p)
{
	cout << "¬вед≥ть ≥м'€ персонажа : " << endl;
	getline(is, p.name);
	cout << "¬каж≥ть його роль у ц≥й книз≥ : " << endl;
	string role;
	getline(is, role);
	p.role_in_book = role;
	return is;
}
Character& Character::operator=(const Character& other_character)
{
	this->name = other_character.name;
	this->role_in_book = other_character.role_in_book;
	return *this;
}
bool Character::operator==(const Character& other_character)
{
	//if (this->name == other_character.name)
	//{
	//	if (this->characters_books.size() == other_character.characters_books.size())
	//	{
	//		for (int i = 0; i < this->characters_books.size(); i++)
	//			if (this->characters_books[i] != other_character.characters_books[i])
	//				return false;
	//		if (this->role_in_book.size() == other_character.role_in_book.size())
	//		{
	//			for (int i = 0; i < this->role_in_book.size(); i++)
	//				if (this->role_in_book[i] != other_character.role_in_book[i])
	//					return false;
	//			return true;//€кщо все однакове
	//		}
	//		else return false;
	//	}
	//	else return false;
	//}
	//else
	//	return false;
	if (this->name == other_character.name)
	{
		return true;
	}
	else return false;
}
bool Character::operator<(const Character & other_character)
{
	return this->name < other_character.name;
}
bool Character::operator>(const Character & other_character)
{
	return this->name > other_character.name;
}
string Character::get_role()
{
	return role_in_book;
}
void Character::get_info()
{
	cout << "≤м'€ персонажу : " << name << endl;
	cout << "…ого роль в ц≥й книз≥ : " << role_in_book << endl;
}
void Character::set_name(string name)
{
	this->name = name;
}
void Character::set_role(string role)
{
	this->role_in_book = role;
}
