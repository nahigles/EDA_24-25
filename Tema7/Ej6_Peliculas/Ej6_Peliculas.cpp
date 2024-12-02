// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


using Pelicula = string;
using Actor = string;

struct PeliInfo {
    unordered_map<Actor, int> actores;
    int numEmisiones;
};

using RepartosPeliculas = unordered_map<Pelicula, PeliInfo>;

// Siendo P=nº de películas, E=nº de emisiones y A=nº de actores

// Complejidad de este metodo es O(P*A)
void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {
    Pelicula peli; int numActores;
    Actor actor; int minutos;

    // Complejidad --> O(P*A) por ser unordered map
    for (int i = 0; i < numPeliculas; ++i) { // O(P)
        cin >> peli; cin >> numActores;
       
            for (int j = 0; j < numActores; ++j) { // O(A)
                cin >> actor >> minutos;
                
                peliculas[peli].actores[actor] = minutos; // Guardo datos 
            }
    }
}


// La complejidad de este metodo es la maxima entre O(E) y O(P*A*log A)
void procesarEmisiones(RepartosPeliculas /*const*/& repartos, vector<string> const& secEmisiones) {
    
    // Complejidad lineal en E --> O(E) al hacerlo con unordered
    // EMISIONES
    int numMasEmitida = 0; Pelicula masEmitida = " ";
    for (int i = 0; i < secEmisiones.size(); i++) { // O(E)

        int& emision = repartos[secEmisiones[i]].numEmisiones; 
        (emision)++;
        if (numMasEmitida <= emision)
        {
            numMasEmitida = emision;
            masEmitida = secEmisiones[i];
        }
    }
    cout << numMasEmitida << " " << masEmitida << endl;

    // TIEMPO ACTORES
    // Actores ordenados totales
    map<Actor, int> actoresTot;

    int tiempoMaxPantalla = 0;

    // O(P*A*log A)
    for (auto itP = repartos.begin(); itP != repartos.end(); ++itP) {  // O(P)

        // Recorre actores y calcula tiempo total de pantalla
        for (auto itA = (*itP).second.actores.begin(); itA != (*itP).second.actores.end(); ++itA) { // O(A)
            int numEmisionesPeli = (*itP).second.numEmisiones;
            int minutosActorPeli = (*itA).second;
            int tiempoTotalActor = numEmisionesPeli * minutosActorPeli + actoresTot[(*itA).first];
            if (tiempoTotalActor >= tiempoMaxPantalla) tiempoMaxPantalla = tiempoTotalActor;
            actoresTot[(*itA).first] = tiempoTotalActor; //O(log A) (por ser ordenado)
        }
    }

    cout << tiempoMaxPantalla << " ";

    // Escribe el que tiene mas minutos en pantalla (Si los siguientes tienen el mismo tiempo los escribe ordenadamente)
    int i = 0;
    for (auto it = actoresTot.begin(); it != actoresTot.end(); ++it) { // O(A)
        if ((*it).second == tiempoMaxPantalla) {
            if (i == actoresTot.size() - 1) cout << (*it).first << endl;
            else cout << (*it).first << " ";
        }
        i++;
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    cin >> numPelis;
    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartosPeliculas repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    cin >> numEmisiones;
    vector<string> secEmisiones(numEmisiones);
    for (string& s : secEmisiones) cin >> s;

    procesarEmisiones(repartos, secEmisiones);

    return true;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}