// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <cmath>
using namespace std;

struct Grupo
{
	string lider;
	int numEnanos;
};

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro en postorden todo el arbol)
Grupo avanzaEnanos(const bintree<string>& t) {
	if (!t.empty()) {

		// si es hoja
		if (t.right().empty() && t.left().empty()) {
			return { t.root(),1}; // num enanos 1 siempre en hojas
		}
		else {

			Grupo izq = avanzaEnanos(t.left());
			Grupo der = avanzaEnanos(t.right());

			// Guardo nuevo num de enanos
			Grupo newGrupo = { "", izq.numEnanos + der.numEnanos };

			// Guardo nuevo lider
			if (izq.numEnanos > der.numEnanos)
				newGrupo.lider = izq.lider;
			else if (izq.numEnanos < der.numEnanos)
				newGrupo.lider = der.lider;
			else
				newGrupo.lider = std::min(izq.lider, der.lider);

			if (t.root() == "Orcos")
				newGrupo.numEnanos = newGrupo.numEnanos / 2;

			return newGrupo;
		}
	}
	else
		return { "Ninguno",0};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<string> arb;
	arb = leerArbol(string(".")); // . es la repr. de arbol vacio
	Grupo sol = avanzaEnanos(arb);

	// Escribo salida
	if (sol.numEnanos)
		cout << sol.lider << " " << sol.numEnanos << endl;
	else
		cout << "Ninguno" << endl;
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