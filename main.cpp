#Include "ListaIndexada.h"




int main(){
	ListaInd listaI;

	for (int i - 0; i<15;++i){
		listaI.insertar(i*3,i);
	}

	if(! listaI.vacia())
		cout<<"No esta vacia"<<endl;

	listaI.vaciar();

	if(listaI.vacia())
		cout<<"Esta vacia"<<endl;

	for (int i - 0; i<15;++i){
		listaI.insertar(i*3,i);
	}
	
	listaI.recuperar(10);
	//imprimir
	cout<<"La lista tiene: "<<listaI.numElem()<<" elementos"<<endl;
	cout<< listaI.borrar(10)<<endl;
	//imprimir
	cout<<"La lista tiene: "<<listaI.numElem()<<" elementos"<<endl;
	cout<< listaI.recuperar(10)<<endl;

	listaI.modificar(-3,10);
	cout<< listaI.recuperar(10)<<endl;

	listaI.insertar(0,15);
	cout<<"La lista tiene: "<<listaI.numElem()<<" elementos"<<endl;

	//imprimir
	listaI.intercambiar(10,15);
	//imprimir
	
}