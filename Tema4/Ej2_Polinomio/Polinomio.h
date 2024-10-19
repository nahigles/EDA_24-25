// Nahia Iglesias Calvo
// EDA-GDV34

#pragma once
#include <vector>
#include <cmath>

using namespace std;
class Polinomio {

protected:
	vector<pair<int, int>>polinomios;

public:
	Polinomio() {}

	// Añade monomio ordenadamente. O(n), n = num elems
	void addMonomio(int coeficiente, int exponente) {
		// Si coeficiente no es 0
		if (coeficiente) {
			// Si hay elementos en el vector
			if (polinomios.size()) {

				// Busco el exponente
				pair<int, bool> isExponent = findExponent(polinomios, 0, polinomios.size(), exponente); // O(log n)

				// Si existe lo sumo
				if (isExponent.second) {
					polinomios[isExponent.first].first += coeficiente;

					// Si tiene coeficiente 0 lo elimino
					if (polinomios[isExponent.first].first == 0)
						removeMonomio(isExponent.first); // O(n)
				}
				else
				{
					// Desplazo derecha a partir del index
					shiftRightFrom(isExponent.first); // O(n)
					// Y añado
					polinomios[isExponent.first] = { coeficiente, exponente };
				}
			}
			// Si no hay nada simplemente hace push back
			else
				polinomios.push_back({ coeficiente, exponente });
		}
	}

	// O(n).
	void removeMonomio(int index) {
		polinomios.erase(polinomios.begin() + index);
	}

	// O(n).
	int calcula(int n) {
		int ac = 0;
		for (auto e : polinomios)
			ac += e.first * pow(n, e.second);

		return ac;
	}

protected:
	// Devuelve indice de exponente y booleano de si se ha encontrado. Busqueda binaria --> O(log n).
	pair<int, bool> findExponent(vector<pair<int, int>>& v, int ini, int fin, int exp) {
		int n = fin - ini;

		if (n == 0)
			return { ini, false };
		else if (n == 1)
			return { ini,v[ini].second == exp };
		else {
			int med = (ini + fin) / 2;

			if (v[med].second == exp)
				return { med, true };
			else if (v[med].second < exp)
				return findExponent(v, med + 1, fin, exp);
			else
				return findExponent(v, ini, med, exp);
		}
	}

	// Desplaza 1 a la derecha. O(n).
	void shiftRightFrom(int i) {
		polinomios.push_back(polinomios.back());
		for (int j = polinomios.size() - 1; j > i; j--)
			polinomios[j] = polinomios[j - 1];
	}
};