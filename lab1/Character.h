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
	os << "��'� ��������� : " << p.name << endl;
	os << "���� ���� � ��� ���� : " << p.role_in_book << endl;
	return os;
}

istream&operator>>(istream&is, Character& p)
{
	cout << "������ ��'� ��������� : " << endl;
	getline(is, p.name);
	cout << "������ ���� ���� � ��� ���� (Only main,secondary or episodic): " << endl;
	getline(is, p.role_in_book);
	string role_check = p.get_role();
	if (role_check == "main" || role_check == "secondary" || role_check == "episodic") {}//��� ��� �����
	else
	{
		p.set_role("episodic");
	}
	return is;
}
Character::Character() :name("character"), role_in_book("episodic") {}


Character& Character::operator=(const Character& other_character)
{
	this->name = other_character.name;
	this->role_in_book = other_character.role_in_book;
	return *this;
}

bool Character::operator==(const Character& other_character)
{
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
	cout << "��'� ��������� : " << name << endl;
	cout << "���� ���� � ��� ���� : " << role_in_book << endl;
}

void Character::set_name(string name)
{
	this->name = name;
}

void Character::set_role(string role)
{
	this->role_in_book = role;
}

