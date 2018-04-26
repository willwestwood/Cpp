#ifndef singlylinkedlist_h
#define singlylinkedlist_h

namespace Containers
{

	template <class T> class SinglyLinkedList
	{
	private:
		struct Node
		{
			T data;
			Node * next;
		};
		Node * head;
		Node * tail;

	public:
		SinglyLinkedList();
		bool Add(T value);
		bool AddToStart(T data);
		bool Add(T data, int pos);
		bool Remove(T data);
		bool Remove(T data, int pos);
		int Size();
		T Get(int pos);
		T GetStart();
		T GetEnd();

		typedef int size_type;

		class iterator
		{
		public:
			iterator(Node * ptr) : ptr_(ptr) { }
			iterator operator++(int)
			{
				iterator i = *this;
				ptr_ = ptr_->next;
				return i;
			}
			iterator operator++()
			{
				ptr_ = ptr_->next;
				return *this;
			}
			T operator*() { return ptr_->data; }
			Node* operator->() { return ptr_; }
			bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
			bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }
		private:
			Node * ptr_;
		};

		class const_iterator
		{
		public:
			typedef const_iterator iterator;
			typedef T value_type;
			typedef T& reference;
			typedef Node* pointer;
			typedef int difference_type;
			//typedef std::forward_iterator_tag iterator_category;
			const_iterator(pointer ptr) : ptr_(ptr) { }
			iterator operator++() { iterator i = *this; ptr_++; return i; }
			iterator operator++(int junk) { ptr_++; return *this; }
			const reference operator*() { return *ptr_; }
			const pointer operator->() { return ptr_; }
			bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
			bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }
		private:
			pointer ptr_;
		};

		iterator begin() { return iterator(head); }
		iterator end() { return iterator(tail->next); }
		const_iterator begin() const { return const_iterator(head); }
		const_iterator end() const { return const_iterator(tail->next); }
	};
}

#include "SinglyLinkedList.tpp"

#endif

