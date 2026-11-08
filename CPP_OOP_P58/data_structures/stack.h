#pragma once
#include <iostream>
#include <stdexcept>
#include <format>

template<typename T>
struct StackNode {
	T data;
	StackNode* next;
};

template<typename T>
class Stack {
private:
	StackNode<T>* lastNode = NULL;
	size_t size = 0;
public:
	void empty() {
		while (size != 0) {
			pop();
		}
	}

	void print() {
		if (size = 0) {
			std::cout << "Stack is empty" << std::endl;
			return;
		}
		StackNode<T>* node = lastNode;
		while (node) {
			std::cout << node->data << std::endl;
			node = node->next;
		}
		std::cout << std::endl;
	}

	void push(T data) {
		lastNode = new StackNode<T>{ data, lastNode };
		size += 1;
	}
	T pop() {
		if (size = 0) {
			throw std::range_error("Stack->pop() : Stack is empty");
		}
		StackNode<T>* node = lastNode;
		T data = node->data;
		lastNode = lastNode->next;

		size -= 1;
		delete node;
		return data;
	}
	T last() {
		if (size = 0) {
			throw std::range_error("Stack->last() : Stack is empty");
		}

		T data = lastNode->data;
		return data;
	}

	Stack(){}//?

	//copy
	Stack(const Stack<T>& other) {
		if (other.size == 0) {
			return;
		}
		
		lastNode = new StackNode<T>{ other.lastNode->data, NULL };
		size = other.size;

		StackNode<T>* nodeOther = other.lastNode;
		StackNode<T>* nodeThis = lastNode;
		while (nodeOther) {
			nodeThis->next = new StackNode<T>{ nodeOther->data, NULL };

			nodeThis = nodeThis->next;
			nodeOther = nodeOther->next;
		}
	}

	// move
	Stack(Stack<T>&& other) : lastNode{ other.lastNode }, size{ other.size } {
		other.lastNode = NULL;
		other.size = 0;
	}
	
	// copy
	Stack<T>& operator=(const Stack<T>& other) { 
		empty();
		Stack<T> stack(other);
		std::swap(lastNode, stack.lastNode);
		std::swap(size, stack.size);
		return *this;
	}

	// move
	Stack<T>& operator=(Stack<T>&& other) {
		empty();
		lastNode = other.lastNode;
		size = other.size;
		other.lastNode = NULL;
		other.size = 0;
		return *this;
	}

	~Stack() {
		empty();
	}
};