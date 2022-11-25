#pragma once

#include "Node.h";
namespace Stack
{
	struct stack {
		Node* head = nullptr;
	};

	bool isEmpty(stack);
	void push(stack&, int);
	void pop(stack&);
	int top(stack&);
};

