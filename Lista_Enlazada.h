#include "Iterador.h"
template<class S>
class linkedListType
{
public:
    const linkedListType<S>& operator=(const linkedListType<S>&);
    void initializelist();
    bool isemptylist()const;
    void print() const;
    int length() const;
    void destroyList();
    S front() const;
    S back() const;
    virtual bool search(const S& searchItem) const = 0;
    virtual void insertFirst(const S& newItem) = 0;
    virtual void insertLast(const S& newItem) = 0;
    virtual void deleteNode(const S& deleteItem) = 0;
    linkedlistiterator<S> begin();
    linkedlistiterator<S> end();
    linkedListType();
    linkedListType(const linkedListType<S>& otherList);
    ~linkedListType();

protected:
    int count;
    nodeType<S> *first;
    nodeType<S> *last;
private:
    void copyList(const linkedListType<S>& otherList);

};

template<class V>
bool linkedListType<V>::isemptylist()const
{
    return (first == NULL);
}
template <class Y>
linkedListType<Y>::linkedListType() //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}
template <class H>
void linkedListType<H>::destroyList()
{
    nodeType<H> *temp; //pointer to deallocate the memory
    //occupied by the node
    while (first != NULL) //while there are nodes in the list
    {
        temp = first; //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp; //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already
//been set to NULL by the while loop
count = 0;
}
template <class R>
void linkedListType<R>::initializelist()
{
    destroyList(); //if the list has any nodes, delete them
}
template <class F>
void linkedListType<F>::print() const
{
    nodeType<F> *current; //pointer to traverse the list
    current = first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}//end print
template <class L>
int linkedListType<L>::length() const
{
    return count;
}
template <class F>
F linkedListType<F>::front() const
{
    assert(first != NULL);
    return first->link; //return the info of the first node
}//end front
template <class W>
W linkedListType<W>::back() const
{
    assert(last != NULL);
    return last->link; //return the info of the last node
}//end back
template <class B>
linkedlistiterator<B> linkedListType<B>::begin()
{
    linkedlistiterator<B> temp(first);
    return temp;
}
template <class E>
linkedlistiterator<E> linkedListType<E>::end()
{
    linkedlistiterator<E> temp(NULL);
    return temp;
}
template <class C>
void linkedListType<C>::copyList
(const linkedListType<C>& otherList)
{
    nodeType<C> *newNode; //pointer to create a node
    nodeType<C> *current; //pointer to traverse the list
    if (first != NULL) //if the list is nonempty, make it empty
    destroyList();
    if (otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
    current = otherList.first; //current points to the
//list to be copied
    count = otherList.count;
//copy the first node
    first = new nodeType<C>; //create the node
    first->info = current->getdato(); //copy the info
    first->link = NULL; //set the link field of the node to NULL
    last = first; //make last point to the first node
    current = current->link; //make current point to the next
// node
//copy the remaining list
    while (current != NULL)
    {
        newNode = new nodeType<C>; //create a node
        newNode->info = current->info; //copy the info
        newNode->link = NULL;
        //set the link of newNode to NULL
        last->link = newNode; //attach newNode after last
        last = newNode; //make last point to the actual last
//node
        current = current->link; //make current point to the
//next node
            }//end while
        }//end else
    }//end copyList
template <class D>
linkedListType<D>::~linkedListType() //destructor
{
    destroyList();
}
template <class Z>
linkedListType<Z>::linkedListType(const linkedListType<Z>& otherList)
{
    first = NULL;
    copyList(otherList);
}//end copy constructor
template <class I>
const linkedListType<I>& linkedListType<I>::operator=(const linkedListType<I>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else
    return *this;
}

