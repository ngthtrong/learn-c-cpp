#include <stdio.h>
#include "alistlib.h"

int main(int argc, char const *argv[])
{
    List L;
    makeNull(&L);
    for (int i = 0; i < 15; i++)
    {
        ElementType rd_num = rand() % 100;
        insertFirst(rd_num, &L);
    }
    insertAt(16, 0, &L);
    insertAt(17, 10, &L);
    insertAt(18, 20, &L);
    insertAt(19, 30, &L);
    insertAt(20, 40, &L);
    insertAt(16, 100, &L);
    printf("List after input 20 ramdom integer:\n");
    print(L);
    sort(&L);
    printf("List after sort:\n");
    print(L);
    return 0;
}
