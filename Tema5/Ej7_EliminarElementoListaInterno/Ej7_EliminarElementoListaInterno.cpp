// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;


template <class T>
class list_plus : public list<T> {
	using Nodo = typename list<T>::Nodo;

public:
	// Complejidad lineal en n, siendo n el numero de elementos de la lista
	void elimina(const T e) {

		Nodo* aux = this->fantasma->sig; // Primer elemeto de la lista

		while (aux != this->fantasma) { // O(n), n = nelems

			// Si es el numero lo borra
			if (aux->elem == e) {
				aux->ant->sig = aux->sig; // Nodo anterior de aux apuntando al siguiente de aux
				aux->sig->ant = aux->ant; // Nodo sigguiente de aux apuntando al anterior de aux

				// Nodo auxiliar para eleminar aux
				Nodo* aux2 = aux->sig; 
				delete aux;
				aux = aux2;
				this->nelems--;
			}
			// Avanzoo aux
			else 
				aux = aux->sig;
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// Leo datos de entrada

	// Guardo cola
	list_plus<int> lista;
	int e;
	cin >> e;
	while (e != -1) {
		lista.push_back(e);
		cin >> e;
	}

	// Numero a eliminar
	cin >> e;

	// Escribo lista sin cambios
	for (list_plus <int>::iterator it = lista.begin(); it != lista.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;


	// llamada a metodo
	lista.elimina(e);

	// escribir sol 
	for (list_plus <int>::iterator it = lista.begin(); it != lista.end(); ++it) {
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