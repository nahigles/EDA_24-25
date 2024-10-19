// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Complejidad lineal, itera la misma cantidad que tenga el tamaño del vector -1
// T(n) --> O(n)
// función que resuelve el problema
void resolver(int& datos, int& dato2, std::vector<int>& nums) {
	bool asce = false, desc = false;

	// Si tiene minimo 2 numeros
	if (nums.size() > 2) {

		if (nums[0] < nums[1]) {
			asce = true;
			desc = false;
		}
		else if (nums[0] > nums[1]) {
			asce = false;
			desc = true;
		}
		else {
			asce = false;
			desc = false;
		}

		for (int i = 1; i < nums.size() - 1; ++i) {
			// si empieza ascendente
			if (asce && nums[i] > nums[i + 1]) {
				++datos;
				asce = false;
				desc = true;
			}
			// si empieza descendiente
			else if (desc && nums[i] < nums[i + 1]) {
				++dato2;
				asce = true;
				desc = false;
			}
			// si son iguales
			else {
				if (nums[i] < nums[i + 1]) {
					asce = true;
					desc = false;
				}
				else if (nums[i] > nums[i + 1]) {
					desc = true;
					asce = false;
				}
				else {
					desc = false;
					asce = false;
				}
			}
		}
	}
	// Si solo hay un número o dos no hay ni picos ni valles
	else {
		datos = 0;
		dato2 = 0;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {


	// leer datos
	int n;
	std::cin >> n;

	int j;
	std::vector<int> nums;

	for (int i = 0; i < n; ++i) {

		std::cin >> j;
		nums.push_back(j);
	}

	int dato1 = 0, dato2 = 0;
	resolver(dato1, dato2, nums);

	// escribir sol
	std::cout << dato1 << " " << dato2 << std::endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#define DOMJUDGE
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