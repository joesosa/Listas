#include <stdlib.h> //Para usar system("cls");
#include <conio.h> //Para usar getch();

//#include "ListaPosicionada_Arreglo.h"
#include "ListaPosicionada_LSE.h"
//#include "ListaPosicionada_LDE.h"

//#include "ListaIndexada_Arreglo.h"
#include "ListaIndexada_LSE.h"

#include "ListaOrdenada_Arreglo.h"
//#include "ListaOrdenada_LSE.h"
/*

/*
@Efecto: Busca en la lista el elemento recibido como parametro y devuelve si existe o no
@Requiere: Una lista no vacia y un elemento valido(de tipo) en la lista
@Modifica: Este metodo no modifica nada
*/
bool buscar(ListaPos& lista, int elemento){
	bool existe = false;
	ListaPos::posicion pos = lista.getPrimera();
	while (!existe && pos){ //pos?
		if( lista.recuperar(pos) == elemento ){
			existe = true;
		}
		pos = lista.siguiente(pos);
	}
	return existe;
}

bool buscar(ListaInd& lista, int elemento){
	bool existe = false;
	int actual = 0;
	while (!existe && actual < lista.numElem()){
		if( lista.recuperar(actual) == elemento ){
			existe = true;
		}
		++actual;
	}
	return existe;
}


