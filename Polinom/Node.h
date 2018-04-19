#pragma once
#include <iostream>

using namespace std;

template <class T>

class Node {
protected:
	T data;
	Node<T>* next;

public:

	void SetNextNode(Node<T>* _nextNode)
	{
		next = _nextNode;
	}

	Node<T>* GetNextNode()
	{
		return next;
	}

	void Set(T _data)
	{
		data = _data;
	}

	T Get()
	{
		return data;
	}

};
