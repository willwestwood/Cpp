#pragma once

namespace containers
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

	template <typename T> bool SinglyLinkedList<T>::AddToStart(T value)
	{
		Node *temp = new Node;
		temp->data = value;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp->next = NULL;
			temp = NULL;
		}
		else
		{
			temp->next = head;
			head = temp;
			temp = NULL;
		}

		return true;
	}

	template <typename T> bool SinglyLinkedList<T>::Add(T value, int pos)
	{
		Node *temp = new Node;
		temp->data = value;
		if (head == NULL)
		{
			if (pos == 0)
			{
				head = temp;
				tail = temp;
				temp->next = NULL;
				temp = NULL;
			}
			else
				return false;
		}
		else if (pos == 0)
		{
			temp->next = head;
			head = temp;
			temp = NULL;

			return true;
		}
		else
		{
			Node *currNode = head;

			for (int i(0); i < pos - 1; i++)
			{
				currNode = currNode->next;

				if (currNode == NULL)
					return false;
			}

			temp->next = currNode->next;
			currNode->next = temp;
			temp = NULL;
		}

		return true;
	}

	template <typename T> bool SinglyLinkedList<T>::Remove(T value)
	{
		if (head == NULL)
		{
			return false;
		}
		else if (value == head->data)
		{
			Node * temp = head;
			head = head->next;
			delete temp;

			return true;
		}

		Node* currNode = head;
		while (currNode->next != NULL)
		{
			if (currNode->next->data == value)
			{
				if (currNode->next == tail)
				{
					Node * temp = tail;
					currNode->next = NULL;
					tail = currNode;
					delete temp;

					return true;
				}
				else
				{
					Node * temp = currNode->next;
					currNode->next = currNode->next->next;
					delete temp;

					return true;
				}
			}
			else
			{
				currNode = currNode->next;
			}
		}

		return false;
	}

	template <typename T> bool SinglyLinkedList<T>::Remove(int pos)
	{
		if (head == NULL)
		{
			return false;
		}
		else if (pos == 0)
		{
			Node * temp = head;
			head = head->next;
			delete temp;

			return true;
		}
		else
		{
			Node * currNode = head;

			for (int i(0); i < pos - 1; ++i)
			{
				currNode = currNode->next;

				if (currNode == NULL)
					return false;
			}

			Node * temp = currNode->next;
			currNode->next = currNode->next->next;
			delete temp;

			return true;
		}

		return false;
	}

	template <typename T> int SinglyLinkedList<T>::Size()
	{
		int size = 0;

		Node * currNode = head;
		while (currNode != NULL)
		{
			size++;
			currNode = currNode->next;
		}

		return size;
	}

	template <typename T> T SinglyLinkedList<T>::Get(int pos)
	{
		if (head == NULL)
		{
			throw new std::exception("empty list");
		}

		Node * currNode = head;
		for (int i(0); i < pos; i++)
		{
			currNode = currNode->next;

			if (currNode == NULL)
			{
				throw new std::exception("not found");
			}
		}

		return currNode->data;
	}
}