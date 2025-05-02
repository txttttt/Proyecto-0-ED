#pragma once

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class LinkedList : public List<E> {
private:
	Node<E>* head;
	Node<E>* current;
	Node<E>* tail;
	int size;

public:
	LinkedList() {
		tail = current = head = new Node<E>();
		size = 0;
	}

	LinkedList(const LinkedList<E>& other) { // Constructor de copia
		for (int i = 0; i < other.getSize(); i++) {
			other.goToPos(i);
			this->append(other.getElement());
		}
	}

	~LinkedList() {
		clear();
		delete head;
	}

	void insert(E element) {
		current->next = new Node<E>(element, current->next);
		if (current == tail)
			tail = current->next;
		size++;
	}

	void append(E element) {
		tail = tail->next = new Node<E>(element);
		size++;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("Error: List is empty.");
		if (current == tail)
			throw runtime_error("Error: No current element.");
		Node<E>* temp = current->next;
		E result = temp->element;
		current->next = temp->next;
		if (temp == tail)
			tail = current;
		delete temp;
		size--;
		return result;
	}

	E getElement() {
		if (size == 0)
			throw runtime_error("Error: List is empty.");
		if (current == tail)
			throw runtime_error("Error: No current element.");
		return current->next->element;
	}

	void clear() {
		while (head->next != nullptr) {
			current = head->next;
			head->next = current->next;
			delete current;
		}
		current = tail = head;
		size = 0;
	}

	void goToStart() {
		current = head;
	}

	void goToEnd() {
		current = tail;
	}

	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Error: Index out of range");
		current = head;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
	}

	void next() {
		if (current != tail)
			current = current->next;
	}

	void previous() {
		if (current != head) {
			Node<E>* temp = head;
			while (temp->next != current)
				temp = temp->next;
			current = temp;
		}
	}

	bool atStart() {
		return current == head;
	}

	bool atEnd() {
		return current == tail;
	}

	int getPos() {
		int pos = 0;
		Node<E>* temp = head;
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
		Node<E>* temp = head->next;
		while (temp != nullptr) {
			if (temp == current->next)
				cout << "*";
			cout << temp->element << " ";
			temp = temp->next;
		}
		if (current == tail)
			cout << "*";
		cout << " ]" << endl;
	}

	int indexOf(E element, int start) {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (start < 0 || start >= size)
			throw runtime_error("Index out of range.");
		Node<E>* temp = head->next;
		for (int i = 0; i < start; i++)
			temp = temp->next;
		for (int i = start; i < size; i++) {
			if (temp->element == element)
				return i;
			temp = temp->next;
		}
		return -1;
	}

	bool contains(E element) {
		if (size == 0)
			return false;//throw runtime_error("List is empty.");
		Node<E>* temp = head->next;
		for (int i = 0; i < size; i++) {
			if (temp->element == element)
				return true;
			temp = temp->next;
		}
		return false;
	}
};
