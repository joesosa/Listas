#include "ListaIndexada_LSE.h"

ListaInd::Celda::Celda(int elemento){
    this->elemento = elemento;
    siguiente = 0;
}

ListaInd::Celda::~Celda(){
    if(siguiente){
        delete siguiente;
    }
}

ListaInd::ListaInd(){
    primera = 0;
} 

ListaInd::~ListaInd(){ 
    if(primera){
        delete primera;
    }
} 

void ListaInd::vaciar(){
    if(primera->siguiente){
        delete primera->siguiente;
    }
    primera = 0;
}

bool ListaInd::vacia(){
    return !primera;
} 

void ListaInd::insertar(int elemento,int indice){
    Celda * nueva = new Celda(elemento);
    if(!vacia()){
        if(indice != 0){    
            Celda * actual = primera;
            int cont = 0;
            while(actual && cont != indice-1){
                actual = actual->siguiente;
                ++cont;
            }
            if(actual){
                nueva->siguiente = actual->siguiente;
                actual->siguiente = nueva;
            }
            else{
                cout << "No se puede insertar en ese Indice "<<endl;
            }
        }
        else{
            nueva->siguiente = primera;
            primera = nueva;
        }
    }
    else{
        if(indice == 0){
            primera = nueva;
        }
        else{
            cout<<"No se puede insertar en ese Indice"<<endl;
        }
    }

} 

void ListaInd::borrar(int indice){
    if(!vacia()){
        Celda * actual = primera;
        if(indice != 0){
            int cont = 0;
            while(actual && cont != indice-1){
                actual = actual->siguiente;
                ++cont;
            }
            if(actual){
                Celda * victima = actual->siguiente;
                actual->siguiente = victima->siguiente;
                victima->siguiente = 0;
                delete victima;
            }
        }
        else{
            primera = actual->siguiente;
            actual-> siguiente = 0;
            delete actual;
        }
    }
}

int ListaInd::recuperar(int indice){
    Celda * actual = primera;
    int cont = 0;
    int elementoDevuelto = -1;
    while(actual && cont != indice ){
        actual = actual->siguiente;
        ++cont;
    }
    if(cont == indice){
        elementoDevuelto = actual->elemento;
    }
    else{
        cout << "El indice no existe "<<endl;
    }
    return elementoDevuelto;
} 

void ListaInd::modificar(int elementoNuevo, int indice){
    Celda * actual = primera;
    int cont = 0;
    while(actual && cont != indice){
        actual = actual->siguiente;
        ++cont;
    }
    if(cont == indice){
        actual->elemento = elementoNuevo;
    }
    else{
        cout << "El Indice no existe "<<endl;
    }
} 

void ListaInd::intercambiar(int indice1,int indice2){
    Celda * actual = primera;
    int cont = 0;
    Celda * porIntercambiar1 = 0;
    Celda * porIntercambiar2 = 0;
    while(actual && (cont <= indice1 || cont <= indice2) ){ //revisar
        if(cont == indice1){
            porIntercambiar1 = actual;
        }
        if(cont == indice2){
            porIntercambiar2 = actual;
        }
        actual = actual->siguiente;
        ++cont;
    }
    if(porIntercambiar2 && porIntercambiar1){
        int aux = porIntercambiar2->elemento;
        porIntercambiar2->elemento = porIntercambiar1->elemento;
        porIntercambiar1->elemento = aux;
    }
    else{
        cout << "No son indices validos"<<endl;
    }
}
    
int ListaInd::numElem(){
    int cont = 0;
    Celda * actual = primera;
    while(actual){
        ++cont;
        actual = actual->siguiente;
    }
    return cont;
}

void ListaInd::imprimir(){
    Celda * actual = primera;
    while(actual){
        cout << actual->elemento << "\t";
        actual = actual->siguiente;
    }
	cout<<endl;

}

char* ListaInd::getNombre() {
	return (char*)"L.S.E.";
}
