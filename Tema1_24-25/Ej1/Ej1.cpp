// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

// Complejidad lineal, itera la misma cantidad que tenga el tamaño del vector -1
// función que resuelve el problema
std::string resolver(std::vector<int>& datos) {

	bool ascen;
	bool dalton = true;
	if (datos[0] < datos[1]) ascen = true;
	else ascen = false;

	int i = 0;
	while (dalton && i < datos.size() - 1) {

		if (((ascen && (datos[i] >= datos[i + 1])))) {
			dalton = false;
		}
		else if ((!ascen && (datos[i] <= datos[i + 1])))
			dalton = false;

		++i;
	}

	if (dalton)
		return "DALTON";
	else
		return "DESCONOCIDOS";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	if (n == 0)
		return false;

	int j;
	std::vector<int> nums;

	for (int i = 0; i < n; ++i) {

		std::cin >> j;
		nums.push_back(j);
	}

	std::string sol = resolver(nums);

	// escribir sol
	std::cout << sol << std::endl;

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