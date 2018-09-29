#include"character.h"
#include<iostream>


using std::endl;
using std::cout;

Character::Character() :name("character"), role_in_book("episodic") {}

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

Character::Character(const Character & other_character)
{
	this->name = other_character.name;
	this->role_in_book = other_character.role_in_book;
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
