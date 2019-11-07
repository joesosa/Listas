#include "pch.h"
#include <iostream>
#include <chrono>
#include <time.h>
#include <stdlib.h>

#include "ListaPosicionada_Arreglo.h"
//#include "ListaPosicionada_LSE.h"
//#include "ListaPosicionada_LDE.h"

#include "ListaIndexada_Arreglo.h"
//#include "ListaIndexada_LSE.h"

#include "ListaOrdenada_Arreglo.h"
//#include "ListaOrdenada_LSE.h"
using namespace std;

void insercion(ListaPos& l1, int total) {
	//srand(time(0));
	auto inicio = chrono::steady_clock::now();
	for (int i = total; i > 0; --i) {
		l1.agregarUltimo(i);
	}
	auto fin = chrono::steady_clock::now();

}

void merge(ListaPos& l1, ListaPos& l2, ListaPos& l3) {
	l3.vaciar();
	ListaPos::posicion actualL1 = l1.getPrimera();
	ListaPos::posicion actualL2 = l2.getPrimera();
	while (actualL1 || actualL2) {
		if (actualL1 && actualL2) {
			if (l1.recuperar(actualL1) <= l2.recuperar(actualL2)) {
				l3.agregarUltimo(l1.recuperar(actualL1));
				actualL1 = l1.siguiente(actualL1);
			}
			else {
				l3.agregarUltimo(l2.recuperar(actualL2));
				actualL2 = l2.siguiente(actualL2);
			}
		}
		else {
			if (actualL1) {
				l3.agregarUltimo(l1.recuperar(actualL1));
				actualL1 = l1.siguiente(actualL1);
			}
			else {
				l3.agregarUltimo(l2.recuperar(actualL2));
				actualL2 = l2.siguiente(actualL2);
			}
		}
	}
}

void mergeSort(ListaPos& lista) {
	int numElem = lista.numElem();
	if (numElem > 1) {
		int mitad = numElem / 2;
		ListaPos::posicion posActual = lista.getPrimera();
		ListaPos primerMitad = ListaPos();
		ListaPos segundaMitad = ListaPos();

		for (int i = 0; i < mitad; ++i) {
			primerMitad.agregarUltimo(lista.recuperar(posActual));
			posActual = lista.siguiente(posActual);
		}
		for (int i = mitad; i < numElem; ++i) {
			segundaMitad.agregarUltimo(lista.recuperar(posActual));
			posActual = lista.siguiente(posActual);
		}
		mergeSort(primerMitad);
		mergeSort(segundaMitad);
		merge(primerMitad, segundaMitad, lista);
	}
}

void burbujaOriginal(ListaPos& lista) {
	ListaPos::posicion posJ;
	for (int i = 0; i < lista.numElem() - 1; ++i) {
		posJ = lista.getPrimera();
		for (int j = 0; j < lista.numElem() - 1; ++j) {
			if (lista.recuperar(posJ) > lista.recuperar(lista.siguiente(posJ))) {
				lista.intercambiar(lista.siguiente(posJ), posJ);
			}
			posJ = lista.siguiente(posJ);
		}
	}
}

void Burbuja_BiDireccional(ListaPos& lista) {
	ListaPos::posicion actual = lista.getPrimera();
	int numElem = lista.numElem();
	int faltan = numElem - 1;
	int dir = 1; //0 para la izq 1 para la der 
	for (int i = 0; i < numElem; ++i)
	{
		for (int j = 0; j < faltan; ++j)
		{
			if (dir) {
				if (lista.recuperar(actual) > lista.recuperar(lista.siguiente(actual)))
				{
					lista.intercambiar(actual, lista.siguiente(actual));
				}
				actual = lista.siguiente(actual);
			}
			else {
				if (lista.recuperar(actual) < lista.recuperar(lista.anterior(actual)))
				{
					lista.intercambiar(actual, lista.anterior(actual));
				}
				actual = lista.anterior(actual);
			}
		}
		if (dir) {
			actual = lista.anterior(actual);
		}
		else {
			actual = lista.siguiente(actual);
		}
		dir = (dir + 1) % 2;
		--faltan;
	}
}

int main()
{
	ListaPos pos;
	ListaInd ind;
	ListaOrdenada oort;

	cout << "\n************ POSICIONADA**************";

	insercion(pos, 1000);
	cout << "\n****************************\n1000:\n";
	auto inicio = chrono::steady_clock::now();
	mergeSort(pos);
	auto fin = chrono::steady_clock::now();

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
		<< " milisegundos" << endl;
	pos.vaciar();
	insercion(pos, 50000);
	 inicio = chrono::steady_clock::now();
	 mergeSort(pos);
	fin = chrono::steady_clock::now();

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::milliseconds>(fin - inicio).count()
		<< " milisegundos" << endl;

/*
	pos.vaciar();
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