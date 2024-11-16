// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct Info {
    int diametro;
    int altura;
};

// Complejidad lineal respecto al numero de nodos del arbol, O(n) siendo n numero de nodos(Recorro todo el arbol)
Info diametroArbol(const bintree<char>& t) {
    if (!t.empty()) {
        // Si es hoja
        if (t.right().empty() && t.left().empty())
            return { 1, 1 };
        else {
            Info info;

            Info izq = diametroArbol(t.left());
            Info der = diametroArbol(t.right());

            info.altura = std::max(izq.altura, der.altura) + 1;

            info.diametro = std::max(izq.diametro, der.diametro);
            info.diametro = std::max(info.diametro, (izq.altura + der.altura + 1));

            return info;
        }
    }
    else
        return { 0, 0 };
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.');

    // Escribo sol
    cout << diametroArbol(tree).diametro << endl;
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
