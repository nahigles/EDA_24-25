// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Creo que esto seria complejidad cuadratica y esta mal

bool anagramas(const string& cad1, const string& cad2) {

	if (cad1.size() != cad2.size()) return false; // Si son de tamaynos distintos no pueden ser anagramas

	int i = 0;
	vector<char> letras;

	for (; i < cad1.size(); i++) letras.push_back(cad1[i]); // Meto las letras que contiene cad1

	i = 0;
	int j = 0;
	while (j < cad2.size() && i < letras.size()) {
		if (letras[i] != cad2[j]) {
			i++;
		}
		else { // Le voy quitando las letras que tiene cad2
			j++;
			letras.erase(letras.begin() + i);
			i = 0;
		}
	}

	return letras.empty(); // Si el vector esta vacio significa que contienen las mismas letras
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