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
@Efecto: Inserta todos los datos de la lista original en la nueva con el fin de que queden exactamente iguales
@Requiere: Una lista original no vacia y una lista nueva sin elementos
@Modifica: La lista nueva
*/
void copiar(ListaOrdenada& listaOriginal, ListaOrdenada& listaNueva) {
	int actual = listaOriginal.primero();
	int cont = 1;
	while (cont <= listaOriginal.numElem()) {
		listaNueva.insertar(actual);
		actual = listaOriginal.siguiente(actual);
		cont++;
	}
}


/*
@Efecto: Indica si el elemento pertenece a la Lista Ordenada
@Requiere: Una lista no vacia
@Modifica: Este metodo no modifica nada
*/
bool pertenece(ListaOrdenada& lista, int elemento) {
	bool pertenece = false;
	int actual = lista.primero();
	int cont = 0;
	while (cont <= lista.numElem() && !pertenece){
		if (elemento == actual) {
			pertenece = true;
		}
		actual = lista.siguiente(actual);
	}
	return pertenece;
}

/*
@Efecto: Encuentra la union entre dos listas y la deja en una lista nueva
@Requiere: Dos listas no vacias
@Modifica: Este metodo modifica la nueva lista
*/
void unionListas(ListaOrdenada& lista1, ListaOrdenada& lista2, ListaOrdenada& listaUnion) {
	int actualL1 = lista1.primero();
	int contador = 1;
	int actualL2 = lista2.primero();
	
	while (contador <= lista1.numElem() && contador <= lista2.numElem()){
		listaUnion.insertar(actualL1);
		listaUnion.insertar(actualL2);
		actualL1 = lista1.siguiente(actualL1);
		actualL2 = lista2.siguiente(actualL2);
		++contador;
	}
	while(contador <= lista1.numElem()){
		listaUnion.insertar(actualL1);
		actualL1 = lista1.siguiente(actualL1);
		++contador;
	}
	
	while(contador <= lista2.numElem()){
		listaUnion.insertar(actualL2);
		actualL2 = lista2.siguiente(actualL2);
		++contador;
	} 
	
}

/*
@Efecto: Busca en la lista el elemento recibido como parametro y devuelve si existe o no
@Requiere: Una lista no vacia y un elemento valido(de tipo) en la lista
@Modifica: Este metodo no modifica nada
*/
bool buscar(ListaPos& lista, int elemento){
	bool existe = false;
	ListaPos::posicion pos = lista.getPrimera();
	while (!existe && pos){
		if( lista.recuperar(pos) == elemento ){
			existe = true;
		}
		pos = lista.siguiente(pos);
	}
	return existe;
}

bool buscar(ListaInd& lista, int elemento){
	bool existe = false;
	int actual = lista.recuperar(0);
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
	
}

void invertir(ListaInd& lista){

}

