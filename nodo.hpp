#include "common.hpp"

#pragma once

template<class tipo_dato>
class nodo{
private:
	tipo_dato dato_;
	nodo* izquierda_;
	nodo* derecha_;
public:
	nodo(void);
	nodo(tipo_dato dato);
	~nodo(void);
	nodo*& izquierda(void);
	nodo*& derecha(void);
	tipo_dato& dato(void);
};

//Constructor de la clase Nodo
template<class tipo_dato>
nodo<tipo_dato>::nodo(void):
dato_(),
izquierda_(nullptr),
derecha_(nullptr)
{}

//Constructor de la clase nodo que recibe un dato.
template<class tipo_dato>
nodo<tipo_dato>::nodo(tipo_dato dato):
dato_(dato),
izquierda_(nullptr),
derecha_(nullptr)
{}

//Destructor de la clase Nodo
template<class tipo_dato>
nodo<tipo_dato>::~nodo(void){}

//Metodo Get Derecha
template<class tipo_dato>
nodo<tipo_dato>*& nodo<tipo_dato>::derecha(void){
	return derecha_;
}

//Metodo Get Izquierda
template<class tipo_dato>
nodo<tipo_dato>*& nodo<tipo_dato>::izquierda(void){
	return izquierda_;
}

//Metodo Get Dato
template<class tipo_dato>
tipo_dato& nodo<tipo_dato>::dato(void){
	return dato_;
}