#include <stdlib.h> //Para usar system("cls");
#include <conio.h> //Para usar getch();

#include "ListaPosicionada_Arreglo.h"
//#include "ListaPosicionada_LSE.h"
//#include "ListaPosicionada_LDE.h"

#include "ListaIndexada_Arreglo.h"
//#include "ListaIndexada_LSE.h"

#include "ListaOrdenada_Arreglo.h"
//#include "ListaOrdenada_LSE.h"

void pruebaListaP(ListaPos& listaO){ //NO ESTA LISTO!!!!!!
	int opcion = 0;
	do{
		//system("cls");
		cout << "\n\t ----Lista Indexada---\n\n 1. Preguntar si la lista esta vacia\n 2. Insertar Elemento\n 3. Borrar Elemento\n 4. Recuperar Elemento\n"
		<< " 5. Modificar Elemento\n 6. Intercambiar Elementos\n 7. Preguntar el Numero de Elementos\n 8. Regresar \n\n  -Digite una opcion: "<<endl;
		cin>> opcion;
		int elemento,indice,indice1,indice2;
		switch (opcion)
		{
		case 1:
			listaP.vacia() ? cout<< "Esta vacia" : cout <<"No esta vacia" << endl;     
			getch();
			cout<< "\n\n\tPulsa una tecla para continuar...";
			break;
		case 2:
			elemento = 0;
			cout<<"Que elemento desea insertar?\n"<<endl;
			cin >> elemento;
			indice = 0;
			cout<<"Que indice desea insertar? "<<endl;
			cin >> indice;
			listaP.insertar(elemento,indice);
			listaP.imprimir();
			break;
		case 3:
			indice = 0;
			cout<<"Que elemento desea borrar?\n"<<endl;
			cin >> indice;
			listaP.borrar(indice);
			listaP.imprimir();
			break;
		case 4:
			indice = 0;
			cout<<"Que elemento desea recuperar?\n"<<endl;
			cin >> indice;
			cout << listaP.recuperar(indice) << endl;
			break;
		case 5:
			indice = 0;
			cout<<"Que indice desea modificar? "<<endl;
			cin >> indice;
			elemento = 0;
			cout<<"Que elemento desea insertar en ese indice?\n"<<endl;
			cin >> elemento;
			listaP.imprimir();
			break;
		case 6:
			indice1 = 0;
			cout<<"Digite el primer indice por intercambiar "<<endl;
			cin >> indice1;
			indice2 = 0;
			cout<<"Digite el primer indice por intercambiar "<<endl;
			cin >> indice2;
			listaP.intercambiar(indice1,indice2);
			listaP.imprimir();
			break;
		case 7:
			cout<<"La lista tiene "<< listaP.numElem() <<" elementos"<<endl;
			break;
		default:
			break;
		}
	} while(opcion != 8);	
}

void pruebaListaI(ListaInd& listaI){
    int opcion = 0;
	do{
		//system("cls");
		cout << "\n\t ----Lista Indexada---\n\n 1. Preguntar si la lista esta vacia\n 2. Insertar Elemento\n 3. Borrar Elemento\n 4. Recuperar Elemento\n"
		<< " 5. Modificar Elemento\n 6. Intercambiar Elementos\n 7. Preguntar el Numero de Elementos\n 8. Regresar \n\n  -Digite una opcion: "<<endl;
		cin>> opcion;
		int elemento,indice,indice1,indice2;
		switch (opcion)
		{
		case 1:
			listaI.vacia() ? cout<< "Esta vacia" : cout <<"No esta vacia" << endl;       
			break;
		case 2:
			elemento = 0;
			cout<<"Que elemento desea insertar?\n"<<endl;
			cin >> elemento;
			indice = 0;
			cout<<"Que indice desea insertar? "<<endl;
			cin >> indice;
			listaI.insertar(elemento,indice);
			listaI.imprimir();
			break;
		case 3:
			indice = 0;
			cout<<"Que elemento desea borrar?\n"<<endl;
			cin >> indice;
			listaI.borrar(indice);
			listaI.imprimir();
			break;
		case 4:
			indice = 0;
			cout<<"Que elemento desea recuperar?\n"<<endl;
			cin >> indice;
			cout << listaI.recuperar(indice) << endl;
			break;
		case 5:
			indice = 0;
			cout<<"Que indice desea modificar? "<<endl;
			cin >> indice;
			elemento = 0;
			cout<<"Que elemento desea insertar en ese indice?\n"<<endl;
			cin >> elemento;
			listaI.imprimir();
			break;
		case 6:
			indice1 = 0;
			cout<<"Digite el primer indice por intercambiar "<<endl;
			cin >> indice1;
			indice2 = 0;
			cout<<"Digite el primer indice por intercambiar "<<endl;
			cin >> indice2;
			listaI.intercambiar(indice1,indice2);
			listaI.imprimir();
			break;
		case 7:
			cout<<"La lista tiene "<< listaI.numElem() <<" elementos"<<endl;
			break;
		default:
			break;
		}
	} while(opcion != 8);
}

