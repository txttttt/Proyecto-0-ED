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
	/* Incialización de la lista de tipos de usuario
	List<KVPair<int, string>>* users = new OrderedArrayList<KVPair<int, string>>();
	users->insert(KVPair<int, string>(1, "Adulto mayor"));
	users->insert(KVPair<int, string>(2, "Persona con necesidades especiales"));
	users->insert(KVPair<int, string>(3, "Usuario regular"));
	users->insert(KVPair<int, string>(0, "Representante organizacional"));
	users->print();

	// Inicialización de la lista de servicios
	List<Service>* services = new ArrayList<Service>();
	services->insert(Service("Desc1", "Area1", 5));
	services->insert(Service("Desc2", "Area2", 6));
	services->insert(Service("Desc3", "Area3", 9));
	services->insert(Service("Desc4", "Area4", 1));
	services->print();
	*/
	// Inicializacion de AdmSystem
	AdmSystem* AdmControl = new AdmSystem();
	/*AdmControl->addService("Desc1", "Area1", 5);
	AdmControl->addService("Desc2", "Area2", 6);
	AdmControl->addService("Desc3", "Area3", 9);
	AdmControl->addService("Desc4", "Area4", 7);
	AdmControl->addService("Desc5", "Area5", 2);
	*/
	
	AdmControl->addType("Adulto Mayor", 1);
	//AdmControl->addType("Persona con nececidades especiales", 2);
	//AdmControl->addType("Usuario regular", 3);
	//AdmControl->addType("Representante organizacional", 0);


	runningLoop(&getMenuAction);
	return 0;
}