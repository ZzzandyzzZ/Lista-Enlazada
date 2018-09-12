#include "Iterador.h"

template<class X>
linkedlistiterator<X>::linkedlistiterator()
{
    current=NULL;
}
template<class R>
linkedlistiterator<R>::linkedlistiterator(nodeType<R>*ptr)
{
    current=ptr;
}
template <class A>
A linkedlistiterator<A>::operator *()
{
    return current->getdato();
}
template <class B>
linkedlistiterator<B> linkedlistiterator<B>::operator++()
{
    current=current->getsiguiente();
    return *this;
}
template <class C>
bool linkedlistiterator<C>::operator ==
                            (const linkedlistiterator<C>& right)const
{
    return(current==right.current);
}
template <class D>
bool linkedlistiterator<D>::operator!=(const linkedlistiterator<D>& right)const
{
    return(current!=right.current);
}
