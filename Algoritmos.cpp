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
	return esSimetrica;
}

bool simetrica(ListaInd& lista){
	int indI = 0;
	int indF = lista.numElem()-1;
	bool esSimetrica = true;
	while(esSimetrica && indI != indF && indI+1 != indF){
		if(indI != indF){
			esSimetrica = false;
		}
		++indI;
		--indF;
	}
	return esSimetrica;
}

/*
@Efecto: Ordena los elementos de la lista en orden ascendente
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
void seleccionIterativo(ListaPos& lista){
	ListaPos::posicion posMin;																																												
	for(ListaPos::posicion i = lista.getPrimera(); i != lista.getUltima(); i = lista.siguiente(i)){
		posMin = i;
		for(ListaPos::posicion j = lista.siguiente(i); j != lista.getUltima(); j = lista.siguiente(j){
			if(lista.recuperar(j) < lista.recuperar(minimo)){
				min = j;
			}
		}
		lista.intercambiar(i,minimo);
	}
}

void seleccionIterativo(ListaInd& lista){
	int minimo = 0;																																													
	for(int i = 0; i < lista.numElem() - 1; ++i){
		minimo = i;
		for(int j = i+1; j < lista.numElem(); ++j){
			if(lista.recuperar(j) < lista.recuperar(minimo)){
				minimo = j;
			}
		}
		lista.intercambiar(i,minimo);
	}
}