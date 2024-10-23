// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;
// TENGO Q CAMBIAR TODO Q ESTO ES SOLO COPIADO DEL ANTERIOR EJ DE COLAS

template <class T>
class queue_plus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:
	// Complejidad lineal en n, n= nelems de la pila
	// T(n) --> O(n)
	void duplica() {

		if (this->nelems > 0) {

			Nodo* aux = this->prim;

			while (aux != nullptr) {
				aux->sig = new Nodo(aux->elem, aux->sig);
				this->nelems++;
				aux = aux->sig->sig;
			}

			this->ult = this->ult->sig;
		}

	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	queue_plus<int> q;
	cin >> n;
	if (!cin) return false;
	while (n != 0) {
		q.push(n);
		cin >> n;
	}

	// llamada a metodo
	q.duplica();

	// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
	for (int i = 0; i < q.size(); ++i) {
		n = q.front();
		q.pop();
		q.push(n);
	}
	// Ahora imprimimos la cola y de paso la dejamos vacía
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return true;
}

//#define DOMJUDGE
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
	//system("PAUSE");
#endif

	return 0;
}