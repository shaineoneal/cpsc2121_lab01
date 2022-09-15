#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    List<char> list1;
    
    char c[] = {'z', 'p', 'r', 'p', 'd', 'a', 'h', 'q', 'o', 'r', 'f', 'r'};
    for(int i = 0; i < 12; i++){
        list1.insertEnd(c[i]);
    }


    list1.print("list1");


    cout << "last? = " << list1.getAt(2) << endl;
    list1.removeAt(2);
    cout << "last? = " << list1.getAt(2) << endl;

    return 0;
}