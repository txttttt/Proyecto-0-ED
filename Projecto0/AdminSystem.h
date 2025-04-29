/* Clase creada por Kevin Jimenez Escalante y Fabian Solis Izaguirre
* Esta clase se encarga de controlar varios aspectos como los tipos de usuarios

agregar o eliminar elementos de listas de tipos de usuario, areas disponibles, ventanillas y servicios disponibles.
Si se borra un tipo de usuario o servicio se eliminan todos los tiquetes.
Si se borra un area se eliminan todos los servicios y las ventanillas
Dar un mensaje de advertencia y solicitar confirmacion antes de borrar.
*/

#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "LinkedPriorityQueue.h"
#include "ArrayList.h"
#include "Ticket.h"
#include "KVPair.h"

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;


class AdminSystem
{
private:
	ArrayList<KVPair<int, string>>* types;

public:
	void addType(int priority, string description) {
		
	}
//Solicitud de un tiquete

//Ventanilla tiene a tiquete

// Administracion del sistema

// Consulta de estadisticas
};

