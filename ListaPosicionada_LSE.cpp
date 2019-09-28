/* 1. Implementar el modelo Lista Posicionada utilizando las estructuras de datos: Lista Simplemente Enlazada.

2. Implementar el modelo Lista Indexada utilizando las estructuras de datos: Arreglo y Lista
Simplemente Enlazada.

3. Implementar el modelo Lista Ordenada utilizando las estructuras de datos: Arreglo y Lista
Simplemente Enlazada. */

#ifndef _LISTAP
#define _LISTAP
#include<iostream>
using namespace std;

class ListaPos {
    class Celda;    // Prototipo
    private:
        Celda * primera;
	    Celda * ultima;
      
	    class Celda{
	        public:
                int elemento;
  			    Celda * siguiente;
  			    Celda(int);
  			    ~Celda();
	     };
	public:
		ListaPos(); //Iniciar(L)
		~ListaPos(); //Destruir(L)
		void vaciar(); //Vaciar(L)
		bool vacia(); //Vacia(L)
		void insertar(int,Celda*); //Insertar(e,p,L)
		void agregarUltimo(int); //AgregarUltimo(e,L)
		void borrar(Celda*); //Borrar(p,L)
		int recuperar(Celda*); //Recuperar(p,L)
		void modificar(Celda*, int); //Modificar(p,e,L)
		void intercambiar(Celda*,Celda*); //Intercambiar(p1,p2,L)
		int numElem(); //NumElem(L)
		Celda* primera(); //Primera(L)
		Celda* ultima(); //Ultima(L)
		Celda* siguiente(Celda*); //Siguiente(L)
		Celda* anterior(Celda*); //Anterior(L)
};
#endif