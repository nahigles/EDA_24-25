// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
using namespace std;

// Complejidad lineal, itera la misma cantidad que tenga el tamaño de los strings, contra mas grande sean los strings mas tarda
// n siendo el tamaño de la primera palabra y m de la segunda palabra
// T(n + m) --> O(n + m)

bool anagramas(const string& cad1, const string& cad2) {

	if (cad1.size() == cad2.size())
	{
		bool anagrama = true;
		array<int, 26> abcedario;
		for (int i = 0; i < 26; i++) { abcedario[i] = 0; } // inicializacion a 0

		for (int j = 0; j < cad1.length(); j++) {
			int letraArray = cad1[j] - 97; // Unicode de 'a' --> 97
			abcedario[letraArray]++;
		}
		for (int k = 0; k < cad2.length(); k++) {
			int letraArray = cad2[k] - 97; //Unicode de 'a' --> 97
			abcedario[letraArray]--;
		}
		for (int l = 0; l < 26 && anagrama; l++) { //O(26) == O(1)
			if (abcedario[l] != 0) anagrama = false; //O(1)
		}
		return anagrama;
	}
	else
		return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	string word1, word2;
	cin >> word1 >> word2;
	cout << (anagramas(word1, word2) ? "SI" : "NO") << endl;
}

//#define DOMJUDGE
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
	//system("PAUSE");
#endif

	return 0;
}