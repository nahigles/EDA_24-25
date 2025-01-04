// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;


template <class T>
class list_plus : public list<T> {
	using Nodo = typename list<T>::Nodo;

public:
	// Complejidad lineal en n, siendo n el numero de elementos de la lista. Como mucho tendra que hacer n iteraciones para colocar el nodo auxiliar mas aavanzado, nunca recorre mas que n.
	void adelantar(int pos, int length, int newPos) {

		if (!(this->nelems == 0 || length == 0 || pos == newPos || newPos < 0 || pos >= this->nelems)) {

			// Nodos auxiliares
			Nodo* iniSegment = this->fantasma;
			Nodo* finSegment;
			Nodo* newPosIni = this->fantasma;
			Nodo* newPosFin;

			// - POSICIONO NODOS AUXILIARES -
			// Nodo auxiliar al inicio del segmento
			for (int i = 0; i <= pos; ++i) // O(pos)
				iniSegment = iniSegment->sig;

			// Si el segmento se sale de la lista
			if ((pos + length) > this->nelems)
				length = this->nelems - pos;

			// Nodo auxiliar al final del segmento
			finSegment = iniSegment;
			for (int i = 1; i < length; ++i) // O(length)
				finSegment = finSegment->sig;
			// Nodo auxiliar al inicio de la nueva posicion
			for (int i = 1; i <= newPos; ++i) // O(newPos)
				newPosIni = newPosIni->sig;

			// Nodo auxiliar al final de la nueva posicion (1 mas)
			newPosFin = newPosIni->sig;

			// - QUITO SEGMENTO DE LA LISTA -
			iniSegment->ant->sig = finSegment->sig;
			finSegment->sig->ant = iniSegment->ant;

			// - INSERTO SEGMENTO EN LA LISTA -
			newPosIni->sig = iniSegment;
			iniSegment->ant = newPosIni;
			finSegment->sig = newPosFin;
			newPosFin->ant = finSegment;
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	char e;
	int n, pos, length, dif;
	list_plus<char> l;

	// leer los datos de la entrada
	cin >> n >> pos >> length >> dif;
	for (int i = 1; i <= n; ++i) {
		cin >> e;
		l.push_back(e);
	}

	l.adelantar(pos, length, pos - dif);

	// Le damos una vuelta para comprobar que la lista está bien formada
	for (int i = 0; i < l.size(); ++i) {
		e = l.back();
		l.pop_back();
		l.push_front(e);
	}

	// Ahora imprimimos la lista y de paso la dejamos vacía (tb para probar su consistencia)
	while (!l.empty()) {
		cout << l.front() << " ";
		l.pop_front();
	}
	cout << endl;
}


//#define DOMJUDGE
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
	//system("PAUSE");
#endif

	return 0;
}
