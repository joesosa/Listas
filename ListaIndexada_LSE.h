// 2. Implementar el modelo Lista Indexada utilizando las estructuras de datos: Lista Simplemente Enlazada.

#ifndef _LISTAILSE
#define _LISTAILSE
#include<iostream>
using namespace std;

class ListaInd {
    class Celda;    // Prototipo
    private:
        Celda * primera;

	    class Celda{
	        public:
                int elemento;
  			    Celda * siguiente;
  			    Celda(int);
  			    ~Celda();
	     };
	public:
		ListaInd(); //Iniciar(L)
		~ListaInd(); //Destruir(L)
		void vaciar(); //Vaciar(L)
		bool vacia(); //Vacia(L)
		void insertar(int,int); //Insertar(e,p,L)
		void borrar(int); //Borrar(p,L)
		int recuperar(int); //Recuperar(p,L)
		void modificar(int, int); //Modificar(p,e,L)
		void intercambiar(int,int); //Intercambiar(p1,p2,L)
		int numElem(); //NumElem(L)
		void imprimir();
		char* getNombre();
};
#endif
