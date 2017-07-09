#pragma once
#include <vector>
template <class T, int max> class List
{
	T *list[max];
	int num;

public:

	List();
	~List();

	bool Add(T *c);
	void Remove();
	void Draw();
	void Move();
	void DestroyContent();
	int GetNum();
	void SetNum(int);

	void Spec(void (T::*func) ())
	{
		for (int i = 0; i < num; i++)
			(list[i]->*func)();
	}
};


template <class T, int max> List<T, max>::List()
{
	num = 0;
}

template <class T, int max> List<T, max>::~List()
{

}

template <class T, int max> int List<T, max>::GetNum() { return num; }

template <class T, int max> void List<T, max>::SetNum(int n) { num = n; }

template <class T, int max> bool List<T, max>::Add(T *c)
{
	if (num < max)
		list[num++] = c;
	else return false;
	return true;
}

template <class T, int max> void List<T, max>::Draw()
{
	for (int i = 0; i < num; i++)
		list[i]->Draw();
}

template <class T, int max> void List<T, max>::Move()
{
	for (int i = 0; i < num; i++)
		list[i]->Move();
}

template <class T, int max> void List<T, max>::DestroyContent()
{
	for (int i = 0; i < num; i++)
	{
		if (list[i])
			delete list[i];
	}
}

template <class T, int max> void List<T, max>::Remove()
{
	if (num <= 0)	return;
	delete list[num - 1];
	num--;
}

