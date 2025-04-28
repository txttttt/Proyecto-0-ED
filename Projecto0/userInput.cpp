/* Archivo creado por: Javier Lee Liang
* Fecha creada: 28/04/2025
* El archivo contiene métodos para recibir entradas del usuario
* a través de la terminal
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::stoi;
using std::ws;
using std::getline;
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;
using std::string;
using std::numeric_limits;

/* Creado por Javier Lee Liang
* Imprime un texto dado y solicita al usuario un número entero dentro de un rango
* @param text Hilera con el texto a imprimir
* @param input Referencia a un entero que se va a usar para guardar la respuesta del usuario
*/
void getInt(const string text, int& input_int) {
	cout << text;
	string input_str;
	getline(cin >> ws, input_str);
	try {
		input_int = stoi(input_str);
	}
	catch (const invalid_argument& ia) {
		cout << "Invalid argument\n";
	}
	catch (const out_of_range& oof) {
		cout << "Out of range\n";
	}
}

/* Creado por Javier Lee Liang
* Imprime un texto dado y solicita al usuario una hilera
* @param text Hilera con el texto a imprimir
* @param input Referencia a un string que se va a usar para guardar la respuesta del usuario
*/
void getStr(const string text, string& input_str) {
	cout << text;
	getline(cin >> ws, input_str);
}