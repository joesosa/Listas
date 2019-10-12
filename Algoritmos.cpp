/*
@Efecto: Inserta todos los datos de la lista original en la nueva con el fin de que queden exactamente iguales
@Requiere: Una lista original no vacia y una lista nueva sin elementos
@Modifica: La lista nueva
*/
void copiar(ListaOrdenada& listaOriginal, ListaOrdenada& listaNueva) {
	int actual = listaOriginal.primero();
	int cont = 1;
	while (cont <= listaoriginal.numElem()) {
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
	bool perenece = false;
	int actual = lista.primero();
	int cont = 0;
	while (cont <= listaoriginal.numElem() && pertenece){
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
ListaOrdenada& union(ListaOrdenada& lista1, ListaOrdenada& lista2) {
	ListaOrdenada listaUnion;
	int actualL1= lista1.primero();
	int contadorL1 = 1;
	while (contadorL1 <= lista1.numElem()) {
		int contadorL2 = 1;
		int actualL2 = lista2.primero();
		while (contadorL2 <= lista2.numElem()) {
			if (actualL1 == actualL2) {
				listaUnion.insertar(actualL1);
				actualL2 = lista2.ultimo();
			}
			else {
				actualL2 = lista2.siguiente(actualL2);
			}
			
		actualL1 = lista1.siguiente(actualL1);
	}
	return listaUnion;
}
