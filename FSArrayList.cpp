#include "Object.h"
#include "TDAList.h"
#include "FSArrayList.h"
#include <iostream>
#include <cstdlib>

using std::cerr;
using std::endl;
using std::cout;

FSArrayList::FSArrayList(int Cap):Capacidad (Cap){
	Datos = new Object*[Capacidad];
	if (!Datos) {
		cerr << "Error\nNo Hay Memoria" << endl;
		exit(0);
	}
}

FSArrayList::~FSArrayList() {
	for (int i = 0; i < size; ++i) {
		delete Datos[i];
	}
	delete Datos;
}

bool FSArrayList::insert(Object* Neo, int Posit){
	if (Posit > size || Posit < 0) {
		return false;
	}
	if (isFull()) {
		return false;
	}
	if (Posit == size) {
		Datos[Posit] = Neo;
	} else {
		for(int i = size; i > Posit; i--) {
			Datos[i] = Datos[i - 1];
		}
		Datos[Posit] = Neo;
	}
	size++;
	return true;
}

bool FSArrayList::erase(unsigned Posit){
	if (Posit < 0 || Posit >= size) {
		return false;
	}
	Object* Objeto = Datos[Posit];
	for(int i = Posit; i < (size - 1); i++){
		Datos[i + 1] = Datos[i];
	}
	size--;
	return true;
}

Object* FSArrayList::first()const {
	if(isEmpty()) {
		return NULL;
	}
	return Datos[0];
}

Object* FSArrayList::last()const{
	if(isEmpty()) {
		return NULL;
	}
	return Datos[size - 1];
}

int FSArrayList::indexOf(Object* Busq)const{
	int Posit = -1;
	for(int i = 0; i < size; i++) {
		if(Datos[i]-> equals(Busq)) {
			Posit = i;
			break;
		}
	}
	return Posit;
}

Object* FSArrayList::get(unsigned Posit)const{
	if(Posit < 0 || Posit >= size) {
		return NULL;
	}
	return Datos[Posit];
}

bool FSArrayList::isEmpty()const{
	if(size == 0) {
		return true;
	}
	return false;
}

bool FSArrayList::isFull()const{
	if(size == Capacidad) {
		return true;
	}
	return false;
}

void FSArrayList::print()const{
	cout << "Jeje" << endl;
}

int FSArrayList::prev(int Posit)const{
	return Posit - 1;
}

int FSArrayList::next(int Posit)const{
	return Posit + 1;
}

void FSArrayList::reset(){
	cout << "Jeje" << endl;
}

int FSArrayList::getCapacity()const{
	return Capacidad;
}