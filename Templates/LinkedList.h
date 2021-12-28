#pragma once
template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	int getNoOfItems();
	void addItem(T item);
	const T operator[](const int index);

private:
	template<typename R>
	class LLNode {
	public:
		LLNode(R data) : data(data), next(nullptr) { }
		int getNoOfItems();
		void addItem(R item);

	private:
		R data;
		LLNode<R>* next;
	};

	LLNode<T>* head;
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
		LLNode<T>* newNode = new LLNode(item);
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
		next = new LLNode<R>(item);
	}
	else {
		next.addItem(item);
	}
}

template<typename T>
const T LinkedList<T>::operator[](const int index) {
	return ();
}