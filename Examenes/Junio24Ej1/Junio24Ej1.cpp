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
	// T(n) --> O(n)
	// Recorre toda la lista
	void partition(int pivote) {
		if (this->nelems > 1) {

			// Nodos auxiliares
			Nodo* actualN = this->fantasma->sig; // primer elem
			Nodo* siguienteN = actualN->sig; // segundo elem

			Nodo* antFantasma = this->fantasma->ant; // ultimo elem

			for (int i = 0; i < this->nelems; i++) {

				// Si es mayor q pivote lo mando al final
				if (actualN->elem > pivote && siguienteN != this->fantasma) {
					// Quito actual de la lista
					actualN->ant->sig = siguienteN;
					siguienteN->ant = actualN->ant;

					// Meto actual despues del ultimo
					antFantasma->sig = actualN;
					actualN->ant = antFantasma;
					actualN->sig = this->fantasma;
					this->fantasma->ant = actualN;

					// Actualizo ultimo
					antFantasma = antFantasma->sig;

				}

				// Actualizo nodos auxiliares
				actualN = siguienteN;
				siguienteN = siguienteN->sig;
			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, p;
	cin >> n;

	if (!std::cin)
		return false;

	cin >> p; // pivote

	list_plus<int> lista;
	int e;
	for (int i = 0; i < n; i++) {
		cin >> e;
		lista.push_back(e);
	}

	lista.partition(p);

	// escribir sol
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		cout << (*it) << " ";
	}

	cout << endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}