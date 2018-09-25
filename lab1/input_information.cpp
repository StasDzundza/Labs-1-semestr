#include<string>
#include<iostream>
#include<fstream>
using namespace std;
bool correct_name(char*str)
{
	int q = strlen(str);
	if (q > 20)
	{
		cout << "У назві не може бути більше 20 символів!" << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < q; i++)
		{
			if (!isalpha(str[i]) && str[i] != ' ')
			{
				cout << "У назві не може бути нічого,окрім літер та пробілів!" << endl;
				return false;
			}
		}
	}
	return true;
}
bool correct_open_file(FILE*ptr, const char*name)
{
	bool op = false;
	if (ptr == NULL)
	{
		cout << "Не вдалося відкрити файл з назвою " << name << " виправте ситуацію з файлом та повторіть знову.";
		return false;
	}
	return true;
}
double correct_input_positive_double()
{
	bool op = false;
	char str[200];
	while (!op)
	{

		op = true;
		gets_s(str);
		int count = 0;
		int i = 0;
		do {
			count++;
			i++;
		} while (isdigit(str[i]));

		int q = strlen(str);
		if (count > 9)
		{
			op = false;
			goto next;
		}
		if (q == 0)
		{
			op = false;
			goto next;
		}
		for (int i = 0; i < q; i++)
		{
			if (!isdigit(str[i]) && str[i] != '.')
			{
				op = false;
				break;
			}
		}

	next:
		if (!op)
			cout << "Некоректний ввід, введіть ще раз" << endl;
	}
	double a;
	a = atof(str);
	return a;
}
int correct_input_positive_int()
{
	bool op = false;
	char str[200] = "";
	while (!op)
	{
		op = true;
		gets_s(str);
		int q = strlen(str);
		if (q == 0)
		{
			op = false;
			goto next;
		}
		if (q == 1 && str[0] == '0')
		{
			int a = atoi(str);
			return a;
		}

		for (int i = 0; i < q; i++)
		{
			if (!isdigit(str[i]) || q>9)
			{
				op = false;
				break;
			}
		}
	next:
		if (!op)
			cout << "Некоректний ввід, введіть ще раз" << endl;
	}
	int a = atoi(str);
	return a;
}
int correct_input_int()
{
	bool op = false;
	char str[200] = "";
	while (!op)
	{
		op = true;
		gets_s(str);
		int q = strlen(str);
		if (q == 0)
		{
			op = false;
			goto next;
		}
		if (q == 1 && str[0] == '0')
		{
			int a = atoi(str);
			return a;
		}

		for (int i = 0; i < q; i++)
		{
			if ((!isdigit(str[i])&&str[0]!='-') || q>9)
			{
				op = false;
				break;
			}
		}
	next:
		if (!op)
			cout << "Некоректний ввід, введіть ще раз" << endl;
	}
	int a = atoi(str);
	return a;
}
double correct_input_double()
{
	bool op = false;
	char str[200];
	while (!op)
	{

		op = true;
		gets_s(str);
		int count = 0;
		int i = 0;
		do {
			count++;
			i++;
		} while (isdigit(str[i]));

		int q = strlen(str);
		if (count > 9)
		{
			op = false;
			goto next;
		}
		if (q == 0)
		{
			op = false;
			goto next;
		}
		for (int i = 0; i < q; i++)
		{
			if (!isdigit(str[i]) && str[i] != '.' && str[0] != '-')
			{
				op = false;
				break;
			}
		}

	next:
		if (!op)
			cout << "Некоректний ввід, введіть ще раз" << endl;
	}
	double a = atof(str);
	return a;
}
//template<typename T>
void fill_array(int arr[], int limit)
{
	bool op = true;
	int temp; 
	int i; 
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) <<  " : ";
		do {
			cin >> temp;
			op = true;
			if (!cin)
			{
				op = false;
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Некоректний ввід. Введіть ще раз." << endl;
			}
		} while (!op);
		arr[i] = temp;
	}

}