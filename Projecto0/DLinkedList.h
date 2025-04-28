#pragma once

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "DNode.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class DLinkedList : public List<E> {
private:
	DNode<E>* head;
	DNode<E>* current;
	DNode<E>* tail;
	int size;

public:
	DLinkedList() {
		current = head = new DNode<E>(nullptr, nullptr);
		head->next = tail = new DNode<E>(nullptr, head);
		size = 0;
	}

	~DLinkedList() {
		clear();
		delete head;
		delete tail;
	}

	void insert(E element) {
		current->next = current->next->previous = new DNode<E>(element, current->next, current);
		size++;
	}

	void append(E element) {
		tail->previous = tail->previous->next = new DNode<E>(element, tail, tail->previous);
		size++;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("Error: List is empty.");
		if (current->next == tail) {
			throw runtime_error("Error: No current element.");
		}
		E result = current->next->element;
		current->next = current->next->next;
		delete current->next->previous;
		current->next->previous = current;
		size--;
		return result;
	}

	E getElement() {
		if (size == 0)
			throw runtime_error("Error: List is empty.");
		if (current->next == tail) {
			throw runtime_error("Error: No current element.");
		}
		return current->next->element;
	}

	void clear() {
		while (head->next != tail) {
			current = head->next;
			head->next = head->next->next;
			delete current;
		}
		tail->previous = head;
		current = head;
		size = 0;
	}

	void goToStart() {
		current = head;
	}

	void goToEnd() {
		current = tail->previous;
	}

	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of range");
		if (pos < size / 2) {
			current = head;
			for (int i = 0; i < pos; i++)
				current = current->next;
		}
		else {
			current = tail->previous;
			for (int i = size; i >= pos; i--)
				current = current->previous;
		}
	}

	void next() {
		if (current->next != tail)
			current = current->next;
	}

	void previous() {
		if (current != head)
			current = current->previous;
	}

	bool atStart() {
		return current == head;
	}

	bool atEnd() {
		return current->next == tail;
	}

	int getPos() {
		int pos = 0;
		DNode<E>* temp = head;
		while (temp != current) {
			pos++;
			temp = temp->next;
		}
		return pos;
	}

	int getSize() {
		return size;
	}

	void print() {
		cout << "[ ";
		DNode<E>* temp = head->next;
		while (temp != tail) {
			if (temp == current->next)
				cout << "*";
			cout << temp->element << " ";
			temp = temp->next;
		}
		if (current->next == tail)
			cout << "*";
		cout << "]" << endl;
	}

	int indexOf(E element, int start) {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (start < 0 || start >= size)
			throw runtime_error("Index out of range.");
		DNode<E>* temp;
		if (start < size / 2) {
			temp = head->next;
			for (int i = 0; i < start; i++)
				temp = temp->next;
		}
		else {
			temp = tail->previous;
			for (int i = size - 1; i > start; i--)
				temp = temp->next;
		}
		for (int i = start; i < size; i++) {
			if (temp->element == element)
				return i;
			temp = temp->next;
		}
		return -1;
	}

	bool contains(E element) {
		if (size == 0)
			throw runtime_error("List is empty.");
		DNode<E>* temp = head->next;
		for (int i = 0; i < size; i++) {
			if (temp->element == element)
				return true;
			temp = temp->next;
		}
		return false;
	}
};