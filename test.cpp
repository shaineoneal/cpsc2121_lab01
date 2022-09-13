#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    List<int> list1;
    
    list1.insertStart(50);
    list1.insertEnd(51);
    
    list1.print("listprint");

    cout << "isEmpty? = " << list1.empty() << endl;

    return 0;
}