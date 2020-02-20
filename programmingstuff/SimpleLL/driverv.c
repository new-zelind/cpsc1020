#include "SimpleLL.h"

int main()
{
    /*head is a global variable*/
    head = NULL;
    removeNode(1);
    append(2);
    append(4);
    append(3);
    addFront(1);
    append(4);
    printList();
    removeNode(8);
    printList();
    removeNode(1);
    printList();
    removeNode(3);
    printList();
    removeAllOcc(4);
    printList();
    deleteList();
    printList();

    return 0;
}
