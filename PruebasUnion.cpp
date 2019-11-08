#include <iostream>
#include <chrono>
#include <time.h>
#include <stdlib.h>

#include "ListaPosicionada_Arreglo.h"
//#include "ListaPosicionada_LSE.h"
//#include "ListaPosicionada_LDE.h"

//#include "ListaIndexada_Arreglo.h"
#include "ListaIndexada_LSE.h"

//#include "ListaOrdenada_Arreglo.h"
#include "ListaOrdenada_LSE.h"
using namespace std;

void insercion(ListaPos& l1, int total) {
	//srand(time(0));
	for (int i = total; i > 0; --i) {
		l1.agregarUltimo(i);
	}
}

void insercion(ListaInd& l1, int total) {
	//srand(time(0));
	for (int i = 0; i < total; ++i) {
		l1.insertar( i*2+1 , i);
	}
}

void insercionInd2(ListaInd& l1, int total) {
	//srand(time(0));
	for (int i = 0; i < total; ++i) {
		l1.insertar(i*2, i);
	}
}

void insercion(ListaOrdenada& l1, int total) {
	for (int i = 0; i <total; ++i) {
		l1.insertar(rand()%(total*10));
	}
}

void unionOrdenadas(ListaInd& l1, ListaInd& l2) {
	int actual1 = 0;
	int elem1 = l1.recuperar(actual1);
	int actual2 = 0;
	int elem2 = l2.recuperar(actual2);
	// Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	bool end = false;
	int cantElementosR1 = 1; // Me indica la cantidad de elementos recorridos en l1
	int cantElementosR2 = 1; // Me indica la cantidad de elementos recorridos en l2
	while (!end) {
		if (elem1 == elem2) {
			if (cantElementosR1 < numElemL1) {
				elem1 = l1.recuperar(++actual1);
			}

			if (cantElementosR2 < numElemL2) {
				elem2 = l2.recuperar(++actual2);
			}
			if (elem2 > elem1&& elem1 == l1.recuperar(l1.numElem() - 1)) {
				actual1 = l1.numElem();
				l1.insertar(elem2, actual1);
			}
			++cantElementosR1;
			++cantElementosR2;
		}
		else {
			if (elem1 > elem2) {
				l1.insertar(elem2, actual1);
				//l1.imprimir();
				++actual1;
				if (cantElementosR2 < numElemL2) {
					elem2 = l2.recuperar(++actual2);
				}
				++cantElementosR2;
			}
			else {
				if (cantElementosR1 < numElemL1) {
					elem1 = l1.recuperar(++actual1);
				}
				else {
					elem1 = l1.recuperar(l1.numElem() - 1);
					actual1 = l1.numElem();
				}
				++cantElementosR1;
			}
		}
		if (cantElementosR1 >= numElemL1 && cantElementosR2 >= numElemL2) {
			end = true;
		}
	}
}

void unionListas(ListaOrdenada& lista1, ListaOrdenada& lista2, ListaOrdenada& listaUnion) {
	int actualL1 = lista1.primero();
	int contador = 1;
	int actualL2 = lista2.primero();

	while (contador <= lista1.numElem() && contador <= lista2.numElem()) {
		listaUnion.insertar(actualL1);
		listaUnion.insertar(actualL2);
		actualL1 = lista1.siguiente(actualL1);
		actualL2 = lista2.siguiente(actualL2);
		++contador;
	}
	while (contador <= lista1.numElem()) {
		listaUnion.insertar(actualL1);
		actualL1 = lista1.siguiente(actualL1);
		++contador;
	}

	while (contador <= lista2.numElem()) {
		listaUnion.insertar(actualL2);
		actualL2 = lista2.siguiente(actualL2);
		++contador;
	}
}

int main()
{
	ListaPos pos;
	ListaInd ind;
	ListaInd ind2;
	ListaOrdenada ord;
	ListaOrdenada ord2;
	ListaOrdenada ord3;
	srand(time(0));
	cout << "\n************ UNIONES**************";

	insercion(ord, 1000);
	insercion(ord2, 1000);
	cout << "\n****************************\n1000:\n";
	auto inicio = chrono::steady_clock::now();
	unionListas(ord,ord2,ord3);
	auto fin = chrono::steady_clock::now();

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
		<< " milisegundos" << endl;
	
	insercion(ind, 1000);
	insercionInd2(ind2, 1000);
	inicio = chrono::steady_clock::now();
	unionOrdenadas(ind,ind2);
	fin = chrono::steady_clock::now();

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
		<< " milisegundos" << endl;


/*		pos.vaciar();
		insercion(pos, 10000);
		cout << "\n****************************\n10000:\n";
		inicio = chrono::steady_clock::now();
		burbujaOriginal(pos);
		fin = chrono::steady_clock::now();

		cout << "Duracion: "
			<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
			<< " milisegundos" << endl;
		pos.vaciar();
		insercion(pos, 10000);
		inicio = chrono::steady_clock::now();
		Burbuja_BiDireccional(pos);
		fin = chrono::steady_clock::now();

		cout << "Duracion: "
			<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
			<< " milisegundos" << endl;

		pos.vaciar();
		insercion(pos, 20000);
		cout << "\n****************************\n20000:\n";
		inicio = chrono::steady_clock::now();
		burbujaOriginal(pos);
		fin = chrono::steady_clock::now();

		cout << "Duracion: "
			<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
			<< " milisegundos" << endl;

		pos.vaciar();
		insercion(pos, 20000);
		inicio = chrono::steady_clock::now();
		Burbuja_BiDireccional(pos);
		fin = chrono::steady_clock::now();

		cout << "Duracion: "
			<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
			<< " milisegundos" << endl;
	*/

	return 0;
}