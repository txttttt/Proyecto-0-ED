#pragma once

#include <iostream>
#include <stdexcept>
#include "Node.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class CircleList {
private:
	Node<E>* current;
	int size;

public:
	CircleList() {
		current = nullptr;
		size = 0;
	}

	~CircleList() {
		clear();
	}

	void insert(E element) {
		if (size == 0) {
			current = new Node<E>(element);
			current->next = current;
		}
		else {
			current->next = new Node<E>(element, current->next);
		}
		size++;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		E result = current->next->elemnent;
		if (size == 1) {
			delete current;
			current = nullptr;
		}
		else {
			Node<E>* temp = current->next;
			current->next = temp->next;
			delete temp;	
		}
		size--;
		return result;
	}

	void clear() {
		while (size != 0)
			remove();
	}

	E getFront() {
		if (size == 0)
			throw runtime_error("List is empty.");
		return current->next->element;
	}

	E getBack() {
		if (size == 0)
			throw runtime_error("List is empty.");
		return current->element;
	}

	void next() {

	}

	void previous() {

	}

	void print() {

	}
};
