// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// La complejidad de esta función es logaritmica en n que es la cantidad de elementos del vector v1.
// Divide el problema a la mitad haciendo una llamada solo a la mitad del problema
// O(log n)

// función que resuelve el problema
int resolver(vector<int> const& v1, vector<int> const& v2, int ini, int fin) {
    int n = fin - ini;

    // Si hay un elem
    if (n == 0)
        return ini;
    else {
        int med = (ini + fin) / 2;
        if (v1[med] == v2[med])
            return resolver(v1, v2, med + 1, fin);
        else
            return resolver(v1, v2, ini, med);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int numElementos;
    cin >> numElementos;
    vector<int> v1(numElementos);
    vector<int> v2(numElementos - 1);
    for (int& e : v1) cin >> e;
    for (int& e : v2) cin >> e;
    int sol = resolver(v1, v2, 0, v1.size() - 1);
    cout << v1[sol] << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("input2.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
#endif

    return 0;
}
