/* Archivo creado por Javier Lee Liang
* Este es el archivo principal en donde se va a correr el proyecto
*/
#include <string>
#include "OrderedArrayList.h"
#include "DLinkedList.h"
#include "KVPair.h"
#include "Service.h"
#include "Header.h"


using std::string;

/* Creado por Javier Lee Liang
* Función principal para correr el proyecto
*/
int main() {
	// Incialización de la lista de tipos de usuario
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

	runningLoop(&getMenuAction);
	return 0;
}