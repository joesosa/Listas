// 1. Implementar el modelo Lista Posicionada utilizando las estructuras de datos: Arreglo.

#ifndef _LISTAP
#define _LISTAP
#include<iostream>
using namespace std;

class ListaPos {
    class Celda;    // Prototipo
    private:
		int* listaPos; 

	public:
		ListaPos(int); //Iniciar(L)
		~ListaPos(); //Destruir(L)
		void vaciar(); //Vaciar(L)
		bool vacia(); //Vacia(L)
		void insertar(int,int); //Insertar(e,p,L)
		void agregarUltimo(int); //AgregarUltimo(e,L)
		void borrar(int); //Borrar(p,L)
		int recuperar(int); //Recuperar(p,L)
		void modificar(int, int); //Modificar(p,e,L)
		void intercambiar(int,int); //Intercambiar(p1,p2,L)
		int numElem(); //NumElem(L)
		int primera(); //Primera(L)
		int ultima(); //Ultima(L)
		int siguiente(int); //Siguiente(L)
		int anterior(int); //Anterior(L)
};
#endif