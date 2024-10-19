// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Polinomio.h"

using namespace std;

// función que resuelve el problema
int resolver(Polinomio& p, int n) {

	return p.calcula(n);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int coef, exp;

	cin >> coef >> exp;

	if (!std::cin)
		return false;

	Polinomio poli;

	// Mienstras no sean 0
	while (!(coef == 0 && exp == 0)) {
		poli.addMonomio(coef, exp);
		cin >> coef >> exp;
	}

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		cout << resolver(poli, num);

		if (!(i == n - 1))
			cout << " ";
		else
			cout << endl;
	}

	// escribir sol


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