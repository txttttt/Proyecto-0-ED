#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "List.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class ArrayList : public List<E> {
protected:
	E* elements;
	int max;
	int size;
	int pos;

	void expand() {
		E* new_elements = new E[2 * max];
		for (int i = 0; i < size; i++)
			new_elements[i] = elements[i];
		delete elements;
		elements = new_elements;
	}

public:
	ArrayList(int max = DEFAULT_MAX) {
		if (max < 1)
			throw runtime_error("Invalid max size.");
		elements = new E[max];
		this->max = max;
		pos = size = 0;
	}

	~ArrayList() {
		delete[] elements;
	}

	void insert(E element) {
		if (size == max)
			expand();
		for (int i = size; i > pos; i--)
			elements[i] = elements[i - 1];
		elements[pos] = element;
		size++;
	}

	void append(E element) {
		if (size == max)
			expand();
		elements[size] = element;
		size++;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		E result = elements[pos];
		for (int i = pos; i < size; i++)
			elements[i] = elements[i + 1];
		size--;
		return result;
	}

	E getElement() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");
		return elements[pos];
	}

	void clear() {
		pos = size = 0;
	}

	void goToStart() {
		pos = 0;
	}

	void goToEnd() {
		pos = size;
	}

	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of range");
		this->pos = pos;
	}

	void next() {
		if (pos < size) {
			pos++;
		}
	}

	void previous() {
		if (pos > 0) {
			pos--;
		}
	}

	bool atStart() {
		return pos == 0;
	}

	bool atEnd() {
		return pos == size;
	}

	int getPos() {
		return pos;
	}

	int getSize() {
		return size;
	}

	void print() {
		cout << "[ ";
		for (int i = 0; i < size; i++) {
			if (i == pos) {
				cout << "*";
			}
			cout << elements[i] << " ";
		}
		if (pos == size) {
			cout << "*";
		}
		cout << "]" << endl;
	}

	int indexOf(E element, int start) {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (start < 0 || start >= size)
			throw runtime_error("Index out of range.");
		for (int i = start; i < size; i++)
			if (elements[i] == element)
				return i;
		return -1;
	}

	bool contains(E element) {
		if (size == 0)
			throw runtime_error("List is empty.");
		for (int i = 0; i < size; i++)
			if (elements[i] == element)
				return true;
		return false;
	}
};
