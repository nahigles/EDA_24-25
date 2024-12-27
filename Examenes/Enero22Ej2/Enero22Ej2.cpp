// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro todo el arbol)
template <class T>
int singularesAux(bintree<T> const& tree, int acumArriba, int& acumAbajo) {
	if (tree.empty())
	{
		acumAbajo = 0;
		return 0;
	}
	else {
		acumArriba = (acumArriba + tree.root());
		int acumAbajoIzq, acumAbajoDer;
		int numSing = singularesAux(tree.left(), acumArriba, acumAbajoIzq) + singularesAux(tree.right(), acumArriba, acumAbajoDer);
		acumAbajo = acumAbajoIzq + acumAbajoDer + tree.root();
		if (acumArriba == acumAbajo)
			numSing++;

		return numSing;
	}
}

template <class T>
int caminoMenosDragones(bintree<T> const& tree) {
	int abajo = 0;
	return singularesAux(tree, 0, abajo);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> tree;
	tree = leerArbol(-1);
	cout << caminoMenosDragones(tree) << endl;
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