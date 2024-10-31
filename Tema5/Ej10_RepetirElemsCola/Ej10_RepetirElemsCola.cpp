// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
#include <vector>
using namespace std;

template <class T>
class queue_plus : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:
	void replicaElems(vector<int> const& mult) {
		Nodo* ant = nullptr;
		Nodo* aux = this->prim;

		int i = 0;
		while (i < mult.size()) {

			// Si es el primer elemento de la cola
			if (aux == this->prim) {

				// Si es 0
				if (!mult[i]) {
					// Borro
					this->prim = this->prim->sig;
					if (this->prim == nullptr) // si la cola se ha quedado vacía
						this->ult = nullptr;
					delete aux;
					aux = this->prim;
					--this->nelems;

				}
				else {
					for (int j = 1; j < mult[i]; j++) {
						aux->sig = new Nodo(aux->elem, aux->sig);
						aux = aux->sig;
						++this->nelems;
					}
					ant = aux;
					aux = aux->sig;

					if (this->ult->sig != nullptr)
						this->ult = ant;
				}
			}
			// Si no es el primer elemento de la cola
			else {
				// Si es 0
				if (!mult[i]) {
					ant->sig = aux->sig;
					delete aux;
					aux = ant->sig;
					--this->nelems;

					if (aux == nullptr)
						this->ult = ant;
				}
				else {

					ant = ant->sig;
					aux = aux->sig;
					for (int j = 1; j < mult[i]; j++) {
						ant->sig = new Nodo(ant->elem, aux);
						ant = ant->sig;
						++this->nelems;
					}

					if (this->ult->sig != nullptr)
						this->ult = ant;

				}
			}

			i++;
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	queue_plus<int> q;

	cin >> n;
	vector<int> mult(n);
	vector<int> aux(n); // Para darle la vuelta a la secuencia de entrada

	// Leemos la secuencia invertida para q y le damos la vuelta
	for (int i = n - 1; i >= 0; --i) cin >> aux[i];
	for (int e : aux) q.push(e);

	// Leemos la secuencia invertida para mult
	for (int i = n - 1; i >= 0; --i) cin >> mult[i];

	// llamada al metodo
	q.replicaElems(mult);

	// escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
	for (int i = 0; i < q.size(); ++i) {
		n = q.front();
		q.pop();
		q.push(n);
	}

	// Ahora imprimimos la cola y de paso la dejamos vacía (tb para probar su consistencia)
	cout << "[";
	if (!q.empty()) {
		cout << q.front();
		q.pop();
	}
	while (!q.empty()) {
		cout << ", " << q.front();
		q.pop();
	}
	cout << "]" << endl;
	return true;
}

//#define DOMJUDGE
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("input1.txt");
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
