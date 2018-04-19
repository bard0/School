
#include <iostream>
#include "Node.h"

using namespace std;

template <class T>

class List {
protected:
	Node<T>* headNode;
	Node<T>* currNode;
	Node<T>* prevNode;
	Node<T>* newNode;

	int length;

public:
	List();

	void Push(T data);
	void DeleteCurr();
	Node<T>* Search(T elem);

	bool IsEmpty();
	int GetLength();

	T GetCurrData(int pos);
	void DeleteList();

	void GoNext();
	void Reset();
};

template <class T>
List<T>::List()
{

	headNode = new Node<T>();
	headNode->SetNextNode(headNode);
	length = 0;
}

template <class T>
void List<T>::Push(T data)
{

	newNode = new Node<T>();
	newNode->Set(data);

	currNode = headNode->GetNextNode();
	prevNode = headNode;

	while (data < currNode->Get())
	{
		prevNode = currNode;
		currNode = currNode->GetNextNode();
	};

	newNode->SetNextNode(currNode);
	prevNode->SetNextNode(newNode);

	prevNode = prevNode->GetNextNode();

	++length;
}

template <class T>
void List<T>::DeleteCurr()
{
	if (!IsEmpty())
	{
		prevNode->SetNextNode(currNode->GetNextNode());
		delete currNode;

		currNode = prevNode->GetNextNode();

		--length;
	};
}

template <class T>
void List<T>::GoNext()
{
	prevNode = currNode;
	currNode = currNode->GetNextNode();
}

template <class T>
void List<T>::Reset()
{
	prevNode = headNode;
	currNode = headNode->GetNextNode();
}

template <class T>
Node<T>* List<T>::Search(T elem)
{
	if (!IsEmpty())
	{
		currNode = headNode->GetNextNode();
		while (currNode->Get() != elem)
		{
			prevNode = currNode;
			currNode = currNode->GetNextNode();
		};

		return currNode;
	};
}

template <class T>
bool List<T>::IsEmpty()
{
	if (length == 0) return true;
	return false;
}

template <class T>
int List<T>::GetLength()
{
	return length;
}

template <class T>
T List<T>::GetCurrData(int pos)
{
	currNode = headNode->GetNextNode();
	prevNode = currNode;

	for (int i = 0; i < pos; i++)
	{
		prevNode = currNode;
		currNode = currNode->GetNextNode();
	};

	return currNode->Get();
}

template <class T>
void List<T>::DeleteList()
{
	currNode = headNode->GetNextNode();

	while (currNode != headNode)
	{
		prevNode = currNode;
		currNode = currNode->GetNextNode();
		delete prevNode;
	};

	delete currNode;
	length = 0;
}
