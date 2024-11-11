// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <fstream>
#include <climits>
#include <cmath>
#include "bintree_eda.h"
using namespace std;

struct Info
{
	int num;
	int altura;
};

bool esPrimo(int numero) {
	bool primo = true;

	for (int i = 2; i <= sqrt(numero) && primo; ++i) {
		if (numero % i == 0) primo = false;
	}

	return primo;
}

bool esMultiplo7(int numero) {
	return numero % 7 == 0;
}

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro todo el arbol)
Info barreraPrimos(const bintree<int>& t, int altAct) {
	if (!t.empty()) {

		// Si es primo
		if (esPrimo(t.root())) {
			return { 0, INT_MAX };
		}
		else {
			// Si es multiplo de 7 no sigue mirando
			if (esMultiplo7(t.root()))
				return { t.root(), altAct };
			else {
				Info infIzq = barreraPrimos(t.left(), altAct + 1);
				Info infDer = barreraPrimos(t.right(), altAct + 1);

				if (infIzq.altura <= infDer.altura)
					return infIzq;
				else
					return infDer;
			}
		}
	}
	else
		return { 0,INT_MAX };
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arb;
	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
	Info sol = barreraPrimos(arb, 1);

	// Escribo salida
	// Si lo ha encontrado
	if (sol.num)
		cout << sol.num << " " << sol.altura;
	else
		cout << "NO HAY";

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
	//system("PAUSE");
#endif

	return 0;
}