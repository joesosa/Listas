#include "ListaIndexada_Arreglo.h"
#include <iostream>
using namespace std;

/*
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de ShakeSort
@Requiere: Una lista lista inicializada, no vacia sin elementos repetidos
@Modifica: La posicion de los elementos en la lista
*/
void Burbuja_BiDireccional(ListaInd lista) {
	int actual = 0;
	int numElem = lista.numElem();
	int faltan = numElem - 1;
	int dir = 1; //0 para la izq 1 para la der 
	for (int i = 0; i < numElem; ++i)
	{
		for (int j = 0; j < faltan; ++j)
		{
			if (dir) {
				if (lista.recuperar(actual) > lista.recuperar(actual+1))
				{
					lista.intercambiar(actual, actual + 1);
				}
				++actual;
			}
			else {
				if (lista.recuperar(actual) < lista.recuperar(actual-1))
				{
					lista.intercambiar(actual, actual - 1);
				}
				--actual;
			}
		}
		if (dir) {
			--actual;
		}
		else {
			++actual;
		}
		dir = (dir + 1) % 2;
		--faltan;
	}
}

/*
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de insercion
@Requiere: Una lista inicializada, no vacia sin elementos repetidos
@Modifica: La posicion de los elementos en la lista
*/
void insercionSort(ListaInd lista) {
	int anterior = 0;
	int ultima = lista.numElem()-1;
	int actual = 1; //Peligro si lista esta vacia
	int primero = 0; //Si va en el primer indice
	int menor = 0; //Si hay un elemento menor antes
	while (actual<=ultima) {
		while (lista.recuperar(actual) < lista.recuperar(anterior) && !primero) {
			menor = 1;
			if (anterior > 0) {
				--anterior;
			}
			else {
				primero = 1;
			}
		}
		if (menor) {
			if (primero) {
				lista.insertar(lista.recuperar(actual), anterior);
				primero = 0;
			}
			else {
				lista.insertar(lista.recuperar(actual), anterior+1);
			}
			++actual;
			lista.borrar(actual);
			anterior = actual - 1;
			menor = 0;
		}
		else {
			anterior = actual;
			++actual;
		}
	}
}

/*
@Efectua: Mezcla ordenadamente el contenido de 2 listas y lo retorna en una lista
@Requiere: l1 y l2 inicializadas, no vacias y sin elementos repetidos
@Modifica: No modifica las listas recibidas
*/
ListaInd merge(ListaInd l1, ListaInd l2) {
	int actualL1 = 0;
	int actualL2 = 0;
	int ultimoL1 = l1.numElem() - 1;
	int ultimoL2 = l2.numElem() - 1;
	int actualL3 = 0;
	ListaInd l3 = ListaInd();
	while (actualL1 <= ultimoL1 || actualL2 <= ultimoL2) {
		if (actualL1 <= ultimoL1 && actualL2 <= ultimoL2) {
			if (l1.recuperar(actualL1) <= l2.recuperar(actualL2)) {
				l3.insertar(l1.recuperar(actualL1), actualL3++);
				++actualL1;
			}
			else {
				l3.insertar(l2.recuperar(actualL2), actualL3++);
				++actualL2;
			}
		}
		else {
			if (actualL1 <= ultimoL1) {
				l3.insertar(l1.recuperar(actualL1), actualL3++);
				++actualL1;
			}
			else {
				l3.insertar(l2.recuperar(actualL2), actualL3++);
				++actualL2;
			}
		}
	}
	return l3;
}

/*
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de MergeSort
@Requiere: Una lista lista inicializada, no vacia sin elementos repetidos, posicion de inicio y final validas dentro de la lista
@Modifica: La posicion de los elementos en la lista
*/ 
ListaInd mergeSort(ListaInd lista, int actualInicio, int actualFinal) {
	ListaInd l = ListaInd();
	if (actualInicio == actualFinal) {
		l = lista;
	}
	else {
		while (actualInicio != actualFinal || actualInicio + 1 != actualFinal) {
			++actualInicio;
			--actualFinal;
		}
		int medio = actualInicio;
		ListaInd nueva1 = mergeSort(lista, actualInicio, medio);
		ListaInd nueva2 = mergeSort(lista, medio + 1, actualFinal);
		l = merge(nueva1, nueva2); //No se si el = esta bien hecho
	}
	return l;
}

