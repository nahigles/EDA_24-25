// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <utility>
#include <map>
#include <list>

using namespace std;

using Heroe = string;
using Villano = string;

class Personaje {
public:
	string nombre;
	int vida;
	Personaje(string nom, int vid) {
		nombre = nom;
		vida = vid;
	}
};

class Villain : public Personaje {
public:
	int ataque;
	Villain(string nom, int vid, int atack) :Personaje(nom, vid) {
		ataque = atack;
	}
};

class Hero : public Personaje {
public:
	map<string, int> ataques; // Mapa ordenado para guardar ataques (NombreAtaque - DañoAtaque)
	Hero(string nom, int vid) :Personaje(nom, vid) {}
};

class SistemaBatallas {
private:
	// Heroes y villanos
	map<Heroe, Hero*>heroes;
	map<Villano, Villain*>villanos;

	// Orden de ataque
	list<Personaje*> turnos;

	// Elimina personaje de la lista de turnos.
	// Coste: Complejidad lineal --> O(H + V), siendo H + V el numero de elementos que tiene la lista turnos
	void eliminaPersonajeDeTurnos(string const& nombre) {
		// Busco en la lista de turnos para eliiminar el personaje derrotado
		auto persTurno = turnos.begin();
		while (persTurno != turnos.end() && (*persTurno)->nombre != nombre) { // O(H+V), siendo H: numero de heroes y V: numero de villanos
			++persTurno;
		}
		turnos.erase(persTurno); // O(H+V)
	}

public:
	// Destructora
	~SistemaBatallas() {
		for (auto& p : turnos) { // O(H + V)
			delete p;
		}

		turnos.clear();
		heroes.clear();
		villanos.clear();
	}


	// Coste: Complejidad logaritmica --> O(log V) , siendo V el numero de villanos
	void aparece_villano(Villano const& v, int puntos, int valor) {

		// Si encuentra el villano lanza excepcion
		if (villanos.find(v) != villanos.end()) // O(log V)
			throw invalid_argument("Personaje ya existente");

		// Guarda villano
		auto vil = new Villain(v, puntos, valor);
		villanos[v] = vil; // O(log V), ya que villanos es un mapa ordenado

		// Añade villano a la cola
		turnos.push_back(vil); // O(1)
	}

	// Coste: Complejidad logaritmica --> O(log H), siendo H el numero de heroes
	void aparece_heroe(Heroe const& h, int puntos) {

		// Si encuentra el heroe lanza excepcion
		if (heroes.find(h) != heroes.end()) // O(log H)
			throw invalid_argument("Personaje ya existente");

		// Guardo heroe
		auto her = new Hero(h, puntos);
		heroes[h] = her; // O(log H), ya que heroes es un mapa ordenado

		// Añado heroe a la cola
		turnos.push_back(her); // O(1)
	}

	// Coste: El mayor entre O(log H) y O(log A), siendo H: numero de heroes y A: Numero de ataques del heroe
	void aprende_ataque(Heroe const& h, string const& ataque, int valor) {

		// Busco heroe
		auto her = heroes.find(h); // O(log H)

		// Si heroe no existe
		if (her == heroes.end())
			throw invalid_argument("Heroe inexistente");

		// Busco ataque de heroe
		auto atackHero = (*her).second->ataques.find(ataque); // O(log A)

		// Si ataque ya existe
		if (atackHero != (*her).second->ataques.end())
			throw invalid_argument("Ataque repetido");

		// Guardo ataque
		(*her).second->ataques[ataque] = valor; // O(log A)
	}

	// Coste: Complejidad lineal --> O(A), siendo A el numero de ataques guardados que tenga el heroe
	vector<pair<string, int>> mostrar_ataques(Heroe const& h) {
		// Busco heroe
		auto her = heroes.find(h); // O(log H)

		// Si heroe no existe
		if (her == heroes.end())
			throw invalid_argument("Heroe inexistente");

		// Me guardo puntero a los ataques
		auto ataquesHeroe = (*her).second->ataques;

		vector<pair<string, int>> res;
		for (auto it = ataquesHeroe.begin(); it != ataquesHeroe.end(); ++it) { // O(A)
			res.push_back(*it); // O(1)
		}
		return res;
	}

	// Coste: Complejidad lineal --> O(V + H), siendo H + V el numero de elementos que tiene la lista turnos (H: num heroes, V: num villanos)
	vector<pair<string, int>> mostrar_turnos() {
		vector<pair<string, int>> res;

		for (auto& t : turnos) { // O(V + H)
			res.push_back({ t->nombre, t->vida });
		}

		return res;
	}

