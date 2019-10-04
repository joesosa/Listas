#include "ListaPosicionada_LDE.h"

ListaPos::Celda::Celda(int valor) {
	elemento = valor;
	anterior = NULL;
	siguiente = NULL;
}

ListaPos::Celda::~Celda() {
	anterior = NULL;
	if (siguiente)
		delete siguiente;
}

ListaPos::ListaPos() { //Iniciar(L)
	primera = NULL;
	ultima = NULL;
	numElementos = 0;
}

ListaPos::~ListaPos() { //Destruir(L)
	vaciar();
	delete this;
}

void ListaPos::vaciar() { //Vaciar(L)
	if (primera)
		delete primera;
	ultima = NULL;
}

bool ListaPos::vacia() { //Vacia(L)
	return !numElementos;
}

void ListaPos::insertar(int elem, posicion pos) { //Insertar(e,p,L)
	Celda* nueva = new Celda(elem);
	if (pos == primera) {
		nueva->siguiente = primera;
		primera->anterior = nueva;
		primera = nueva;
	}
	else {
		Celda* auxiliar = pos->anterior;
		auxiliar->siguiente = nueva;
		nueva->anterior = auxiliar;
		nueva->siguiente = pos;
		pos->anterior = nueva;
	}
	++numElementos;
}

void ListaPos::agregarUltimo(int elem) { //AgregarUltimo(e,L)
	Celda* nueva = new Celda(elem);
	if (!primera) {
		primera = nueva;
		ultima = nueva;
	}
	else {
		ultima->siguiente = nueva;
		nueva->anterior = ultima;
		ultima = nueva;
	}
	++numElementos;
}

void ListaPos::borrar(posicion pos) { //Borrar(p,L)
	if (pos == primera) {
		primera = primera->siguiente;
		primera->anterior = NULL;
		pos->siguiente = NULL;
		delete pos;
	}
	else {
		pos->anterior->siguiente = pos->siguiente;
		if (ultima == pos)
			ultima = pos->anterior;
		else
			pos->siguiente->anterior = pos->anterior;
		pos->siguiente = NULL;
		pos->anterior = NULL;
		delete pos;
	}
	--numElementos;
}

int ListaPos::recuperar(posicion pos) { //Recuperar(p,L)
	return pos->elemento;
}

void ListaPos::modificar(posicion pos, int elem) { //Modificar(p,e,L)
	pos->elemento = elem;
}

void ListaPos::intercambiar(posicion pos1, posicion pos2) { //Intercambiar(p1,p2,L)
	int aux = recuperar(pos1);
	pos1->elemento = pos2->elemento;
	pos2->elemento = aux;
}

int ListaPos::numElem() { //NumElem(L)
	return numElementos;
}

ListaPos::posicion ListaPos::getPrimera() { //Primera(L)
	return primera;
}

ListaPos::posicion ListaPos::getUltima() { //Ultima(L)
	return ultima;
}

ListaPos::posicion ListaPos::siguiente(posicion pos) { //Siguiente(p,L)
	return pos->siguiente;
}

ListaPos::posicion ListaPos::anterior(posicion pos) { //Anterior(p,L)
	return pos->anterior;
}

char* getNombre() {
	return (char*)"L.D.E.";
}
