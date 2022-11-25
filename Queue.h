#pragma once

namespace Queue{

	struct node {
		int value;
		node* next;
	};

	struct queue {
		node* first = nullptr;
		node* last = nullptr;
		int length = 0;
	};

	void pop(queue& q);
	void push(queue& q, int newValue);
	int top(queue& q);
	bool isEmpty(queue& q);
}

