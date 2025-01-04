// Nahia Iglesias Calvo
// EDA-GDV34

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;


class Fecha {
	int _dia, _mes, _anio;

public:
	Fecha(int d = 0, int m = 0, int a = 0) : _dia(d), _mes(m), _anio(a) {}
	int dia() const { return _dia; }
	int mes() const { return _mes; }
	int anio() const { return _anio; }
	bool operator<(Fecha const& other) const {
		return _anio < other._anio ||
			(_anio == other._anio && _mes < other._mes) ||
			(_anio == other._anio && _mes == other._mes && _dia < other._dia);
	}
};

inline std::istream& operator>>(std::istream& entrada, Fecha& h) {
	int d, m, a; char c;
	std::cin >> d >> c >> m >> c >> a;
	h = Fecha(d, m, a);
	return entrada;
}

inline std::ostream& operator<<(std::ostream& salida, Fecha const& f) {
	salida << std::setfill('0') << std::setw(2) << f.dia() << '/';
	salida << std::setfill('0') << std::setw(2) << f.mes() << '/';
	salida << std::setfill('0') << std::setw(2) << f.anio();
	return salida;
}

using Codigo = string;
using Cliente = string;

class Tienda {
private:
	list<pair<Cliente, Codigo>> listaEspera; // Lista de espera
	unordered_map<Codigo, map<Fecha, int>> almacen; // Almacen

public:
	// Gestiona la adquisición de CANT unidades (un entero no negativo)
	// del producto COD con fecha F.Si hubiera clientes esperando la llegada de este producto,
	// devuelve un vector con los identi!cadores de los clientes que han podido ser servidos, en el
	// orden en que hicieron la petición.El resto de unidades(si las hay) se guardan en el almacén.
	vector<Cliente> adquirir(Codigo const& cod, Fecha const& f, int cant) {
		// Vector clientes
		vector<Cliente> vClientes;

		// Recorro lista de espera
		auto it = listaEspera.begin();
		while (it != listaEspera.end() && cant > 0) {

			// Si un cliente quiere el producto recien adquirido en almacen
			if ((*it).second == cod) {
				vClientes.push_back((*it).first); // Guardo cliente servido
				cant--;							  // Resto unidad
				it = listaEspera.erase(it);		  // Elimino cliente de la lista de espera
			}
			else
				++it;
		}

		// Meto al almacen los productos no vendidos que han quedado
		if (cant > 0) {
			auto itC = almacen.find(cod);

			// Si el codigo ya existe
			if (itC != almacen.end()) {
				// Busco la fecha en ese codigo
				auto itF = (*itC).second.find(f);

				// Si encuentra la fecha
				if (itF != (*itC).second.end()) {
					(*itF).second += cant;
				}
				// Si no la encuentra la crea
				else
					(*itC).second[f] = cant;
			}
			// Si no existe la creo con la fecha y las unidades que han quedado
			else
				almacen[cod][f] = cant;
		}

		return vClientes;
	}

	// Gestiona la venta de una unidad del producto COD al cliente CLI (un string
	// sin espacios).Si hay existencias, la operación devuelve true y la fecha del producto vendido
	// (la menor entre las disponibles).Si no hay existencias, devuelve false y añade al cliente a
	// la lista de espera de este producto(un cliente puede aparecer varias veces en la lista de
	// espera).
	pair<bool, Fecha> vender(Codigo const& cod, Cliente const& cli) {
		pair<bool, Fecha> producto;
		producto.first = false;

		// Busco el codigo
		auto itC = almacen.find(cod);

		// Si encuentra el codigo
		if (itC != almacen.end()) {

			auto itCodigoMap = (*itC).second; // Guardo iterador al mapa del codigo

			// Busca unidades del codigo en la primera fecha q encuentre (Porque estan ordenadas)
			auto it = itCodigoMap.begin();
			while (it != itCodigoMap.end() && !producto.first) {

				// Si hay unidades
				if ((*it).second > 0) {
					producto.first = true;
					producto.second = (*it).first; // Guardo fecha

					(*it).second--; // Resta una unidad
				}
				// Si no hay existencias
				else {
					++it;
				}
			}
		}

		if (!producto.first) {

			// Cliente a lista de espera
			listaEspera.push_back({ cli, cod });
		}

		return producto;
	}

	// Devuelve cuántas unidades tiene la tienda del producto COD (independientemente de la fecha).
	// Si se trata de un producto que nunca se ha adquirido simplemente se devuelve 0.
	int cuantos(Codigo const& cod) const {

		int unidades = 0;
		// Busco producto
		auto itC = almacen.find(cod);

		// Si lo ha encontrado
		if (itC != almacen.end()) {

			// Recorre todas las fechas sumando las unidades
			for (auto itF = (*itC).second.begin(); itF != (*itC).second.end(); ++itF) {
				unidades += (*itF).second;
			}
		}

		return unidades;
	}

	// Indica si hay clientes en la lista de espera del producto COD. Si se trata
	// de un producto que nunca se ha adquirido simplemente se devuelve false.
	bool hay_esperando(Codigo const& cod) const {
		bool esperando = false;

		auto it = listaEspera.begin();
		while (it != listaEspera.end() && !esperando) {
			
			esperando = ((*it).second == cod);

			++it;
		}

		return esperando;
	}
};

bool resuelveCaso() {
	std::string operacion, cod, cli;
	Fecha f;
	int cant;
	std::cin >> operacion;
	if (!std::cin)
		return false;

	Tienda tienda;

	while (operacion != "FIN") {
		if (operacion == "adquirir") {
			cin >> cod >> f >> cant;
			vector<Cliente> clientes = tienda.adquirir(cod, f, cant);
			cout << "PRODUCTO ADQUIRIDO";
			for (auto c : clientes)
				cout << ' ' << c;
			cout << '\n';
		}
		else if (operacion == "vender") {
			cin >> cod >> cli;
			pair<bool, Fecha> venta = tienda.vender(cod, cli);
			if (venta.first) {
				cout << "VENDIDO " << venta.second << '\n';
			}
			else
				cout << "EN ESPERA\n";
		}
		else if (operacion == "cuantos") {
			cin >> cod;
			cout << tienda.cuantos(cod) << '\n';
		}
		else if (operacion == "hay_esperando") {
			cin >> cod;
			if (tienda.hay_esperando(cod))
				cout << "SI\n";
			else
				cout << "NO\n";
		}

		std::cin >> operacion;
	}
	std::cout << "---\n";
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