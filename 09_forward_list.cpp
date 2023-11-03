#include "FList.h"

int main()
{
    FList<int> list;
    list.addHead(25);
    list.addHead(22);
    list.addTail(55);
    list.addTail(51);
    list.print();
    FList<int> list3;
    list3.addHead(12);
    list3.addTail(45);
    list3.addTail(56);
    list3.print();
    list3 += list;
    list3.print();
    FList<int> list2;
    list2.addHead(25);
    list2.addHead(28);
    list2.addHead(22);
    list2.addTail(55);
    list2.addTail(55);
    list2.addTail(220);
    list2.print();

    FList<int> test = list2 - list;
    test.print();
    FList<int> test2 = list2 + list;
    test2.print();
    FList<int> test3 = list2 * list;
    test3.print();
}
