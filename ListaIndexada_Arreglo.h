/* 
2. Implementar el modelo Lista Indexada utilizando las estructuras de datos: Arreglo y Lista
Simplemente Enlazada.
 */

#ifndef _LISTAI
#define _LISTAI
#include<iostream>
using namespace std;

class ListaInd {
    private:
		int* listaI;
		int ultimoLleno;

	public:
		ListaInd(int); //Iniciar(L)
		~ListaInd(); //Destruir(L)
		void vaciar(); //Vaciar(L)
		bool vacia(); //Vacia(L)
		void insertar(int,int); //Insertar(e,p,L)
		void borrar(int); //Borrar(p,L)
		int recuperar(int); //Recuperar(p,L)
		void modificar(int, int); //Modificar(p,e,L)
		void intercambiar(int,int); //Intercambiar(p1,p2,L)
		int numElem(); //NumElem(L)
};
#endif
