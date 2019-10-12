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
