// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro todo el arbol)
template <class T>
bool simetricos(bintree<T> const& t1, bintree<T> const& t2) {
	// Si los dos estan vacios
	if (t1.empty() && t2.empty())
		return true;
	// Si uni esta vacio y el otro no
	else if (t1.empty() && !t2.empty() || !t1.empty() && t2.empty())
		return false;
	// Si el hijo izquierdo del arbol 1 esta vacio y el derecho del 2 no o viceversa
	else if ((t1.left().empty() && !t2.right().empty()) || (t1.right().empty() && !t2.left().empty()))
		return false;
	// Si ninguno esta vacio
	else {
		return (t1.root() == t2.root()) &&
			simetricos(t1.left(), t2.right()) &&
			simetricos(t1.right(), t2.left());
	}
}

template <class T>
bool simetrico(bintree<T> const& tree) {
	if (tree.empty())
		return true;
	else {
		return simetricos(tree.left(), tree.right());
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<char> tree;
	tree = leerArbol('.');
	cout << (simetrico(tree) ? "SI" : "NO") << endl;
}


//#define DOMJUDGE
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
	//system("PAUSE");
#endif

	return 0;
}