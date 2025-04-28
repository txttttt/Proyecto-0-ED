/* Archivo creado por Javier Lee Liang
* Este es el archivo principal en donde se va a correr el proyecto
*/
#include <string>
#include "OrderedArrayList.h"
#include "KVPair.h"
#include "Header.h"

using std::string;

/* Creado por Javier Lee Liang
* Función principal para correr el proyecto
*/
int main() {
	// Incialización de las listas
	List<KVPair<int, string>>* users = new OrderedArrayList<KVPair<int, string>>(10);
	users->insert(KVPair<int, string>(1, "Adulto mayor"));
	users->insert(KVPair<int, string>(2, "Persona con necesidades especiales"));
	users->insert(KVPair<int, string>(3, "Usuario regular"));
	users->insert(KVPair<int, string>(0, "Representante organizacional"));
	users->print();
	List<KVPair<int, string>>* services = new OrderedArrayList<KVPair<int, string>>(10);
	runningLoop(&getMenuAction);
	return 0;
}