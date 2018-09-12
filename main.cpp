#include <iostream>
#include "LE_O_D.h"
using namespace std;
int main()
{
    orderedLinkedList<int> list1,list2;
    unorderedLinkedList<int> list3;
    int num;
    cout <<"Enter numbers ending with -999." << endl;
    cin >> num;
    while (num != -999)
    {
        list1.insert(num);
        list3.insertLast(num);
        cin >> num;
    }
    cout<<endl;
    cout<<"list1: ";
    list1.print();
    cout<<endl;
    cout<<"list3: ";
    list3.print();
    cout<<endl;
    list2 = list1;

    cout<<"list2: ";
    list2.print();
    cout << endl;
    cout << "Enter the number to be deleted: ";
    cin >> num;
    cout << endl;
    list2.deleteNode(num);
    cout << "After deleting "
    << num << ", list2: " << endl;
    list2.print();
    cout << endl;
    return 0;
}
