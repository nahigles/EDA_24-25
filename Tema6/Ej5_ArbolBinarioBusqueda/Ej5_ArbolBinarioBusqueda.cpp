// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <fstream>
#include <climits>
#include <cmath>
#include "bintree_eda.h"
using namespace std;

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro todo el arbol)
bool arbolBinarioBusq(const bintree<int>& t, int& min, int& max) {
	if (!t.empty()) {

		// Si es hoja
		if (t.right().empty() && t.left().empty()) {
			min = t.root();
			max = min;
			return true;
		}
		else {
			int minIzq;
			int maxIzq;
			int minDer;
			int maxDer;

			// SI solo tiene derecho
			if (t.left().empty()) {

				bool der = arbolBinarioBusq(t.right(), minDer, maxDer);
				min = std::min(minDer, t.root());
				max = std::max(maxDer, t.root());

				return der && minDer > t.root();
			}
			// Si solo tiene izquierdo
			else if (t.right().empty()) {
				bool izq = arbolBinarioBusq(t.left(), minIzq, maxIzq);
				min = std::min(minIzq, t.root());
				max = std::max(maxIzq, t.root());

				return izq && maxIzq < t.root();
			}
			// Si tiene los dos
			else {

				bool izq = arbolBinarioBusq(t.left(), minIzq, maxIzq);
				bool der = arbolBinarioBusq(t.right(), minDer, maxDer);

				min = std::min(minIzq, minDer);
				min = std::min(min, t.root());

				max = std::max(maxIzq, maxDer);
				max = std::max(max, t.root());

				return izq && der && maxIzq < t.root() && minDer > t.root();
			}
		}
	}
	else
		return true;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arb;
	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
	int min, max;
	// Escribo salida
	cout << (arbolBinarioBusq(arb, min, max) ? "SI" : "NO") << endl;
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