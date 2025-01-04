// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// La complejidad de esta función es logaritmica en n que es la cantidad de elementos del vector v.
// Divide el problema a la mitad haciendo una llamada solo a la mitad del problema
// O(log n)

// función que resuelve el problema
int ultimoConsecutivo(vector<int> const& v, int ini, int fin) {
    int n = fin - ini;

    if (n == 1)
        return v[ini];
    else {
        int med = (ini + fin) / 2;

        // Si el del medio esta colocado bien en orden
        if ((v[med] - v[0]) == med)
            return ultimoConsecutivo(v, med, fin);
        else
            return ultimoConsecutivo(v, ini, med);

    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int numElementos;
    cin >> numElementos;
    vector<int> v(numElementos);
    for (int& e : v) cin >> e;
    int sol = ultimoConsecutivo(v, 0, numElementos);
    cout << sol << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos.txt");
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
