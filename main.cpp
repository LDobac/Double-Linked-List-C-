#include <iostream>
#include "DLinkedList.h"

int main()
{
	DLinkedList<int> list;
	list.AddNode(500);
	list.AddNode(1000);
	list.AddNode(200);

	for (auto node = list.GetHead()->next; node != list.GetTail(); node = node->next)
	{
		std::cout << node->data << std::endl;
	}
	return 0;
}