// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>

using namespace std;

// Complejidad lineal, T(n) --> O(n), n = numero de caracteeres que tiene el string
// función que resuelve el problema
bool equilibrado(string& s) {

    list<char> lista;

    for (int i = 0; i < s.size(); i++) {
        switch (s[i])
        {
        case '(':
            lista.push_back('(');
            break;
        case '[':
            lista.push_back('[');
            break;
        case '{':
            lista.push_back('{');
            break;
        case ')': {
            if (!lista.empty() && lista.back() == '(')
                lista.pop_back();
            else
                return false;

            break;
        }
        case ']': {
            if (!lista.empty() && lista.back() == '[')
                lista.pop_back();
            else
                return false;
            break;
        }
        case '}': {
            if (!lista.empty() && lista.back() == '{')
                lista.pop_back();
            else
                return false;
            break;
        }
        default:
            break;
        }
    }

    return lista.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string linea;
    getline(cin, linea);

    if (!std::cin)
        return false;

    // escribir sol
    cout << (equilibrado(linea) ? "SI" : "NO") << endl;

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