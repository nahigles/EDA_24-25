// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// La complejidad de esta función es logaritmica en n siendo n la cantidad de elementos del vector sec.
// Divide el problema a la mitad haciendo una llamada solo a la mitad del problema
// O(log n)
// función que resuelve el problema
bool resolver(const vector<int>& sec, int ini, int fin,const int num) {
	int n = fin - ini;
	if (n == 0)
		return false;
	else if (n == 1)
		return (sec[ini] == num);
	else {
		int med = (ini + fin) / 2;

		// parte izq sin rotar
		if (sec[ini] < sec[med]) {
			// Si esta en el cacho ordenado
			if (sec[ini] <= num && num < sec[med])
				return resolver(sec, ini, med, num);
			else
				return resolver(sec, med, fin, num);
		}
		// Parte derecha sin rotar
		else {
			if (sec[med] <= num && num <= sec[fin - 1])
				return resolver(sec, med, fin, num);
			else
				return resolver(sec, ini, med, num);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n == -1) return false;
	int num;
	cin >> num;
	vector<int> sec(n);
	for (int& e : sec) cin >> e;
	cout << (resolver(sec, 0, n, num) ? "SI" : "NO") << endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
//#define DOMJUDGE
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