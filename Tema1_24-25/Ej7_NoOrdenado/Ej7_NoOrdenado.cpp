// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Complejidad n * log(n) por ordenar los vectores de eda y tpv con sort
// O(n ∗ log(n))

// función que resuelve el problema
void comparaListados(vector<string>& eda, vector<string>& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {

    // Ordeno los vectores
    sort(eda.begin(), eda.end()); // O(n ∗ log(n)) siendo n tamaño del vector eda
    sort(tpv.begin(), tpv.end()); // O(m ∗ log(m)) siendo m tamaño del vector tpv

    int i = 0;
    int j = 0;

    while (i < eda.size() && j < tpv.size()) { // O(n + m) --> O(n)
        // Si son iguales avanzo los dos 
        if (eda[i] == tpv[j]) {
            comunes.push_back(eda[i]);
            i++;
            j++;
        }
        // Si es menor guardo en su lista y avanzo
        else if (eda[i] < tpv[j]) {
            soloEda.push_back(eda[i]);
            i++;
        }
        else {
            soloTpv.push_back(tpv[j]);
            j++;
        }
    }

    if (i < eda.size())
        for (; i < eda.size(); i++) soloEda.push_back(eda[i]);

    if (j < tpv.size())
        for (; j < tpv.size(); j++) soloTpv.push_back(tpv[j]);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<string> eda(n);
    vector<string> comunes;
    vector<string> soloEda;
    vector<string> soloTpv;
    for (string& e : eda) cin >> e;
    cin >> n;
    vector<string> tpv(n);
    for (string& e : tpv) cin >> e;
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);
    for (string& e : comunes) cout << e << " ";
    cout << endl;
    for (string& e : soloEda) cout << e << " ";
    cout << endl;
    for (string& e : soloTpv) cout << e << " ";
    cout << endl;
}


//#define DOMJUDGE
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
