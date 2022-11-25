#include "Stack.h"
#include "Exceptions.h"

bool Stack::isEmpty(stack s) {
	return s.head == nullptr;
}
void Stack::push(stack& s, int newValue) {
	Node* newNode = new Node({ newValue, s.head });
	if (isEmpty(s)) {
		newNode->next = nullptr;
	}
	s.head = newNode;
}
void Stack::pop(stack& s) {
	if (isEmpty(s)) {
		throw Exceptions::LogicException("Can't pop from empty stack");
	}
	s.head = s.head->next;
}
int Stack::top(stack& s) {
	if (isEmpty(s)) {
		throw Exceptions::LogicException("Can't access top from empty stack");
	}
	return s.head->value;
}