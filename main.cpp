#include <stdlib.h> //Para usar system("cls");
#include <conio.h> //Para usar getch();

//#include "ListaPosicionada_Arreglo.h"
#include "ListaPosicionada_LSE.h"
//#include "ListaPosicionada_LDE.h"

//#include "ListaIndexada_Arreglo.h"
#include "ListaIndexada_LSE.h"

#include "ListaOrdenada_Arreglo.h"
//#include "ListaOrdenada_LSE.h"

ListaPos::posicion traducir(ListaPos& lista, int indice) { //Traduce un indice ingresado por el usuarion en una posicion
	ListaPos::posicion pos;
	pos = lista.getPrimera();
	for (int i = 1; i < indice; ++i)
		pos = lista.siguiente(pos);
	return pos;
}
void pruebaListaP(ListaPos& listaP) {
	int opcion = 0;
	do{
		system("cls");
		cout << "\n\t ---- Lista Posicionada ---\n\n 1. Preguntar si la lista esta vacia\n 2. Vaciar la Lista\n 3. Insertar Elemento\n 4. Agregar Elemento al Final\n 5. Borrar Elemento\n 6. Recuperar Elemento\n"
		<< " 7. Modificar Elemento\n 8. Intercambiar Elementos\n 9. Preguntar el Numero de Elementos\n 10. Elemento Siguiente\n 11. Elemento Anterior\n 12. Primer Elemento\n 13. Ultimo Elemento\n 14. Regresar \n\n  -Digite una opcion: "<<endl;
		cin>> opcion;
		int elemento,indice = 0;
		ListaPos::posicion pos;
		switch (opcion)
		{
		case 1:
			system("cls");
			listaP.vacia() ? cout << "\n\t ---- Lista Posicionada ---\n\n -Esta vacia" : cout << "\n\t ---- Lista Posicionada ---\n\n -No esta vacia" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2: {
			system("cls");
			char opc = 'N';
			cout << "\n\t ---- Lista Posicionada ---\n\n -Desea vaciar la lista?(S/N) ";
			cin >> opc;
			if (opc == 'S'|| opc == 's') {
				listaP.vaciar();
				cout << "\n ---Lista vaciada correctamente --- ";
			}
			else{
				cout << "\n ---Lista NO fue vaciada --- ";
			}
			getch();
			break;
		}
		case 3:
			system("cls");
			cout<<"\n\t ---- Lista Posicionada ---\n\n -Que elemento desea insertar?: ";
			cin >> elemento;
			cout<<"\n\n -En que posicion desea insertar?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			listaP.insertar(elemento,pos);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -Que elemento desea insertar?: ";
			cin >> elemento;
			listaP.agregarUltimo(elemento);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 5:
			system("cls");
			cout<<"\n\t ---- Lista Posicionada ---\n\n -Que posicion desea borrar?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			listaP.borrar(pos);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 6:
			system("cls");
			cout<<"\n\t ---- Lista Posicionada ---\n\n -Que posicion desea recuperar?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			cout << "\n\n El elemento es: " << listaP.recuperar(pos) << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
			system("cls");
			cout<<"\n\t ---- Lista Posicionada ---\n\n -Que posicion desea modificar?: ";
			cin >> indice;
			cout<<"\n\n -Que elemento desea insertar en esa posicion?: ";
			cin >> elemento;
			pos = traducir(listaP, indice);
			listaP.modificar(pos, elemento);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 8: {
			system("cls");
			indice = 0;
			int indice2 = 0;
			ListaPos::posicion pos2;
			cout<<"\n\t ---- Lista Posicionada ---\n\n -Digite la primera posicion por intercambiar: ";
			cin >> indice;
			cout<<"\n -Digite la segunda posicion por intercambiar: ";
			cin >> indice2;
			pos = traducir(listaP, indice);
			pos2 = traducir(listaP, indice2);
			listaP.intercambiar(pos,pos2);
			listaP.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		}
		case 9:
			system("cls");
			cout<<"\n\t ---- Lista Posicionada ---\n\n -La lista tiene "<< listaP.numElem() <<" elementos."<<endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 10:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -De que posicion desea conocer el siguiente elemento?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			cout << "\n\n El elemento es: " << listaP.recuperar(listaP.siguiente(pos));
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 11:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -De que posicion desea conocer el elemento anterior?: ";
			cin >> indice;
			pos = traducir(listaP, indice);
			cout << "\n\n El elemento es: " << listaP.recuperar(listaP.anterior(pos));
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 12:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -El primer elemento es: " << listaP.recuperar(listaP.getPrimera());
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 13:
			system("cls");
			cout << "\n\t ---- Lista Posicionada ---\n\n -El ultimo elemento es: " << listaP.recuperar(listaP.getUltima());
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 14:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while(opcion != 14);	
}


void pruebaListaI(ListaInd& listaI){
    int opcion = 0;
	do{
		system("cls");
		cout << "\n\t ---- Lista Indexada ---\n\n 1. Preguntar si la lista esta vacia\n 2. Vaciar la Lista\n 3. Insertar Elemento\n 4. Borrar Elemento\n 5. Recuperar Elemento\n"
		<< " 6. Modificar Elemento\n 7. Intercambiar Elementos\n 8. Preguntar el Numero de Elementos\n 9. Regresar \n\n  -Digite una opcion: "<<endl;
		cin>> opcion;
		int elemento,indice,indice1,indice2;
		switch (opcion)
		{
		case 1:
			system("cls");
			listaI.vacia() ? cout << "\n\t ---- Lista Indexada ---\n\n -Esta vacia" : cout << "\n\t ---- Lista Indexada ---\n\n -No esta vacia" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2: {
			system("cls");
			char opc = 'N';
			cout << "\n\t ---- Lista Indexada ---\n\n -Desea vaciar la lista?(S/N) ";
			cin >> opc;
			if (opc == 'S' || opc == 's') {
				listaI.vaciar();
				cout << "\n ---Lista vaciada correctamente --- ";
			}
			else {
				cout << "\n ---Lista NO fue vaciada --- ";
			}
			getch();
			break;
		}
		case 3:
			system("cls");
			cout<<"\n\t ---- Lista Indexada ---\n\n -Que elemento desea insertar?: ";
			cin >> elemento;
			cout<<"\n\n -En que indice desea insertar?: ";
			cin >> indice;
			listaI.insertar(elemento,indice);
			listaI.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4:
			system("cls");
			cout<<"\n\t ---- Lista indexada ---\n\n -Que indice desea borrar?: ";
			cin >> indice;
			listaI.borrar(indice);
			listaI.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 5:
			system("cls");
			cout<<"\n\t ---- Lista Indexada ---\n\n -Que indice desea recuperar?: ";
			cin >> indice;
			cout << "\n\n El elemento es: " << listaI.recuperar(indice) << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 6:
			system("cls");
			cout<<"\n\t ---- Lista Indexada ---\n\n -Que indice desea modificar?: ";
			cin >> indice;
			cout<<"\n\n -Que elemento desea insertar en esa posicion?: ";
			cin >> elemento;
			listaI.modificar(elemento,indice);
			listaI.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
			system("cls");
			cout<<"\n\t ---- Lista Indexada ---\n\n -Digite el primer indice por intercambiar: ";
			cin >> indice1;
			cout<<"\n -Digite el segundo indice por intercambiar: ";
			cin >> indice2;
			listaI.intercambiar(indice1,indice2);
			listaI.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 8:
			system("cls");
			cout<<"\n\t ---- Lista Indexada ---\n\n -La lista tiene "<< listaI.numElem() <<" elementos."<<endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 9:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while(opcion != 9);
}

void pruebaListaO(ListaOrdenada& listaO){ 
	int opcion = 0;
	do{
		system("cls");
		cout << "\n\t ---- Lista Ordenada ---\n\n 1. Preguntar si la lista esta vacia\n 2. Vaciar la Lista\n 3. Insertar Elemento\n 4. Borrar Elemento\n"
		<< " 5. Preguntar el Numero de Elementos\n 6. Elemento Siguiente\n 7. Elemento Anterior\n 8. Primer Elemento\n 9. Ultimo Elemento\n 10. Regresar \n\n  -Digite una opcion: "<<endl;
		cin>> opcion;
		int elemento,indice = 0;
		char opc = 'N';
		switch (opcion)
		{
		case 1:
			system("cls");
			listaO.vacia() ? cout << "\n\t ---- Lista Ordenada ---\n\n -Esta vacia" : cout << "\n\t ---- Lista Ordenada ---\n\n -No esta vacia" << endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 2:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -Desea vaciar la lista?(S/N) ";
			cin >> opc;
			if (opc == 'S'|| opc == 's') {
				listaO.vaciar();
				cout << "\n ---Lista vaciada correctamente --- ";
			}
			else{
				cout << "\n ---Lista NO fue vaciada --- ";
			}
			getch();
			break;
		case 3:
			system("cls");
			cout<<"\n\t ---- Lista Ordenada ---\n\n -Que elemento desea insertar?: ";
			cin >> elemento;
			listaO.insertar(elemento);
			listaO.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 4:
			system("cls");
			cout<<"\n\t ---- Lista Ordenada ---\n\n -Que elemento desea borrar?: ";
			cin >> elemento;
			listaO.borrar(elemento);
			listaO.imprimir();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 5:
			system("cls");
			cout<<"\n\t ---- Lista Ordenada ---\n\n -La lista tiene "<< listaO.numElem() <<" elementos."<<endl;
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 6:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -De que elemento desea conocer el siguiente?: ";
			cin >> elemento;
			cout << "\n\n El elemento es: " << listaO.siguiente(elemento);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 7:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -De que elemento desea conocer el elemento anterior?: ";
			cin >> elemento;
			cout << "\n\n El elemento es: " << listaO.anterior(elemento);
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 8:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -El primer elemento es: " << listaO.primero();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 9:
			system("cls");
			cout << "\n\t ---- Lista Ordenada ---\n\n -El ultimo elemento es: " << listaO.ultimo();
			cout << "\n\n\tPulsa una tecla para continuar...";
			getch();
			break;
		case 10:
			break;
		default:
			cout << "\n Opcion Invalida";
			getch();
			break;
		}
	} while(opcion != 10);	
}

int main(){
	ListaPos listaP; //Lista Posicionada
	ListaInd listaI; //Lista Indexada
	ListaOrdenada listaO; //Lista Ordenada
	
	int op = 0;
	do{
		system("cls");
		cout << "\n\t ----- Menu Principal ----- \n\n 1-) Lista Posicionada: " << listaP.getNombre() << "\n 2-) Lista Indexada: " << listaI.getNombre() << """\n 3-) Lista Ordenada: " << listaO.getNombre() <<"\n 4-) Salir\n\n  -Digite una opcion: ";
		cin >> op;
		switch (op)
    	{
    		case 1:
       			pruebaListaP(listaP);
       			break;
    		case 2:
    			pruebaListaI(listaI);
       			break;
   			case 3:
        		pruebaListaO(listaO);
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
