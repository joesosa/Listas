#include "pch.h"
#include <iostream>
#include <chrono>

#include "ListaPosicionada_Arreglo.h"
//#include "ListaPosicionada_LSE.h"
//#include "ListaPosicionada_LDE.h"

#include "ListaIndexada_Arreglo.h"
//#include "ListaIndexada_LSE.h"

#include "ListaOrdenada_Arreglo.h"
//#include "ListaOrdenada_LSE.h"
using namespace std;



void insercion(ListaInd& l1,  int total) {
	auto inicio = chrono::steady_clock::now();
	for (int i = 0; i < total; ++i) {
		l1.insertar(i, i);
	}
	auto fin = chrono::steady_clock::now();

	cout << "Duracion : "
		<< chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count()
		<< " nanosegundos" << endl;

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::microseconds>(fin - inicio).count()
		<< " microsegundos" << endl;
}

void insercion(ListaPos& l1, int total) {
	auto inicio = chrono::steady_clock::now();
	for (int i = 0; i < total; ++i) {
		l1.agregarUltimo(i);
	}
	auto fin = chrono::steady_clock::now();

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count()
		<< " nanosegundos" << endl;

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::microseconds>(fin - inicio).count()
		<< " microsegundos" << endl;
}

void busquedas(ListaInd& l1, int total) {
	auto inicio = chrono::steady_clock::now();
	int valorAleatorio = 0;
	for (int i = 0; i < total; ++i) {
		valorAleatorio = rand() % total;
		l1.recuperar(valorAleatorio);
	}
	auto fin = chrono::steady_clock::now();

	cout << " : "
		<< chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count()
		<< " nanosegundos" << endl;

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::microseconds>(fin - inicio).count()
		<< " microsegundos" << endl;
}

void busquedas(ListaPos& l1, int total) {
	auto inicio = chrono::steady_clock::now();
	int valorAleatorio = 0;
	for (int i = 0; i < total; ++i) {
		valorAleatorio = rand() % total;
		l1.recuperar(valorAleatorio);
	}
	auto fin = chrono::steady_clock::now();

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count()
		<< " nanosegundos" << endl;

	cout << "Duracion: "
		<< chrono::duration_cast<chrono::microseconds>(fin - inicio).count()
		<< " microsegundos" << endl;
}


int main()
{
	ListaPos pos;
	ListaInd ind;
	ListaOrdenada oort;
	cout << "\n************ INDEXADA**************";

	cout << "\n****************************\n10000:\n";
	insercion(ind, 10000);
	busquedas(ind, 10000);

	ind.vaciar();
	cout << "\n****************************\n100000:\n";
	insercion(ind, 100000);
	busquedas(ind, 100000);

	ind.vaciar();
	cout << "\n****************************\n1000000:\n";
	insercion(ind, 1000000);
	busquedas(ind, 1000000);


	cout << "\n************ POSICIONADA**************";

	cout << "\n****************************\n10000:\n";
	insercion(pos, 10000);
	busquedas(pos, 10000);

	pos.vaciar();
	cout << "\n****************************\n100000:\n";
	insercion(pos, 100000);
	busquedas(pos, 100000);

	pos.vaciar();
	cout << "\n****************************\n1000000:\n";
	insercion(pos, 1000000);
	busquedas(pos, 1000000);

	return 0;
}