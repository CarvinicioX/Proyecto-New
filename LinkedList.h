#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Object.h"
#include "TDAList.h"
#include "DLLNode.h"
/*
* Declaración de la Clase LinkedList, que es una implementación del TDAList
* utilizando listas doblemente enlazadas. Nótese la herencia en esta clase.
* Nótese así mismo, que están todas las operaciones virtuales puras de la
* clase TDAList, pues acá se tendrán que definir cada una de estas.
* El único miembro que tiene esta clase es head, que representa la cabeza de
* la lista, no es necesario tener size, pues lo heredamos de la clase base.
*/
class LinkedList : public TDAList{
  protected:
    DLLNode* head;
  public:
    LinkedList();
    virtual ~LinkedList();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual bool erase(unsigned) ;
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void reset() ;
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isFull()const ;
    virtual int getCapacity()const;
};

#endif
