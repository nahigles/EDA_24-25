// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


//template <class T>
//class queue_plus : public queue<T> {
//	using Nodo = typename queue<T>::Nodo;
//
//public:
//	void cuela(const T a, queue<T>& b) {
//
//		if (!this->empty()) {
//
//			// Avanza hasta encontrar al pringao
//			Nodo* aux = this->prim;
//			while (aux != nullptr && aux->elem != a)
//				aux = aux->sig;
//
//			// Si lo ha encontrado
//			if (aux != nullptr) {
//				Nodo* auxSig = aux->sig; // Siguiente a pringao
//				aux->sig = b.prim;
//				b.ult->sig = auxSig;
//
//				// Actualizo ult en caso de insertar al final
//				if (aux == this->ult) {
//					this->ult = b.ult;
//					this->ult->sig = nullptr;
//				}
//
//				// Sumo numero de elementos
//				this->nelems += b.nelems;
//
//				// Borro cola colegas
//				b.prim = nullptr;
//				b.ult = nullptr;
//				b.nelems = 0;
//			}
//		}
//	}
//};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// Leo datos de entrada

	// Guardo cola
	queue<int> cola;
	int e;
	cin >> e;
	while (e != -1) {
		cola.push(e);
		cin >> e;
	}

	// Elemento donde colar
	int pringao;
	cin >> pringao;

	// Guardo elemento a colar
	queue<int> colegas;
	cin >> e;
	while (e != -1) {
		colegas.push(e);
		cin >> e;
	}

	// Escribo cola sin cambios
	int n = cola.size();
	for (int i = 0; i < n; i++) {
		e = cola.front();
		cout << e << " ";
		cola.push(e);
		cola.pop();
	}
	cout << endl;

	// llamada a metodo
	cola.cuela(pringao, colegas);

	// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
	for (int i = 0; i < cola.size(); ++i) {
		e = cola.front();
		cola.pop();
		cola.push(e);
	}
	// Ahora imprimimos la cola y de paso la dejamos vacía
	while (!cola.empty()) {
		cout << cola.front() << " ";
		cola.pop();
	}
	cout << endl;
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