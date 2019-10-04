// 1. Implementar el modelo Lista Posicionada utilizando las estructuras de datos: Arreglo.

#ifndef _LISTAP
#define _LISTAP
#include<iostream>
using namespace std;

class ListaPos {
    class Celda;    // Prototipo
	typedef int posicion;
	private:
		int* vListaPos; 
		int ultimoLleno;
		
	public:
		ListaPos(int); //Iniciar(L)
		~ListaPos(); //Destruir(L)
		void vaciar(); //Vaciar(L)
		bool vacia(); //Vacia(L)
		void insertar(int,posicion); //Insertar(e,p,L)
		void agregarUltimo(int); //AgregarUltimo(e,L)
		void borrar(posicion); //Borrar(p,L)
		int recuperar(posicion); //Recuperar(p,L)
		void modificar(posicion, int); //Modificar(p,e,L)
		void intercambiar(posicion,posicion); //Intercambiar(p1,p2,L)
		int numElem(); //NumElem(L)
		posicion getPrimera(); //Primera(L)
		posicion getUltima(); //Ultima(L)
		posicion siguiente(posicion); //Siguiente(p,L)
		posicion anterior(posicion); //Anterior(p,L)
};
#endif