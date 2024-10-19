// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>

// Las dos funciones tienen coste lineal, ya que tiene que recorrer cada cifra del número. Contra más cifras tenga el número más más aumenta el tiempo.
// T(n) --> O(n) siendo n el número de cifras
// función que resuelve el problema
int complementario(int num) {
	if ((num / 10) == 0) {
		return 9 - num;
	}
	else {
		int cifra = num % 10; // cifra de la derecha del todo
		return 10 * complementario(num / 10) + (9 - cifra);
	}
}

int complementarioInverso(int num, int& ac) {

	if ((num / 10) == 0) {
		ac++;
		return 9 - num;
	}
	else {
		int cifra = num % 10; // cifra de la derecha del todo
		int resultRecur = complementarioInverso(num / 10, ac);
		int result = (9 - cifra) * pow(10, ac) + resultRecur;
		ac++;
		return result;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	// leer datos
	int numero;
	std::cin >> numero;

	int sol = complementario(numero);

	int ac = 0;
	int sol2 = complementarioInverso(numero, ac);

	// escribir sol
	std::cout << sol << " " << sol2 << std::endl;
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
	system("PAUSE");
#endif

	return 0;
}