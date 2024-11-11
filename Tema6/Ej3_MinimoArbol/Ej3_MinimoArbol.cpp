// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro todo el arbol)
template <class T>
T minimo(bintree<T> const& tree) {

	// Si es hoja
	if (tree.left().empty() && tree.right().empty()) {
		return tree.root();
	}
	// Si izquierdo vacio
	else if (tree.left().empty()) {
		// llama derecho
		T derMin = minimo(tree.right());
		return std::min(derMin, tree.root());
	}
	// Si derecho vacio
	else if (tree.right().empty()) {
		// llama izquierdo
		T izqMin = minimo(tree.left());
		return std::min(izqMin, tree.root());
	}
	// si tiene los dos
	else {
		T izqMin = minimo(tree.left());
		T derMin = minimo(tree.right());

		T mini = std::min(izqMin, derMin);

		return std::min(mini, tree.root());
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char tipo;
	cin >> tipo;
	if (!cin) return false;
	if (tipo == 'N') {
		bintree<int> tree = leerArbol(int(-1));
		cout << minimo(tree) << endl;
	}
	else if (tipo == 'P') {
		bintree<string> tree = leerArbol(string("#"));
		cout << minimo(tree) << endl;
	}
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
