#include "Object.h"
#include <iostream>
using std::cout;
using std::endl;
// Constructor por Defecto de Object
Object::Object(){
}
// Destructor de Object, necesario colocarlo para "definir" que los
// destructores de esta "Familia" de clases serán virtuales
Object::~Object(){
}
// Método de Impresión por defecto.
void Object::print()const{
    cout << "Object@" << this << endl;
}
// Método de Comparación por defecto, sólo compara las Direcciones.
bool Object::equals(Object* other)const{
    return this == other;
}


