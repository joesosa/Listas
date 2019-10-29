#include "ListaPosicionada_Arreglo.h"

ListaPos::ListaPos(){ //Iniciar(L)
	vListaPos = new int[20];
	ultimoLleno = -1;
}

ListaPos::~ListaPos(){
	delete vListaPos;	//Destruir(L)
	delete this;
}

void ListaPos::vaciar(){ //Vaciar(L)
	ultimoLleno = -1;
}

bool ListaPos::vacia(){ //Vacia(L)
	return (ultimoLleno == -1);
}

void ListaPos::insertar(int elem, posicion pos){ //Insertar(e,p,L)
	for(int i = ultimoLleno+1; i> pos ;--i)
		vListaPos[i]= vListaPos[i-1];
	vListaPos[pos]= elem;
	++ultimoLleno;
}

void ListaPos::agregarUltimo(int elem){ //AgregarUltimo(e,L)
	vListaPos[++ultimoLleno] = elem;
}

void ListaPos::borrar(posicion pos){ //Borrar(p,L)
	for(int i = pos; i< ultimoLleno ;++i)
			vListaPos[i]= vListaPos[i+1];
	--ultimoLleno;
}

int ListaPos::recuperar(posicion pos){ //Recuperar(p,L)
	return vListaPos[pos];
}

void ListaPos::modificar(posicion pos, int elem){ //Modificar(p,e,L)
	vListaPos[pos] = elem;
}

void ListaPos::intercambiar(posicion pos1, posicion pos2){ //Intercambiar(p1,p2,L)
	int auxiliar = vListaPos[pos1];
	vListaPos[pos1] = vListaPos[pos2];
	vListaPos[pos2] = auxiliar;
}

int ListaPos::numElem(){ //NumElem(L)
	return ultimoLleno+1;
}

ListaPos::posicion ListaPos::getPrimera(){ //Primera(L)
	return 0;
}

ListaPos::posicion ListaPos::getUltima(){ //Ultima(L)
	return ultimoLleno;
}

ListaPos::posicion ListaPos::siguiente(posicion pos){ //Siguiente(p,L)
	return (pos<ultimoLleno && pos>-1)? pos+1 : -1;
}

ListaPos::posicion ListaPos::anterior(posicion pos){ //Anterior(p,L)
	return pos-1;
}

char* ListaPos::getNombre() {
	return (char*)"Arreglo";
}

void ListaPos::imprimir(){
	cout << "\n";
    for(int i = 0; i <= ultimoLleno; ++i){
        cout << vListaPos[i]<<"\t";
    }
	cout << endl;
}
