#pragma once
#include "Node.h";
namespace Queue{

	struct queue {
		Node* first = nullptr;
		Node* last = nullptr;
		int length = 0;
	};

	void pop(queue& q);
	void push(queue& q, int newValue);
	int top(queue& q);
	bool isEmpty(queue& q);
}

