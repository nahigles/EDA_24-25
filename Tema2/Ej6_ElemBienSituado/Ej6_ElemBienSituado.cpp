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

// función que resuelve el problema
bool resolver(const vector<int>& v, int ini, int fin) {
    int n = fin - ini;
    if (n == 0)
        return false;
    else if (n == 1)
        return v[ini] == ini;
    else {
        int med = (ini + fin) / 2;

        if (med < v[med])
            return resolver(v, ini, med);
        else
            return resolver(v, med, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << (resolver(sec, 0, n) ? "SI" : "NO") << endl;
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
