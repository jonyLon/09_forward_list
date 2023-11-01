#include "FList.h"

int main()
{
    FList<int> list;

    list.addHead(25);
    list.addHead(22);
    list.addTail(55);
    list.addTail(51);
    list.print();
    FList<int> list2;
    list2.addHead(25);
    list2.addHead(28);
    list2.addHead(22);
    list2.addTail(55);
    list2.addTail(220);
    list2.print();

    FList<int> test = list2 - list;
    test.print();
}
