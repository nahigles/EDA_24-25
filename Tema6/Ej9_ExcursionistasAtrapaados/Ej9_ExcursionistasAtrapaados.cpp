// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct Rio
{
    int numTramosNavegables;
    int caudal;
};

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro en postorden todo el arbol)
Rio cuentaTramosNav(const bintree<int>& t) {
    if (!t.empty()) {

        // si es hoja
        if (t.right().empty() && t.left().empty()) {
            return { 0,1 }; // Caudal 1 siempre en hojas
        }
        else {

            Rio izq = cuentaTramosNav(t.left());
            Rio der = cuentaTramosNav(t.right());

            if (izq.caudal >= 3)
                izq.numTramosNavegables += 1;
            if (der.caudal >= 3)
                der.numTramosNavegables += 1;

            // Caudal resto lo que haya en el root
            int raiz = t.root();
            int newCaudal = izq.caudal + der.caudal - raiz;
            if (newCaudal < 0)
                newCaudal = 0;
            return { izq.numTramosNavegables + der.numTramosNavegables, newCaudal };
        }
    }
    else
        return { 0,0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arb;
    arb = leerArbol(-1); // -1 es la repr. de arbol vacio
    int sol = cuentaTramosNav(arb).numTramosNavegables;

    // Escribo salida
    cout << sol << endl;
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
    //system("PAUSE");
#endif

    return 0;
}