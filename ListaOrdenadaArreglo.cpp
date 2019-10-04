#include "ListaOrdenadaArreglo.h"



//Efecto: Inicializa la lista dejándola accesible para que el resto de operadores básicos puedan trabajar en ella.
//Requiere: Este operador no tiene requerimientos.
//Modifica: Modifica la lista.
ListaOrdenada::ListaOrdenada(int espacio){
    listaO = new int[espacio];
    ultimoLleno = -1;
    primera = -2;
}

//Efecto: Destruye la existencia de la lista.
//Requiere: Una lista inicializada.
//Modifica: Modifica la lista.
ListaOrdenada::~ListaOrdenada(){
    delete listaO;
}

//Efecto: Edita la lista indexada de modo que termine con 0 elementos.
//Requiere: Una lista inicializada.
//Modifica: Modifica la lista.
void ListaOrdenada::vaciar(){
    ultimoLleno = -1;
}

//Efecto: Devuelve un valor de verdad (verdadero o falso) acorde al estado de la lista recibida.
//Requiere: Una lista inicializada.
//Modifica: No aplica.
bool ListaOrdenada::vacia(){
    return ultimoLleno == -1;
}

//Efecto: Agrega el elemento recibido como parámetro en su posición correspondiente,
// de modo que su anterior(sí existe) sea menor y su siguiente(si existe) sea mayor.
//Aumenta el tamaño en uno.
//Requiere: Una lista inicializada y un elemento no existente.
//Modifica: Modifica la lista.
void ListaOrdenada::insertar(int elemento){
    bool existe = false;
    int posElemento = 0;
    int indice = 1;
    if( ultimoLleno!=-1 && elemento == listaO[0] ){
      existe = true;
    }
    else if(ultimoLleno!=-1 && elemento>listaO[ultimoLleno]){
      listaO[++ultimoLleno] = elemento;
      existe = true;
    }
    else if(ultimoLleno!= -1 && elemento > listaO[0]){
        while (!existe && indice<=ultimoLleno ) {
          if(listaO[indice] == elemento){
            existe = true;
          }
          if(elemento > listaO[indice -1] && elemento < listaO[indice]){
            posElemento = indice;
          }
          ++indice;
        }
    }
    if(!existe){
        if(posElemento == 0){
          primera = elemento;
        }
        for(int i = ultimoLleno; i >= indice; --i){
            listaO[i+1] = listaO[i];
        }
        listaO[indice] = elemento;
        ++ultimoLleno;
    }
}



//Efecto: Elimina el elemento recibido como parámetro de la lista. A su vez decrementa el tamaño de la lista en uno.
//Requiere: Una lista inicializada y un elemento existente en la lista.
//Modifica: Modifica la lista
void ListaOrdenada::borrar(int elemento){
    int posElemento = -1;
    for(int i = 0; i <= ultimoLleno;++i){
      if(elemento == listaO[i]){
        posElemento = i;
      }
    }
    if(posElemento != -1){
      for(int i = posElemento; i < ultimoLleno;++i){
            listaO[i] = listaO[i+1];
        }
        --ultimoLleno;
    }
}

//Efecto: Retorna el primer elemento de la lista ordenada.
//Requiere: Una lista inicializada y una lista no vacía.
//Modifica: Este operador no realiza modificaciones.
int ListaOrdenada::primero(){
  return primera;
}

//Efecto: Retorna el último elemento de la lista ordenada.
//Requiere: Una lista inicializada y una lista con al menos un elemento..
//Modifica: Este operador no realiza modificaciones.
int ListaOrdenada::ultimo(){
  return listaO[ultimoLleno];
}

//Efecto: Retorna el elemento siguiente del elemento recibido como parámetro.
//Requiere: Una lista inicializada y que el elemento siguiente al recibido exista.
//Modifica: Este operador no realiza modificaciones.
int ListaOrdenada::siguiente(int elemento){
  int elemSiguiente = -300; // Elemento Nulo
  for(int i = 0; i+1 <=ultimoLleno && elemSiguiente == -300;++i){
    if(elemento == listaO[i]){
      elemSiguiente = listaO[i+1];
    }
  }
  return elemSiguiente;
}

//Efecto: Retorna el elemento siguiente del elemento recibido como parámetro.
//Requiere: Una lista inicializada y que el elemento siguiente al recibido exista.
//Modifica: Este operador no realiza modificaciones.
int ListaOrdenada::anterior(int elemento){
  int elemAnterior = -300; // Elemento Nulo
  for(int i = 1; i <=ultimoLleno && elemAnterior == -300;++i){
    if(elemento == listaO[i]){
      elemAnterior = listaO[i-1];
    }
  }
  return elemAnterior;
}

//Efecto: Devuelve el número de elementos de la lista.
//Requiere: Una lista inicializada.
//Modifica: No aplica.
int ListaOrdenada::numElem(){
    return ultimoLleno+1;
}

char* getNombre() {
	return "Arreglo";
}
