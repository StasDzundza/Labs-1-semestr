#include"Character.h"
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


