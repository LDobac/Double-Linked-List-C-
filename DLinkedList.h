#pragma once

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class DLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	DLinkedList();
	~DLinkedList();

	void AddNode(T newData);
	void RemoveNode(Node<T>* pNode);

	Node<T>* GetHead() const;
	Node<T>* GetTail() const;

	Node<T>* SearchNode(T data);
};

template<typename T>
inline DLinkedList<T>::DLinkedList()
{
	head = new Node<T>();
	tail = new Node<T>();

	head->next = tail;
	head->prev = nullptr;

	tail->next = nullptr;
	tail->prev = head;
}

template<typename T>
inline DLinkedList<T>::~DLinkedList()
{
	Node<T>* node = head->next;
	
	while(node != tail)
	{
		Node<T>* nextNode = node->next;

		delete node;

		node = nextNode;
	}

	delete head;
	delete tail;
}

template<typename T>
inline void DLinkedList<T>::AddNode(T newData)
{
	Node<T>* newNode = new Node<T>();

	newNode->data = newData;

	newNode->next = tail;
	newNode->prev = tail->prev;

	tail->prev->next = newNode;
	tail->prev = newNode;
}

template<typename T>
inline void DLinkedList<T>::RemoveNode(Node<T>* pNode)
{
	for (Node<T>* node = head->next; node != tail; node = node->next)
	{
		if (node == pNode);
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;

			delete node;

			break;
		}
	}
}

template<typename T>
inline Node<T>* DLinkedList<T>::GetHead() const
{
	return head;
}

template<typename T>
inline Node<T>* DLinkedList<T>::GetTail() const
{
	return tail;
}

template<typename T>
inline Node<T>* DLinkedList<T>::SearchNode(T data)
{
	for (Node<T>* node = head->next; node != tail; node = node->next)
	{
		if (node->data == data)
		{
			return node;
		}
	}
}
