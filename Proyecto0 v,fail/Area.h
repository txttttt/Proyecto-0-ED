/* Clase creada por Kevin Jimenez Escalante y Fabian Solis Izaguirre
* Esta clase es la implementacion de las areas
*/

/*
La keyword friend permite a funciones o clases exteriores visualizar variables privadas
Esto se hace porque de otro modo parecia no funcionar
Friend: https://learn.microsoft.com/en-us/cpp/cpp/friend-cpp?view=msvc-170
Informacion adicional: https://www.geeksforgeeks.org/friend-class-function-cpp/
*/


#pragma once

#include <iostream>
#include <stdexcept>
#include <ctime>
#include "List.h"
#include "LinkedPriorityQueue.h"
#include "Ticket.h"
#include "Counter.h"
#include "LinkedList.h"

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;
using std::to_string;
// Se usa `time_t` para el manejo de tiempos en estadísticas
using std::time;
using std::time_t;

class Area {
private:
    string description;
    string code;
    int numCounter;
    int totalWaitTime;
    int attendedTickets;
    LinkedPriorityQueue<Ticket>* tickets; // Cola de prioridad para tiquetes en el área
    LinkedList<Counter> counters; // Lista de ventanillas en el área

public:
    Area() {}

    Area(string description, string code, int numCounter) {
        this->description = description;
        this->code = code;
        this->numCounter = numCounter;
        tickets = new LinkedPriorityQueue<Ticket>(110);
        totalWaitTime = 0;
        attendedTickets = 0;
        initializeCounters();
    }

    ~Area() {
        delete tickets;
    }

    // Métodos de acceso
    string getDescription() const { return description; }
    string getCode() const { return code; }
    int getNumCounter() const { return numCounter; }

    void setDescription(string description) { this->description = description; }
    void setCode(string code) { this->code = code; }
    void setNumCounter(int numCounter) {
        this->numCounter = numCounter;
        initializeCounters(); // Regenera la lista de ventanillas
    }

    void initializeCounters() {
        counters.clear();
        for (int i = 1; i <= numCounter; i++) {
            string counterName = code + to_string(i);
            counters.append(Counter(counterName));
        }
    }

    void addTicket(Ticket ticket) {
        tickets->insert(ticket, ticket.getFinalPriority());
    }

    Ticket attendNextTicket() {
        if (tickets->getSize() != 0) {
            time_t now;
            time(&now);
            Ticket ticket = tickets->removeMin();
            int waitTimeSeconds = difftime(now, ticket.getCreation());
            cout << "Tiempo de espera en horas: " << float(waitTimeSeconds) / 3600 << endl;
            totalWaitTime += waitTimeSeconds;
            attendedTickets++;
            return ticket;
        }
        throw std::runtime_error("No hay tiquetes en espera.");
    }
    /*
    bool distributeTicket() {
        if (tickets->getSize() == 0) {
            cout << "No hay tiquetes en espera." << endl;
            return false;
        }

        Ticket nextTicket = tickets->removeMin();

        for (int i = 0; i < counters.getSize(); i++) {
            counters.goToPos(i);
            if (counters.getElement().assignTicket(nextTicket)) {
                cout << "Tiquete " << nextTicket.getCode() << " asignado a " << counters.getElement().getName() << endl;
                return true;
            }
        }

        cout << "Todas las ventanillas están ocupadas." << endl;
        return false;
    }
    */

    void printCounters() {
        cout << "Ventanillas en el área " << code << ":" << endl;
        counters.print();
    }

    void printTickets() {
        if (tickets->getSize() == 0) {
            cout << "No hay tiquetes registrados." << endl;
        }
        else {
            cout << "Lista de Tiquetes:" << endl;
            tickets->print();
        }
    }

    float averageWaitTime() const {
        return attendedTickets != 0 ? float(totalWaitTime) / float(attendedTickets) : 0;
    }

    LinkedList<Counter>& getCounters() { return counters; }

    bool operator==(const Area& other) const { return code == other.code; }

    friend ostream& operator<<(ostream& os, const Area& area) {
        return os << "[Área: " << area.getCode() << ", Descripción: " << area.getDescription()
            << ", Ventanillas: " << area.getNumCounter() << "]";
    }
};
