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
        int elemento = 0;
        cout<<"Que elemento desea insertar?\n"<<endl;
        cin >> elemento;
        int indice = 0;
        cout<<"Que indice desea insertar? "<<endl;
        cin >> indice;
        listaI.insertar(elemento,indice);
        listaI.imprimir();
        break;
    case 3:
        int indice = 0;
        cout<<"Que elemento desea borrar?\n"<<endl;
        cin >> indice;
        listaI.borrar(indice);
        listaI.imprimir();
        break;
    case 4:
        int indice = 0;
        cout<<"Que elemento desea recuperar?\n"<<endl;
        cin >> indice;
        cout << listaI.recuperar(indice) << endl;
        break;
    case 5:
        int indice = 0;
        cout<<"Que indice desea modificar? "<<endl;
        cin >> indice;
        int elemento = 0;
        cout<<"Que elemento desea insertar en ese indice?\n"<<endl;
        cin >> elemento;
        listaI.imprimir();
        break;
    case 6:
        int indice1 = 0;
        cout<<"Dijite el primer indice por intercambiar "<<endl;
        cin >> indice1;
        int indice2 = 0;
        cout<<"Dijite el primer indice por intercambiar "<<endl;
        cin >> indice2;
        listaI.intercambiar(indice1,indice2);
        listaI.imprimir();
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

