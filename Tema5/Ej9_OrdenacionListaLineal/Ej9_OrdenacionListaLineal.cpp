// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;


// Complejidad lineal en n, siendo n el numero de elementos de la lista
void ordena(list<int>& lista) {

	if (lista.size() > 1) {
		list <int>::iterator itAnt = lista.begin(); // Primer elem
		list <int>::iterator it = lista.begin(); // Segund elem
		++it;

		while (it != lista.end()) { // O(n-1), n: nelems
			if (*(itAnt) > *(it)) {
				it = lista.erase(it);
			}
			else {
				++itAnt;
				++it;
			}
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// Leo datos de entrada
	list<int> lista;
	int e;
	cin >> e;
	while (e != -1) {
		lista.push_back(e);
		cin >> e;
	}

	// llamada a metodo
	ordena(lista);

	// escribir sol 
	if (!lista.empty()) {
		list <int>::iterator it = lista.begin();
		cout << (*it);
		++it;

		while (it != lista.end()) {
			cout << " " << (*it);

			++it;
		}
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