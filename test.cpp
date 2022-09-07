#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    List<int> list1;

    for (int i=1, j = 1; i <= 10; i++){
        j = -2*j;
        list1.insertEnd(j);
    }
    //list1.removeStart();

    return 0;

}
