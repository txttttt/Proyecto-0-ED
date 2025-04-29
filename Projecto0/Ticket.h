#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "LinkedPriorityQueue.h"

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class Ticket {
private:
	string code;
	float hour;
	int finalPriority;
public:
	Ticket(string code, float hour, int finalPriority) {
		this->code = code;
		this->hour = hour;
		this->finalPriority = finalPriority;
	}

	void setCode(code) {
		this->code = code;
	}

	string getCode() {
		reutrn code;
	}

	void setHour(float hour) {
		this->hour = hour;
	}

	float getHour() {
		reutrn hour;
	}

	void setFinalPriority(int fp) {
		this->finalPriority = fp;
	}

	int getFinalPriority() {
		return finalPriority;
	}
};
