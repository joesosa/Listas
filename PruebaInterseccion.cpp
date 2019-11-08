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
	for (int i = 0; i < total; ++i) {
		if (i < total / 2)
			l1.agregarUltimo(i * 2+1);
		else
			l1.agregarUltimo(i);
	}
}

void insercionPos2(ListaPos& l1, int total) {
	//srand(time(0));
	for (int i = 0; i < total; ++i) {
		if(i<total/2)
			l1.agregarUltimo(i * 2);
		else
			l1.agregarUltimo(i);
	}
}

void insercion(ListaOrdenada& l1, int total) {
	for (int i = 0; i < total; ++i) {
		l1.insertar(rand() % (total * 10));
	}
}

void interseccionOrdenadasV1(ListaPos& l1, ListaPos& l2, ListaPos& l3) {
	ListaPos::posicion posActual1 = l1.getPrimera();
	ListaPos::posicion posActual2 = l2.getPrimera();
	int elem1 = l1.recuperar(posActual1);
	int elem2 = l2.recuperar(posActual2);
	// Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	bool end = false;
	int cantElementosR1 = 1; // Me indica si la cantidad de elemetnos recorridos en l1
	int cantElementosR2 = 1;
	while (!end) {
		if (elem1 == elem2) {
			l3.agregarUltimo(elem1);
			if (cantElementosR1 < numElemL1) {
				posActual1 = l1.siguiente(posActual1);
				elem1 = l1.recuperar(posActual1);
			}
			if (cantElementosR2 < numElemL2) {
				posActual2 = l2.siguiente(posActual2);
				elem2 = l2.recuperar(posActual2);
			}
			++cantElementosR1;
			++cantElementosR2;
		}
		else {
			if (elem1 > elem2) {
				if (cantElementosR2 < numElemL2) {
					posActual2 = l2.siguiente(posActual2);
				}
				elem2 = l2.recuperar(posActual2);
				++cantElementosR2;
			}
			else {
				if (cantElementosR1 < numElemL1) {
					posActual1 = l1.siguiente(posActual1);
				}
				elem1 = l1.recuperar(posActual1);
				++cantElementosR1;
			}
		}
		if (cantElementosR1 >= numElemL1 && cantElementosR2 >= numElemL2) {
			end = true;
		}
	}
}

bool buscar(ListaPos& lista, int elemento) {
	bool existe = false;
	int cont = 0;
	int numElem = lista.numElem();
	ListaPos::posicion pos = lista.getPrimera();
	while (!existe && cont < numElem) { //pos
		if (lista.recuperar(pos) == elemento) {
			existe = true;
		}
		++cont;
		pos = lista.siguiente(pos);
	}
	return existe;
}
void interseccionOrdenadasV2(ListaPos& l1, ListaPos& l2, ListaPos& l3) {
	int elem1;// Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	ListaPos::posicion posActual1 = l1.getPrimera();
	for (int actual1 = 0; actual1 < numElemL1; ++actual1) {
		elem1 = l1.recuperar(posActual1);
		if (buscar(l2, elem1)) {
			l3.agregarUltimo(elem1);
		}
		posActual1 = l1.siguiente(posActual1);
	}
}


int main()
{
	ListaPos pos;
	ListaPos pos2;
	ListaPos pos3;
	ListaInd ind;
	ListaOrdenada ord;
	srand(time(0));
	cout << "\n************ INTERSECCIONES**************";

	insercion(pos, 1000);
	insercionPos2(pos2, 1000);
	cout << "\n****************************\n1000:\n";
	auto inicio = chrono::steady_clock::now();
	interseccionOrdenadasV1(pos, pos2, pos3);
	auto fin = chrono::steady_clock::now();

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
		<< " milisegundos" << endl;

	pos.vaciar();
	pos2.vaciar();
	pos3.vaciar();
	insercion(pos, 1000);
	insercionPos2(pos2, 1000);
	inicio = chrono::steady_clock::now();
	interseccionOrdenadasV2(pos, pos2, pos3);
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