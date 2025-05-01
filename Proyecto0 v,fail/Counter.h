#pragma once

#include <string>

using std::string;

class Counter {
public:
    string name;          
    int ticketsServed;    

    
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
};

