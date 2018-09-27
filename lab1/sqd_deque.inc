#include"sqd_deque.h"


template<typename T>
T sqd_deque<T>::back()
{
	if (DEQUE.size() > 0)
		return DEQUE.back();
	else exit(1);
}

template<typename T>
T sqd_deque<T>::front()
{
	if (DEQUE.size() > 0)
		return DEQUE.front();
	else exit(1);
}

template<typename T>
void sqd_deque<T>::pop_front()
{
	if (DEQUE.size() > 0)
	{
		DEQUE.pop_front();
	}
}

template<typename T>
bool sqd_deque<T>::erase_from_position(int position)
{
	if (position <= DEQUE.size() && position>=1)
	{
		auto it = DEQUE.begin();
		advance(it, position-1);
		DEQUE.erase(it);
		return true;
	}
	else return false;
}

template<typename T>
bool sqd_deque<T>::delete_data(T data)
{
	if (DEQUE.size() > 0)
	{
		int position = -1;
		for (int i = 0; i < DEQUE.size(); i++)
		{
			if (data == DEQUE[i])
			{
				position = i;
				break;
			}
		}
		if (position != -1)//знайшли такий елемент
		{
			auto it = DEQUE.begin();
			advance(it, position);
			DEQUE.erase(it);
			return true;
		}
		else
			return false;
	}
	else return false;
}

template<typename T>
int sqd_deque<T>::size() const
{
	return DEQUE.size();
}

/////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void sqd_deque<T>::show()
{
	for (int i = 0; i < DEQUE.size(); i++)
	{
		std::cout << DEQUE[i] << " ";
	}
	std::cout << endl;
}

template<typename T>
bool sqd_deque<T>::is_empty()
{
	return DEQUE.empty();
}

template<typename T>
void sqd_deque<T>::push_back(T a)
{
	DEQUE.push_back(a);
}

template<typename T>
void sqd_deque<T>::push_front(T a)
{
	DEQUE.push_front(a);
}

template<typename T>
void sqd_deque<T>::pop_back()
{
	if (DEQUE.size() > 0)
	{
		DEQUE.pop_back();
	}
}

template<typename T>
void sqd_deque<T>::clear()
{
	DEQUE.clear();
}

template<typename T>
T sqd_deque<T>::operator[](int index)
{
	int SIZE = DEQUE.size();
	if (SIZE > 0 && index < SIZE && index >= 0)
	{
		return DEQUE[index];
	}
	else exit(1);
}

template<typename T>
void sqd_deque<T>::sort()
{
	for (int i = 0; i < DEQUE.size(); i++)
	{
		bool swapped = false;
		for (int j = 1; j < DEQUE.size() - i; j++)
		{
			if (DEQUE[j - 1] > DEQUE[j])
			{
				T tmp = DEQUE[j - 1];
				DEQUE[j - 1] = DEQUE[j];
				DEQUE[j] = tmp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}