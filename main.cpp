#include <iostream>
#include "ListaIndexada_LSE.h"
using namespace std;





int main(){
	ListaInd listaI;

	for (int i = 0; i<15;++i){
		listaI.insertar(i*3,i);
	}

	if(! listaI.vacia())
		cout<<"No esta vacia"<<endl;

	listaI.vaciar();

	if(listaI.vacia())
		cout<<"Esta vacia"<<endl;

	for (int i = 0; i<15;++i){
		listaI.insertar(i*3,i);
	}
	
	cout<< listaI.recuperar(10)<<endl;
	listaI.imprimir();
	cout<<"La lista tiene: "<<listaI.numElem()<<" elementos"<<endl;
	listaI.borrar(10);
	listaI.imprimir();
	cout<<"La lista tiene: "<<listaI.numElem()<<" elementos"<<endl;
	cout<< listaI.recuperar(10)<<endl;

	listaI.modificar(-3,10);
	cout<< listaI.recuperar(10)<<endl;

	listaI.insertar(0,14);
	cout<<"La lista tiene: "<<listaI.numElem()<<" elementos"<<endl;

	listaI.imprimir();
	listaI.intercambiar(10,1);
	listaI.imprimir();

}
