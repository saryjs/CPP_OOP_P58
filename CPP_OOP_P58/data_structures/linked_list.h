#pragma once
template<typename T>
class LinkedList {
private:
	ListNode<T>* first;
public:
	void add(T data);
	void insetBefore(T data, size_t index);

	void print() {
		ListNode<T> node = first;
		while (node) {
			std::cout << node->data << " ";
		}
		std::cout << std::endl;
	}
};
template<typename T>
class ListNode {
	T data;
	ListNode* prev;
	ListNode* next;
};
