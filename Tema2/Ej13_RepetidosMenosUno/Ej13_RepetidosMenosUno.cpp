// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// La complejidad de esta función es logaritmica en n que es la cantidad de elementos del vector v.
// Divide el problema a la mitad haciendo una llamada solo a la mitad del problema
// O(log n)

// función que resuelve el problema
int resolver(vector<int>& v, int ini, int fin) {
	int n = fin - ini;

	if (n == 1)
		return ini;
	else {
		int med = (ini + fin) / 2;

		if (v[med] != v[med - 1] && v[med] != v[med + 1])
			return med;
		else {
			// Si es impar
			if (med % 2) {
				if (v[med] == v[med - 1])
					return resolver(v, med + 1, fin);
				else
					return resolver(v, ini, med);
			}
			// Par
			else {
				if (v[med] == v[med - 1])
					return resolver(v, ini, med - 1);
				else
					return resolver(v, med + 2, fin);
			}
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	vector<int> v(n);
	for (int& e : v) cin >> e;

	// Llamada a la función resolver
	int sol = resolver(v, 0, n);

	// Mostrar el resultado
	cout << sol << endl;
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