	// Coste: Complejidad lineal -->  O(H + V), siendo H + V el numero de elementos que tiene la lista turnos (H: num heroes, V: num villanos)
	bool villano_ataca(Villano const& v, Heroe const& h) {

		// Busco villano
		auto vil = villanos.find(v); // O(log V)

		// Si villano no existe
		if (vil == villanos.end())
			throw invalid_argument("Villano inexistente");

		// Busco heroe
		auto her = heroes.find(h); // O(log H)

		// Si heroe no existe
		if (her == heroes.end())
			throw invalid_argument("Heroe inexistente");

		// Comprueba turno
		if (turnos.front()->nombre != v) // O(1)
			throw invalid_argument("No es su turno");

		// Pone al final de la cola al villano
		turnos.push_back(turnos.front()); // O(1)
		turnos.pop_front(); // O(1)

		// Villano ataca (Resta vida de heroe con ataque de villano)
		(*her).second->vida -= (*vil).second->ataque;
		if ((*her).second->vida <= 0) {

			eliminaPersonajeDeTurnos(h); // O(H + V)

			delete (*her).second;
			(*her).second = nullptr;
			heroes.erase(her); // O(log H)
			return true;
		}

		return false;
	}

	// Coste: Complejidad lineal -->  O(H + V), siendo H + V el numero de elementos que tiene la lista turnos (H: num heroes, V: num villanos)
	bool heroe_ataca(Heroe const& h, string const& ataque, Villano const& v) {
		// Busco villano
		auto vil = villanos.find(v); // O(log V)

		// Si villano no existe
		if (vil == villanos.end())
			throw invalid_argument("Villano inexistente");

		// Busco heroe
		auto her = heroes.find(h); // O(log H)

		// Si heroe no existe
		if (her == heroes.end())
			throw invalid_argument("Heroe inexistente");

		// Comprueba turno
		if (turnos.front()->nombre != h)
			throw invalid_argument("No es su turno");

		auto ataq = (*her).second->ataques.find(ataque); // O(log A), A: num ataques que tiene el heroe

		if (ataq == (*her).second->ataques.end())
			throw invalid_argument("Ataque no aprendido");

		// Pone al final de la cola al heroe
		turnos.push_back(turnos.front()); // O(1)
		turnos.pop_front(); // O(1)

		// Heroe ataca (Resta vida de villano con ataque elegido)
		(*vil).second->vida -= (*ataq).second;
		if ((*vil).second->vida <= 0) {

			eliminaPersonajeDeTurnos(v); // O(H + V)

			// Elimino
			delete (*vil).second;
			(*vil).second = nullptr;
			villanos.erase(vil); // O(log V)

			return true;
		}

		return false;
	}

};


bool resuelveCaso() { // No tacar nada de esta función!
	string comando;
	cin >> comando;
	if (!cin) return false;

	SistemaBatallas sistema;
	Villano v; Heroe h;
	string ataque; int ptos; int valor;
	while (comando != "FIN") {
		try {
			if (comando == "aparece_villano") {
				cin >> v >> ptos >> valor;
				sistema.aparece_villano(v, ptos, valor);
			}
			else if (comando == "aparece_heroe") {
				cin >> h >> ptos;
				sistema.aparece_heroe(h, ptos);
			}
			else if (comando == "aprende_ataque") {
				cin >> h >> ataque >> valor;
				sistema.aprende_ataque(h, ataque, valor);
			}
			else if (comando == "mostrar_ataques") {
				cin >> h;
				auto ataques = sistema.mostrar_ataques(h);
				cout << "Ataques de " << h << endl;
				for (auto& a: ataques) {
					cout << a.first << " " << a.second << "\n";
				}
			}
			else if (comando == "mostrar_turnos") {
				cout << "Turno: " << endl;
				auto turnos = sistema.mostrar_turnos();
				for (auto& t : turnos) {
					cout << t.first << " " << t.second << "\n";
				}
			}
			else if (comando == "villano_ataca") {
				cin >> v >> h;
				bool derrotado = sistema.villano_ataca(v, h);
				cout << v << " ataca a " << h << endl;
				if (derrotado) cout << h << " derrotado" << endl;
			}
			else if (comando == "heroe_ataca") {
				cin >> h >> ataque >> v;
				bool derrotado = sistema.heroe_ataca(h, ataque, v);
				cout << h << " ataca a " << v << endl;
				if (derrotado) cout << v << " derrotado" << endl;
			}
		}
		catch (std::exception& e) {
			cout << "ERROR: " << e.what() << "\n";
		}
		cin >> comando;
	}

	cout << "---\n";
	return true;
}

//#define DOMJUDGE
int main() {
#ifndef DOMJUDGE
	ifstream in("input3.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
