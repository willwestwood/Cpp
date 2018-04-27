#include <list>
#include <iostream>
#include "SinglyLinkedList.h"

void printList(containers::SinglyLinkedList<std::string> & sll);

int main()
{
	/*std::list<std::string> l;
	l.push_back("this");
	l.push_back("is");
	l.push_back("a");
	l.push_back("string");
	l.push_back("test");
	for (auto i = l.begin(); i != l.end();)
	{
	std::string * s = NULL;
	s = new std::string(*(i++));
	std::cout << (*s).c_str() << std::endl;
	}*/

	containers::SinglyLinkedList<std::string> sll;
	sll.Add("this");
	sll.Add("is");
	sll.Add("a");
	sll.Add("string");
	sll.Add("test");
	printList(sll);

	//sll.Add("insert", 2);

	//printList(sll);

	//sll.Remove(2);

	//printList(sll);

	sll.Remove("is");

	printList(sll);

	std::cout << sll.Size() << std::endl;

	return 0;
}

void printList(containers::SinglyLinkedList<std::string> & sll)
{
	for (auto i = sll.begin(); i != sll.end();)
	{
		std::string * s = NULL;
		s = new std::string(*(i++));
		std::cout << (*s).c_str() << std::endl;
		delete s;
	}

	std::cout << std::endl;
}