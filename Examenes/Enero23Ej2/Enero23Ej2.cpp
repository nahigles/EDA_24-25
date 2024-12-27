// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct InfoCamino {
	int numDragones;
	int camino;
};

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro todo el arbol)
template <class T>
InfoCamino caminoMenosDragones(bintree<T> const& tree) {
	// Si esta vacio
	if (tree.empty()) {
		return { INT_MAX,0 };
	}
	// Si es una hoja
	else if (tree.right().empty() && tree.left().empty()) {
		return { 0,tree.root() };
	}
	else {
		InfoCamino izq = caminoMenosDragones(tree.left());
		InfoCamino der = caminoMenosDragones(tree.right());

		InfoCamino sol = { 0,0 };

		if (izq.numDragones <= der.numDragones) {
			sol = izq;
		}
		else {
			sol = der;
		}

		// Si hay dragon sumo dragon
		if (tree.root() == 1)
			sol.numDragones++;

		return sol;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	cout << caminoMenosDragones(tree).camino << endl;
}


//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("input2.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}