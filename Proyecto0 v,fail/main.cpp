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
*
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
*/
//Main de pruebas sin pasar por el menu, por si gustan copiarlo y poder usarlo en otro proyecto para probar cosas, Creado por Fabian Solis Izaguirre 

#include <iostream>
#include <stdexcept>
//#include <string>
// #include "AdmSystem.h"
#include "Area.h"
#include "Counter.h"
#include "Ticket.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {
    // Permite que el sistema pueda soportar texto con tildes y la ñ
    setlocale(LC_ALL, "");

    // Inicialización del sistema de administración
    AdmSystem* AdmControl = new AdmSystem();

    // Creación de un área con ventanillas
    Area* serviceArea = new Area("Servicio al Cliente", "S", 3);


    // Agregamos servicios y tipos de cliente
    AdmControl->addService("Atencion General", "S", 5);
    AdmControl->addService("Reclamos", "S", 7);
    AdmControl->addType("Adulto Mayor", 1);
    AdmControl->addType("Usuario Regular", 3);

    // Imprimimos estado del sistema
    AdmControl->printServices();
    AdmControl->printTypes();

    // Creación de tiquetes y asignación a área
    Ticket ticket1("S101", 5);
    Ticket ticket2("S102", 7);

    serviceArea->addTicket(ticket1);
    serviceArea->addTicket(ticket2);

    cout << "Tiquetes agregados a la cola de prioridad del area." << endl;
    serviceArea->printTickets();

    // Distribución de tiquetes a ventanillas disponibles
    serviceArea->distributeTicket();
    serviceArea->distributeTicket();

    // Imprimimos estado del área y ventanillas
    //serviceArea->print();

    // Eliminamos un servicio y un tipo de usuario para probar las funciones de eliminación
    AdmControl->deleteService("Atencion General");
    AdmControl->deleteType("Usuario Regular");

    // Mostramos el estado actualizado del sistema
    AdmControl->printServices();
    AdmControl->printTypes();

    // Limpiamos memoria
    delete AdmControl;
    delete serviceArea;

    return 0;
};

/*int main() {
    try {
        // Inicialización del sistema
        AdmSystem* admControl = new AdmSystem();

        // Agregar tipos de usuario
        admControl->addType("Adulto Mayor", 1);
        admControl->addType("Usuario Regular", 3);
        admControl->printTypes();

        // Agregar servicios
        admControl->addService("Atencion General", "A", 5);
        admControl->addService("Reclamos", "B", 7);
        admControl->printServices();

        // Generar tiquetes con código dinámico
        admControl->addTicket("A", "Adulto Mayor", "Atencion General");
        admControl->addTicket("B", "Usuario Regular", "Reclamos");
        admControl->addTicket("A", "Usuario Regular", "Atencion General");
        admControl->printTickets();
        /*
        // Intentar generar un tiquete con un tipo de usuario inexistente
        admControl->addTicket("C", "Estudiante", "Atencion General");

        // Intentar generar un tiquete con un servicio inexistente
        admControl->addTicket("B", "Usuario Regular", "Tramites Especiales");

        // Verificar que el contador de tiquetes sigue aumentando
        admControl->addTicket("A", "Adulto Mayor", "Reclamos");
        admControl->printTickets();
        
        // Limpiar memoria
        delete admControl;

        return 0;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
};
*/