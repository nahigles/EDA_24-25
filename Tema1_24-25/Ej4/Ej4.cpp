// Nahia Iglesias Calvo
// EDA-GDV34


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Complejidad lineal, recorre el vector
// T(n) --> O(n), siendo n el numero de elementos del vector nums
// función que resuelve el problema
void resolver(vector<int>& nums) {
    int ultParPos = 0;
    for (int i = 0; i < nums.size(); i++) { // O(n)

        // Si es par
        if (nums[i] % 2 == 0){
            nums[ultParPos] = nums[i]; // O(1)
            ultParPos++;
        }
    }

    nums.resize(ultParPos); // O(n)
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, numero;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) { // O(n)
        cin >> numero;
        nums.push_back(numero);
    }

    resolver(nums);
    // escribir sol

    for (int i = 0; i < nums.size(); i++) { // O(n)
        cout << nums[i] << " ";
    }

    cout << endl;
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
    system("PAUSE");
#endif

    return 0;
}