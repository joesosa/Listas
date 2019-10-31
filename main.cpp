#include <stdlib.h> //Para usar system("cls");
#include <conio.h> //Para usar getch();

//#include "ListaPosicionada_Arreglo.h"
#include "ListaPosicionada_LSE.h"
//#include "ListaPosicionada_LDE.h"

//#include "ListaIndexada_Arreglo.h"
#include "ListaIndexada_LSE.h"

#include "ListaOrdenada_Arreglo.h"
//#include "ListaOrdenada_LSE.h"
using namespace std;

ListaPos::posicion traducir(ListaPos& lista, int indice) { //Traduce un indice ingresado por el usuarion en una posicion
	ListaPos::posicion pos;
	pos = lista.getPrimera();
	for (int i = 1; i < indice; ++i)
		pos = lista.siguiente(pos);
	return pos;
}

//----------------Algoritmos Posicionada
/*
@Efecto: Despliega en pantallos los elementos de la lista
@Requiere: Una lista inicializada
@Modifica: Este metodo no modifica la lista
*/
void listar(ListaPos& lista) {
	lista.imprimir();
}

/*
@Efecto: Averigua si una lista es simetrica verfificando si la primera es igual a la ultima y asi sucesivamente
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo no modifica la lista
*/
bool simetrica(ListaPos& lista) {
	ListaPos::posicion posI = lista.getPrimera();
	ListaPos::posicion posF = lista.getUltima();
	bool esSimetrica = true;
	while (esSimetrica && posI != posF && lista.siguiente(posI) != posF) { //probar
		if (lista.recuperar(posI) != lista.recuperar(posF)) {
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

/*
@Efecto: Invierte todos los elementos de una lista, de manera en que el ultimo sea el primero y el primero el ultimo y asi respectivamente
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
void invertir(ListaPos& lista) {
	ListaPos::posicion posI = lista.getPrimera();
	ListaPos::posicion posF = lista.getUltima();
	while (posI != posF && lista.siguiente(posI) != posF) { //probar lista.recuperar(posI) != lista.recuperar(posF) && lista.recuperar(lista.siguiente(posI)) != lista.recuperar(posF)
		lista.intercambiar(posI, posF);
		posI = lista.siguiente(posI);
		posF = lista.anterior(posF);
	}
	lista.intercambiar(posI, posF);
}

/*
@Efectua: Busca en la lista el elemento recibido como parametro y devuelve si existe o no
@Requiere: Una lista no vacia y un elemento valido(de tipo) en la lista
@Modifica: Este metodo no modifica nada
*/
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

/*
@Efecto: Elimina los elementos repetidos de una lista
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista y la cantidad de elementos
*/
void eliminarRepetidos(ListaPos& lista) {
	ListaPos::posicion posI = lista.getPrimera();
	ListaPos::posicion posJ = posI;
	for (int i = 0; i < lista.numElem(); ++i) {
		bool repetido = false;
		for (int j = 0; j < lista.numElem(); ++j) {
			if (i != j && lista.recuperar(posI) == lista.recuperar(posJ)) {
				repetido = true;
				j = lista.numElem();
			}
			posJ = lista.siguiente(posJ);
		}
		if (repetido) {
			lista.borrar(posI);
		}
		posI = lista.siguiente(posI);
	}
}


/*
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de BubbleSort
@Requiere: Una lista lista inicializada, no vacia sin elementos repetidos
@Modifica: La posicion de los elementos en la lista
*/
void burbujaOriginal(ListaPos& lista) { //revisar
	ListaPos::posicion posI = lista.getPrimera();
	ListaPos::posicion posJ;
	for (int i = 0; i < lista.numElem() - 1; ++i) {
		posJ = lista.getPrimera();
		for (int j = 0; j < lista.numElem() - i - 1; ++j) { //solucionar error
			if (lista.recuperar(posJ) > lista.recuperar(lista.siguiente(posJ))) {
				lista.intercambiar(lista.siguiente(posJ), posJ);
			}
			posJ = lista.siguiente(posJ);
		}
		posI = lista.siguiente(posI);
	}
}

/*
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de ShakeSort
@Requiere: Una lista lista inicializada, no vacia sin elementos repetidos
@Modifica: La posicion de los elementos en la lista
*/
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

ListaPos::posicion encuentraPivoteAho(ListaPos& l1, ListaPos::posicion inicial, ListaPos::posicion final) {
    int pivoteTemp1 = l1.recuperar(inicial);
    ListaPos::posicion posPivote = -1;
    bool pivoteEncontrado = false;
    ListaPos::posicion actual = inicial;
    cout << "Pivote\n";
    l1.imprimir();
    while (l1.anterior(actual)!= final && !pivoteEncontrado) {
        if (pivoteTemp1 > l1.recuperar(actual)) {
            pivoteEncontrado = true;
            posPivote = inicial;
        }
        else if (pivoteTemp1 < l1.recuperar(actual)) {
            pivoteEncontrado = true;
            posPivote = actual;
        }
        actual = l1.siguiente(actual);
    }
    return posPivote;
}


ListaPos::posicion parteYOrdena(ListaPos& l1, ListaPos::posicion inicial, ListaPos::posicion final) {
    int pivote = l1.recuperar(encuentraPivoteAho(l1, inicial, final));
    ListaPos::posicion inicioEMP = 0;// Guarda el indice donde inician los elemento mayores que el pivote
    while (l1.anterior(inicial) != final) {
        cout << "intercambiar\n\n";
        l1.intercambiar(inicial, final);
        while (l1.recuperar(inicial) < pivote) {
            inicial = l1.siguiente(inicial);
            inicioEMP = inicial;
        }
        while (l1.recuperar(final) >= pivote) {
            final = l1.anterior(final);
        }
    }
    return inicioEMP;
}

void quickSort(ListaPos& l1, ListaPos::posicion inicial, ListaPos::posicion final) {
    if (inicial != final && l1.anterior(inicial) !=  final && encuentraPivoteAho(l1, inicial, final) != -1) {
        ListaPos::posicion posDivisora = parteYOrdena(l1, inicial, final);
        quickSort(l1, inicial, l1.anterior(posDivisora));
        quickSort(l1, posDivisora, final);
    }
}

/*
@Efecto: Ordena los elementos de la lista en orden ascendente y se manera secuencial iterativa mediante...
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
void seleccionIterativo(ListaPos& lista) {
	ListaPos::posicion posMin;
	ListaPos::posicion posI = lista.getPrimera();
	for (int i = 0; i < lista.numElem() - 1; ++i) {
		ListaPos::posicion posJ = lista.siguiente(posI);
		posMin = posI;
		for (int j = i + 1; j < lista.numElem(); ++j) {
			if (lista.recuperar(posJ) < lista.recuperar(posMin)) {
				posMin = posJ;
			}
			posJ = lista.siguiente(posJ);
		}
		lista.intercambiar(posI, posMin);
		posI = lista.siguiente(posI);
	}
}

/*
@Efecto: Ordena los elementos de la lista en orden ascendente y se manera recursiva mediante...
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
void seleccionRecursivo(ListaPos& lista, int inicio) {
	if (inicio == lista.numElem() - 1) {
		return;
	}
	else {
		ListaPos::posicion posI = traducir(lista, inicio);
		ListaPos::posicion minimo = posI;
		ListaPos::posicion posActual = posI;
		posI = lista.siguiente(posI);
		for (int i = inicio + 1; i <= lista.numElem(); ++i) {
			if (lista.recuperar(posI) < lista.recuperar(minimo)) {
				minimo = posI;
			}
			posI = lista.siguiente(posI);
		}
		lista.intercambiar(posActual, minimo);
		seleccionRecursivo(lista, ++inicio);
	}
}

/*
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de insercion
@Requiere: Una lista inicializada, no vacia sin elementos repetidos
@Modifica: La posicion de los elementos en la lista
*/
void insercionSort(ListaPos& lista) {
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

/*
@Efectua: Mezcla ordenadamente el contenido de 2 listas y lo retorna en una lista
@Requiere: l1 y l2 inicializadas, no vacias y sin elementos repetidos
@Modifica: No modifica las listas recibidas
*/
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
/*
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de MergeSort
@Requiere: Una lista lista inicializada, no vacia sin elementos repetidos, posicion de inicio y final validas dentro de la lista
@Modifica: La posicion de los elementos en la lista
*/
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

/*
@Efectua:le agrega a L1 los elementos que están en L2, de manera que en L1 no
queden elementos repetidos.
@Requiere: L1 y L2 inicializadas y que sean listas ordenadas y sin elementos repetidos.
@Modifica:Modifica l1
*/
void unionOrdenadas(ListaPos& l1, ListaPos& l2) {
	ListaPos::posicion posActual1 = l1.getPrimera();
	ListaPos::posicion posActual2 = l2.getPrimera();
	int elem1 = l1.recuperar(posActual1);
	int elem2 = l2.recuperar(posActual2);
	// Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	bool end = false;
	int cantElementosR1 = 0; // Me indica la cantidad de elementos recorridos en l1
	int cantElementosR2 = 0; // Me indica la cantidad de elementos recorridos en l2
	while (!end) {
		if (elem1 == elem2) {
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
				if (cantElementosR1 < numElemL1) {
					l1.insertar(elem2, posActual1);
					posActual1 = l1.siguiente(posActual1);
				}
				if (cantElementosR2 < numElemL2) {
					posActual2 = l2.siguiente(posActual2);
					elem2 = l2.recuperar(posActual2);
				}
				++cantElementosR2;
			}
			else {
				if (cantElementosR1 < numElemL1) {
					posActual1 = l1.siguiente(posActual1);
					elem1 = l1.recuperar(posActual1);
				}
				++cantElementosR1;
			}
		}
		if (cantElementosR1 >= numElemL1 && cantElementosR2 >= numElemL2) {
			end = true;
		}
	}
}

/*
@Efectua:Le agrega a L1 los elementos que están en L2, de manera que en L1 no
queden elementos repetidos(Supone que L1 y L2 son listas NO necesariamente ordenadas).
@Requiere:L1 y L2 inicializadas y que no tengan elementos repetidos.
@Modifica: Modifica L1
*/
void unionNoOrdenadas(ListaPos& l1, ListaPos& l2) {
	int elem2;
	// Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	bool encontrada;
	ListaPos::posicion posActual1 = l1.getPrimera();
	ListaPos::posicion posActual2 = l2.getPrimera();
	for (int actual2 = 0; actual2 < numElemL2; ++actual2) {
		elem2 = l2.recuperar(posActual2);
		encontrada = false;
		for (int actual1 = 0; actual1 < numElemL1 && !encontrada; ++actual1) {
			if (elem2 == l1.recuperar(posActual1)) {
				encontrada = true;
			}
			posActual1 = l1.siguiente(posActual1);
		}
		posActual1 = l1.getPrimera();
		posActual2 = l2.siguiente(posActual2);
		if (!encontrada) {
			l1.agregarUltimo(elem2);
		}
	}
}

/*
@Efectua:Deja en L3 el resultado de la intersección de L1 y L2.
@Requiere: L1 y L2 sean listas ordenadas y sin elementos repetidos, L3 inicializada y vacía.
@Modifica: Modifica L3
*/
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

/*
@Efectua: Deja en L3 el resultado de la intersección de L1 y L2(emplea un algoritmo de busqueda auxiliar).
@Requiere:Requiere que L1 y L2 estén inicializadas y sean listas ordenadas y sin elementos repetidos.
L3 inicializada y sin elementos
@Modifica: Modifica la L3
*/
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

/*
@Efectua: Deja en L3 el resultado de la intersección de L1 y L2(Supone que L1 y L2 son
listas NO necesariamente ordenadas).
@Requiere:L1 y L2 no tengan elementos repetidos y estén inicializdas.
@Modifica: Modifica L3
*/
void interseccionNoOrdenadas(ListaPos& l1, ListaPos& l2, ListaPos& l3) {
	int elem1;
	// Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	ListaPos::posicion posActual1 = l1.getPrimera();
	ListaPos::posicion posActual2 = l2.getPrimera();
	bool encontrada;
	for (int actual1 = 0; actual1 < numElemL1; ++actual1) {
		elem1 = l1.recuperar(posActual1);
		encontrada = false;
		for (int actual2 = 0; actual2 < numElemL2 && !encontrada; ++actual2) {
			if (elem1 == l2.recuperar(posActual2)) {
				l3.agregarUltimo(elem1);
				encontrada = true;
			}
			posActual2 = l2.siguiente(posActual2);
		}
		posActual2 = l2.getPrimera();
		posActual1 = l1.siguiente(posActual1);
	}
}
//----------------Algoritmos Posicionada



//----------------Algoritmos Indexada
/*
@Efecto: Despliega en pantallos los elementos de la lista
@Requiere: Una lista inicializada
@Modifica: Este metodo no modifica la lista
*/
void listar(ListaInd& lista) {
	lista.imprimir();
}

/*
@Efecto: Averigua si una lista es simetrica verfificando si la primera es igual a la ultima y asi sucesivamente
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
bool simetrica(ListaInd& lista) {
	int indI = 0;
	int indF = lista.numElem() - 1;
	bool esSimetrica = true;
	if (lista.numElem() > 1) {
		while (esSimetrica && indI != indF && indI + 1 != indF) {
			if (lista.recuperar(indI) != lista.recuperar(indF)) {
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
@Efecto: Invierte todos los elementos de una lista, de manera en que el ultimo sea el primero y el primero el ultimo y asi respectivamente
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
void invertir(ListaInd& lista) {
	int indI = 0;
	int indF = lista.numElem() - 1;
	while (indI != indF && indI + 1 != indF) {
		lista.intercambiar(indI, indF);
		++indI;
		--indF;
	}
	lista.intercambiar(indI, indF);
}

/*
@Efecto: Busca en la lista el elemento recibido como parametro y devuelve si existe o no
@Requiere: Una lista no vacia y un elemento valido(de tipo) en la lista
@Modifica: Este metodo no modifica nada
*/
bool buscar(ListaInd& lista, int elemento) {
	bool existe = false;
	int actual = 0;
	int cantElem = lista.numElem();
	while (!existe && actual < cantElem) {
		if (lista.recuperar(actual) == elemento) {
			existe = true;
		}
		++actual;
	}
	return existe;
}

/*
@Efecto: Elimina los elementos repetidos de una lista
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
void eliminarRepetidos(ListaInd& lista) {
	for (int i = 0; i < lista.numElem(); ++i) {
		bool repetido = false;
		for (int j = 0; j < lista.numElem(); ++j) {
			if (i != j && lista.recuperar(i) == lista.recuperar(j)) {
				repetido = true;
				j = lista.numElem();
			}
		}
		if (repetido) {
			lista.borrar(i);
		}
	}
}

/*
@Efecto:
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
bool subLista(ListaInd& lista1, ListaInd& lista2) {
	int indiceL1 = 0;
	int indiceL2 = 0;
	int indiceL2aux = 0;
	bool esSubLista = false;
	while (!esSubLista && indiceL2 < lista2.numElem()) {
		int cont = 0;
		indiceL2aux = indiceL2;
		while (!esSubLista && indiceL1 < lista1.numElem() && indiceL2aux < lista2.numElem() && lista1.recuperar(indiceL1) == lista2.recuperar(indiceL2aux)) {
			++cont;
			if (cont == lista1.numElem()) {
				esSubLista = true;
			}
			++indiceL1;
			++indiceL2aux;
		}
		indiceL1 = 0;
		if (lista1.recuperar(indiceL1) != lista2.recuperar(indiceL2)) {
			++indiceL2;
		}
	}
	return esSubLista;
}

/*
@Efecto: Ordena ascendentemente los elementos en una lista usando el algoritmo de BubbleSort
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
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
				if (lista.recuperar(actual) > lista.recuperar(actual + 1))
				{
					lista.intercambiar(actual, actual + 1);
				}
				++actual;
			}
			else {
				if (lista.recuperar(actual) < lista.recuperar(actual - 1))
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
@Efecto: Ordena los elementos de la lista en orden ascendente y se manera secuencial iterativa mediante...
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
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
@Efecto:Ordena los elementos de la lista en orden ascendente y se manera recursiva mediante...
@Requiere: Una lista no vacia y de tamano minimo de dos
@Modifica: Este metodo modifica la lista
*/
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
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de insercion
@Requiere: Una lista inicializada, no vacia sin elementos repetidos
@Modifica: La posicion de los elementos en la lista
*/
void insercionSort(ListaInd lista) {
	int anterior = 0;
	int ultima = lista.numElem() - 1;
	int actual = 1; //Peligro si lista esta vacia
	int primero = 0; //Si va en el primer indice
	int menor = 0; //Si hay un elemento menor antes
	while (actual <= ultima) {
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
				lista.insertar(lista.recuperar(actual), anterior + 1);
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
@Efecto: Busca la posición donde está el elemento mayor de los primeros dos elementos distintos de la lista si los hay.
@Requiere: Una lista no vacia, e inicializada, y posiciones inicial y final validas dentro de la lista.
@Modifica: Este método no modifica l1.
*/
int encuentraPivoteAho(ListaInd& l1, int inicial, int final) {
	int pivoteTemp1 = l1.recuperar(inicial);
	int indicePivote = -1;
	bool pivoteEncontrado = false;
	int contador = inicial;
	cout << "Pivote\n";
	l1.imprimir();
	while (contador <= final && !pivoteEncontrado) {
		if (pivoteTemp1 > l1.recuperar(contador)) {
			pivoteEncontrado = true;
			indicePivote = inicial;
		}
		else if (pivoteTemp1 < l1.recuperar(contador)) {
			pivoteEncontrado = true;
			indicePivote = contador;
		}
		++contador;
	}
	return indicePivote;
}


/*
@Efecto: Deja en l1 los elementos mayores o iguales que un valor "pivote" del lado derecho de la lista, y los menores de lado izquierdo.
@Requiere: Una lista no vacia, e inicializada, y posiciones inicial y final validas dentro de la lista.
@Modifica: Este método modifica el orden de los elementos de la lista l1, si no tiene todos los elementos iguales.
*/
int parteYOrdena(ListaInd& l1, int inicial, int final) {
	int pivote = l1.recuperar(encuentraPivoteAho(l1, inicial, final));
	int inicioEMP = -1; // Guarda el indice donde inician los elemento mayores que el pivote
	while (inicial < final) {
		l1.intercambiar(inicial, final);
		while (l1.recuperar(inicial) < pivote) {
			++inicial;
			inicioEMP = inicial;
		}
		while (l1.recuperar(final) >= pivote) {
			--final;
		}
	}
	return inicioEMP;
}


/*
@Efecto: Ordena los elementos ascendentemente de la lista.
@Requiere: Una lista no vacia, e inicializada, y posiciones inicial y final validas dentro de la lista.
@Modifica: Este método modifica el orden de los elementos de la lista l1 si no están en orden ascendente, y tiene no tiene todos los elementos iguales.
*/
void quickSort(ListaInd& l1, int inicial, int final) {
	if (inicial != final && inicial < final && encuentraPivoteAho(l1, inicial, final) != -1) {
		int indiceDivisor = parteYOrdena(l1, inicial, final);
		quickSort(l1, inicial, indiceDivisor - 1);
		quickSort(l1, indiceDivisor, final);
	}
}

/*
@Efectua: Mezcla ordenadamente el contenido de 2 listas y lo retorna en una lista
@Requiere: l1 y l2 inicializadas, no vacias y sin elementos repetidos
@Modifica: No modifica las listas recibidas
*/
void merge(ListaInd l1, ListaInd l2, ListaInd& l3) {
	l3.vaciar();
	int actualL1 = 0;
	int actualL2 = 0;
	int ultimoL1 = l1.numElem() - 1;
	int ultimoL2 = l2.numElem() - 1;
	int actualL3 = 0;
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
}
/*
@Efectua: Ordena ascendentemente los elementos en una lista usando el algoritmo de MergeSort
@Requiere: Una lista lista inicializada, no vacia sin elementos repetidos, posicion de inicio y final validas dentro de la lista
@Modifica: La posicion de los elementos en la lista
*/
void mergeSort(ListaInd& lista) {
	int numElem = lista.numElem();
	if (numElem > 1) {
		int mitad = numElem / 2;
		int posActual = 0;
		ListaInd primerMitad = ListaInd();
		ListaInd segundaMitad = ListaInd();

		for (int i = 0; i < mitad; ++i) {
			primerMitad.insertar(lista.recuperar(posActual), i);
			++posActual;
		}
		for (int i = mitad; i < numElem; ++i) {
			segundaMitad.insertar(lista.recuperar(posActual), i);
			++posActual;
		}
		mergeSort(primerMitad);
		mergeSort(segundaMitad);
		merge(primerMitad, segundaMitad, lista);
	}
}

/*
@Efectua:le agrega a L1 los elementos que están en L2, de manera que en L1 no
queden elementos repetidos.
@Requiere: L1 y L2 inicializadas y que sean listas ordenadas y sin elementos repetidos.
@Modifica:Modifica l1
*/
void unionOrdenadas(ListaInd& l1, ListaInd& l2) {
	int actual1 = 0;
	int elem1 = l1.recuperar(actual1);
	int actual2 = 0;
	int elem2 = l2.recuperar(actual2);
	// Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	bool end = false;
	int cantElementosR1 = 1; // Me indica la cantidad de elementos recorridos en l1
	int cantElementosR2 = 1; // Me indica la cantidad de elementos recorridos en l2
	while (!end) {
		if (elem1 == elem2) {
			if (cantElementosR1 < numElemL1) {
				elem1 = l1.recuperar(++actual1);
			}

			if (cantElementosR2 < numElemL2) {
				elem2 = l2.recuperar(++actual2);
			}
			if (elem2 > elem1&& elem1 == l1.recuperar(l1.numElem() - 1)) {
				actual1 = l1.numElem();
				l1.insertar(elem2, actual1);
			}
			++cantElementosR1;
			++cantElementosR2;
		}
		else {
			if (elem1 > elem2) {
				l1.insertar(elem2, actual1);
				l1.imprimir();
				++actual1;
				if (cantElementosR2 < numElemL2) {
					elem2 = l2.recuperar(++actual2);
				}
				++cantElementosR2;
			}
			else {
				if (cantElementosR1 < numElemL1) {
					elem1 = l1.recuperar(++actual1);
				}
				else {
					elem1 = l1.recuperar(l1.numElem() - 1);
					actual1 = l1.numElem();
				}
				++cantElementosR1;
			}
		}
		if (cantElementosR1 >= numElemL1 && cantElementosR2 >= numElemL2) {
			end = true;
		}
	}
}

/*
@Efectua:Le agrega a L1 los elementos que están en L2, de manera que en L1 no
queden elementos repetidos(Supone que L1 y L2 son listas NO necesariamente ordenadas).
@Requiere:L1 y L2 inicializadas y que no tengan elementos repetidos.
@Modifica: Modifica L1
*/
void unionNoOrdenadas(ListaInd& l1, ListaInd& l2) {
	int elem2;
	// Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	bool encontrada;
	int posElemInsercion;
	for (int actual2 = 0; actual2 < numElemL2; ++actual2) {
		elem2 = l2.recuperar(actual2);
		encontrada = false;
		for (int actual1 = 0; actual1 < numElemL1 && !encontrada; ++actual1) {
			if (elem2 == l1.recuperar(actual1)) {
				encontrada = true;
			}
		}
		if (!encontrada) {
			l1.insertar(elem2, l1.numElem());
		}
	}
}

/*
@Efectua:Deja en L3 el resultado de la intersección de L1 y L2.
@Requiere: L1 y L2 sean listas ordenadas y sin elementos repetidos, L3 inicializada y vacía.
@Modifica: Modifica L3
*/
void interseccionOrdenadasV1(ListaInd& l1, ListaInd& l2, ListaInd& l3) {
	int actual1 = 0;
	int elem1 = l1.recuperar(actual1);
	int actual2 = 0;
	int elem2 = l2.recuperar(actual2);
	// Se usan las variables elem1 y elem2 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int actual3 = 0;
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	bool end = false;
	int cantElementosR1 = 0; // Me indica si la cantidad de elemetnos recorridos en l1
	int cantElementosR2 = 0;
	while (!end) {
		if (elem1 == elem2) {
			l3.insertar(elem1, actual3++);
			elem1 = l1.recuperar(++actual1);
			elem2 = l2.recuperar(++actual2);
			++cantElementosR1;
			++cantElementosR2;
		}
		else {
			if (elem1 > elem2) {
				elem2 = l2.recuperar(++actual2);
				++cantElementosR2;
			}
			else {
				elem1 = l1.recuperar(++actual1);
				++cantElementosR1;
			}
		}
		if (cantElementosR1 == numElemL1 || cantElementosR2 == numElemL2) {
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
void interseccionOrdenadasV2(ListaInd& l1, ListaInd& l2, ListaInd& l3) {
	int elem1;// Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int actual3 = 0;
	for (int actual1 = 0; actual1 <= numElemL1; ++actual1) {
		elem1 = l1.recuperar(actual1);
		if (buscar(l2, elem1)) {
			l3.insertar(elem1, actual3++);
		}
	}
}

/*
@Efectua: Deja en L3 el resultado de la intersección de L1 y L2(Supone que L1 y L2 son
listas NO necesariamente ordenadas).
@Requiere:L1 y L2 no tengan elementos repetidos y estén inicializdas.
@Modifica: Modifica L3
*/
void interseccionNoOrdenadas(ListaInd& l1, ListaInd& l2, ListaInd& l3) {
	int elem1;
	// Se usa la variable elem1 con el fin de no hacer muchos llamados al metodo recuperar(int)
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	int actual3 = 0;
	bool encontrada;
	for (int actual1 = 0; actual1 < numElemL1; ++actual1) {
		elem1 = l1.recuperar(actual1);
		encontrada = false;
		for (int actual2 = 0; actual2 < numElemL2 && !encontrada; ++actual2) {
			if (elem1 == l2.recuperar(actual2)) {
				l3.insertar(elem1, actual3++);
				encontrada = true;
			}
		}
	}
}
//----------------Algoritmos Indexada



//----------------Algoritmos Ordenada
/*
@Efecto: Despliega en pantallos los elementos de la lista
@Requiere: Una lista inicializada
@Modifica: Este metodo no modifica la lista
*/
void listar(ListaOrdenada& lista) {
	lista.imprimir();
}

//Efecto: Averigua si L1 es igual a L2, y retorna un booleano true si son iguales, false si no lo son.
//Requiere: L1 , L2 inicializadas
//Modifica: No modifica las listas
bool iguales(ListaOrdenada& l1, ListaOrdenada& l2) {
	bool iguales = true;
	int actual1 = l1.primero();
	int actual2 = l2.primero();
	int cantElementos = 0;
	if (l1.numElem() != l2.numElem()) {
		iguales = false;
		cantElementos = l1.numElem();
	}
	int contador = 1;
	while (iguales && contador <= cantElementos) {
		if (actual1 != actual2) {
			iguales = false;
		}
		else {
			actual1 = l1.siguiente(actual1);
			actual2 = l2.siguiente(actual2);
			++contador;
		}
	}
	return iguales;
}

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

//Efecto: Revisa si la lista listaPorVerificar está contenida en listaPrincipal, retorna un booleano true si está contenida, false si no
//Requiere: listaPorVerificar  y listaPrincipal inicializadas
//Modifica: No modifica las listas
bool contenida(ListaOrdenada& listaPorVerificar, ListaOrdenada& listaPrincipal) {
	bool contenida = false;
	if (listaPrincipal.numElem() >= listaPorVerificar.numElem()) {
		int actual1 = listaPorVerificar.primero();
		int actual2 = listaPrincipal.primero();
		int cantElementosLPorVerificar = listaPorVerificar.numElem();
		int elemContenidos = 0;
		int cantElementosLPrincipal = listaPrincipal.numElem();
		for (int i = 1; i <= cantElementosLPrincipal && elemContenidos != cantElementosLPorVerificar; ++i) {
			if (actual1 == actual2) {
				++elemContenidos;
				actual1 = listaPorVerificar.siguiente(actual1);
				actual2 = listaPrincipal.siguiente(actual2);
			}
			else {
				actual2 = listaPrincipal.siguiente(actual2);
			}
		}
		if (elemContenidos == cantElementosLPorVerificar) {
			contenida = true;
		}
	}
	return contenida;
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
	while (cont <= lista.numElem() && !pertenece) {
		if (elemento == actual) {
			pertenece = true;
		}
		actual = lista.siguiente(actual);
	}
	return pertenece;
}

//Efecto:Eliminar de l1 los elementos que están en l2
//Requiere:l1,l2 inicializadas
//Modifica: Modifica la lista l1
void borrarComunes(ListaOrdenada& l1, ListaOrdenada& l2) {
	int actual1 = l1.primero();
	int actual2 = l2.primero();
	int numElemL1 = l1.numElem();
	int victima;
	cout << "numElemL1:" << numElemL1 << endl;
	bool end = false;
	int cantElementosR1 = 0;
	while (!end) {
		if (actual1 == actual2) {
			victima = actual1;
			actual1 = l1.siguiente(actual1);
			actual2 = l2.siguiente(actual2);
			l1.borrar(victima);
			++cantElementosR1;
			cout << "cantElementosR1:" << cantElementosR1 << endl;
		}
		else {
			if (actual1 > actual2) {
				actual2 = l2.siguiente(actual2);
			}
			else {
				actual1 = l1.siguiente(actual1);
				++cantElementosR1;
			}
		}
		if (cantElementosR1 == numElemL1) {
			end = true;
		}
	}
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

	while (contador <= lista1.numElem() && contador <= lista2.numElem()) {
		listaUnion.insertar(actualL1);
		listaUnion.insertar(actualL2);
		actualL1 = lista1.siguiente(actualL1);
		actualL2 = lista2.siguiente(actualL2);
		++contador;
	}
	while (contador <= lista1.numElem()) {
		listaUnion.insertar(actualL1);
		actualL1 = lista1.siguiente(actualL1);
		++contador;
	}

	while (contador <= lista2.numElem()) {
		listaUnion.insertar(actualL2);
		actualL2 = lista2.siguiente(actualL2);
		++contador;
	}

}

//Efecto:Deja en L3 el resultado de la intersección de L1 y L2
//Requiere:l1,l2,l3 inicializadas
//Modifica: Modifica la lista l3
void interseccion(ListaOrdenada& l1, ListaOrdenada& l2, ListaOrdenada& l3) {
	int actual1 = l1.primero();
	int actual2 = l2.primero();
	int numElemL1 = l1.numElem();
	int numElemL2 = l2.numElem();
	bool end = false;
	int cantElementosR1 = 0;
	int cantElementosR2 = 0;
	while (!end) {
		if (actual1 == actual2) {
			l3.insertar(actual1);
			actual1 = l1.siguiente(actual1);
			actual2 = l2.siguiente(actual2);
			++cantElementosR1;
		}
		else {
			if (actual1 > actual2) {
				actual2 = l2.siguiente(actual2);
			}
			else {
				actual1 = l1.siguiente(actual1);
				++cantElementosR1;
			}
		}
		if (cantElementosR1 == numElemL1 || cantElementosR2 == numElemL2) {
			end = true;
		}
	}
}
//----------------Algoritmos Ordenada

void pruebaListaP(ListaPos& listaP) {
	int opcion = 0;
	do {
		system("cls");
		cout << "\n\t ---- Lista Posicionada ---\n\n 1. Preguntar si la lista esta vacia\n 2. Vaciar la Lista\n 3. Insertar Elemento\n 4. Agregar Elemento al Final\n 5. Borrar Elemento\n 6. Recuperar Elemento\n"
			<< " 7. Modificar Elemento\n 8. Intercambiar Elementos\n 9. Preguntar el Numero de Elementos\n 10. Elemento Siguiente\n 11. Elemento Anterior\n 12. Primer Elemento\n 13. Ultimo Elemento\n 14. Regresar \n\n  -Digite una opcion: " << endl;
		cin >> opcion;
		int elemento, indice = 0;
		ListaPos::posicion pos;
		switch (opcion)
		{
		case 1:
			system("cls");
			listaP.vacia() ? cout << "\n\t ---- Lista Posicionada ---\n\n -Esta vacia" : cout << "\n\t ---- Lista Posicionada ---\n\n -No esta vacia" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2: {
			system("cls");
			char opc = 'N';
			cout << "\n\t ---- Lista Posicionada ---\n\n -Desea vaciar la lista?(S/N) ";
			cin >> opc;
			if (opc == 'S' || opc == 's') {
				listaP.vaciar();
				cout << "\n ---Lista vaciada correctamente --- ";
			}
			else {
				cout << "\n ---Lista NO fue vaciada --- ";
			}
			getch();
			break;
		}
		case 3:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Que elemento desea insertar?: ";
			cin >> elemento;
			cout << "\n\n -En que posicion desea insertar?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			listaP.insertar(elemento, pos);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Que elemento desea insertar?: ";
			cin >> elemento;
			listaP.agregarUltimo(elemento);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 5:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Que posicion desea borrar?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			listaP.borrar(pos);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 6:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Que posicion desea recuperar?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			cout << "\n\n El elemento es: " << listaP.recuperar(pos) << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Que posicion desea modificar?: ";
			cin >> indice;
			cout << "\n\n -Que elemento desea insertar en esa posicion?: ";
			cin >> elemento;
			pos = traducir(listaP, indice);
			listaP.modificar(pos, elemento);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 8: {
			system("cls");
			indice = 0;
			int indice2 = 0;
			ListaPos::posicion pos2;
			cout << "\n\t ---- Lista Posicionada ---\n\n -Digite la primera posicion por intercambiar: ";
			cin >> indice;
			cout << "\n -Digite la segunda posicion por intercambiar: ";
			cin >> indice2;
			pos = traducir(listaP, indice);
			pos2 = traducir(listaP, indice2);
			listaP.intercambiar(pos, pos2);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 9:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -La lista tiene " << listaP.numElem() << " elementos." << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 10:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -De que posicion desea conocer el siguiente elemento?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			cout << "\n\n El elemento es: " << listaP.recuperar(listaP.siguiente(pos));
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 11:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -De que posicion desea conocer el elemento anterior?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			cout << "\n\n El elemento es: " << listaP.recuperar(listaP.anterior(pos));
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 12:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -El primer elemento es: " << listaP.recuperar(listaP.getPrimera());
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 13:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -El ultimo elemento es: " << listaP.recuperar(listaP.getUltima());
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 14:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while (opcion != 14);
}

void pruebaListaI(ListaInd& listaI) {
	int opcion = 0;
	do {
		system("cls");
		cout << "\n\t ---- Lista Indexada ---\n\n 1. Preguntar si la lista esta vacia\n 2. Vaciar la Lista\n 3. Insertar Elemento\n 4. Borrar Elemento\n 5. Recuperar Elemento\n"
			<< " 6. Modificar Elemento\n 7. Intercambiar Elementos\n 8. Preguntar el Numero de Elementos\n 9. Regresar \n\n  -Digite una opcion: " << endl;
		cin >> opcion;
		int elemento, indice, indice1, indice2;
		switch (opcion)
		{
		case 1:
			system("cls");
			listaI.vacia() ? cout << "\n\t ---- Lista Indexada ---\n\n -Esta vacia" : cout << "\n\t ---- Lista Indexada ---\n\n -No esta vacia" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2: {
			system("cls");
			char opc = 'N';
			cout << "\n\t ---- Lista Indexada ---\n\n -Desea vaciar la lista?(S/N) ";
			cin >> opc;
			if (opc == 'S' || opc == 's') {
				listaI.vaciar();
				cout << "\n ---Lista vaciada correctamente --- ";
			}
			else {
				cout << "\n ---Lista NO fue vaciada --- ";
			}
			getch();
			break;
		}
		case 3:
			system("cls");
			cout << "\n\t ---- Lista Indexada ---\n\n -Que elemento desea insertar?: ";
			cin >> elemento;
			cout << "\n\n -En que indice desea insertar?: ";
			cin >> indice;
			listaI.insertar(elemento, indice);
			listaI.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4:
			system("cls");
			cout << "\n\t ---- Lista indexada ---\n\n -Que indice desea borrar?: ";
			cin >> indice;
			listaI.borrar(indice);
			listaI.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 5:
			system("cls");
			cout << "\n\t ---- Lista Indexada ---\n\n -Que indice desea recuperar?: ";
			cin >> indice;
			cout << "\n\n El elemento es: " << listaI.recuperar(indice) << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 6:
			system("cls");
			cout << "\n\t ---- Lista Indexada ---\n\n -Que indice desea modificar?: ";
			cin >> indice;
			cout << "\n\n -Que elemento desea insertar en esa posicion?: ";
			cin >> elemento;
			listaI.modificar(elemento, indice);
			listaI.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
			system("cls");
			cout << "\n\t ---- Lista Indexada ---\n\n -Digite el primer indice por intercambiar: ";
			cin >> indice1;
			cout << "\n -Digite el segundo indice por intercambiar: ";
			cin >> indice2;
			listaI.intercambiar(indice1, indice2);
			listaI.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 8:
			system("cls");
			cout << "\n\t ---- Lista Indexada ---\n\n -La lista tiene " << listaI.numElem() << " elementos." << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 9:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while (opcion != 9);
}

void pruebaListaO(ListaOrdenada& listaO) {
	int opcion = 0;
	do {
		system("cls");
		cout << "\n\t ---- Lista Ordenada ---\n\n 1. Preguntar si la lista esta vacia\n 2. Vaciar la Lista\n 3. Insertar Elemento\n 4. Borrar Elemento\n"
			<< " 5. Preguntar el Numero de Elementos\n 6. Elemento Siguiente\n 7. Elemento Anterior\n 8. Primer Elemento\n 9. Ultimo Elemento\n 10. Regresar \n\n  -Digite una opcion: " << endl;
		cin >> opcion;
		int elemento, indice = 0;
		char opc = 'N';
		switch (opcion)
		{
		case 1:
			system("cls");
			listaO.vacia() ? cout << "\n\t ---- Lista Ordenada ---\n\n -Esta vacia" : cout << "\n\t ---- Lista Ordenada ---\n\n -No esta vacia" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -Desea vaciar la lista?(S/N) ";
			cin >> opc;
			if (opc == 'S' || opc == 's') {
				listaO.vaciar();
				cout << "\n ---Lista vaciada correctamente --- ";
			}
			else {
				cout << "\n ---Lista NO fue vaciada --- ";
			}
			getch();
			break;
		case 3:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -Que elemento desea insertar?: ";
			cin >> elemento;
			listaO.insertar(elemento);
			listaO.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -Que elemento desea borrar?: ";
			cin >> elemento;
			listaO.borrar(elemento);
			listaO.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 5:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -La lista tiene " << listaO.numElem() << " elementos." << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 6:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -De que elemento desea conocer el siguiente?: ";
			cin >> elemento;
			cout << "\n\n El elemento es: " << listaO.siguiente(elemento);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -De que elemento desea conocer el elemento anterior?: ";
			cin >> elemento;
			cout << "\n\n El elemento es: " << listaO.anterior(elemento);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 8:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -El primer elemento es: " << listaO.primero();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 9:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -El ultimo elemento es: " << listaO.ultimo();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 10:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while (opcion != 10);
}

void pruebaAlgoritmosP(ListaPos& listaP, ListaPos& listaP2) {
	int opcion = 0;
	do {
		system("cls");
		cout << "\n\t ---- Lista Posicionada ---\n\n 1. Listar\n 2. Es simetrica?\n 3. Invertir lista\n 4. Buscar elemento\n 5. Borrar Elementos Repetidos\n 6. Es Lista 2 sublista de Lista 1?\n"
			<< " 7. Ordenar por Burbuja \n 8. Ordenar por Burbuja Bi\n 9. Ordenar por Seleccion Iterativo\n 10. Ordenar por Seleccion Recursiva\n 11. Ordenar por Insercion\n 12. Ordenar por QuickSort\n 13. Ordenar por QuickSort-Insercion\n 14. Ordenar por MergeSort\n 15. Union de las 2 listas Ordenadas\n 15. Union de las 2 listas No ordenadas\n 16.Interseccion de las 2 listas Ordenadas V.1\n 17. 16.Interseccion de las 2 listas Ordenadas V.2\n 18. 16.Interseccion de las 2 listas No ordenadas\n 19. Regresar\n\n  -Digite una opcion: " << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n ";
			simetrica(listaP) ? cout << " -Es simetrica" : cout << " -No es simetrica" << endl;;
			getch();
			break;
		}
		case 3:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			invertir(listaP);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Digite el elemento a buscar: ";
			int elem = 0;
			cin >> elem;
			buscar(listaP, elem) ? cout << " -El elemento esta" : cout << " -El elemento no esta" << endl;
			getch();
			break;
		}
		case 5:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			eliminarRepetidos(listaP);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 6:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			//subLista(listaP,listaP2) ? cout << " -Es sublista" : cout << " -No es sublista" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			burbujaOriginal(listaP);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 8:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			Burbuja_BiDireccional(listaP);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 9:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			seleccionIterativo(listaP);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 10:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			seleccionRecursivo(listaP,1);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 11:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			insercionSort(listaP);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 12:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			//quickSort(listaP, listaP.getPrimera(), listaP.getUltima());
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 13:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			//quickSort(listaP, listaP.getPrimera(), listaP.getUltima());
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 14:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			mergeSort(listaP);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 15:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			unionOrdenadas(listaP,listaP2);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 16:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			unionNoOrdenadas(listaP,listaP2);
			cout << endl;
			listar(listaP);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 17: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			ListaPos l3 = ListaPos();
			interseccionOrdenadasV1(listaP, listaP2, l3);
			cout << endl;
			listar(l3);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 18:
		{
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			ListaPos l3 = ListaPos();
			interseccionOrdenadasV2(listaP, listaP2, l3);
			cout << endl;
			listar(l3);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 19:
		{
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaP);
			ListaPos l3 = ListaPos();
			interseccionNoOrdenadas(listaP, listaP2, l3);
			cout << endl;
			listar(l3);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 20:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while (opcion != 20);
}

void pruebaAlgoritmosI(ListaInd& listaI, ListaInd& listaI2) {
	int opcion = 0;
	do {
		system("cls");
		cout << "\n\t ---- Lista Posicionada ---\n\n 1. Listar\n 2. Es simetrica?\n 3. Invertir lista\n 4. Buscar elemento\n 5. Borrar Elementos Repetidos\n 6. Es Lista 2 sublista de Lista 1?\n"
			<< " 7. Ordenar por Burbuja \n 8. Ordenar por Burbuja Bi\n 9. Ordenar por Seleccion Iterativo\n 10. Ordenar por Seleccion Recursiva\n 11. Ordenar por Insercion\n 12. Ordenar por QuickSort\n 13. Ordenar por QuickSort-Insercion\n 14. Ordenar por MergeSort\n 15. Union de las 2 listas Ordenadas\n 15. Union de las 2 listas No ordenadas\n 16.Interseccion de las 2 listas Ordenadas V.1\n 17. 16.Interseccion de las 2 listas Ordenadas V.2\n 18. 16.Interseccion de las 2 listas No ordenadas\n 19. Regresar\n\n  -Digite una opcion: " << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n ";
			simetrica(listaI) ? cout << " -Es simetrica" : cout << " -No es simetrica" << endl;;
			getch();
			break;
		}
		case 3:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			invertir(listaI);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Digite el elemento a buscar: ";
			int elem = 0;
			cin >> elem;
			buscar(listaI, elem) ? cout << " -El elemento esta" : cout << " -El elemento no esta" << endl;
			getch();
			break;
		}
		case 5:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			eliminarRepetidos(listaI);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 6:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			subLista(listaI, listaI2) ? cout << " -Es sublista" : cout << " -No es sublista" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			burbujaOriginal(listaI);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 8:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			Burbuja_BiDireccional(listaI);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 9:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			seleccionIterativo(listaI);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 10:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			seleccionRecursivo(listaI, 1);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 11:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			insercionSort(listaI);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 12:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			quickSort(listaI, 0, listaI.numElem()-1);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 13:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			quickSort(listaI, 0, listaI.numElem() - 1);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 14:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			mergeSort(listaI);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 15:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			unionOrdenadas(listaI, listaI2);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 16:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			unionNoOrdenadas(listaI, listaI2);
			cout << endl;
			listar(listaI);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 17: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			ListaInd l3 = ListaInd();
			interseccionOrdenadasV1(listaI, listaI2, l3);
			cout << endl;
			listar(l3);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 18:
		{
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			ListaInd l3 = ListaInd();
			interseccionOrdenadasV2(listaI, listaI2, l3);
			cout << endl;
			listar(l3);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 19:
		{
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaI);
			ListaInd l3 = ListaInd();
			interseccionNoOrdenadas(listaI, listaI2, l3);
			cout << endl;
			listar(l3);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 20:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while (opcion != 20);
}

void pruebaAlgoritmosO(ListaOrdenada& listaO, ListaOrdenada& listaO2) {
	int opcion = 0;
	do {
		system("cls");
		cout << "\n\t ---- Lista Posicionada ---\n\n 1. Listar\n 2. Lista 1 es igual a Lista 2?\n 3. Copiar en Lista 2 Lista 1\n 4. Esta Lista 1 contenida en Lista 2?\n 5. Pertenece Elemento\n 6. Eliminar de Lista 1 los elementos de Lista 2\n"
			<< " 7. Union de las 2 listas \n 8. Interseccion de las 2 listas\n 9. Regresar\n\n  -Digite una opcion: " << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaO);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n ";
			iguales(listaO, listaO2) ? cout << " -Son iguales" : cout << " -No son iguales" << endl;;
			getch();
			break;
		}
		case 3:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaO);
			copiar(listaO, listaO2);
			cout << "\nL2: " << endl;
			listar(listaO2);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n";
			int elem = 0;
			cin >> elem;
			contenida(listaO, listaO2) ? cout << " -Esta contenida" : cout << " -No esta contenida" << endl;
			getch();
			break;
		}
		case 5: {
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Digite el elemento a buscar: " << endl;
			int elem = 0;
			cin >> elem;
			pertenece(listaO, elem) ? cout << " -Pertenece" : cout << " -No pertenece" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 6:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaO);
			cout << endl;
			listar(listaO2);
			borrarComunes(listaO, listaO2);
			cout << endl;
			listar(listaO);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
		{
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaO);
			cout << endl;
			listar(listaO2);
			ListaOrdenada l3 = ListaOrdenada();
			unionListas(listaO, listaO2, l3);
			cout << endl;
			listar(l3);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 8:
		{
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n" << endl;
			listar(listaO);
			cout << endl;
			listar(listaO2);
			ListaOrdenada l3 = ListaOrdenada();
			interseccion(listaO, listaO2, l3);
			cout << endl;
			listar(l3);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 9:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while (opcion != 9);
}

void menuPosicionada(ListaPos& listaP) {
	int op = 0;
	ListaPos listaP2 = ListaPos();
	do {
		system("cls");
		cout << "\n\t ----- Menu Posicionada ----- \n\n 1-) Operadores Basicos: Lista 1" << "\n 2-) Operadores Basicos: Lista 2" << "\n 3-) Algoritmos" << "\n 4-) Regresar\n\n  -Digite una opcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			pruebaListaP(listaP);
			break;
		case 2:
			pruebaListaP(listaP2);
			break;
		case 3:
			pruebaAlgoritmosP(listaP, listaP2);
			break;
		case 4:
			break;
		default:
			cout << "Opcion Invalida" << endl;
			break;
		}
	} while (op != 4);
}

void menuIndexada(ListaInd& listaI) {
	int op = 0;
	ListaInd listaI2 = ListaInd();
	do {
		system("cls");
		cout << "\n\t ----- Menu Posicionada ----- \n\n 1-) Operadores Basicos: Lista 1" << "\n 2-) Operadores Basicos: Lista 2" << "\n 3-) Algoritmos" << "\n 4-) Regresar\n\n  -Digite una opcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			pruebaListaI(listaI);
			break;
		case 2:
			pruebaListaI(listaI2);
			break;
		case 3:
			pruebaAlgoritmosI(listaI, listaI2);
			break;
		case 4:
			break;
		default:
			cout << "Opcion Invalida" << endl;
			break;
		}
	} while (op != 4);
}

void menuOrdenada(ListaOrdenada& listaO) {
	int op = 0;
	ListaOrdenada listaO2 = ListaOrdenada();
	do {
		system("cls");
		cout << "\n\t ----- Menu Posicionada ----- \n\n 1-) Operadores Basicos: Lista 1" << "\n 2-) Operadores Basicos: Lista 2" << "\n 3-) Algoritmos" << "\n 4-) Regresar\n\n  -Digite una opcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			pruebaListaO(listaO);
			break;
		case 2:
			pruebaListaO(listaO2);
			break;
		case 3:
			pruebaAlgoritmosO(listaO, listaO2);
			break;
		case 4:
			break;
		default:
			cout << "Opcion Invalida" << endl;
			break;
		}
	} while (op != 4);
}

int main() {
	ListaPos listaP; //Lista Posicionada
	ListaInd listaI; //Lista Indexada
	ListaOrdenada listaO; //Lista Ordenada

	int op = 0;
	do {
		system("cls");
		cout << "\n\t ----- Menu Principal ----- \n\n 1-) Lista Posicionada: " << listaP.getNombre() << "\n 2-) Lista Indexada: " << listaI.getNombre() << """\n 3-) Lista Ordenada: " << listaO.getNombre() << "\n 4-) Salir\n\n  -Digite una opcion: ";
		cin >> op;
		switch (op)
		{
		case 1:
			menuPosicionada(listaP);
			break;
		case 2:
			menuIndexada(listaI);
			break;
		case 3:
			menuOrdenada(listaO);
			break;
		case 4:
			cout << "Programa terminado con exito!" << endl;
			break;
		default:
			cout << "Opcion Invalida" << endl;
			break;
		}
	} while (op != 4);
	return 0;
}
