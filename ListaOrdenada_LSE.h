#ifndef _LISTAORD
#define _LISTAORD
#include<iostream>
using namespace std;

class ListaOrdenada {
    class Celda;
    private:
    	Celda * primera;
	Celda * ultima;
    	int numElementos;
     	class Celda{
        	public:
               	int elemento;
           	Celda * siguiente;
           	Celda(int);
           	~Celda();
      	};
	public:
		ListaOrdenada(); //Iniciar(L)
		~ListaOrdenada(); //Destruir(L)
		void vaciar(); //Vaciar(L)
		bool vacia(); //Vacia(L)
		void insertar(int); //Insertar(e,L)
    void borrar(int); //Borrar(e,L)
    int primero(); // Primero(L)
    int ultimo(); // Ultimo(L)
    int siguiente(int); // Siguiente(e,L)
    int anterior(int); // Anterior(e,L)
		int numElem(); //NumElem(L)
		char* getNombre();
		void imprimir();
};
#endif
