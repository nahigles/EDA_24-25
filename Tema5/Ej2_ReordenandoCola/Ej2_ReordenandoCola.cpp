// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "queue_eda.h"

using namespace std;

// Complejidad lineal, T(n) --> O(n), n = numero de elementos de la cola
// He utilizado una lista ya que se puede añadir tanto por el principio como por el final, y aqui
// nos es muy util ya que la cola esta ordenada por valor absoluto
list<int> resolver(queue<int>& datos ) {

    list<int>auxList; 
    int sizeQueue = datos.size();
    for (int i = 0; i < sizeQueue; i++) {
        int num = datos.front();
        if (num > 0)
            auxList.push_back(num);
        else
            auxList.push_front(num);

        datos.pop();
    }

    return auxList;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, e;
    cin >> n;

    if (n == 0)
        return false;

    queue<int>cola;
    for (int i = 0; i < n; i++) {
        cin >> e;
        cola.push(e);
    }

    list<int> sol = resolver(cola);

    // escribir sol
    for (auto& e : sol)
        cout << e << " ";
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
