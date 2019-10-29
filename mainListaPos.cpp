#include "ListaPosicionada_LDE.h"
#include <iostream>
#include <string>
using namespace std;

void Burbuja_BiDireccional(ListaPos lista) {
	ListaPos::posicion actual = lista.getPrimera();
	int numElem = lista.numElem();
	int faltan = numElem- 1;
	int dir = 1; //0 para la izq 1 para la der 
	for(int i = 0; i < numElem; ++i)
	{
		for (int j = 0; j < faltan; ++j)
		{
			if (dir) {
				if (lista.recuperar(actual) > lista.recuperar(lista.siguiente(actual)) )
				{
					lista.intercambiar(actual, lista.siguiente(actual));
				}
				actual = lista.siguiente(actual);
			}
			else {
				if (lista.recuperar(actual) < lista.recuperar(lista.anterior(actual)) )
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

void insercionSort(ListaPos lista) {
	ListaPos::posicion anterior = lista.getPrimera();
	ListaPos::posicion ultima = lista.getUltima();
	ListaPos::posicion actual = lista.siguiente(anterior); //Peligro si lista esta vacia
	ListaPos::posicion victima;
	int primero = 0;
	int menor = 0;
	while (actual) {
		while (lista.recuperar(actual) < lista.recuperar(anterior) && !primero) {
			menor = 1;
			if (lista.anterior(anterior)) {
				anterior = lista.anterior(anterior);
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
				lista.insertar(lista.recuperar(actual), lista.siguiente(anterior));
			}
			victima = actual;
			actual = lista.siguiente(actual);
			lista.borrar(victima);
			anterior = lista.anterior(actual);
		}
		else {
			anterior = actual;
			actual = lista.siguiente(actual);
		}
		menor = 0;
	}
}

ListaPos merge(ListaPos l1, ListaPos l2) {
	ListaPos::posicion actualL1 = l1.getPrimera();
	ListaPos::posicion actualL2 = l2.getPrimera();
	ListaPos l3 = ListaPos();
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
	return l3;
}

ListaPos mergeSort(ListaPos lista, ListaPos::posicion actualInicio, ListaPos::posicion actualFinal) {
	ListaPos l = ListaPos();
	if (actualInicio == actualFinal) {
		l = lista;
	}
	else {
		while (actualInicio != actualFinal || lista.siguiente(actualInicio) != actualFinal) {
			actualInicio = lista.siguiente(actualInicio);
			actualFinal = lista.anterior(actualFinal);
		}
		ListaPos::posicion medio = actualInicio;
		ListaPos nueva1 = mergeSort(lista, actualInicio, medio);
		ListaPos nueva2 = mergeSort(lista, lista.siguiente(medio), actualFinal);
		l = merge(nueva1, nueva2); //No se si el = esta bien hecho
	} //Verificar que no estoy sobreescribiendo la lista para los demas
	return l;
}

/*
@Efectua: Busca en la lista el elemento recibido como parametro y devuelve si existe o no
@Requiere: Una lista no vacia y un elemento valido(de tipo) en la lista
@Modifica: Este metodo no modifica nada
*/
bool buscar(ListaPos& lista, int elemento){
	bool existe = false;
	int cont = 0;
	ListaPos::posicion pos = lista.getPrimera();
	while (!existe && cont < lista.numElem()){ //pos
		if( lista.recuperar(pos) == elemento ){
			existe = true;
		}
		pos = lista.siguiente(pos);
	}
	return existe;
}

///ListaPos::posicion pos = lista.getPrimera();

/*
@Efectua:Deja en L3 el resultado de la intersección de L1 y L2.
@Requiere: L1 y L2 sean listas ordenadas y sin elementos repetidos, L3 inicializada y vacía.
@Modifica: Modifica L3
*/
void interseccionOrdenadasV1(ListaPos& l1, ListaPos& l2, ListaPos& l3){
  ListaPos::posicion posActual1 = l1.getPrimera();
  ListaPos::posicion posActual2 = l2.getPrimera();
  int elem1 = l1.recuperar(posActual1);
  int elem2 = l2.recuperar(posActual2);
  // Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  int numElemL2= l2.numElem();
  //cout<<"nE1: "<<numElemL1<<endl;
  //cout<<"nE2: "<<numElemL2<<endl;
  bool end = false;
  int cantElementosR1 = 1; // Me indica si la cantidad de elemetnos recorridos en l1
  int cantElementosR2 = 1;
  //cout<<"outside whileEE el1: "<<elem1<<endl;
  //cout<<"outside while el2: "<<elem2<<endl;
  while (!end) {
    if(elem1 == elem2){
      cout<<"Muerte en el if ==\n";
      l3.agregarUltimo(elem1);
      if(cantElementosR1 <numElemL1){
        // cout<<"Muerte en el if anidado == 1\n"; 
        posActual1 = l1.siguiente(posActual1);
      //  cout<<"BEFORE_RECUPERAR_1\n";
        elem1 = l1.recuperar(posActual1);
      }
      if(cantElementosR2 <numElemL2){ 
       // cout<<"Muerte en el if anidado == 2\n";
       posActual2 = l2.siguiente(posActual2);
       elem2 = l2.recuperar(posActual2);
      }
      /* cout<<"Muerte before el rec1 \n";
      cout<<"Muerte en el rec1 \n";
      cout<<"Muerte en el rec2 \n";
      */
      ++cantElementosR1;
      ++cantElementosR2;
      /* cout<<" el1: "<<elem1<<endl;
      cout<<"el2: "<<elem2<<endl;
      cout<<"++cantElementosR1: "<<cantElementosR1<<endl;
      cout<<"++cantElementosR2: "<<cantElementosR2<<endl;
      */
    }
    else{
      if (elem1>elem2){
        //cout<<"Muerte en el else if\n";
        if(cantElementosR2 <numElemL2){
          posActual2 = l2.siguiente(posActual2);
        }
        elem2 = l2.recuperar(posActual2);
        ++cantElementosR2;
        /* cout<<"el2: "<<elem2<<endl;
        cout<<"++cantElementosR2: "<<cantElementosR2<<endl;
        */
      }
      else{
         // cout<<"Muerte en el else else\n";
          if(cantElementosR1 <numElemL1){ 
            posActual1 = l1.siguiente(posActual1);
          }
          elem1 = l1.recuperar(posActual1);
          ++cantElementosR1;
          //cout<<"el1: "<<elem1<<endl;
          //cout<<"++cantElementosR1: "<<cantElementosR1<<endl;
      
      }
    }
    if(cantElementosR1 >= numElemL1 && cantElementosR2 >= numElemL2 ){
      //cout<<"entre end = true\n";
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

void interseccionOrdenadasV2(ListaPos& l1, ListaPos& l2, ListaPos& l3){
  int elem1;// Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  ListaPos::posicion posActual1 = l1.getPrimera();
  for(int actual1= 0; actual1 <= numElemL1; ++actual1){
    elem1 = l1.recuperar(posActual1);
    if(buscar(l2,elem1)){
      l3.agregarUltimo(elem1);
    }
    posActual1 = l1.siguiente(posActual1);
  }
}

/*
@Efectua: Deja en L3 el resultado de la intersección de L1 y L2(Supone que L1 y L2 son
listas NO necesariamente ordenadas).
@Requiere:L1 y L2 no tengan elementos repetidos y estén inicializdas.
@Modifica: Modifica L3
*/
void interseccionNoOrdenadas(ListaPos& l1, ListaPos& l2, ListaPos& l3){
  int elem1;
  // Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  int numElemL2= l2.numElem();
  ListaPos::posicion posActual1 = l1.getPrimera();
  ListaPos::posicion posActual2 = l2.getPrimera();
  bool encontrada;
  for(int actual1= 0; actual1 < numElemL1; ++actual1){
    elem1 = l1.recuperar(posActual1);
    encontrada = false;
    for(int actual2 = 0;actual2 < numElemL2 && !encontrada;++actual2 ){
      if(elem1 == l2.recuperar(posActual2)){
        l3.agregarUltimo(elem1);
        encontrada = true;
      }
       posActual2 = l2.siguiente(posActual2);
    }
     posActual1 = l1.siguiente(posActual1);
  }
}


/*
@Efectua:Le agrega a L1 los elementos que están en L2, de manera que en L1 no
queden elementos repetidos(Supone que L1 y L2 son listas NO necesariamente ordenadas).
@Requiere:L1 y L2 inicializadas y que no tengan elementos repetidos.
@Modifica: Modifica L1
*/
void unionNoOrdenadas(ListaPos& l1, ListaPos& l2){
  int elem2;
  // Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  int numElemL2= l2.numElem();
  bool encontrada;
  int posElemInsercion;
  ListaPos::posicion posActual1 = l1.getPrimera();
  ListaPos::posicion posActual2 = l2.getPrimera();
  for(int actual2= 0; actual2 < numElemL2; ++actual2){
    elem2 = l2.recuperar(posActual2);
    encontrada = false;
    for(int actual1 = 0; actual1 < numElemL1 && !encontrada;++actual1 ){
      if(elem2 == l1.recuperar(posActual1)){
        encontrada = true;
      }
      posActual1 = l1.siguiente(posActual1);
    }
    posActual2 = l2.siguiente(posActual2);
    if (!encontrada) {
      l1.agregarUltimo(elem2);
    }
  }
}


/*
@Efectua:le agrega a L1 los elementos que están en L2, de manera que en L1 no
queden elementos repetidos.
@Requiere: L1 y L2 inicializadas y que sean listas ordenadas y sin elementos repetidos.
@Modifica:Modifica l1
*/
void unionOrdenadas(ListaPos& l1, ListaPos& l2){
  ListaPos::posicion posActual1 = l1.getPrimera();
  ListaPos::posicion posActual2 = l2.getPrimera();
  int elem1 = l1.recuperar(posActual1);
  int elem2 = l2.recuperar(posActual2);
  // Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
  int numElemL1= l1.numElem();
  int numElemL2= l2.numElem();
  bool end = false;
  int cantElementosR1 = 0; // Me indica la cantidad de elementos recorridos en l1
  int cantElementosR2 = 0; // Me indica la cantidad de elementos recorridos en l2
  cout<<"outside while el1"<<elem1<<endl;
  cout<<"outside while el2"<<elem2<<endl;
  while (!end) {
    if(elem1 == elem2){
      if(cantElementosR1 <numElemL1){
        cout<<"Muerte en el if anidado == 1\n"; 
        posActual1 = l1.siguiente(posActual1);
        cout<<"BEFORE_RECUPERAR_1\n";
        elem1 = l1.recuperar(posActual1);
      }
      if(cantElementosR2 <numElemL2){ 
       cout<<"Muerte en el if anidado == 2\n";
       posActual2 = l2.siguiente(posActual2);
       elem2 = l2.recuperar(posActual2);
      }
      cout<<" el1"<<elem1<<endl;
      cout<<"outside while el2"<<elem2<<endl;
      ++cantElementosR1;
      ++cantElementosR2;
    }
    else{
      if (elem1>elem2){
        cout<<"beforee actual1-1"<<endl;
        if(cantElementosR1 <numElemL1){
        l1.insertar(elem2,posActual1);
        cout<<"Muerte en el if anidado if 1\n"; 
        posActual1 = l1.siguiente(posActual1);
        } 
        cout<<"after actual1-1"<<endl;
        if(cantElementosR2 <numElemL2){ 
          cout<<"Muerte en el if anidado if 2\n";
          posActual2 = l2.siguiente(posActual2);
          elem2 = l2.recuperar(posActual2);
        }
        ++cantElementosR2;
      }
      else{
          if(cantElementosR1 <numElemL1){
            cout<<"Muerte en el if anidado == 1\n"; 
            posActual1 = l1.siguiente(posActual1);
            cout<<"BEFORE_RECUPERAR_1\n";
            elem1 = l1.recuperar(posActual1);
          }
          ++cantElementosR1;
      }
    }
    if(cantElementosR1 >= numElemL1 && cantElementosR2 >= numElemL2 ){
      end = true;
    }
  }
  }








int main(){
ListaPos l1;
ListaPos l2;
ListaPos l3;
ListaPos l4;
ListaPos l5;
//Insertar(e,p,L)
int i = 0;
int j = 0;
l1.agregarUltimo(2);
l1.agregarUltimo(3);
l1.agregarUltimo(5);
l1.agregarUltimo(6);
l1.agregarUltimo(7);
l1.agregarUltimo(8);
l1.agregarUltimo(27);
l2.agregarUltimo(1);
l2.agregarUltimo(4);
l2.agregarUltimo(7);
l2.agregarUltimo(8);
l2.agregarUltimo(13);
l2.agregarUltimo(21);
l2.agregarUltimo(27);
l2.agregarUltimo(30);
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
cout<<"aaAAAAAAAA\n";
// cout<<"\nunionOrdenadas(l2,l1);";
// unionOrdenadas(l2,l1);
// cout<<"\n L2:";
// l2.imprimir();
cout<<"unionNOOrdenadas(l1,l2)\n";
unionNoOrdenadas(l1,l2);
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
l1.agregarUltimo(200);
l1.agregarUltimo(3);
l1.agregarUltimo(-34);
l1.agregarUltimo(56);
l1.agregarUltimo(7678);
l1.agregarUltimo(81);
l2.agregarUltimo(81);
l2.agregarUltimo(400000);
l2.agregarUltimo(7678);
l2.agregarUltimo(131);
l2.agregarUltimo(-34);
l2.agregarUltimo(-3200);
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
// g++ ListaPosexada_Arreglo.cpp mainindexada.cpp

return 0;
}
