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

	LinkedList<T>* clone() const;

	void clear() {
		ListNode<T>* node = this->first;
		while (node) {
			first = first->next;
			delete node;
			node = first;
		}
		first = last = NULL;
	}

	LinkedList() : first{ NULL }, last{ NULL }, size{ 0 } { 
		// default constructor
	}
	LinkedList(const LinkedList<T>& other){ // copy
		ListNode<T>* node = other.first;
		while (node) {
			this->add(node->data);
			node = node->next;
		}
	}
	LinkedList(LinkedList<T>&& other) noexcept : // move
		first{ other.first }, last{ other.last }, size{ other.size } 
	{
		other.first = other.last = NULL;
	}

	LinkedList<T>& operator =(const LinkedList<T>& other);   // copy
	LinkedList<T>& operator =(LinkedList<T>&& other);       // move
	LinkedList<T>  operator +(const LinkedList<T>& other) const;
	LinkedList<T>  operator *(const LinkedList<T>& other) const;

	~LinkedList() {
		while (first) {
			last = first;
			first = first->next;
			delete last;
		}
	}
};

template<typename T>
LinkedList<T>* LinkedList<T>::clone() const{
	/*
	Q1
		*list1
		  *first1 --> [p|d|n] <--> [p|d|n]...[ ] <-- last1
	clone(res)           |            |       |
	      *first1 --> [p|d|n] <--> [p|d|n]...[ ] <-- last2
	*/
	LinkedList<T>* res = new LinkedList<T>;
	ListNode<T>* node = this->first;
	while (node) {
		res->add(node->data);

		node = node->next;
	}
	return res;
}

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
			size += 1;
		}
		else {
			throw std::range_error(
				std::format("LinkedList<T>::insertBefore: Max index {} but got {}", size - 1, index)
			);
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
			if (last) {
				last->next = NULL;
			}
			delete node;
			size -= 1;
			if (size == 0){
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
			std::format("LinkedList<T>::remove: Unable to remove element. Max index {} but got {}", size - 1, index)
		);
	}
}

template<typename T>
void LinkedList<T>::print() {
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

template<typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& other) {
	clear();

	ListNode<T>* node = other.first;
	while (node) {
		this->add(node->data);
		node = node->next;
	}
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator =(LinkedList<T>&& other) {
	ListNode<T>* node = this->first;
	while (node) {
		first = first->next;
		delete node;
		node = first;
	}
	first = last = NULL;
	this->first = other.first;
	this->last = other.last;
	this->size = other.size;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator +(const LinkedList<T>& other) const {
	LinkedList<T> sum;
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
LinkedList<T> LinkedList<T>::operator *(const LinkedList<T>& other) const {
	LinkedList<T> share;
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

/*
     node
0<-[p|d|n]<->[p|d|n]->0

*/

/*
Оброблення виняткових ситуацій.
Виняток (Exception) - перехід середовища виконання програми
у спеціальній режим оброблення винятків.
Виняткова ситуація створюється оператором throw
Цей оператор зупиняє нормальне виконання програми і переводить її в режим
оброблення "ловлення" винятків.
"Зловити" виняток може оператор catch, якщо жодний оператор не "спіймав"
виняток то програма зупиняється в аварійному режимі (з помилкою необробленого
винятку)

Загальна схема роботи з винятками має вигляд:
try {
	блок з контролем за винятковими ситуаціями
	десь у цьому блоці або у функціях, що тут
	викликаються, трапляється оператор throw:
	throw std::range_error("Index out of range");
}
catch(const std::range_error& ex){
	дії з оброблення виняткової ситуації з винятком std::range_error
}
*/