/*
@Efectua: Busca en la lista el elemento recibido como parametro y devuelve si existe o no
@Requiere: Una lista no vacia y un elemento valido(de tipo) en la lista
@Modifica: Este metodo no modifica nada
*/
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
@Efectua:Deja en L3 el resultado de la intersección de L1 y L2.
@Requiere: L1 y L2 sean listas ordenadas y sin elementos repetidos, L3 inicializada y vacía.
@Modifica: Modifica L3
*/
void interseccionOrdenadasV1(ListaInd& l1, ListaInd& l2, ListaInd& l3){
  int actual1 = 0;
  int elem1 = l1.recuperar(actual1);
  int actual2 = 0;
  int elem2 = l2.recuperar(actual2);
  // Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int actual3 = 0;
  int numElemL1= l1.numElem();
  int numElemL2= l2.numElem();
  bool end = false;
  int cantElementosR1 = 0; // Me indica si la cantidad de elemetnos recorridos en l1
  int cantElementosR2 = 0;
  while (!end) {
    if(elem1 == elem2){
      l3.insertar(elem1,actual3++);
      elem1 = l1.recuperar(++actual1);
      elem2 = l2.recuperar(++actual2);
      ++cantElementosR1;
      ++cantElementosR2;
    }
    else{
      if (elem1>elem2){
        elem2 = l2.recuperar(++actual2);
        ++cantElementosR2;
      }
      else{
          elem1 = l1.recuperar(++actual1);
          ++cantElementosR1;
      }
    }
    if(cantElementosR1 == numElemL1 || cantElementosR2 == numElemL2 ){
      end = true;
    }
  }
  }

/*
@Efectua: Deja en L3 el resultado de la intersección de L1 y L2(emplea un algoritmo de busqueda auxiliar).
@Requiere:Requiere que L1 y L2 estén inicializadas y sean listas ordenadas y sin elementos repetidos.
L3 inicializada y sin elementos
@Modifica: Modifica la L3
*/

void interseccionOrdenadasV2(ListaInd& l1, ListaInd& l2, ListaInd& l3){
  int elem1;// Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  int actual3= 0;
  for(int actual1= 0; actual1 <= numElemL1; ++actual1){
    elem1 = l1.recuperar(actual1);
    if(buscar(l2,elem1)){
      l3.insertar(elem1,actual3++);
    }
  }
}

/*
@Efectua: Deja en L3 el resultado de la intersección de L1 y L2(Supone que L1 y L2 son
listas NO necesariamente ordenadas).
@Requiere:L1 y L2 no tengan elementos repetidos y estén inicializdas.
@Modifica: Modifica L3
*/
void interseccionNoOrdenadas(ListaInd& l1, ListaInd& l2, ListaInd& l3){
  int elem1;
  // Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  int numElemL2= l2.numElem();
  int actual3= 0;
  bool encontrada;
  for(int actual1= 0; actual1 < numElemL1; ++actual1){
    elem1 = l1.recuperar(actual1);
    encontrada = false;
    for(int actual2 = 0;actual2 < numElemL2 && !encontrada;++actual2 ){
      if(elem1 == l2.recuperar(actual2)){
        l3.insertar(elem1,actual3++);
        encontrada = true;
      }
    }
  }
}


/*
@Efectua:Le agrega a L1 los elementos que están en L2, de manera que en L1 no
queden elementos repetidos(Supone que L1 y L2 son listas NO necesariamente ordenadas).
@Requiere:L1 y L2 inicializadas y que no tengan elementos repetidos.
@Modifica: Modifica L1
*/
void unionNoOrdenadas(ListaInd& l1, ListaInd& l2){
  int elem2;
  // Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  int numElemL2= l2.numElem();
  bool encontrada;
  int posElemInsercion;
  for(int actual2= 0; actual2 < numElemL2; ++actual2){
    elem2 = l2.recuperar(actual2);
    encontrada = false;
    for(int actual1 = 0; actual1 < numElemL1 && !encontrada;++actual1 ){
      if(elem2 == l1.recuperar(actual1)){
        encontrada = true;
      }
    }
    if (!encontrada) {
      l1.insertar(elem2,l1.numElem());
    }
  }
}


