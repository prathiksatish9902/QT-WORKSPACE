#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    LinkedList <int> intList;
    LinkedList <float> floatList;
    LinkedList <char> charList;
    LinkedList <string> stringList;
    LinkedList <double> doubleList;


    intList.append(1);
    intList.append(2);
    intList.append(3);
    intList.append(4);
    intList.append(5);
    intList.display();


    floatList.append(2.5);
    floatList.append(2.6);
    floatList.append(2.7);
    floatList.append(2.8);
    floatList.append(2.9);
    floatList.display();


    charList.append('P');
    charList.append('r');
    charList.append('a');
    charList.append('t');
    charList.append('h');
    charList.append('i');
    charList.append('k');
    charList.display();

    stringList.append("prathik");
    stringList.append("darshan");
    stringList.append("girish");
    stringList.append("anurag");
    stringList.append("dhimanth");
    stringList.display();

    doubleList.append(3.142);
    doubleList.append(3.143);
    doubleList.append(3.144);
    doubleList.append(3.145);
    doubleList.append(3.146);
    doubleList.display();


    return 0;
}
