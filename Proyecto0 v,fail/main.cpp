/* Archivo creado por Javier Lee Liang
* Este es el archivo principal en donde se va a correr el proyecto
*/
#include <string>
#include "OrderedArrayList.h"
#include "DLinkedList.h"
#include "KVPair.h"
#include "Service.h"
#include "Header.h"
#include "AdmSystem.h"

using std::string;

/* Creado por Kevin Jimenez y Fabian Solis
* Función principal para correr el proyecto
*/
int main() {
	// Permite que el sistema pueda soportar texto con tildes y la ñ
	setlocale(LC_ALL, "");
	
	// Inicializacion de AdmSystem
	AdmSystem* AdmControl = new AdmSystem();

	// Agregar una serie de servicios iniciales
	AdmControl->addService("Desc1", "Area1", 5);
	AdmControl->addService("Desc2", "Area2", 6);
	AdmControl->addService("Desc3", "Area3", 9);
	AdmControl->addService("Desc4", "Area4", 7);
	AdmControl->addService("Desc5", "Area5", 2);
	
	// Agregar una serie de tipos de clientes
	AdmControl->addType("Adulto Mayor", 1);
	AdmControl->addType("Persona con nececidades especiales", 2);
	AdmControl->addType("Usuario regular", 3);
	AdmControl->addType("Representante organizacional", 0);

	runningLoop(&getMainMenuAction);
	return 0;
}