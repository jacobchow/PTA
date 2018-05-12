#include <stdio.h>
#include <string.h>

#define MAXN 100000
#define ROW 3
#define VALUE   0
#define NEXT    1
#define PRE     2

int initList(int listArray[][ROW], int allNum)
{
    int address, value, next;
    int rear = -1;
    while (allNum--)
    {
        scanf("%d %d %d", &address, &value, &next);
        listArray[address][VALUE] = value;
        listArray[address][NEXT] = next;
        if (next != -1)
            listArray[next][PRE] = address;
        else
            rear = address;
    }
    return rear;
}

int reversingList(int listArray[][ROW], int head, int rear, int allNum, int subNum)
{
    int lastn = allNum % subNum;
    int address = rear;
    int nextHead, newHead;
    int index;

    while (lastn--)
    {
        address = listArray[address][PRE];
    }
    nextHead = listArray[address][NEXT];
    while (1)
    {
        newHead = address;
        index = subNum;
        while (--index)
        {
            listArray[address][NEXT] = listArray[address][PRE];
            address = listArray[address][PRE];
        }
        listArray[address][NEXT] = nextHead;
        nextHead = newHead;
        if (listArray[address][PRE] != -1)
            address = listArray[address][PRE];
        else
            break;
    }
    return newHead;
}
void printList(int listArray[][ROW], int head)
{
    int index = head;
    while (listArray[index][NEXT] != -1)
    {
        printf("%05d %d %05d\n", 
            index, listArray[index][VALUE], listArray[index][NEXT]);
        index = listArray[index][NEXT];
    }
    printf("%05d %d %d\n", index, listArray[index][VALUE], listArray[index][NEXT]);
}

int main()
{
    int listArray[MAXN][ROW] = { {-1} };
    int allNum, subNum;
    int head, rear;

    memset(listArray, -1, MAXN*ROW);
    scanf("%d %d %d", &head, &allNum, &subNum);
    if (!allNum)
        return 0;

    rear = initList(listArray, allNum);
    head = reversingList(listArray, head, rear, allNum, subNum);
    printList(listArray, head);

    return 0;
}