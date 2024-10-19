// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Calcula el numero de digitos que tiene n.
// Complejidad lineal -> O(m) siendo m el numero de digitos del numero
int numDigitos(long long n) {
	int cont = 0;

	while (n != 0) {
		n = n / 10;
		cont++;
	}

	return cont;
}

// Esta es la recursiva y la que escribe
void escribePoliAux(long long raiz, int maxDigitos, int digActual) {
	if (digActual <= maxDigitos) {
		long long cifra = raiz % 10;
		// Calculo nuevo numero que comprobar
		if (cifra == 9) {
			raiz = (raiz - 9) * 10;
			digActual++; // sumo la cantidad de digitos que hay
		}
		else
			raiz++;

		// Si es polidivisible escribo
		if (raiz % digActual == 0)
			cout << raiz << endl;

		// Llamada recursiva
		escribePoliAux(raiz, maxDigitos, digActual);

	}
}

// función que resuelve el problema
void escribePolidivisibles(long long raiz, int maxDigitos) {
	int nDigitos = numDigitos(raiz);
	cout << raiz << endl;
	escribePoliAux(raiz, maxDigitos, nDigitos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, d;
	cin >> n >> d;
	if (!cin) return false;

	escribePolidivisibles(n, d);

	// Escribe sol
	cout << "---" << endl;

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