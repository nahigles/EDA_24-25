// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Set1.h"

int sumaCifrasCuadradas(int n) {
	int newNumber = 0;

	while (n != 0) { // O(n) siendo n numero de cifras del numero
		int cifra = n % 10;
		newNumber += pow(cifra, 2);
		n = n / 10;
	}

	return newNumber;
}

// O((n+m)*i) siendo i el numero de iteraciones que hace hasta salir 1 o un numero repetido 
// función que resuelve el problema
bool felices(int n, Set1<int>& s) {

	while (n != 1 && !s.contains(n)) { // O(m) siendo m la cantidad de elementos que hay en s
		s.add(n);
		n = sumaCifrasCuadradas(n); // O(n)
	}

	s.add(n);
	return n == 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;

	if (!std::cin)
		return false;

	Set1<int> set;
	bool sol = felices(n, set);

	// escribir sol
	cout << set << " " << sol << endl;

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