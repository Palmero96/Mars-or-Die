#pragma once
#define MAX 200

template <class T> class List
{
	T *list[MAX];
	int num;

public:

	List();
	~List();

	bool Add(T *c);
	void Draw();
	void Move();
	void DestroyContent();
	int GetNum();
	void SetNum(int);
};


template <class T> List<T>::List()
{
	num = 0;
}
template <class T> List<T>::~List()
{

}

template <class T> int List<T>::GetNum() { return num; }

template <class T> void List<T>::SetNum(int n) { num = n; }

template <class T> bool List<T>::Add(T *c)
{
	if (num < MAX)
		list[num++] = c;
	else return false;
	return true;
}

template <class T> void List<T>::Draw()
{
	for (int i = 0; i < num; i++)
		list[i]->Draw();
}

template <class T> void List<T>::Move()
{
	for (int i = 0; i < num; i++)
		list[i]->Move();
}

template <class T> void List<T>::DestroyContent()
{
	for (int i = 0; i < num; i++)
		delete list[i];
}

