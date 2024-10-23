// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"

using namespace std;

// Complejidad O(k* i)
// n: nelems de set
// i: num elems del vector datos
// k: cantidad de numeros mas pequeños que se piden
// 
// función que resuelve el problema
Set<int> resolver(vector<int>& datos, int k) {
	Set<int>set(k);
	int i = 0;

	while (i < datos.size()) {
		// Añado los primeros k elementos diferentes
		if (i < k) {
			if (!set.contains(datos[i])) // O(log k)
				set.add(datos[i]); // O(k)
			else
				k++;
		}
		// Si alguno de los siguientes es menor lo añado
		else {
			if (datos[i] < set.getMax() && !set.contains(datos[i])) { // O(log k), no va a tener + de k elementos
				set.removeMax(); // O(1)
				set.add(datos[i]); // O(k), no va a tener + de k elementos
			}
		}
		i++;
	}

	return set;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int k, n;
	cin >> k >> n;
	if (k == 0)
		return false;

	vector<int>numsVec;

	while (n != -1) {
		numsVec.push_back(n);
		cin >> n;
	}


	Set<int> sol = resolver(numsVec, k);

	// escribir sol
	cout << sol << endl;

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
	system("PAUSE");
#endif

	return 0;
}
