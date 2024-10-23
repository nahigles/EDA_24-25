// Nahia Iglesias Calvo
// EDA-GDV34

#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

struct Tiempo {
	double horas;
	double minutos;
	double segundos;
};

class Horas {
protected:
	vector<Tiempo> horasTrenes;

public:
	Horas(){}

	void leer() {
		Tiempo t;
		char c;
		cin >> t.horas >> c >> t.minutos >> c >> t.segundos;
		horasTrenes.push_back(t);
	}

	void consultar(Tiempo t) {
		if (0 <= t.horas && t.horas <= 23 && 0 <= t.minutos && t.minutos <= 59 && 0 <= t.segundos && t.segundos <= 59) {
			int i = buscaHora(t);

			if (i != -1)
				escribeHora(horasTrenes[i]);
			else
				cout << "NO" << endl;
		}
		else
			throw exception();
		
	}

	// Tiempo 1 es mayor que tiempo 2
	bool mayorIgual(Tiempo t1, Tiempo t2) {
	/*	if (t1.horas > t2.horas)
			return true;
		else if (t1.horas < t2.horas)
			return false;
		else {
			if (t1.minutos > t2.minutos)
				return true;
			else if (t1.minutos < t2.minutos)
				return false;
			else {
				if (t1.segundos < t2.segundos)
					return false;
				else {
					return true;
				}
			}
		}*/

		return t1.horas > t2.horas || (t1.horas == t2.horas && t1.minutos > t2.minutos) || (t1.horas == t2.horas && t1.minutos == t2.minutos && t1.segundos >= t2.segundos);
	}

	void escribeHora(Tiempo t) {
		if (t.horas < 10 || t.horas == 0)
			cout << "0";
		cout << t.horas << ":";

		if(t.minutos < 10 || t.minutos == 0)
			cout << "0";
		cout << t.minutos << ":";

		if(t.segundos < 10 || t.segundos == 0)
			cout << "0";
		cout << t.segundos << endl;
			
	}

protected:
	// Devuelve index de la hora m ayor o igual que queremos. Si no encuentra devuelve -1. O(n).
	int buscaHora(Tiempo t) {
		int i = 0;
		bool encontrado = false;
		while (i < horasTrenes.size() && !encontrado) {
			if (mayorIgual(horasTrenes[i], t))
				encontrado = true;
			else 
				i++;
			
		}

		if (encontrado)
			return i;
		else
			return -1;
	}
};