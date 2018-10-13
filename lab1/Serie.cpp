#include"serie.h"
#include"queue.h"
using std::cout;
using std::cin;
using std::endl;

Serie& Serie:: operator=(Serie& other_serie)
{
	this->serie_of_books.clear();
	for (int i = 0; i < other_serie.serie_of_books.size(); i++)
	{
		this->serie_of_books.push(other_serie.serie_of_books[i]);
	}
	return *this;
}



bool Serie::operator==(Serie other_serie)
{
	if (this->serie_of_books.size() != other_serie.serie_of_books.size())
		return false;
	if (this->serie_of_books.size() == 0 && other_serie.serie_of_books.size() == 0)
		return true;
	for (int i = 0; i < serie_of_books.size(); i++)
	{
		if (!(this->serie_of_books[i] == other_serie.serie_of_books[i]))
		{
			return false;
		}
	}
	return true;
}

ostream & operator<<(ostream & os, Serie &current_serie)
{
	for (int i = 0; i < current_serie.serie_of_books.size(); i++)
	{
		os << current_serie.serie_of_books[i];
	}
	os << endl;
	return os;
}

void Serie::add_book(Book book)
{
	serie_of_books.push(book);
}

void Serie::sort_serie()
{
	serie_of_books.sort();
}

void Serie::show_serie()
{
	serie_of_books.show();
}


bool book_in_serie(Book book, Character current)
{
	const string role1 = "main";
	const string role2 = "secondary";
	for (int i = 0; i < book.get_size_characters(); i++)
	{
		Character a = book.get_I_character(i);
		if (a == current)
		{
			string role = a.get_role();
			if (role == role1 || role == role2)
			{
				return true;
			}
		}
	}
	return false;
}

Stack<Serie>& create_series(Stack<Book> &books)
{
	const string role1 = "main";
	const string role2 = "secondary";
	Stack<Serie> *series = new Stack<Serie>;
	Queue<Character> *characters = new Queue<Character>;
	int size = books.size();

	//create queue with main and secondary characters
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < books[i].get_size_characters(); j++)
		{
			Character current = books[i].get_I_character(j);
			string role = current.get_role();
			if (role == role1 || role == role2)
			{
				characters->push_back(current);
			}
		}
	}

	//delete the same characters
	for (int i = 0; i < characters->size(); i++)
	{
		for (int j = i + 1; j < characters->size(); j++)
		{
			bool deleted = false;
			if (characters->operator[](i) == characters->operator[](j))
			{
				characters->erase_from_position(j + 1);
				deleted = true;
			}
			if (deleted)
				j--;
		}
	}


	//creating stack with series
	for (int i = 0; i < characters->size(); i++)
	{
		Serie current_serie;
		Character current = characters->operator[](i);
		for (int j = 0; j < books.size(); j++)
		{
			if (book_in_serie(books[j], current))
			{
				current_serie.add_book(books[j]);
			}
		}
		series->push_front(current_serie);
	}


	//delete the same series
	for (int i = 0; i < series->size(); i++)
	{
		for (int j = i + 1; j < series->size(); j++)
		{
			bool deleted = false;
			Serie a = series->operator[](i);
			Serie b = series->operator[](j);
			if (a == b)
			{
				series->erase_from_position(j + 1);
				deleted = true;
			}
			if (deleted)
				j--;
		}

	}

	//We are sorting series
	for (int i = 0; i < series->size(); i++)
	{
		series->operator[](i).sort_serie();
	}
	return *series;
}














////////////////////////////////////////////////////
bool Serie::operator>(const Serie & other_serie)
{
	return false;
}

bool Serie::operator<(const Serie & other_serie)
{
	return false;
}