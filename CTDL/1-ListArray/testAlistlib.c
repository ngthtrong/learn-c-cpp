#include <stdio.h>
#include "alistlib.h"

int main() {
    List L;
    makeNull(&L);

    // Test makeNull()
    printf("Test makeNull():\n");
    printf("List size after makeNull(): %d\n", len(L));
    printf("Is the list empty? %s\n", empty(L) ? "Yes" : "No");
    printf("..................PASS\n");
    printf("\n");

    // Test insertFirst() and append()
    printf("Test insertFirst() and append():\n");
    insertFirst(5, &L);
    append(10, &L);
    append(15, &L);
    printf("List after insertFirst() and append(): ");
    print(L);
    printf("..................PASS\n");
    printf("\n");


    // Test len() and getAt()
    printf("Test len() and getAt():\n");
    printf("List size: %d\n", len(L));
    printf("Element at position 2: %d\n", getAt(2, L));
    printf("..................PASS\n");
    printf("\n");


    // Test setAt()
    printf("Test setAt():\n");
    setAt(2, 20, &L);
    printf("List after setAt(): ");
    print(L);
    printf("..................PASS\n");
    printf("\n");


    // Test popFirst() and popLast()
    printf("Test popFirst() and popLast():\n");
    printf("Popped element from the first position: %d\n", popFirst(&L));
    printf("Popped element from the last position: %d\n", popLast(&L));
    printf("List after popFirst() and popLast(): ");
    print(L);
    printf("..................PASS\n");
    printf("\n");

    // Test insertAt()
    printf("Test insertAt():\n");
    insertAt(1, 30, &L);
    insertAt(2, 40, &L);
    printf("List after insertAt(): ");
    print(L);
    printf("..................PASS\n");
    printf("\n");

    // Test popAt()
    printf("Test popAt():\n");
    printf("Popped element from position 2: %d\n", popAt(2, &L));
    printf("List after popAt(): ");
    print(L);
    printf("..................PASS\n");
    printf("\n");

    // Test locate()
    printf("Test locate():\n");
    printf("Position of element 40: %d\n", locate(40, L));
    printf("List after locate(): ");
    print(L);
    printf("..................PASS\n");
    printf("\n");

    // Test next() and previous()
    printf("Test next() and previous():\n");
    printf("Next position of position 1: %d\n", next(1, L));
    printf("Previous position of position 2: %d\n", previous(2, L));
    printf("\n");

    return 0;
}