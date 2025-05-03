#pragma once

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class UserType {
private:
	string description;
	int priority;
	int ticketCount;

public:
	UserType() {
	}

	UserType(string description, int priority) {
		this->description = description;
		this->priority = priority;
		ticketCount = 0;
	}

	~UserType() {
	}

	string getDescription() {
		return description;
	}

	int getPriority() {
		return priority;
	}

	int getTicketCount() {
		return ticketCount;
	}

	void incrementTicketCount() {
		ticketCount++;
	}

	bool operator==(UserType& other) {
		return description == other.getDescription();
	}
};

ostream& operator<<(ostream& os, UserType& userType) {
	return os << "(" << userType.getDescription() << ", " << userType.getPriority() << ")";
}