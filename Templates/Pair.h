#pragma once
#include <memory>

template<typename T, typename R>
class Pair
{
public:
	Pair();
	~Pair() = default;

	int getNoOfItems();
	void addItem(T item1, R item2);
	T operator[](int index) const;

private:
	template<typename I, typename J>
	class PNode
	{
		friend class Pair;

	public:
		PNode(I data1, J data2) : data1(data1), data2(data2), next(nullptr) { }
		int getNoOfItems();
		void addItem(I item1, J item2);

	private:
		I data1;
		J data2;
		std::shared_ptr<PNode<I, J>> next;
	};

	std::shared_ptr<PNode<T, R>> head;
};

template<typename T, typename R>
Pair<T, R>::Pair() : head(nullptr) { };


template<typename T, typename R>
int Pair<T, R>::getNoOfItems() { return (head ? head->getNoOfItems() : 0); }

template <typename T, typename R>
template <typename I, typename J>
int Pair<T, R>::PNode<I, J>::getNoOfItems() { return (next ? 1 + next->getNoOfItems() : 1); }

template <typename T, typename R>
void Pair<T, R>::addItem(T item1, R item2)
{
	if(head == nullptr)
	{
		std::shared_ptr<PNode<T, R>> newNode = std::make_shared<PNode<T, R>>(item1, item2);
		head = newNode;
	}
	else
	{
		head->addItem(item1, item2);
	}
}

template <typename T, typename R>
template <typename I, typename J>
void Pair<T, R>::PNode<I, J>::addItem(I item1, J item2)
{
	if(next == nullptr)
	{
		next = std::make_shared<PNode<I, J>>(item1, item2);
	}
	else
	{
		next->addItem(item1, item2);
	}
}

template<typename T, typename R>
T Pair<T, R>::operator[](int index) const
{
	std::shared_ptr<PNode<T, R>> current = head;
	while(current != nullptr && index-- > 0)
	{
		current = current->next;
	}

	if(current == nullptr)
		return 0;

	return current->data1;
}