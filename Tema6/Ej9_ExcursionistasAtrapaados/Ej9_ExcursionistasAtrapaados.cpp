// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <fstream>
#include <cmath>
#include "bintree_eda.h"
using namespace std;

struct Rescate
{
	int numGrupos;
	int numRescatados;
};

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro en postorden todo el arbol)
Rescate rescate(const bintree<int>& t) {

	// Si es vacio
	if (!t.empty()) {
		// Si es hoja
		if (t.right().empty() && t.left().empty()) {
			// Si no es 0
			if (t.root())
				return { 1,t.root() };
			else
				return { 0,0 };
		}
		else {
			Rescate izq = rescate(t.left());
			Rescate der = rescate(t.right());
			Rescate total;
			// Si no es 0
			if (t.root()) {
				// Si ninguno de los hijos tiene grupo de rescate(Si son 0 los dos)
				if (izq.numGrupos == 0 && der.numGrupos == 0) {
					total.numGrupos = 1;
					total.numRescatados = t.root();
				}
				else {
					total.numGrupos = izq.numGrupos + der.numGrupos;
					total.numRescatados = std::max(izq.numRescatados, der.numRescatados) + t.root();
				}
			}
			else {
				total.numGrupos = izq.numGrupos + der.numGrupos;
				total.numRescatados = std::max(izq.numRescatados, der.numRescatados);
			}

			return total;
		}
	}
	else
		return { 0,0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arb;
	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
	Rescate sol = rescate(arb);

	// Escribo salida
	cout << sol.numGrupos << " " << sol.numRescatados << endl;
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