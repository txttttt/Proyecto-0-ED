/* Clase creada por Kevin Jimenez Escalante
* Esta clase es la implementacion de las areas
*/

#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "LinkedPriorityQueue.h"
#include "Ticket.h"

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class Area
{
private:
	string description;
	string code;
	int numCounter;
	LinkedPriorityQueue<Tiquete>* tiquetes;

public:
	Area() {
	}

	Area(string descripcion, string codigo, int numVentanillas) {
		this->codigo = codigo;
		this->description = description;
		this->numVentanillas = numVentanillas;
		tiquetes = new LinkedPriorityQueue<Tiquete>();
	}

	~Area() {
	}

	void setDescription(String description) {
		this->description = description;
	}

	String getDescription() {
		return description;
	}

	void setCode(String code) {
		this->code = code;
	}

	String getCode() {
		return code;
	}

	void setNumCounter(String numCounter) {
		this->numCounter = numCounter;
	}

	String getNumCounter() {
		return numCounter;
	}
};