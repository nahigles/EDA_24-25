// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// La complejidad de esta función es logaritmica en n que es la cantidad de elementos del vector.
// Divide el problema a la mitad haciendo una llamada solo a la mitad del problema
// O(log n)
// función que resuelve el problema
int minimoVector(const vector<int>& v, int ini, int fin) {
	int n = fin - ini;

	if (n == 1) {
		return v[ini];
	}
	else {
		int med = (ini + fin) / 2;

		if (v[med] < v[ini])
			return minimoVector(v, med, fin);
		else
			return minimoVector(v, ini, med);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!cin) return false;
	vector<int> sec(n);
	for (int& e : sec) cin >> e;
	cout << minimoVector(sec, 0, n) << endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}