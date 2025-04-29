#pragma once

#include <stdexcept>
#include <iostream>
#include "Queue.h"
#include "Node.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class LinkedQueue : public Queue<E> {
private:
	Node<E>* front;
	Node<E>* back;
	int size;

public:
	LinkedQueue() {
		front = new Node<E>(nullptr);
		back = front; 
		size = 0;
	}

	~LinkedQueue() {
		clear();
		delete front;
	}

	void enqueue(E element) {
		back = back->next = new Node<E>(element);
		size++;
	}

	E dequeue() {
		if (size == 0) {
			throw runtime_error("Queue is empty.");
		}
		E result = front->next->element;
		Node<E>* temp = front->next;
		front->next = temp->next;
		delete temp;
		if (size == 1){
			back = front;
		}
		size--;
		return result;
	}

	E frontValue(){
		if (size == 0){
			throw runtime_error("Queue is empty.");
		}
		return front->next->element;
	}

	void clear(){
		while (front->next != nullptr){
			back = front->next;
			front->next = back->next;
			delete back;
		}
		back = front;
		size = 0;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return size == 0;
	}

	void print(){
		Node<E>* temp = front->next;
		cout << "[";
		while (temp != nullptr){
			temp = temp->next;
			cout << temp->element << " ";
		}
		cout << "]" << endl;
	}
};
