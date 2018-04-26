#pragma once

namespace Containers
{

	template <typename T> SinglyLinkedList<T>::SinglyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	template <typename T> bool SinglyLinkedList<T>::Add(T value)
	{
		Node *temp = new Node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}

		return true;
	}
}