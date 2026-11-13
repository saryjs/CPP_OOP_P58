#pragma once
#include <iostream>
#include <stdexcept>
#include <format>
#include <string>

const char roundL = 40; // (
const char roundR = 41; // )
const char squareL = 91; // [
const char squareR = 93; // ]
const char curlyL = 123; // {
const char curlyR = 125; // }

const char endLine = 59; // ;

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
	bool isEmpty() {
		if (lastNode == NULL) {
			return true;
		}
		return false;
	}

	void empty() {
		while (size != 0) {
			pop();
		}
	}

	void print() {
		if (size == 0) {
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
		if (size == 0) {
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
		if (size == 0) {
			throw std::range_error("Stack->last() : Stack is empty");
		}

		T data = lastNode->data;
		return data;
	}

	void checkLine(std::string& line) {
		Stack<char> bracket;
		size_t length = strlen(line.c_str());
		for (size_t i = 0; i < length; i++) {
			if (line[i] == roundL or
				line[i] == squareL or
				line[i] == curlyL ) {
				bracket.push(line[i]);
			}
			if (line[i] == roundR or
				line[i] == squareR or
				line[i] == curlyR ) {
				if (bracket.isEmpty()) {
					std::cout << "Stack is empty";
					return;
				}
				else {
					char last = bracket.pop();
					if (last == roundL and line[i] == roundR) {}
					else if (last == squareL and line[i] == squareR) {}
					else if (last == curlyL and line[i] == curlyR) {}
					else {
						std::cout << std::format("First error happened at char {}", i);
						return;
					}
				}
			}
		}
		if (bracket.isEmpty()) {
			std::cout << "Valid";
		}
		else {
			std::cout << "Bracket not closed";
		}
		return;
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