/*
@Efectua:le agrega a L1 los elementos que están en L2, de manera que en L1 no
queden elementos repetidos.
@Requiere: L1 y L2 inicializadas y que sean listas ordenadas y sin elementos repetidos.
@Modifica:Modifica l1
*/
void unionOrdenadas(ListaInd& l1, ListaInd& l2){
  int actual1 = 0;
  int elem1 = l1.recuperar(actual1);
  int actual2 = 0;
  int elem2 = l2.recuperar(actual2);
  // Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  int numElemL2= l2.numElem();
  bool end = false;
  int cantElementosR1 = 0; // Me indica la cantidad de elementos recorridos en l1
  int cantElementosR2 = 0; // Me indica la cantidad de elementos recorridos en l2
  while (!end) {
    if(elem1 == elem2){
      elem1 = l1.recuperar(++actual1);
      elem2 = l2.recuperar(++actual2);
      ++cantElementosR1;
      ++cantElementosR2;
    }
    else{
      if (elem1>elem2){
        cout<<"beforee actual1-1"<<actual1<<endl;
        l1.insertar(elem2,actual1);
        ++actual1;
        cout<<"after actual1-1"<<actual1<<endl;
        elem2 = l2.recuperar(++actual2);
        ++cantElementosR2;
      }
      else{
          elem1 = l1.recuperar(++actual1);
          ++cantElementosR1;
      }
    }
    if(cantElementosR1 == numElemL1 || cantElementosR2 == numElemL2 ){
      end = true;
    }
  }
  }



int main(){
ListaInd l1;
ListaInd l2;
ListaInd l3;
ListaInd l4;
ListaInd l5;
//Insertar(e,p,L)
int i = 0;
int j = 0;
l1.insertar(2,i++);
l1.insertar(3,i++);
l1.insertar(5,i++);
l1.insertar(6,i++);
l1.insertar(7,i++);
l1.insertar(8,i++);
l1.insertar(27,i++);

l2.insertar(1,j++);
l2.insertar(4,j++);
l2.insertar(7,j++);
l2.insertar(8,j++);
l2.insertar(13,j++);
l2.insertar(21,j++);
l2.insertar(27,j++);
l2.insertar(30,j++);
cout<<"L1:";
l1.imprimir();
cout<<"L2:";
l2.imprimir();
interseccionOrdenadasV1(l1,l2,l3);
cout<<"L3:";
l3.imprimir();
cout<<endl<<endl<<endl;
interseccionOrdenadasV1(l2,l1,l4);
cout<<"L4:";
l4.imprimir();
// cout<<"\nunionOrdenadas(l2,l1);";
// unionOrdenadas(l2,l1);
// cout<<"\n L2:";
// l2.imprimir();
cout<<"\nunionOrdenadas(l1,l2);";
unionOrdenadas(l1,l2);
cout<<"\n L1:";
l1.imprimir();



cout<<"vaciando L3 y L4";
l3.vaciar();
l4.vaciar();
cout<<"\nL3:";
l3.imprimir();
cout<<"L4:";
l4.imprimir();

interseccionOrdenadasV2(l1,l2,l3);
cout<<"L3:";
l3.imprimir();
cout<<endl<<endl<<endl;
interseccionOrdenadasV2(l2,l1,l4);
cout<<"L4:";
l4.imprimir();
l1.vaciar();
l2.vaciar();
l3.vaciar();
i = 0;
j = 0;
l1.insertar(200,i++);
l1.insertar(3,i++);
l1.insertar(-34,i++);
l1.insertar(56,i++);
l1.insertar(7678,i++);
l1.insertar(81,i++);
l2.insertar(81,j++);
l2.insertar(400000,j++);
l2.insertar(7678,j++);
l2.insertar(131,j++);
l2.insertar(-34,j++);
l2.insertar(-3200,l2.numElem());
cout<<"L2:";
l2.imprimir();
cout<<"\ninterseccionNoOrdenadas(l2,l1,l3)";
interseccionNoOrdenadas(l2,l1,l3);
cout<<"\nL1:";
l1.imprimir();
cout<<"L2:";
l2.imprimir();
cout<<"L3:";
l3.imprimir();
cout<<"\nunionNoOrdenadas(l2,l1);";
unionNoOrdenadas(l2,l1);
cout<<"\n L2:";
l2.imprimir();
// cd C:\Users\b85560\Downloads\Listas-master_Naranjo
// g++ Listaindexada_Arreglo.cpp mainindexada.cpp

return 0;
}