void pruebaListaO(ListaOrdenada& listaO){ //NO ESTA LISTO!!!!!!
	int opcion = 0;
	do{
		//system("cls");
		cout << "\n\t ----Lista Indexada---\n\n 1. Preguntar si la lista esta vacia\n 2. Insertar Elemento\n 3. Borrar Elemento\n 4. Recuperar Elemento\n"
		<< " 5. Modificar Elemento\n 6. Intercambiar Elementos\n 7. Preguntar el Numero de Elementos\n 8. Regresar \n\n  -Digite una opcion: "<<endl;
		cin>> opcion;
		int elemento,indice,indice1,indice2;
		switch (opcion)
		{
		case 1:
			listaO.vacia() ? cout<< "Esta vacia" : cout <<"No esta vacia" << endl;       
			break;
		case 2:
			elemento = 0;
			cout<<"Que elemento desea insertar?\n"<<endl;
			cin >> elemento;
			indice = 0;
			cout<<"Que indice desea insertar? "<<endl;
			cin >> indice;
			listaO.insertar(elemento,indice);
			listaO.imprimir();
			break;
		case 3:
			indice = 0;
			cout<<"Que elemento desea borrar?\n"<<endl;
			cin >> indice;
			listaO.borrar(indice);
			listaO.imprimir();
			break;
		case 4:
			indice = 0;
			cout<<"Que elemento desea recuperar?\n"<<endl;
			cin >> indice;
			cout << listaO.recuperar(indice) << endl;
			break;
		case 5:
			indice = 0;
			cout<<"Que indice desea modificar? "<<endl;
			cin >> indice;
			elemento = 0;
			cout<<"Que elemento desea insertar en ese indice?\n"<<endl;
			cin >> elemento;
			listaO.imprimir();
			break;
		case 6:
			indice1 = 0;
			cout<<"Digite el primer indice por intercambiar "<<endl;
			cin >> indice1;
			indice2 = 0;
			cout<<"Digite el primer indice por intercambiar "<<endl;
			cin >> indice2;
			listaO.intercambiar(indice1,indice2);
			listaO.imprimir();
			break;
		case 7:
			cout<<"La lista tiene "<< listaO.numElem() <<" elementos"<<endl;
			break;
		default:
			break;
		}
	} while(opcion != 8);	
}

int main(){
	ListaPos* listaP = new ListaPos(); //Lista Posicionada
	ListaInd* listaI = new ListaInd(); //Lista Indexada
	ListaOrdenada* listaO = new ListaOrdenada(); //Lista Ordenada
	
	int op = 0;
	do{
		//system("cls");
		cout << "\n\t -----Menu Principal----- \n\n 1-) Lista Posicionada: " << listaP->getNombre() << "\n 2-) Lista Indexada: " << listaI->getNombre() << """\n 3-) Lista Ordenada: " << listaO->getNombre() <<"\n 4-) Salir\n\n  -Digite una opcion: ";
		cin >> op;
		switch (op)
    	{
    		case 1:
       			pruebaListaP(*listaP);
       			break;
    		case 2:
    			pruebaListaI(*listaI);
       			break;
   			case 3:
        		pruebaListaO(*listaO);
       			break;
    		case 4:
        		cout<< "Programa terminado con exito!"<<endl;
        		break;
    		default:
    			cout<< "Opcion Invalida"<<endl;
        		break;
    	}
	} while(op != 4);
	return 0;
}
