#pragma once

#include "ArrayList.h"

template <typename E>
class SortedArrayList : public ArrayList<E> {
public:
	SortedArrayList(int max = DEFAULT_MAX) : ArrayList<E>(max) {}
	void insert(E element) {
		ArrayList<E>::gotoStart();
		while (!ArrayList<E>::atEnd() && element >= ArrayList<E>::getElement()) {
			ArrayList<E>::next();
		}
		ArrayList<E>::insert(element);
	}

	void append(E element) {
		insert(element);
	}
};