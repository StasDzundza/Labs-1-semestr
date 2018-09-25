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
	string role_in_book;

};

ostream&operator<<(ostream&os, const Character& p)
{
	os << "≤м'€ персонажу : " << p.name << endl;
	os << "…ого роль в ц≥й книз≥ : " << p.role_in_book << endl;
	return os;
}

istream&operator>>(istream&is, Character& p)
{
	cout << "¬вед≥ть ≥м'€ персонажа : " << endl;
	getline(is, p.name);
	cout << "¬каж≥ть його роль у ц≥й книз≥ (Only main,secondary or episodic): " << endl;
	getline(is, p.role_in_book);
	string role_check = p.get_role();
	if (role_check == "main" || role_check == "secondary" || role_check == "episodic") {}//тод≥ все добре
	else
	{
		p.set_role("episodic");
	}
	return is;
}