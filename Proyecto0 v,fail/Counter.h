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

    // Método para obtener el nombre del contador
    string getName() {
        return name;
    }

    // Método para incrementar el contador de tiquetes atendidos
    void incrementTicketsServed() {
        ticketsServed++;
    }

    // Método para obtener el número de tiquetes atendidos
    int getTicketsServed() {
        return ticketsServed;
    }

    void setCurrentTicket(Ticket ticket) {
        if (currentTicket.getCode().empty()) { // Si no hay un tiquete asignado, lo asigna
            currentTicket = ticket;
            incrementTicketsServed();
        }
        else {
            cout << "Error: La ventanilla " << name << " ya está atendiendo un tiquete." << endl;
        }
    }

    bool assignTicket(Ticket ticket) {
        if (currentTicket.getCode().empty()) { // Si la ventanilla está libre
            setCurrentTicket(ticket);
            return true;
        }
        return false; // Ventanilla ocupada
    }

    void print() {
        cout << "Ventanilla: " << name << ", Tiquetes atendidos: " << ticketsServed << endl;
    }

    void clearCurrentTicket() {
        currentTicket = Ticket(); // Reinicia el tiquete en la ventanilla
    }

    bool operator==(const Counter& other) const {
        return name == other.name; // Compara las ventanillas por nombre
    }

};

ostream& operator<<(ostream& os, const Counter& counter) {
    return os << "[Ventanilla: " << counter.name
        << ", Tiquetes atendidos: " << counter.ticketsServed << "]";
}
