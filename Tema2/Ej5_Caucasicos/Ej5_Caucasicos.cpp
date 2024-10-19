// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// La funcion tiene coste lineal, ya que tiene que recorrer el vector entero en caso peor. Contra más numeros tenga el vector el tiempo aumenta linealmente.
// T(n) --> O(n) siendo n el número de elementos del vector v
bool caucasico(vector<int>&v, int ini, int fin, int& numPares) {
    int n = fin - ini;

    if (n == 1) {
        if (v[ini] % 2 == 0)
            numPares = 1;
        else
            numPares = 0;
        return true;
    }
    else{
        int med = (ini + fin) / 2;
        int pIzq, pDer;
        bool izq = caucasico(v, ini, med, pIzq);
        bool der = caucasico(v, med, fin, pDer);
        numPares = pIzq + pDer;
        return (abs(pIzq - pDer) <= 2) && izq && der;
    
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    int p = 0; // ??????
    cout << (caucasico(sec, 0, n, p) ? "SI" : "NO") << endl;
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