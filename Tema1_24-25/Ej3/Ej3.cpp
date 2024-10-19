// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

// Complejidad lineal, recorre el vector
// T(n) --> O(n), siendo n el numero de elementos del vector nums
// función que resuelve el problema
bool resolver(vector<int>& nums, int pos) {

	int maxIzq = INT_MIN;

	int i = 0;
	// Busco maximo en la parte izquierda
	for (; i <= pos; i++) {
		if (nums[i] > maxIzq)
			maxIzq = nums[i];
	}

	bool yes = true;
	// Miro si el maximo de la izquierda es menor que todos
	while (i < nums.size() && yes) {
		if (maxIzq >= nums[i])
			yes = false;

		i++;
	}

	return yes;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElems, pos, numero;
	cin >> numElems >> pos;
	vector<int> nums;
	for (int i = 0; i < numElems; i++) { // O(n)
		cin >> numero;
		nums.push_back(numero);
	}

	// escribir sol
	cout << (resolver(nums, pos) ? "SI" : "NO") << endl;
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