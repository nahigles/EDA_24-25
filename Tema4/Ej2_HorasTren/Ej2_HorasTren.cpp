// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Horas.h"
#include <stdexcept>
#include <ostream>

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nTrenes, nConsultas;
	cin >> nTrenes >> nConsultas;

	if (nTrenes == 0 && nConsultas == 0)
		return false;
	Horas trenes;
	string line;
	for (int i = 0; i < nTrenes; i++) {
		trenes.leerHora();
	}

	for (int i = 0; i < nConsultas; i++) {
		Tiempo t;
		char c;
		cin >> t.horas >> c >> t.minutos >> c >> t.segundos;
		try
		{
			trenes.consultar(t);
		}
		catch (exception& e)
		{
			cout << "ERROR" << endl;;
		}
	}

	// escribir sol
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
	system("PAUSE");
#endif

	return 0;
}
