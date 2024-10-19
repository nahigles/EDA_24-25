// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;
// La funcion tiene coste lineal, ya que tiene que recorrer el vector entero en caso peor. Contra más numeros tenga el vector el tiempo aumenta linealmente.
// T(n) --> O(n) siendo n el número de elementos del vector v
// función que resuelve el problema
bool suficientementeDisperso(vector<int>& v, int ini, int fin, int k) {
	int n = fin - ini;
	if (n == 0 || n == 1)
		return true;
	else {
		int med = (ini + fin) / 2;

		return abs(v[fin - 1] - v[ini]) >= k && suficientementeDisperso(v, ini, med, k) && suficientementeDisperso(v, med, fin, k);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, k;
	cin >> n >> k;
	if (!std::cin)
		return false;

	vector<int> sec(n);
	for (int& e : sec) cin >> e;

	// escribir sol
	cout << (suficientementeDisperso(sec, 0, n, k) ? "SI" : "NO") << endl;

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
	system("PAUSE");
#endif

	return 0;
}