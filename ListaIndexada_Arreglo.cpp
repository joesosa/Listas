#include "ListaIndexada_Arreglo.h"

ListaInd::ListaInd(int tamano){
    listaI = new int[tamano];
    ultimoLleno = -1;
    length = tamano;
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
//esperar respuesta
void ListaInd::insertar(int elemento,int indice){ 
    if(indice < length && indice >= 0){  
        for(int i = ultimoLleno; i >= indice; --i){
            listaI[i+1] = listaI[i]; 
        }
        listaI[indice] = elemento;
        indice > ultimoLleno ? ultimoLleno = indice;
    }
    else{
        cout << "Indice mayor a la M"<<endl;
    }
}
//esperar respuesta
void ListaInd::borrar(int indice){
    if(indice < length && indice >= 0){
        istaI[indice] = -1;
        if(indice == ultimoLleno){
            ultimoLleno = -1;
            for(int i = 0; i < length;++i){
                listaI[i] > ultimoLleno ? ultimoLleno = listaI[i];
            }
        }
    }
    else{
        cout << "Indice mayor a la M"<<endl;
    }
}

int ListaInd::recuperar(int indice){
    if(indice < length && indice >= 0){
        return listaI[indice];
    }
    else{
        cout << "Indice mayor a la M"<<endl;
        return -1;
    }
}

void ListaInd::modificar(int indice, int elemento){
    if(indice < length && indice >= 0){
        listaI[indice] = elemento;
    }
    else{
        cout << "Indice mayor a la M"<<endl;
    }
}

void ListaInd::intercambiar(int indice1,int indice2){
    if(indice1 < length && indice1 >= 0 && indice2 < length && indice2 >= 0){
        int aux = listaI[indice1];
        listaI[indice1] = listaI[indice2];
        listaI[indice2] = aux; 
    }
    else{
        cout << "Indice mayor a la M"<<endl;
    }
}

int ListaInd::numElem(){
    int cont = 0;
    for(int i = 0; i < ultimoLleno; ++i){
        if(listaI[i] != -1){
            ++cont;
        }
    }
} 
