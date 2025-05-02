/* Clase creada por Kevin Jimenez Escalante y Fabian Solis Izaguirre
* Esta clase es la implementacion de las areas
*/


/*
La keyword friend permite a funciones o clases exteriores visualizar variables privadas
Esto se hace porque de otro modo parecia no funcionar
Friend: https://learn.microsoft.com/en-us/cpp/cpp/friend-cpp?view=msvc-170
Informacion adicional: https://www.geeksforgeeks.org/friend-class-function-cpp/
*/

/*
* Los Constructores copia son necesario para el correcto funcionamiento de este codigo
* Estos se encargan de actuar como un constructor cuando se devuelve un obj de la clase por valor, cuando se pasa un obj como argumento,
* cuando el obj se construye en base a otro o cuando el compilador genera un objeto temporal.
https://www.geeksforgeeks.org/copy-constructor-in-cpp/
* Para el correcto funcionamiento de este codigo tambien es necesario el uso de sobrecarga de operadores de asignacion
* Este es necesario cuando la clase tiene punteros y se necesita utilizar copias pero previniendo una doble eliminacion
* de informacion o corrupcion de datos
https://www.geeksforgeeks.org/cpp-assignment-operator-overloading/
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
    LinkedList<Counter>* counters; // Lista de ventanillas en el área

public:
    Area() {
        tickets = new LinkedPriorityQueue<Ticket>(110);
        counters = new LinkedList<Counter>();
        totalWaitTime = 0;
        attendedTickets = 0;
    }

    Area(string description, string code, int numCounter) {
        this->description = description;
        this->code = code;
        this->numCounter = numCounter;
        tickets = new LinkedPriorityQueue<Ticket>(110);
        counters = new LinkedList<Counter>();
        totalWaitTime = 0;
        attendedTickets = 0;
        initializeCounters();
    }

    Area(const Area& other) { // Constructor de copia
        this->description = other.description;
        this->code = other.code;
        this->numCounter = other.numCounter;
        this->tickets = new LinkedPriorityQueue<Ticket>(110);
        this->counters = new LinkedList<Counter>();

        // Copiar los elementos de la lista de ventanillas
        for (int i = 0; i < other.counters->getSize(); i++) {
            other.counters->goToPos(i);
            this->counters->append(other.counters->getElement());
        }

        this->totalWaitTime = other.totalWaitTime;
        this->attendedTickets = other.attendedTickets;
    }

    ~Area() {
        delete tickets;
        delete counters;
    }

    Area& operator=(const Area& other) { // Operador de asignación
        if (this == &other)
            return *this; // Evita auto-asignación

        // Liberar memoria existente antes de copiar
        delete tickets;
        delete counters;

        // Copiar atributos simples
        description = other.description;
        code = other.code;
        numCounter = other.numCounter;
        totalWaitTime = other.totalWaitTime;
        attendedTickets = other.attendedTickets;

        // Copiar estructuras dinámicas
        tickets = new LinkedPriorityQueue<Ticket>(110);
        counters = new LinkedList<Counter>();

        for (int i = 0; i < other.counters->getSize(); i++) {
            other.counters->goToPos(i);
            counters->append(other.counters->getElement());
        }

        return *this;
    }

    // Métodos de acceso
    string getDescription() const { return description; }
    string getCode() const { return code; }
    int getNumCounter() const { return numCounter; }

    void setDescription(string description) { this->description = description; }
    void setCode(string code) { this->code = code; }
    void setNumCounter(int numCounter) {
        this->numCounter = numCounter;
        initializeCounters();
    }

    void initializeCounters() {
        counters->clear();
        for (int i = 1; i <= numCounter; i++) {
            string counterName = code + to_string(i);
            counters->append(Counter(counterName));
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

    void printCounters() {
        cout << "Ventanillas en el area " << code << ":" << endl;
        counters->print();
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

    void deleteTickets() {
        tickets->clear();
    }

    LinkedList<Counter>& getCounters() { return *counters; }

    bool operator==(const Area& other) const { return code == other.code; }

    friend ostream& operator<<(ostream& os, const Area& area) {
        return os << "[Area: " << area.getCode() << ", Descripcion: " << area.getDescription()
            << ", Ventanillas: " << area.getNumCounter() << "]";
    }
};
