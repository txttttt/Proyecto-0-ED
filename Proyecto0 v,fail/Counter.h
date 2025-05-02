/*Clase creada por Fabian Solis Izaguirre
* Implementacion de la clase ventanilla.
*/
#pragma once

#include <iostream>
#include <string>
#include "Ticket.h"

using std::ostream;
using std::string;

class Counter {
public:
    string name;
    int ticketsServed;
    Ticket currentTicket;

    Counter() {
        ticketsServed = 0;
    }

    Counter(const string& name) {
        this->name = name;
        ticketsServed = 0;
    }

    string getName() {
        return name;
    }

    void incrementTicketsServed() {
        ticketsServed++;
    }

    int getTicketsServed() {
        return ticketsServed;
    }

    void setCurrentTicket(Ticket ticket) {
        if (currentTicket.getCode() == "") { // Validación correcta de tiquete vacío
            currentTicket = ticket;
            incrementTicketsServed();
        }
        else {
            cout << "Error: La ventanilla " << name << " ya está atendiendo un tiquete." << endl;
        }
    }

    bool assignTicket(Ticket ticket) {
        if (currentTicket.getCode() == "") { // Evita uso incorrecto de empty()
            setCurrentTicket(ticket);
            return true;
        }
        return false;
    }

    void print() {
        cout << "Ventanilla: " << name << ", Tiquetes atendidos: " << ticketsServed << endl;
    }

    void clearCurrentTicket() {
        currentTicket = Ticket(); // Reinicia el tiquete en la ventanilla
    }

    bool operator==(const Counter& other) const {
        return name == other.name;
    }
};

ostream& operator<<(ostream& os, const Counter& counter) {
    return os << "[Ventanilla: " << counter.name
        << ", Tiquetes atendidos: " << counter.ticketsServed << "]";
}


