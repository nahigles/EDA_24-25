// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

using Diccionario = map<string, int>;

struct ActualizacionDiccionarios {
	vector<string> anadidas;
	vector<string> quitadas;
	vector<string> cambiadas;
};

void comparaDiccionarios(Diccionario& dicAntiguo, Diccionario& dicNuevo, ActualizacionDiccionarios& actualizado) {
	auto itAnt = dicAntiguo.begin();
	auto itNuev = dicNuevo.begin();

	while (itAnt != dicAntiguo.end() && itNuev != dicNuevo.end()) {
		// Si las claves son iguales
		if ((*itAnt).first == (*itNuev).first) {

			// Si los valores son distintos se guarda en cambios
			if ((*itAnt).second != (*itNuev).second) {
				actualizado.cambiadas.push_back((*itAnt).first);
			}

			++itAnt;
			++itNuev;
		}
		// Si se quita en el antiguo
		else if ((*itAnt).first < (*itNuev).first) {
			actualizado.quitadas.push_back((*itAnt).first);
			++itAnt;
		}
		// Anadido en el nuevo
		else {
			actualizado.anadidas.push_back((*itNuev).first);
			++itNuev;
		}
	}


	// SI queda alguno en el antiguo se han quitado
	while (itAnt != dicAntiguo.end()) {
		actualizado.quitadas.push_back((*itAnt).first);
		++itAnt;
	}

	// Si queda alguno en el nuevo se han anadido
	while (itNuev != dicNuevo.end()) {
		actualizado.anadidas.push_back((*itNuev).first);
		++itNuev;
	}

}

void leerDiccionario(Diccionario& diccionario) {
	char c;
	string clave;
	int valor;
	cin.get(c);
	while (c != '\n') {
		cin.unget();
		cin >> clave >> valor;
		diccionario[clave] = valor;
		cin.get(c);
	}
}

void resuelveCaso() {
	Diccionario antiguo;
	Diccionario nuevo;
	leerDiccionario(antiguo);
	leerDiccionario(nuevo);

	// Soluicion ejercicio
	ActualizacionDiccionarios sol;
	comparaDiccionarios(antiguo, nuevo, sol);

	// Escribir
	if (sol.anadidas.empty() && sol.cambiadas.empty() && sol.quitadas.empty())
		cout << "Sin cambios" << endl;
	else {
		if (!sol.anadidas.empty()) {
			cout << "+";
			for (auto it = sol.anadidas.begin(); it != sol.anadidas.end(); ++it) {
				cout << " " << (*it);
			}
			cout << endl;
		}

		if (!sol.quitadas.empty()) {
			cout << "-";
			for (auto it = sol.quitadas.begin(); it != sol.quitadas.end(); ++it) {
				cout << " " << (*it);
			}
			cout << endl;
		}

		if (!sol.cambiadas.empty()) {
			cout << "*";
			for (auto it = sol.cambiadas.begin(); it != sol.cambiadas.end(); ++it) {
				cout << " " << (*it);
			}
			cout << endl;
		}
	}

	cout << "---" << endl;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos; char c;
	std::cin >> numCasos;
	cin.get(c);
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
