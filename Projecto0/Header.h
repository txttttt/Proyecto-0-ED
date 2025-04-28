/* Archivo creado por: Javier Lee Liang
* Fecha creada: 27/04/2025
* El archivo contiene el nombre de los métodos que se van usar para 
* compartir dentro del proyecto
*/
#pragma once

#include <string>

using std::string;

// Métodos de "menu.cpp"
void runningLoop(void (*f)(bool&, int&));
void getMenuAction(bool& running, int& input);

// Métodos de "userInput.cpp"
void getInt(const string text, int& input_int);
void getStr(const string text, string& input_str);

