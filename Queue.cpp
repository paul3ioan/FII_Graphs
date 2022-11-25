#include "Queue.h"
#include "Exceptions.h";

bool Queue::isEmpty(queue& q) {
	return (q.first == q.last && q.first == nullptr);
}
int Queue::top(queue& q) {
	if (q.first == nullptr) {
		throw Exceptions::LogicException("Queue no top element if list is empty");
	}
	return q.first->value;
}
void Queue::pop(queue& q) {
	Node* nodeToBePopped = q.first;
	if (q.first == nullptr) {
		throw Exceptions::LogicException("Queue is popping from 0 elements!");
	}
	q.first = q.first->next;
	delete(nodeToBePopped);
	if (q.length == 1) {
		 q.last= nullptr;
	}
	q.length--;
}
void Queue::push(queue& q, int newValue) {
	Node* newNode = new Node({ newValue, nullptr });
	if (q.last == nullptr) {
		q.last = newNode;
		q.first = newNode;
		q.length++;
		return;
	}
	q.last->next = newNode;
	q.last = newNode;
	q.length++;
}