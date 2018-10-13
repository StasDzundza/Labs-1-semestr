#pragma once
#include<string>
#include<iostream>

using std::string;
using std::ostream;
using std::istream;


	class Character
	{
	public:
		Character();
		Character(string Name, string role) :name(Name), role_in_book(role) {}
		Character(const Character&other_character);
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

	