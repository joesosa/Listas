#include "pch.h"

#include "ListaIndexada_Arreglo.h"
#define ESPACIO 50000



ListaInd::ListaInd(){
    listaI = new int[ESPACIO];
    ultimoLleno = -1;
    cout << "El tamano predeterminado es de 20"<<endl;
}

ListaInd::~ListaInd(){
    delete listaI;
}

void ListaInd::vaciar(){
    ultimoLleno = -1;
}

bool ListaInd::vacia(){
    return ultimoLleno == -1;
}

void ListaInd::insertar(int elemento, int indice){
    if(indice >= 0 && indice <= ultimoLleno+1){
        for(int i = ultimoLleno; i >= indice; --i){
            listaI[i+1] = listaI[i];
        }
        listaI[indice] = elemento;
        ++ultimoLleno;
    }
    else{
        cout << "No se puede insertar en ese Indice "<<endl;
    }
}

void ListaInd::borrar(int indice){
    if(indice >= 0 && indice <= ultimoLleno){
        for(int i = indice; i < ultimoLleno;++i){
            listaI[i] = listaI[i+1];
        }
        --ultimoLleno; //el pasado ultimo lleno se deja como estaba?
    }
    else{
        cout << "No existe el elemento en la lista"<<endl;
    }
}

int ListaInd::recuperar(int indice){
    if(indice >= 0 && indice <= ultimoLleno){
        return listaI[indice];
    }
    else{
        cout << "No existe el elemento en la lista"<<endl;
        return -1;
    }
}

void ListaInd::modificar(int elemento, int indice){
    if(indice >= 0 && indice <= ultimoLleno){
        listaI[indice] = elemento;
    }
    else{
        cout << "No existe el elemento en la lista"<<endl;
    }
}

void ListaInd::intercambiar(int indice1,int indice2){
    if(indice1 >= 0 && indice1 <= ultimoLleno && indice2 >= 0 && indice2 <= ultimoLleno){
        int aux = listaI[indice1];
        listaI[indice1] = listaI[indice2];
        listaI[indice2] = aux;
    }
    else{
        cout << "No existe el elemento en la lista"<<endl;
    }
}

int ListaInd::numElem(){
    return ultimoLleno +1;
}

void ListaInd::imprimir(){
	cout << "\n";
    for(int i = 0; i <= ultimoLleno; ++i){
        cout << listaI[i]<<" , ";
    }
	cout << endl;
}

char* ListaInd::getNombre() {
	return (char*)"Arreglo";
}
