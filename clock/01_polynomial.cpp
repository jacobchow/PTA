#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode * Polynomial;
struct PolyNode {
    int coefficient;
    int exponent;
    Polynomial next;
};
Polynomial ReadPloy(void);
Polynomial Multi(Polynomial p1, Polynomial p2);
Polynomial Add(Polynomial p1, Polynomial p2);
void PrintPoly(Polynomial P);
void Attach(int c, int e, Polynomial *rear);
Polynomial insert(int c, int e, Polynomial head);

int main()
{
    Polynomial p1, p2, pplus, pmulti;

    p1 = ReadPloy();
    p2 = ReadPloy();
    pmulti = Multi(p1, p2);
    PrintPoly(pmulti);
    pplus = Add(p1, p2);
    PrintPoly(pplus);

    return 0;
}

Polynomial ReadPloy(void)
{
    int sum, c, e;
    Polynomial head, rear, tmp;
    //printf("input please\n");
    scanf("%d", &sum);
    if (sum <= 0)
        return NULL;
    head = (Polynomial)malloc(sizeof(struct PolyNode));
    head->next = NULL;
    rear = head;

    while (sum--)
    {
        scanf("%d %d", &c, &e);
        Attach(c, e, &rear);
    }
    tmp = head;
    head = head->next;
    free(tmp);

    return head;
}

Polynomial Multi(Polynomial p1, Polynomial p2)
{
    Polynomial head, rear, tmp;
    Polynomial t1 = p1;
    Polynomial t2 = p2;
    int c, e;

    head = (Polynomial)malloc(sizeof(struct PolyNode));
    head->next = NULL;
    rear = head;

    if (t1 == NULL || t2 == NULL)
        return NULL;

    while (t2)
    {
        Attach(t1->coefficient * t2->coefficient, t1->exponent + t2->exponent, &rear);
        t2 = t2->next;
    }
    tmp = head;
    head = head->next;
    free(tmp);

    t1 = t1->next;
    while (t1)
    {
        t2 = p2;
        while (t2)
        {
            c = t1->coefficient * t2->coefficient;
            e = t1->exponent + t2->exponent;
            head = insert(c, e, head);

            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return head;
}

Polynomial Add(Polynomial p1, Polynomial p2)
{
    Polynomial head, rear, tmp;
    Polynomial t1 = p1;
    Polynomial t2 = p2;

    head = (Polynomial)malloc(sizeof(struct PolyNode));
    head->next = NULL;
    rear = head;

    while (t1 && t2)
    {
        if (t1->exponent == t2->exponent)
        {
            Attach(t1->coefficient + t2->coefficient, t1->exponent, &rear);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->exponent > t2->exponent)
        {
            Attach(t1->coefficient, t1->exponent, &rear);
            t1 = t1->next;
        }
        else
        {
            Attach(t2->coefficient, t2->exponent, &rear);
            t2 = t2->next;
        }        
    }

    while (t1)
    {
        Attach(t1->coefficient, t1->exponent, &rear);
        t1 = t1->next;
    }
    while (t2)
    {
        Attach(t2->coefficient, t2->exponent, &rear);
        t2 = t2->next;
    }
    tmp = head;
    head = head->next;
    free(tmp);

    return head;
}

void PrintPoly(Polynomial P)
{
    int flag = 0;
    if (P == NULL)
    {
        printf("0 0\n");
        return;
    }
    while (P)
    {
        if (P->coefficient)
        {
            if (flag)
                printf(" ");
            else
                flag = 1;
                printf("%d %d", P->coefficient, P->exponent);  
        }
        P = P->next; 
    }
    if(flag == 0)
        printf("0 0\n");
    printf("\n");
}

void Attach(int c, int e, Polynomial *rear)
{
    Polynomial newNode = (Polynomial)malloc(sizeof(struct PolyNode));

    newNode->coefficient = c;
    newNode->exponent = e;
    newNode->next = NULL;
    (*rear)->next = newNode;
    *rear = newNode;
}

Polynomial insert(int c, int e, Polynomial head)
{
    Polynomial newNode, tmp;
    Polynomial index = (Polynomial)malloc(sizeof(struct PolyNode));
    tmp = index;
    index->next = head;
    if (index->next == NULL)
    {
        head = (Polynomial)malloc(sizeof(struct PolyNode));
        head->coefficient = c;
        head->exponent = e;
        head->next = NULL;
        
        free(tmp);
        return head;
    }
    while (index->next && index->next->exponent > e)
        index = index->next;
    if (index->next != NULL && index->next->exponent == e)
    {
        index->next->coefficient += c;
    }
    else
    {
        newNode = (Polynomial)malloc(sizeof(struct PolyNode));
        newNode->coefficient = c;
        newNode->exponent = e;
        newNode->next = index->next;
        index->next = newNode;
    }
    free(tmp);
    return head;
}