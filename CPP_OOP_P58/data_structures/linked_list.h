#pragma once
#include <iostream>
template<typename T>
struct ListNode {
	T data;
	ListNode* prev;
	ListNode* next;
};

template<typename T>
class LinkedList {
private:
	ListNode<T>* first = NULL;
	ListNode<T>* last = NULL;
	size_t size = 0;
public:
	void add(T data);
	void insertBefore(T data, size_t index);
	T remove(size_t index);
	size_t getSize() const { return size; }

	void print();
	void printId();
};

//#include "linked_list.cpp"
template<typename T>
void LinkedList<T>::add(T data) {
	if (last) {
		//                                     /попередній = node
		last->next = new ListNode<T> { data, last, NULL };
		last = last->next;
	}
	else {
		first = last = new ListNode<T> { data, NULL, NULL };
	}
	size += 1;
}

template<typename T>
void LinkedList<T>::insertBefore(T data,size_t index) {
	if (index == 0) {
		if (first) {
			first = first->prev = new ListNode<T>{ data, NULL, first };
			size += 1;
		}
		else {
			add(data);
		}
	}
	else {
		if (index < size) {
			ListNode<T>* node = first;
			for (size_t i = 0; i < index-1; ++i) {
				node = node->next;     //                  / next
			}                         //        / prev    /
			node->next = new ListNode<T>{ data, node, node->next };
			node->next->next->prev = node->next;
		}
		else {
			std::cout << "Index out of range" << std::endl;
		}
	}
}

template<typename T>
T LinkedList<T>::remove(size_t index) {
	if (index < size) {
		if (index == 0) {
			ListNode<T>* node = first;
			T data = node->data;
			first = first->next;
			if (first) {
				first->prev = NULL;
			}
			delete node;
			size -= 1;
			if (size == 0) {
				last = NULL;
			}
			return data;
		}
		else if (index == size - 1) {
			// last
			ListNode<T>* node = last;
			T data = node->data;
			last = last->prev;
			last->next = NULL;
			delete node;
			size -= 1;
			return data;
		}
		else {
			return T(0);
		}	
	}
	else {
		return T(0);
		//if (first) {
		//	std::cout << "Index out of range" << std::endl;
		//}
		//else {
		//	std::cout << "Nothing to delete" << std::endl;
		//}
	}
}

template<typename T>
void LinkedList<T>::print() {
	ListNode<T>* node = first;
	while (node) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;
}
template<typename T>
void LinkedList<T>::printId() {
	ListNode<T>* node = first;
	size_t num = 0;
	while (node) {
		std::cout << num << "." << node->data << " ";
		node = node->next;
		num += 1;
	}
	std::cout << std::endl;
}

/*
     node
0<-[p|d|n]<->[p|d|n]->0

*/