ConstruirGrafo(Grafo grafoDirigido, Arreglo etiquetas, Matriz matrizPesos){
	grafoDirigido.Iniciar()
	contador = 1
	while (contador <= etiquetas.NumElem()){
		etiquetaActual = etiquetas.Recuperar(contador)
		grafoDirigido.AgregarVertice(etiquetaActual)
		contador++
	}

	for (int i = 1; i <= matrizPesos.NumFilas(); ++i){
		for (int j = 1; j <= matrizPesos.NumColumnas(); ++j){
			nuevoPeso = matrizPesos.recuperar(i,j)
			if(nuevoPeso > 0){
				etiquetaI = grafoDirigido.Etiqueta(i)
				etiquetaJ = grafoDirigido.Etiqueta(j)
				grafoDirigido.AgregarArista(etiquetaI,etiquetaJ,nuevoPeso)
			}

		}
	}
}

dijkstra(Grafo grafo, Vertice inicio){
	ListaDistancia.Iniciar()
	ListaRecorridos.Iniciar()
	for(int i = 1; i < grafo.NumElem(); i++){
		ListaDistancia.Insertar(i,INF) //INF infinito
		ListaRecorridos.Insertar(i, false)  //si ya fue recorrido o no
	}
	ListaDistancia.Modificar(inicio,0)
	ListaRecorridos.Modificar(inicio,true)

	for(int cont = 1; cont < grafo.NumElem(); cont++){
		min = DistanciaMinima(ListaDistancia,ListaRecorridos)
		ListaRecorridos.Modificar(min,true)
		for(int otroVert = 1; otroVert <= grafo.NumElem(); otroVert++){
			if(ListaRecorridos.Recuperar(otroVert == false) && 
				ListaDistancia.Recuperar(min) + grafo.Peso(min,otroVert) < ListaDistancia.recuperar(otroVert)){

				ListaDistancia.Modificar(otroVert, ListaDistancia.Recuperar(min) + grafo.Peso(min,otroVert))
			}
		}


}

int DistanciaMinima(Lista dist, Lista recc){ 
    min = dist.Recuperar(1)
    indice = 1 
    for (int v = 1; v <= dist.NumElem(); v++) 
        if (recc.Recuperar(v) == false && dist.Recuperar(v) <= min){ 
            min = dist[v]
            indice = v 
        }

    retorna indice 
}
