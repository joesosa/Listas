#include "ListaPosicionada_LDE.h"

ListaPos::Celda::Celda(int valor) {
	elemento = valor;
	anterior = NULL;
	siguiente = NULL;
}

ListaPos::Celda::~Celda() {
	if (siguiente)
		delete siguiente;
}

ListaPos::ListaPos() {
	primera = NULL;
	ultima = NULL;
	numElem = 0;
}

ListaPos::~ListaPos() {
	vaciar();
	delete this;
}

void ListaPos::vaciar() { 
	if (primera)
		delete primera;
	ultima = NULL;
}

bool ListaPos::vacia() {
	return !numElem;
}

void ListaPos::insertar(int elem, int pos) {
	Celda nueva = new Celda(elem);
	if (pos == 1) {
		nueva.siguiente = primera;
		if(primera)
			primera->anterior = nueva;
		primera = nueva;
	}
	else if (pos > 1 && pos < numElementos)
	{
		Celda* actual = primera;
		for (int i = 1; i < pos - 1; ++i)
			actual = actual->siguiente;
		Celda* auxiliar = actual->siguiente;
		actual->siguiente = nueva;
		nueva.anterior = actual;
		nueva.siguiente = auxiliar;
		auxiliar->anterior = nueva;
	}
	++numElementos;
}

void ListaPos::agregarUltimo(int elem) {
	Celda nueva = new Celda(elem);
	if (!primera) {
		primera = nueva;
		ultima = nueva;
		numElementos = 1;
	}
	else {
		ultima->siguiente = nueva;
		nueva.anterior = ultima;
		ultima = nueva;
		++numElementos;
	}

}

void ListaPos::borrar(int pos) {
	if (pos == 1) {
		Celda* victima = primera;
		primera = primera->siguiente;
		primera->anterior = NULL;
		victima->siguiente = NULL;
		delete victima;
	}
	else {
		Celda* actual = primera;
		for (int i = 1; i < pos - 1; ++i)
			actual = actual->siguiente;
		if (actual->siguiente) {
			Celda* victima = actual->siguiente;
			actual->siguiente = victima->siguiente;
			victima->siguiente->anterior = actual;
			if (ultima == victima)
				ultima = actual;
			victima->siguiente = NULL;
			delete victima;
		}
	}
}

int ListaPos::recuperar(int pos) {
	Celda* actual = primera;
	for (int i = 1; i < pos; ++i)
		actual = actual->siguiente;
	return actual->elemento;
}

void ListaPos::modificar(int pos, int elem) {
	Celda* actual = primera;
	for (int i = 1; i < pos; ++i)
		actual = actual->siguiente;
	actual->elemento = elem;
}

void ListaPos::intercambiar(int pos1, int pos2) { // CASO ULTIMA FALTAAAAAA con numElementos
	if ((pos1 == 1 && pos2 > 1) || (pos2 == 1 && pos1 > 1)) {
		Celda* actual1 = primera;
		Celda* actual2 = primera;
		for (int i = 1; i < pos1 - 1; ++i)
			actual1 = actual1->siguiente;
		Celda* auxiliar = actual1->siguiente->siguiente;
		actual1->siguiente->siguiente = actual2->siguiente;
		primera = actual1->siguiente;
		actual1->siguiente = actual2;
		actual2->siguiente = auxiliar;
	}
	else if (pos1 > 1 && pos2 > 1)
	{
		Celda* actual1 = primera;
		Celda* actual2 = primera;
		for (int i = 1; i < pos1 - 1; ++i)
			actual1 = actual1->siguiente;
		for (int i = 1; i < pos2 - 1; ++i)
			actual2 = actual2->siguiente;

		Celda* auxiliar = actual1->siguiente;
		actual1->siguiente = actual2->siguiente;
		actual2->siguiente = auxiliar;

		auxiliar = actual1->siguiente->siguiente;
		actual1->siguiente->siguiente = actual2->siguiente->siguiente;
		actual2->siguiente->siguiente = auxiliar;
	}
}

int ListaPos::numElem() {
	return numElementos;
}

ListaPos::Celda* ListaPos::getPrimera() {
	return primera;
}

ListaPos::Celda* ListaPos::getUltima() {
	return ultima;
}

ListaPos::Celda* ListaPos::siguiente(int pos) {
	Celda* actual = primera;
	for (int i = 1; i < pos; ++i)
		actual = actual->siguiente;
	return actual->siguiente;
}

ListaPos::Celda* ListaPos::anterior(int pos) {
	Celda* actual = primera;
	for (int i = 1; i < pos; ++i)
		actual = actual->siguiente;
	return actual->anterior;
