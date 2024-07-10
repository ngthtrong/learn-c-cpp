#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int Position;
typedef int ElementType;

typedef struct {
    ElementType elements[MAXSIZE];
    Position size;
} List;

List L;

void makeNull(List *L) {
    L->size = 0;
}

int len(List L) {
    return L.size;
}

int empty(List L) {
    return (L.size == 0);
}

int fullList(List L) {
    return (L.size == MAXSIZE);
}

void print(List L) {
    Position i;
    for (i = 0; i < L.size; ++i) {
        printf("%d ", L.elements[i]);
    }
    printf("\n");
}

ElementType getAt(Position p, List L) {
    if (p >= 1 && p <= L.size) {
        return L.elements[p - 1];
    } else {
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}

Position first(List L) {
    return 1;
}

Position endList(List L) {
    return L.size;
}

void setAt(Position p, ElementType x, List *L) {
    if (p >= 1 && p <= L->size) {
        L->elements[p - 1] = x;
    } else {
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}

void insertAt(Position p, ElementType x, List *L) {
    int i;
    if (p >= 1 && p <= L->size + 1) {
        if (L->size < MAXSIZE) {
            L->size += 1;
            for (i = L->size - 1; i >= p; i--) {
                L->elements[i] = L->elements[i - 1];
            }
            L->elements[p - 1] = x;
        } else {
            printf("List is full! Exit....\n");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}

ElementType popAt(Position p, List *L) {
    ElementType x;
    if (p >= 1 && p <= L->size) {
        x = L->elements[p - 1];
        Position q;
        for (q = p; q < L->size; q++) {
            L->elements[q - 1] = L->elements[q];
        }
        L->size--;
        return x;
    } else {
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}

void insertFirst(ElementType x, List *L) {
    insertAt(first(*L), x, L);
}

ElementType popFirst(List *L) {
    return popAt(first(*L), L);
}

void append(ElementType x, List *L) {
    insertAt(endList(*L) + 1, x, L);
}

ElementType popLast(List *L) {
    return popAt(endList(*L), L);
}

Position locate(ElementType x, List L) {
    Position p;
    int found = 0;
    for (p = first(L); p <= endList(L) && !found; p++) {
        if (L.elements[p - 1] == x) {
            found = 1;
        }
    }
    return p;
}

Position next(Position p, List L) {
    if (p >= 1 && p <= L.size) {
        return (p < L.size) ? p + 1 : p;
    } else {
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}

Position previous(Position p, List L) {
    if (p >= 1 && p <= L.size) {
        return (p > 1) ? p - 1 : p;
    } else {
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}



