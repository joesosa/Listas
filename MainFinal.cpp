#include "ListaIndexada_Arreglo.h"
//#include "ListaIndexada_LSE.h"
#include "ListaIndexada_Arreglo.h"
//#include "ListaIndexada_LSE.h"
#include "ListaIndexada_Arreglo.h"
//#include "ListaIndexada_LSE.h"


int main(){
    //listaP
    //listaI
    //listaO


    




}


void pruebaListaI(ListaInd& listaI){
    int opcion = 0;
    cout << "¿Que desea hacer?\n1.Preguntar si la lista esta vacia\n2.Insertar Elemento\n3.Borrar Elemento\n4.Recuperar Elemento\n"
    << "5.Modificar Elemento\n6.intercambiar Elementos\n6.Preguntar el Numero de Elementos"<<endl;
    cin>> opcion;
    switch (opcion)
    {
    case 1:
        listaI.vacia() ? cout<< "Esta vacia" : cout <<"No esta vacia" << endl;       
        break;
    case 2:
    cout<<"Que elemento desesa "
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    default:
        break;
    }
}


void vaciar(); //Vaciar(L)
		bool vacia(); //Vacia(L)
		void insertar(int,int); //Insertar(e,p,L)
		void borrar(int); //Borrar(p,L)
		int recuperar(int); //Recuperar(p,L)
		void modificar(int, int); //Modificar(p,e,L)
		void intercambiar(int,int); //Intercambiar(p1,p2,L)
		int numElem(); //NumElem(L)
        void imprimir();

