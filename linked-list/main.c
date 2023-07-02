#include<stdio.h>
#include<linked-list.h>

LinkedList newLinkedList(size_t size) {
    return (LinkedList) {
        .head = NULL,
        .tail = NULL,
        .len = 0,
        .ele_size = size
    };
}


void main() {
    LinkedList ll = newLinkedList(sizeof(int));

    pushBackLinkedList(&ll, (void*) 10);
    pushBackLinkedList(&ll, (void*) 20);
    pushBackLinkedList(&ll, (void*) 30);
    pushBackLinkedList(&ll, (void*) 40);

    return 0;
}
