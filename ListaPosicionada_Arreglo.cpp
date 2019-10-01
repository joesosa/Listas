#include "ListaPosicionada_Arreglo.h"

ListaPos::ListaPos(int tamanoMaximo){ //Iniciar(L)
	vListaPos = new int[tamanoMaximo];
	ultimoLleno = -1;
}	

ListaPos::~ListaPos(){
	delete vListaPos;	//Destruir(L)
}

void ListaPos::vaciar(){ //Vaciar(L)
	ultimoLleno = -1;
}

bool ListaPos::vacia(){ //Vacia(L)
	return (ultimoLleno == -1); 
}

void ListaPos::insertar(int elem, int pos){ //Insertar(e,p,L)
	for(int i = ultimoLleno+1; i> pos ;--i)
		vListaPos[i]= vListaPos[i-1];
	vListaPos[pos]= elem;
	++ultimoLleno;
}

void ListaPos::agregarUltimo(int elem){ //AgregarUltimo(e,L)
	vListaPos[++ultimoLleno] = elem;
}

void ListaPos::borrar(int pos){ //Borrar(p,L)
	for(int i = pos; i< ultimoLleno ;++i)
			vListaPos[i]= vListaPos[i+1];
	--ultimoLleno;
}

int ListaPos::recuperar(int pos){ //Recuperar(p,L)
	return vListaPos[pos];
}

void ListaPos::modificar(int pos, int elem){ //Modificar(p,e,L)
	vListaPos[pos] = elem;
}

void ListaPos::intercambiar(int pos1, int pos2){ //Intercambiar(p1,p2,L)
	int auxiliar = vListaPos[pos1];
	vListaPos[pos1] = vListaPos[pos2];
	vListaPos[pos2] = auxiliar;
}

int ListaPos::numElem(){ //NumElem(L)
	return ultimoLleno+1;
}

int ListaPos::primera(){ //Primera(L)
	return vListaPos[0];
}

int ListaPos::ultima(){ //Ultima(L)
	return vListaPos[ultimoLleno];
}

int ListaPos::siguiente(int pos){ //Siguiente(p,L)
	return (pos!=ultimoLleno)? pos+1 : -1;
}

int ListaPos::anterior(int pos){ //Anterior(p,L)
	return pos-1;
}