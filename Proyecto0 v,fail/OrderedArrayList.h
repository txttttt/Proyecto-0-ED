#pragma once

#include "List.h"
#include "ArrayList.h"

template <typename E>
class OrderedArrayList : public List<E> {
private:
	List<E>* data;

public:
	OrderedArrayList(int max = DEFAULT_MAX) {
		data = new ArrayList<E>(max);
	}

	~OrderedArrayList() {
		delete data;
	}

	void insert(E element) {
		data->goToStart();
		while (!data->atEnd() && element >= data->getElement())
			data->next();
		data->insert(element);
	}

	void append(E element) {
		insert(element);
	}

	E remove() {
		return data->remove();
	}

	E getElement() {
		return data->getElement();
	}

	void clear() {
		data->clear();
	}

	void goToStart() {
		data->goToStart();
	}

	void goToEnd() {
		data->goToEnd();
	}

	void goToPos(int pos) {
		data->goToPos(pos);
	}

	void next() {
		data->next();
	}

	void previous() {
		data->previous();
	}

	bool atStart() {
		return data->atStart();
	}

	bool atEnd() {
		return data->atEnd();
	}

	int getPos() {
		return data->getPos();
	}

	int getSize() {
		return data->getSize();
	}

	void print() {
		data->print();
	}

	int indexOf(E element, int start) {
		return data->indexOf(element, start);
	}

	bool contains(E element) {
		return data->contains(element);
	}
};
