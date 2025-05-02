#pragma once

#include <iostream>
#include <stdexcept>
#include "PriorityQueue.h"
#include "LinkedQueue.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class LinkedPriorityQueue : public PriorityQueue<E> {
private:
	LinkedQueue<E>* queues;
	int priorities;
	int size;

public:
	LinkedPriorityQueue() {}
	LinkedPriorityQueue(int priorities) {
		if (priorities <= 0)
			throw runtime_error("ERROR: Invalid amount of priorities.");
		queues = new LinkedQueue<E>[priorities];
		this->priorities = priorities;
		size = 0;
	}

	~LinkedPriorityQueue() {
		delete[] queues;
	}

	void insert(E element, int priority) {
		if (priority < 0 || priority >= priorities)
			throw runtime_error("ERROR: Invalid priority access number.");
		queues[priority].enqueue(element);
		size++;
	}

	E min() {
		if (size == 0)
			throw runtime_error("ERROR: All queues are empty.");
		E element;
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty()) {
				element = queues[i].frontValue();
				i = priorities;		// Esto funciona como un break
			}
		}
		return element;
	}

	E removeMin() {
		if (size == 0)
			throw runtime_error("ERROR: All queues are empty.");
		E element;
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty()) {
				element = queues[i].dequeue();
				i = priorities;		// Esto funciona como un break
			}
		}
		size--;
		return element;
	}

	void clear() {
		for (int i = 0; i < priorities; i++) {
			queues[i].clear();
		}
		size = 0;
	}

	int getSize() {
		return size;
	}

	int getPriorities() {
		return priorities;
	}

	bool isEmpty() {
		return size == 0;
	}

	void print() {
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty()) {
				cout << i << ": ";
				queues[i].print();
			}
		}
	}
};

