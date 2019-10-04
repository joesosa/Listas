#include "ListaOrdenada_LSE.h"


ListaOrdenada::Celda::Celda(int elemento){
    this->elemento = elemento;
    siguiente = 0;
}

ListaOrdenada::Celda::~Celda(){
    if(siguiente){
        delete siguiente;
    }
}


//Efecto: Inicializa la lista dejándola accesible para que el resto de operadores básicos puedan trabajar en ella.
//Requiere: Este operador no tiene requerimientos.
//Modifica: Modifica la lista.
ListaOrdenada::ListaOrdenada(){
    primera = 0;
    ultima = 0;
    numElementos = 0;
}

//Efecto: Destruye la existencia de la lista.
//Requiere: Una lista inicializada.
//Modifica: Modifica la lista.
ListaOrdenada::~ListaOrdenada(){
  if(primera){
     delete primera;
 }
}

//Efecto: Edita la lista indexada de modo que termine con 0 elementos.
//Requiere: Una lista inicializada.
//Modifica: Modifica la lista.
void ListaOrdenada::vaciar(){
  if(primera->siguiente){
      delete primera->siguiente;
  }
  primera = 0;
}

//Efecto: Devuelve un valor de verdad (verdadero o falso) acorde al estado de la lista recibida.
//Requiere: Una lista inicializada.
//Modifica: No aplica.
bool ListaOrdenada::vacia(){
    return primera;
}

//Efecto: Agrega el elemento recibido como parámetro en su posición correspondiente,
// de modo que su anterior(sí existe) sea menor y su siguiente(si existe) sea mayor.
//Aumenta el tamaño en uno.
//Requiere: Una lista inicializada y un elemento no existente.
//Modifica: Modifica la lista.
void ListaOrdenada::insertar(int elemento){
    bool existe = false;
    Celda * posElemento = 0;
    if( primera && elemento == primera->elemento ){
      existe = true;
    }
    else if(ultima && elemento>ultima->elemento){
      Celda * nueva = new Celda(elemento);
      ultima->siguiente = ultima;
      ultima = nueva;
      existe = true;
      ++numElementos;
    }
    else if(primera && elemento < primera->elemento){
      Celda * nueva = new Celda(elemento);
      nueva->siguiente = primera;
      primera = nueva;
      existe = true;
      ++numElementos;
    }
    else if(!existe && primera && elemento > primera->elemento){
      Celda * actual = primera;
      Celda * anterior = 0;
      while(actual->siguiente && !existe){
        anterior = actual;
        if(anterior->elemento < elemento && elemento < actual->siguiente->elemento ){
          Celda * nueva = new Celda(elemento);
          anterior->siguiente = nueva;
          anterior->siguiente->siguiente = actual->siguiente;
          existe = true;
          ++numElementos;
         }
        actual = actual->siguiente;
      }
    }
}



//Efecto: Elimina el elemento recibido como parámetro de la lista. A su vez decrementa el tamaño de la lista en uno.
//Requiere: Una lista inicializada y un elemento existente en la lista.
//Modifica: Modifica la lista
void ListaOrdenada::borrar(int elemento){
    Celda * posElemento = 0;
    Celda * actual = primera;
    Celda * anterior = 0;
    bool encontrado = false;
    if(primera && elemento == primera->elemento){
      posElemento = primera;
    }
    else{
      while(actual->siguiente && !encontrado){
        if(elemento == actual->siguiente->elemento){
          anterior = actual;
          posElemento = actual->siguiente;
          encontrado = true;
        }
        actual = actual->siguiente;
      }
    }
    if(actual){
      if (posElemento == primera) {
		      primera = primera->siguiente;
		      posElemento->siguiente = 0;
		      delete posElemento;
	     }
       else if (posElemento == ultima){
           ultima = anterior;
           delete posElemento;
         }
       else{
         anterior->siguiente = posElemento->siguiente;
       }
     --numElementos;
     }
    }

//Efecto: Retorna el primer elemento de la lista ordenada.
//Requiere: Una lista inicializada y una lista no vacía.
//Modifica: Este operador no realiza modificaciones.
int ListaOrdenada::primero(){
  return primera->elemento;
}

//Efecto: Retorna el último elemento de la lista ordenada.
//Requiere: Una lista inicializada y una lista con al menos un elemento..
//Modifica: Este operador no realiza modificaciones.
int ListaOrdenada::ultimo(){
  return ultima->elemento;
}

//Efecto: Retorna el elemento siguiente del elemento recibido como parámetro.
//Requiere: Una lista inicializada y que el elemento siguiente al recibido exista.
//Modifica: Este operador no realiza modificaciones.
int ListaOrdenada::siguiente(int elemento){
  Celda* actual = 0;
  Celda* siguiente = 0;
  bool encontrado = false;
	if (ultima && elemento != ultima->elemento) {
    actual = primera;
		while (actual->siguiente && !encontrado){
			actual = actual->siguiente;
      if(actual->siguiente->elemento == elemento){
        siguiente = actual->siguiente;
        encontrado = true;
      }
		}
	}
	return siguiente->elemento;
}

//Efecto: Retorna el elemento siguiente del elemento recibido como parámetro.
//Requiere: Una lista inicializada y que el elemento siguiente al recibido exista.
//Modifica: Este operador no realiza modificaciones.
int ListaOrdenada::anterior(int elemento){
  Celda* actual = 0;
  Celda* anterior = 0;
  bool encontrado = false;
	if (primera && elemento != primera->elemento) {
    actual = primera;
		while (actual->siguiente && !encontrado){
      if(actual->siguiente->elemento == elemento){
        anterior = actual;
        encontrado = true;
      }
			actual = actual->siguiente;
		}
	}
	return anterior->elemento;
}

//Efecto: Devuelve el número de elementos de la lista.
//Requiere: Una lista inicializada.
//Modifica: No aplica.
int ListaOrdenada::numElem(){
  int cont = 0;
  Celda * actual = primera;
  while(actual){
      ++cont;
      actual = actual->siguiente;
  }
  return cont;
}
