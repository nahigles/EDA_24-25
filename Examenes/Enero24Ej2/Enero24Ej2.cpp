// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct Info {
	bool encontrado;
	int n1;
	int n2;
};

// La complejidad de esta función es logaritmica en n siendo n la cantidad de elementos del vector v1 y v2.
// Divide el problema a la mitad haciendo una llamada solo a la mitad del problema
// O(log n)
Info cruceLineas(const vector<int>& v1, const vector<int>& v2, int ini, int fin) {

	int n = fin - ini;

	// Si hay 1 elemento
	if (n == 1) {
		// Si lo encuentra
		if (v1[ini] == v2[ini])
			return { true,ini,ini };

		// v1 menor, esta a la derecha
		else if (v1[ini] < v2[ini])
			return { false, ini,ini + 1 };

		// v1 mayor, esta a la izquierda
		else
			return { false, ini - 1,ini };

	}
	else {
		int med = (ini + fin) / 2;

		// v1 menor o iguales, esta a la derecha
		if (v1[med] <= v2[med])
			return cruceLineas(v1, v2, med, fin);
		// v1 mayor, esta a la izquierda
		else
			return cruceLineas(v1, v2, ini, med);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;

	if (n == 0)
		return false;

	std::vector<int> v1(n);
	for (int& e : v1) cin >> e;

	std::vector<int> v2(n);
	for (int& e : v2) cin >> e;

	Info sol = cruceLineas(v1, v2, 0, n);

	// escribir sol
	if (sol.encontrado) {
		cout << "SI " << sol.n1 << endl;
	}
	else {
		cout << "NO " << sol.n1 << " " << sol.n2 << endl;
	}

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