/*
@Efecto: Invierte todos los elementos de una lista, de manera en que el ultimo sea el primero y el primero el ultimo y asi respectivamente
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
void invertir(ListaPos& lista){
	ListaPos::posicion posI = lista.getPrimera();
	ListaPos::posicion posF = lista.getUltima();
	while(posI != posF && lista.siguiente(posI) != posF){ //probar lista.recuperar(posI) != lista.recuperar(posF) && lista.recuperar(lista.siguiente(posI)) != lista.recuperar(posF)
		lista.intercambiar(posI,posF);
		posI = lista.siguiente(posI);
		posF = lista.anterior(posF);
	}
	lista.intercambiar(posI,posF);
}

void invertir(ListaInd& lista){
	int indI = 0;
	int indF = lista.numElem()-1;
	while(indI != indF && indI+1 != indF ){
		lista.intercambiar(indI,indF);
		++indI;
		--indF;
	}
	lista.intercambiar(indI,indF);
}

/*
@Efecto: Averigua si una lista es simetrica verfificando si la primera es igual a la ultima y asi sucesivamente
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
bool simetrica(ListaPos& lista){
	ListaPos::posicion posI = lista.getPrimera();
	ListaPos::posicion posF = lista.getUltima();
	bool esSimetrica = true;
	while(esSimetrica && posI != posF && lista.siguiente(posI) != posF) { //probar
		if(lista.recuperar(posI) != lista.recuperar(posF)){
			esSimetrica = false;
		}
		posI = lista.siguiente(posI);
		posF = lista.anterior(posF);
	}
	if (lista.recuperar(posI) != lista.recuperar(posF)) {
		esSimetrica = false;
	}
	return esSimetrica;
}

bool simetrica(ListaInd& lista){
	int indI = 0;
	int indF = lista.numElem() - 1;
	bool esSimetrica = true;
	if(lista.numElem() > 1){	
		while(esSimetrica && indI != indF && indI+1 != indF){
			if(lista.recuperar(indI) != lista.recuperar(indF)){
				esSimetrica = false;
			}
			++indI;
			--indF;
		}
		if (lista.recuperar(indI) != lista.recuperar(indF)) {
			esSimetrica = false;
		}
	}
	return esSimetrica;
}

/*
@Efecto: Ordena los elementos de la lista en orden ascendente y se manera secuencial iterativa mediante...
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
void seleccionIterativo(ListaPos& lista){
	ListaPos::posicion posMin;																																												
	for(ListaPos::posicion i = lista.getPrimera(); i != lista.anterior(lista.getUltima()) ; i = lista.siguiente(i)){
		posMin = i;
		for(ListaPos::posicion j = lista.siguiente(i); j != lista.getUltima(); j = lista.siguiente(j){
			if(lista.recuperar(j) < lista.recuperar(posMin)){
				posMin = j;
			}
		}
		lista.intercambiar(i,minimo);
	}
}

void seleccionIterativo(ListaInd& lista) {
	int minimo = 0;
		for (int i = 0; i < lista.numElem() - 1; ++i) {
			minimo = i;
			for (int j = i + 1; j < lista.numElem(); ++j) {
				if (lista.recuperar(j) < lista.recuperar(minimo)) {
					minimo = j;
				}
			}
			lista.intercambiar(i, minimo);
		}
}

/*
@Efecto: 
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
//posible error
void seleccionRecursivo(ListaPos& lista, int inicio) {
	ListaPos::posicion i = traducir(lista, inicio);
	if (i == lista.getUltima()) {
		return;
	}
	else {
		ListaPos::posicion minimo = i;
		for (i = lista.siguiente(lista.getPrimera()); i != lista.siguiente(lista.getUltima()); i = lista.siguiente(i)) {
			if (lista.recuperar(i) < lista.recuperar(minimo)) {
				minino = i
			}
		}
		lista.intercambiar(inicio, minimo);
		seleccionRecursivo(lista, ++inicio);
	}
}

void seleccionRecursivo(ListaInd& lista, int inicio) {
	if (inicio == lista.numElem() - 1) {
		return;
	}
	else {
		int minimo = inicio;
		for (int i = inicio + 1; i < lista.numElem(); ++i) {
			if (lista.recuperar(i) < lista.recuperar(minimo)) {
				minimo = i;
			}
		}
		lista.intercambiar(inicio, minimo);
		seleccionRecursivo(lista, ++inicio);
	}
}

/*
@Efecto: 
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
//posible error
void burbujaOriginal(ListaPos& lista) { //revisar
	for (ListaPos::posicion i = lista.getPrimera(); i != lista.anterior(lista.getUltima()); i = lista.siguiente(i)) {
		for (ListaPos::posicion j = lista.getPrimera(); ; j = lista.siguiente(j)) { //solucionar error
			if (lista.recuperar(j) < lista.recuperar(lista.siguiente(j))) {
				lista.intercambiar(lista.siguiente(j) , j);
			}
		}
	}
}

void burbujaOriginal(ListaInd& lista) {
	for (int i = 0; i < lista.numElem() - 1; ++i) {
		for (int j = 0; j < lista.numElem() - i - 1; ++j) {
			if (lista.recuperar(j) > lista.recuperar(j + 1)) {
				lista.intercambiar(j + 1, j);
			}
		}
	}
}

/*
@Efecto: 
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
//posible error
void eliminarRepetidos(ListaPos& lista){
	ListaPos::posicion posI = lista.getPrimera();
	ListaPos::posicion posJ = posI;
	for(int i = 0; i < lista.numElem(); ++i){
		bool repetido = false;
		for(int j = 0; j < lista.numElem(); ++j){
			if(i != j && lista.recuperar(posI) == lista.recuperar(posJ) ){
				repetido = true;
				j = lista.numElem();
			}
			posJ = lista.siguiente(posJ);
		}
		if(repetido){
			lista.borrar(posI);
		}
		posI = lista.siguiente(posI);
	}
}

void eliminarRepetidos(ListaInd& lista){
	for(int i = 0; i < lista.numElem(); ++i){
		bool repetido = false;
		for(int j = 0; j < lista.numElem(); ++j){
			if(i != j && lista.recuperar(i) == lista.recuperar(j) ){
				repetido = true;
				j = lista.numElem();
			}
		}
		if(repetido){
			lista.borrar(i);
		}
	}
}

/*
@Efecto: 
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
//posible error
bool subLista(ListaInd& lista1, ListaInd& lista2){
	int indiceL1 = 0;
	int indiceL2 = 0;
	bool esSubLista = false;
	while(!esSubLista && indiceL2 < lista2.numElem()){
		int cont = 0;
		while(!esSubLista && actualL1 < lista1.numElem() && lista1.recuperar(indiceL1) == lista2.(indiceL2) ){
			++cont;
			if(cont == lista1.numElem()){
				esSubLista = true;
			}
			++indiceL1;
			++indiceL2;
		}
	}
	return esSubLista;
}

bool subLista(ListaInd& lista1, ListaInd& lista2){
	int indiceL1 = 0;
	int indiceL2 = 0;
	bool esSubLista = false;
	while(!esSubLista && indiceL2 < lista2.numElem()){
		int cont = 0;
		while(!esSubLista && indiceL1 < lista1.numElem() && lista1.recuperar(indiceL1) == lista2.recuperar(indiceL2) ){
			++cont;
			if(cont == lista1.numElem()){
				esSubLista = true;
			}
			++indiceL1;
			++indiceL2;
		}
		indiceL1 = 0;
		if(lista1.recuperar(indiceL1) != lista2.recuperar(indiceL2)){
				++indiceL2;
		}
	}
	return esSubLista;
}
