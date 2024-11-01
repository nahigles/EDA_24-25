// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;


// Complejidad lineal en n, siendo n el numero de elementos de la lista
void ordena(list<int>& lista, const int& e) {
	list <int>::iterator it = lista.begin();
	while (it != lista.end()) {
		if ((*it) == e) {
			it = lista.erase(it);
		}
		else
			++it;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// Leo datos de entrada

	// Guardo cola
	list<int> lista;
	int e;
	cin >> e;
	while (e != -1) {
		lista.push_back(e);
		cin >> e;
	}

	// Numero a eliminar
	cin >> e;

	// Escribo lista sin cambios
	for (list <int>::iterator it = lista.begin(); it != lista.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;


	// llamada a metodo
	ordena(lista, e);

	// escribir sol 
	for (list <int>::iterator it = lista.begin(); it != lista.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}