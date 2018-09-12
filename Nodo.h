#ifndef NODO_H
#define NODO_H


#include <iostream>

using namespace std;
template <class R>
class nodeType{
 public:
     R info;
    nodeType<R> *link;
    nodeType(R d=0)
    {
        info=d;
        this->link=NULL;
    }
    void nextnodeType(nodeType<R> *next)
    {
        link=next;
    }
    R getdato()
    {
        return info;
    }
    nodeType<R>*getsiguiente()
    {
        return link;
    }
};
#endif // NODO_H
