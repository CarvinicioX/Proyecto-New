#include "FSCursorList.h"
#include "TDAList.h"
#include "Object.h"
#include <iostream>

using namespace std;

FSCursorList::FSCursorList(int Posit){
    this->Capacidad = Posit;
    head = -1;
    size =0;
    rows = new Row[Posit];
    if (!rows)
        cerr << "Error\nNo Hay Memoria" << endl;
    for (int i = 0; i < Capacidad; ++i){
        rows[i].prev = -1;
        rows[i].next = -1;
        rows[i].Data = NULL;

    }
}

FSCursorList::~FSCursorList(){
    int temp = head;
    for (int i = 0; i < size; ++i) {
        delete rows[temp].Data;
        temp = rows[temp].next;
    }
    delete[] rows;

}

bool FSCursorList::insert(Object* Dato, int Posit){
    if (Posit < 0 || Posit >= Capacidad) {
        return false;
    }
    if (isFull()) {
        return false;
    }
    int neo = nextAvail();
    if (head == -1 && Posit == 0) {
        head = neo;
        rows[head].prev = -1;
        rows[head].next =-1;
        rows[head].Data = Dato;
    } else if (Posit == 0 && head != -1) {
        rows[neo].prev = -1;
        rows[neo].next = head;
        rows[head].prev = neo;
        head = neo;
        rows[neo].Data = Dato;
    } else {
        int temp = head;
        for (int i = 0; i < (Posit - 1); ++i) {
            temp = rows[temp].next;
        }
        rows[neo].prev = temp;
        rows[neo].next = rows[temp].next;
        if(Posit < size)
            rows[rows[neo].prev].next = neo;
        rows[neo].Data = Dato;
    }
    size++;
    return true;
}

bool FSCursorList::erase(unsigned Posit){
    if (Posit < 0 || Posit >= size) {
        return false;
    }
    int neo, temp;
    Object* Dato;
    if (Posit == 0){
        temp = head;
        Dato = rows[head].Data;
        head = rows[head].next;
        rows[temp].next = -1;
        rows[temp].prev = -1;
        rows[temp].Data = NULL;
        rows[head].prev = -1;
    } else {
        temp = head;
        for (int i = 0 ; i < (Posit - 1); i++) {
            temp = rows[temp].next;
        }
        neo = rows[temp].next;
        Dato = rows[neo].Data;
        rows[temp].next = rows[neo].next;
        rows[rows[neo].next].prev = temp;
    }
    size--;
    return true;
}

Object* FSCursorList::first()const{
    if (size == 0) {
        return NULL;
    }
    return rows[head].Data;
}

Object* FSCursorList::last()const{ 
    int temp = head, Contador = 0;
    do {
        temp = rows[temp].next;
        Contador++;
    } while (Contador < size);
    return rows[temp].Data;
}

int FSCursorList::indexOf(Object* Dato)const{
    int temp = head;
    for (int i = 0; i < size; i++) {
        if (rows[i].Data->equals(Dato)) {
            return i;
        }
        temp = rows[temp].next;
    }
    return -1;
}

Object* FSCursorList::get(unsigned Posit)const{
    if (size == 0) {
        return NULL;
    }
    int temp = head;
    for (int i = 0; i < Posit; ++i) {
        temp = rows[temp].next;
    }
    return rows[temp].Data;
}

int FSCursorList::nextAvail(){
    if (size == 0) {
        return 0;
    }
    for (int i = 0; i < Capacidad; ++i) {
        if (rows[i].next == -1 && rows[i].prev == -1 && rows[i].Data == NULL) {
            return i;
        }
    }
}

bool FSCursorList::isEmpty()const{
    if (size == 0) {
        return true;
    }
    return false;
}

bool FSCursorList::isFull()const{
    if (size == Capacidad) {
        return true;
    }
    return false;
}

void FSCursorList::print()const{
    cout << "Jeje" << endl;
}

int FSCursorList::prev(int Posit)const{
    return Posit - 1;
}

int FSCursorList::next(int Posit)const{
    return Posit + 1;
}

void FSCursorList::reset(){
    cout << "Jeje" << endl;
}

int FSCursorList::getCapacity()const{
    return Capacidad;
}