// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// La complejidad de esta función es logaritmica en n que es la cantidad de elementos del vector.
// Divide el problema a la mitad haciendo una llamada solo a la mitad del problema
// O(log n)
// función que resuelve el problema
char resolver(const vector<char>& sec, int ini, int fin, char prim, char ult) {
    int n = fin - ini;

    if (n == 0)
        return prim;
    else if (n == 1) {
        if (sec[ini] == prim)
            return prim + 1;
        else
            return prim;
    }
    else {
        int mit = (ini + fin) / 2;

        // Si el caracter de la mitad esta bn colocado miro en la derecha
        if (sec[mit] ==  (prim + (mit - ini)))
            return resolver(sec, mit + 1, fin, sec[mit] + 1, ult); //  mitad no hace falta creo
        else
            return resolver(sec, ini, mit, prim, sec[mit] + 1);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char prim, ult, n;
    cin >> prim >> ult;
    n = ult - prim;
    vector<char> sec(n);
    for (char& e : sec) cin >> e;
    cout << resolver(sec, 0, n, prim, ult) << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input2.txt");
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