// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

using namespace std;

template <class T>
class queue_plus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:
	// Complejidad lineal en n, siendo n el numero de elementos de la cola
	// T(n) --> O(n)
	// En el caso peor recorre toda la cola en caso de que el elemento b no este y el elemento a si
	void cuela(const T& a, const T& b) {
		// Busco a
		Nodo* aNodo = this->prim;
		while (aNodo != this->ult && aNodo->elem != a) {
			aNodo = aNodo->sig;
		}

		// Si hemos encontrado a y no es el ultimo elemento
		if (aNodo->elem == a && aNodo != this->ult) {
			// Nodo auxiliar al siguiente de a
			Nodo* aNodoSig = aNodo->sig;

			// Nodo auxiliar al anterior de b
			Nodo* bNodoAnt = aNodo;

			// Busco b
			Nodo* bNodo = aNodoSig;
			while (bNodo != nullptr && bNodo->elem != b) {
				bNodo = bNodo->sig;
				bNodoAnt = bNodoAnt->sig;
			}

			// Si hemos encontrado b y no esta ya colocado
			if (bNodo != nullptr && aNodoSig != bNodo) {

				// Saco b de su posicion
				bNodoAnt->sig = bNodo->sig;

				// Si b es el ultimo elemento de la cola actualizo el ultimo
				if (bNodo == this->ult)
					this->ult = bNodoAnt;

				// Meto b detras de a
				aNodo->sig = bNodo;
				bNodo->sig = aNodoSig;

			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer datos
	int n, a, b;
	queue_plus<int> q;
	cin >> n;
	if (n == -1) return false;
	while (n != -1) {
		q.push(n);
		cin >> n;
	}
	cin >> a >> b;

	// llamada a metodo
	q.cuela(a, b);

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
