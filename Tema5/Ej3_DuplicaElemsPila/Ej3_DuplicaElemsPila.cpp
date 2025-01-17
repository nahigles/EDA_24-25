// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "LinkedListStack.h"
using namespace std;

// Complejidad lineal en n, n= nelems de la pila s
// T(n*2) --> O(n*2) --> O(n)
// función externa que resuelve el problema sobre stack
void duplicar(stack<int>& s) {
	stack<int>aux;
	int nElems = s.size();

	// Añado elementos a unu auxiliar
	for (int i = 0; i < nElems; i++) { // O(n), n = nelems de s
		aux.push(s.top());
		s.pop();
	}

	 // Para despuues volverlo a meter pero dos veces
	for (int i = 0; i < nElems; i++) { /// O(n), n = nelems de s
		s.push(aux.top());
		s.push(aux.top());
		aux.pop();
	}
}

// Clase extendida con operación interna duplicar que reaprovecha nodos existentes
template <class T>
class LinkedListStack_plus : public LinkedListStack<T> {
	using Nodo = typename LinkedListStack<T>::Nodo;

public:
	// Complejidad lineal en n, n= nelems de la pila
	// T(n) --> O(n)
	void duplicar() {
		Nodo* aux = this->cima;

		while (aux != nullptr) {
			aux->sig = new Nodo(aux->elem, aux->sig);
			this->nelems++;
			aux = aux->sig->sig;
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int e;
	//stack<int> s;
	LinkedListStack_plus<int> s;
	cin >> e;
	if (!cin) return false;
	while (e != 0) {
		s.push(e);
		cin >> e;
	}
	//duplicar(s);
	s.duplicar();

	// Ahora imprimimos la pila de cima a base y de paso la dejamos vacía
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
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
	//system("PAUSE");
#endif

	return 0;
}