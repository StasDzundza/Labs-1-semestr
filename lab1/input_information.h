#pragma once
#include<fstream>
#include<iostream>
bool correct_name(char*str);
bool correct_open_file(FILE*ptr, const char*name);
double correct_input_positive_double();
double correct_input_double();
int correct_input_int();
int correct_input_positive_int();
//template<typename T>
void fill_array(int arr[], int limit);