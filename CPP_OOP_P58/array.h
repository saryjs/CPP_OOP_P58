#pragma once
#include <iostream>
#include <stdexcept>
#include <format>


template<typename T>
struct ListNode {
	T data;
	ListNode* prev;
	ListNode* next;
};

template<typename T>
class Array {
private:
	ListNode<T>* first = NULL;
	ListNode<T>* last = NULL;
	size_t size = 0;
public:
	void insertBefore(T data, size_t index);
	T remove(size_t index);

	//

	size_t getSize() const { return size; }
	size_t setSize(int size, int grow = 1);
	size_t getUpperBound();
	bool isEmpty() { return getSize() == 0; }
	void freeExtra();
	void removeAll();
	void getAt(size_t index);
	void setAt(size_t index);
	void add(T data);
	void append(const Array& other);
	void getData();
	void removeAt(size_t index);

	//

	void print();
	void printId();

	Array<T>& operator =(const Array<T>& other);
	Array<T>  operator +(const Array<T>& other) const;
	Array<T>  operator *(const Array<T>& other) const;
};

//#include "linked_list.cpp"
template<typename T>
void Array<T>::add(T data) {
	if (last) {
		//                                     /попередній = node
		last->next = new ListNode<T>{ data, last, NULL };
		last = last->next;
	}
	else {
		first = last = new ListNode<T>{ data, NULL, NULL };
	}
	size += 1;
}

template<typename T>
void Array<T>::insertBefore(T data, size_t index) {
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
			for (size_t i = 0; i < index - 1; ++i) {
				node = node->next;     //                  / next
			}                         //        / prev    /
			node->next = new ListNode<T>{ data, node, node->next };
			node->next->next->prev = node->next;
		}
		else {
			throw std::range_error(
				std::format("Array<T>::insertBefore: Max index {} but got {}", size - 1, index)
			);
		}
	}
}

template<typename T>
T Array<T>::remove(size_t index) {
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
			if (last) {
				last->next = NULL;
			}
			delete node;
			size -= 1;
			if (size == 0) {
				first = NULL;
			}
			return data;
		}
		else {
			ListNode<T>* node = first;
			for (size_t i = 0;i < index; ++i) {
				node = node->next;
			}
			node->prev->next = node->next;
			node->next->prev = node->prev;
			T data = node->data;
			delete node;
			size -= 1;
			return data;
		}
	}
	else {
		throw std::range_error(
			std::format("Array<T>::remove: Unable to remove element. Max index {} but got {}", size - 1, index)
		);
	}
}

template<typename T>
void Array<T>::print() {
	ListNode<T>* node = first;
	if (node == NULL) {
		std::cout << "Empty list, size = " << size << std::endl;
	}
	else {
		std::cout << size << " element(s): ";
		while (node) {
			std::cout << node->data << " ";
			node = node->next;
		}
	}
	std::cout << std::endl;
}
template<typename T>
void Array<T>::printId() {
	ListNode<T>* node = first;
	size_t num = 0;
	while (node) {
		std::cout << num << "." << node->data << " ";
		node = node->next;
		num += 1;
	}
	std::cout << std::endl;
}

template<typename T>
Array<T>& Array<T>::operator =(const Array<T>& other) {
	while (this->first != NULL) {
		this->remove(0);
	}
	ListNode<T>* node = other.first;
	while (node != NULL) {
		this->add(node->data);
		node = node->next;
	}
	return *this;
}

template<typename T>
Array<T> Array<T>::operator +(const Array<T>& other) const {
	Array<T> sum;
	ListNode<T>* node = this->first;
	while (node != NULL) {
		sum.add(node->data);
		node = node->next;
	}
	node = other.first;
	while (node != NULL) {
		sum.add(node->data);
		node = node->next;
	}
	return sum;
}

template<typename T>
Array<T> Array<T>::operator *(const Array<T>& other) const {
	Array<T> share;
	ListNode<T>* node_this = this->first;

	while (node_this) {

		ListNode<T>* node_other = other.first;
		while (node_other) {
			if (node_this->data == node_other->data) {
				share.add(node_this->data);
			}
			node_other = node_other->next;
		}
		node_this = node_this->next;
	}
	return share;
}