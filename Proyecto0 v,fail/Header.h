/* Archivo creado por: Javier Lee Liang
* Fecha creada: 27/04/2025
* El archivo contiene el nombre de los métodos que se van usar para 
* compartir dentro del proyecto
*/
#pragma once

#include <string>

using std::string;

// Métodos de "userInput.cpp"
void getInt(const string text, int& input_int);
void getStr(const string text, string& input_str);

// Hileras constantes para el menú
string const main_menu =
"\nMenú principal\n"
"---------------------------------\n"
"0. Estado de las colas\n"
"1. Agregar tiquetes\n"
"2. Atender\n"
"3. Administración\n"
"4. Estadísticas del sistema\n"
"5. Salir\n"
"---------------------------------\n"
"Seleccione alguna de las acciones: ";

string const admin_menu =
"\nMenú de administración\n"
"---------------------------------\n"
"0. Tipos de usuario\n"
"1. Áreas\n"
"2. Servicios disponibles\n"
"3. Limpiar colas y estadísticas\n"
"4. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las opciones a modificar: ";

string const users_options =
"\nOpciones de usuarios\n"
"---------------------------------\n"
"0. Agregar\n"
"1. Eliminar\n"
"2. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las opciones: ";

string const areas_options =
"\nOpciones de áreas\n"
"---------------------------------\n"
"0. Agregar\n"
"1. Modificar cantdad de ventanillas\n"
"2. Eliminar\n"
"3. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las opciones: ";

string const services_options =
"\nOpciones de servicios\n"
"---------------------------------\n"
"0. Agregar\n"
"1. Eliminar\n"
"2. Reordernar\n"
"3. Regresar\n"
"---------------------------------\n"
"Seleccione alguna de las opciones: ";