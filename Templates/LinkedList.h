#pragma once
#include <iostream>

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	int getNoOfItems();
	void addItem(T item);
	T operator[](int index) const;

private:
	template<typename R>
	class LLNode {
		friend class LinkedList;
	public:
		LLNode(R data) : data(data), next(nullptr) { }
		int getNoOfItems();
		void addItem(R item);

	private:
		R data;
		std::shared_ptr<LLNode<T>> next;
	};

	std::shared_ptr<LLNode<T>> head;
};

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr) {};

template<typename T>
LinkedList<T>::~LinkedList() {}

template<typename T>
int LinkedList<T>::getNoOfItems() { return (head ? head->getNoOfItems() : 0); }

template<typename T>
template<typename R>
int LinkedList<T>::LLNode<R>::getNoOfItems() { return (next ? 1 + next->getNoOfItems() : 1); }

template<typename T>
void LinkedList<T>::addItem(T item) {
	if (head == nullptr) {
		std::shared_ptr<LLNode<T>> newNode = std::make_shared<LLNode<T>>(item);
		head = newNode;
	}
	else {
		head->addItem(item);
	}
}

template<typename T>
template<typename R>
void LinkedList<T>::LLNode<R>::addItem(R item) {
	if (next == nullptr) {
		next = std::make_shared<LLNode<R>>(item);
	}
	else {
		next->addItem(item);
	}
}

template<typename T>
T LinkedList<T>::operator[](int index) const
{
	std::shared_ptr<LLNode<T>> current = head;
	while(current != nullptr && index-- > 0)
	{
		current = current->next;
	}

	return (current == nullptr ? 0 : current->data);
}
