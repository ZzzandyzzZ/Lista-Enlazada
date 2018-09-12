
#include "Lista_Enlazada.h"

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
bool search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list
    current = linkedListType<Type>::first; //start the search at the first node
    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
    if (found)
        found = (current->info == searchItem); //test for equality
    return found;
}//end search

void insert(const Type& newItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode; //pointer to create a node
    bool found;
    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem; //store newItem in the node
    newNode->link = NULL; //set the link field of the node
    //to NULL
    if (linkedListType<Type>::first == NULL) //Case 1
    {
        linkedListType<Type>::first = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;
    }
    else
    {
        current = linkedListType<Type>::first;
        found = false;
        while (current != NULL && !found) //search the list
            if (current->info >= newItem)
                found = true;
            else
            {
            trailCurrent = current;
            current = current->link;
            }
        if (current == linkedListType<Type>::first) //Case 2
        {
            newNode->link = linkedListType<Type>::first;
            linkedListType<Type>::first = newNode;
            linkedListType<Type>::count++;
        }
        else //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == NULL)
            linkedListType<Type>::last = newNode;
            linkedListType<Type>::count++;
        }
    }//end else
}//end insert

void insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst
void insertLast(const Type& newItem)
{
    insert(newItem);
}
void deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    if (linkedListType<Type>::first == NULL) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = linkedListType<Type>::first;
        found = false;
        while (current != NULL && !found) //search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == NULL) //Case 4
            cout << "The item to be deleted is not in the list."<< endl;
        else
            if (current->info == deleteItem){
                if (linkedListType<Type>::first == current) //Case 2
                {
                linkedListType<Type>::first = linkedListType<Type>::first->link;
                    if (linkedListType<Type>::first == NULL)
                        linkedListType<Type>::last = NULL;
                delete current;
                }
                else //Case 3
                {
                    trailCurrent->link = current->link;
                    if (current == linkedListType<Type>::last)
                    linkedListType<Type>::last = trailCurrent;
                    delete current;
                }
                linkedListType<Type>::count--;
            }
            else
                cout << "The item to be deleted is not in the "<< "list." << endl;
    }
}
};

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
bool search(const Type& searchItem) const
{
    nodeType<Type> *current;
    bool found = false;
    current = linkedListType<Type>::first;

    while (current != NULL && !found)
        if (current->info == searchItem)
            found = true;
        else
            current = current->link;
    return found;

}
void insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = linkedListType<Type>::first;
    linkedListType<Type>::first = newNode;
    linkedListType<Type>::count++;
    if (linkedListType<Type>::last == NULL)
    linkedListType<Type>::last = newNode;
}

void insertLast(const Type& newItem)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = NULL;
    if (linkedListType<Type>::first == NULL){
        linkedListType<Type>::first = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;
    }
    else
    {
        linkedListType<Type>::last->link = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;
    }
}
void deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;
    if (linkedListType<Type>::first == NULL)
        cout << "Cannot delete from an empty list."<< endl;
    else
    {
        if (linkedListType<Type>::first->info == deleteItem) //Case 2
        {
            current = linkedListType<Type>::first;
            linkedListType<Type>::first = linkedListType<Type>::first->link;
            linkedListType<Type>::count--;
            if (linkedListType<Type>::first == NULL) //the list has only one node
                linkedListType<Type>::last = NULL;
            delete current;
        }
    else //search the list for the node with the given info
    {
        found = false;
        trailCurrent = linkedListType<Type>::first; //set trailCurrent to point
        //to the first node
        current = linkedListType<Type>::first->link; //set current to point to
        //the second node

        while (current != NULL && !found)
        {
            if (current->info != deleteItem)
            {
                trailCurrent = current;
                current = current-> link;
            }
            else
                found = true;
            }//end while
            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                linkedListType<Type>::count--;
                if (linkedListType<Type>::last == current)
                    linkedListType<Type>::last = trailCurrent;
                delete current;
            }
            else
                cout << "The item to be deleted is not in "<< "the list." << endl;
        }
    }
}
};
