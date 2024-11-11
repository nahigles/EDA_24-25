// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// Todos los métodos son de complejidad lineal ya que recorren todoo el arbol entero.
// Es decir O(n), siendo n el numero de nodos del arbol

template <class T>
int nodos(bintree<T> const& tree) {
	if (!tree.empty()) {
		if (tree.right().empty() && tree.left().empty()) {
			return 1;
		}
		else
			return nodos(tree.left()) + nodos(tree.right()) + 1;
	}
	else
		return 0;
}

template <class T>
int hojas(bintree<T> const& tree) {
	if (!tree.empty()) {
		if (tree.right().empty() && tree.left().empty()) {
			return 1;
		}
		else
			return hojas(tree.left()) + hojas(tree.right());
	}
	else
		return 0;
}

template <class T>
void alturaAux(bintree<T> const& tree, int ac, int& maxHeight) {

	if (ac > maxHeight)
		maxHeight = ac;

	if (!tree.empty()) {

		alturaAux(tree.left(), ac + 1, maxHeight);
		alturaAux(tree.right(), ac + 1, maxHeight);
	}
}

template <class T>
int altura(bintree<T> const& tree) {
	int maxH = 0;

	alturaAux(tree, 0, maxH);

	return maxH;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<char> tree;
    tree = leerArbol('.');
    cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << endl;
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
    //system("PAUSE");
#endif

    return 0;
}
