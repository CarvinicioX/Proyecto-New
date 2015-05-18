#ifndef FSCURSORLIST_H
#define FSCURSORLIST_H
#include "Object.h"
#include "TDAList.h"
class FSCursorList : public TDAList{
    struct Row{
        int next, prev;
        Object* Data;
    };
    int head, Capacidad;
    Row* rows;
  public:
    FSCursorList(int);
    virtual ~FSCursorList();
    virtual bool insert(Object*, int);
    virtual bool erase(unsigned);
    virtual Object* first()const;
    virtual Object* last()const;
    virtual int indexOf(Object*)const;
    virtual Object* get(unsigned)const;
    virtual bool isEmpty()const;
    virtual bool isFull()const;
    int nextAvail();
    virtual void print()const;
    virtual int prev(int)const;
    virtual int next(int)const;
    virtual void reset();
    virtual int getCapacity()const;
};

#endif