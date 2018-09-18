#include"Stack.h"
#include"sqd_types.h"
template<typename T>
void Stack<T>::set_state(int st)
{
	if (st == 1)
		mode = MODE::list;
	else
		mode = MODE::arr;
}
template<typename T>
void Stack<T>::push_back(T a)
{
	if (mode == MODE::list)
		lst.add_st(a);
	else
	{
		arrr.add_st(a);
	}
}

template<typename T>
void Stack<T>::show()
{
	if (mode == MODE::list)
		lst.show_st();
	else
		arrr.show_st();
}
