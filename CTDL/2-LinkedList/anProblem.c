#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct groupStudent
{
    char ten[100];
    int diem;
} Ele;

typedef struct cellTag
{
    Ele data;
    struct cellTag *next;
} node;

typedef node *Position;
typedef Position List;
char firsName[100];

Position MakeNull(List *pL)
{
    *pL = (Position)malloc(sizeof(node));
    (*pL)->next = NULL;
    return *pL;
}

void PrintList(List *pL)
{
    Position p = (*pL)->next;
    while (p != NULL)
    {
        printf("%s: %d\n", p->data.ten, p->data.diem);
        p = p->next;
    }
    printf("---END---\n");
}

void Insert(List *pL, int pos, Ele newsStudent)
{
    Position p = *pL;
    for (int i = 0; i < pos - 1 && p->next != NULL; i++)
    {
        p = p->next;
    }
    Position temp = (Position)malloc(sizeof(node));
    strcpy(temp->data.ten, newsStudent.ten);
    temp->data.diem = newsStudent.diem;
    temp->next = p->next;
    p->next = temp;
}

void Delete(List *pL, int pos)
{
    Position p = *pL;
    for (int i = 0; i < pos - 1 && p->next != NULL; i++)
    {
        p = p->next;
    }
    if (p->next != NULL)
    {
        Position temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

int locateOfMark(List *pL, char c[])
{
    Position p = (*pL)->next;
    while (p != NULL)
    {
        if (strcmp(c, p->data.ten) == 0)
        {
            return p->data.diem;
        }
        p = p->next;
    }
    return -1;
}

int main()
{
    List L;
    L = MakeNull(&L);

    fgets(firsName, sizeof(firsName), stdin);
    int len = strlen(firsName);
    if (len > 0 && firsName[len - 1] == '\n')
    {
        firsName[len - 1] = '\0';
    }
    Insert(&L, 1, (Ele){"Harry Potter", 10});
    Insert(&L, 2, (Ele){"Hermione Granger", 8});
    Insert(&L, 3, (Ele){"Draco Malfoy", 7});
    Insert(&L, 4, (Ele){"Luna Lovegood", 8});
    Insert(&L, 5, (Ele){"Ron Weasley", 9});

    // Ele student[5] = {
    //     {"Harry Potter", 10},
    //     {"Hermione Granger", 8},
    //     {"Draco Malfoy", 7},
    //     {"Luna Lovegood", 8},
    //     {"Ron Weasley", 9}};

    Ele newsStudent = {"Gini Weasley", 6};

    // CreateList(&L, student);
    PrintList(&L);

    Insert(&L, 2, newsStudent);
    PrintList(&L);

    Delete(&L, 3);
    PrintList(&L);

    int mark = locateOfMark(&L, firsName);
    if (mark != -1)
    {
        printf("%d\n", mark);
    }
    else
    {
        printf("Student not found.\n");
    }

    return 0;
}