#include <stdio.h>
#include "alistlib.h"

int main(int argc, char const *argv[])
{
    List L;
    makeNull(&L);
    for (int i = 0; i < 20; i++)
    {
        ElementType rd_num = rand() % 100;
        insertFirst(rd_num, &L);
    }
    printf("List after input 20 ramdom integer:\n");
    print(L);
    sort(&L);
    printf("List after sort:\n");
    print(L);
    return 0;
}
