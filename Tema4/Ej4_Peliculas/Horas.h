// Nahia Iglesias Calvo
// EDA-GDV34

#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

struct Tiempo {
	int horas;
	int minutos;
	int segundos;
};

struct Pelicula {
	Tiempo horaComienzo;
	Tiempo duracion;
	Tiempo horaFinalicacion;
	string nombre;
};

class Horas {
protected:
	vector<Pelicula> peliculas;

public:
	Horas() {}

	void leer() {
		Pelicula p;
		char c;
		// Hora comienzo
		cin >> p.horaComienzo.horas >> c >> p.horaComienzo.minutos >> c >> p.horaComienzo.segundos;

		// Duracion
		cin >> p.duracion.horas >> c >> p.duracion.minutos >> c >> p.duracion.segundos;

		// Nombre
		getline(cin, p.nombre);

		p.horaFinalicacion = suma(p.horaComienzo, p.duracion);

		// Busco indice
		int index = buscaIndex(p, 0, peliculas.size());

		// Añado en indice buscado
		addFilm(p, index);
	}

	// Tiempo 1 es mayor que tiempo 2. O(1).
	bool mayorIgual(Tiempo t1, Tiempo t2) {

		return t1.horas > t2.horas || (t1.horas == t2.horas && t1.minutos > t2.minutos) || (t1.horas == t2.horas && t1.minutos == t2.minutos && t1.segundos >= t2.segundos);
	}

	// Tiempo 1 estrictamente mayor que t2. O(1).
	bool mayor(Tiempo t1, Tiempo t2) {

		return t1.horas > t2.horas || (t1.horas == t2.horas && t1.minutos > t2.minutos) || (t1.horas == t2.horas && t1.minutos == t2.minutos && t1.segundos > t2.segundos);
	}

	// Devuelve true si son iguales. O(1).
	bool igual(Tiempo t1, Tiempo t2) {
		return t1.horas == t2.horas && t1.minutos == t2.minutos && t1.segundos == t2.segundos;
	}

	// Escribe la hora. O(1).
	void escribeHora(Tiempo t) {
		if (t.horas < 10 || t.horas == 0)
			cout << "0";
		cout << t.horas << ":";

		if (t.minutos < 10 || t.minutos == 0)
			cout << "0";
		cout << t.minutos << ":";

		if (t.segundos < 10 || t.segundos == 0)
			cout << "0";
		cout << t.segundos;

	}

	// Eescribe todas las peliculas y la hora a la que termina. O(n).
	void escribePeliculas() {
		for (int i = 0; i < peliculas.size(); i++) {
			escribeHora(peliculas[i].horaFinalicacion);
			cout << peliculas[i].nombre << endl;
		}
	}

	// Suma t1 + t2 y lo devuelve. O(1).
	Tiempo suma(Tiempo t1, Tiempo t2) {
		Tiempo t = { t1.horas + t2.horas, t1.minutos + t2.minutos, t1.segundos + t2.segundos };

		if (t.segundos >= 60) {
			t.minutos += t.segundos / 60;
			t.segundos = t.segundos % 60;
		}
		if (t.minutos >= 60) {
			t.horas += t.minutos / 60;
			t.minutos = t.minutos % 60;
		}

		if (t.horas >= 24)
			throw exception();

		return t;
	}

protected:
	// Devuelve index de la hora mayor o igual que queremos. O(log n).
	int buscaIndex(Pelicula& p, int ini, int fin) {

		int n = fin - ini;

		if (n == 0 || n == 1)
			return ini;
		else {
			int med = (ini + fin) / 2;
			if (mayor(peliculas[med].horaFinalicacion, p.horaFinalicacion)) {
				return buscaIndex(p, ini, med);
			}
			else if (igual(peliculas[med].horaFinalicacion, p.horaFinalicacion)) {
				if (nombreMayor(peliculas[med].nombre, p.nombre))
					return buscaIndex(p, ini, med);
				else
					return buscaIndex(p, med + 1, fin);
			}
			else {
				return buscaIndex(p, med + 1, fin);
			}
		}
	}

	// Devuelve true si s1 es mayor estricto que s2. O(n).
	bool nombreMayor(string s1, string s2) {
		int i = 0;
		while (s1[i] == s2[i])
			i++;

		return s1[i] > s2[i];
	}

	// Añade pelicula en el vector de peliculas en el index que se indique. O(n).
	void addFilm(Pelicula p, int index) {
		if (index != peliculas.size()) {
			shiftRightFrom(index);
			peliculas[index] = p;
		}
		else
			peliculas.push_back(p);
	}

	// Desplaza 1 a la derecha. O(n).
	void shiftRightFrom(int i) {
		peliculas.push_back(peliculas.back());
		for (int j = peliculas.size() - 1; j > i; j--)
			peliculas[j] = peliculas[j - 1];
	}
};