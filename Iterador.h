#include "Nodo.h"
#ifndef ITERADOR_H
#define ITERADOR_H


template <class T>
class linkedlistiterator
{
    nodeType<T>*current;
public:
    linkedlistiterator();
    linkedlistiterator(nodeType<T>*ptr);
    T operator*();
    linkedlistiterator<T> operator++();
    bool operator==(const linkedlistiterator<T> &right)const;
    bool operator!=(const linkedlistiterator<T> &right)const;


};

#endif // ITERADOR_H
