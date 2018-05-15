#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Null -1
#define MAXTREE 10

typedef int Tree;
typedef char TreeElementType;
typedef struct {
    Tree left;
    Tree right;
}TreeNode;

typedef Tree QueElementType;
typedef struct {
    int capacity;
    int front;
    int rear;
    QueElementType *node;
} Quene;

Quene *queneCreate(int capacity)
{
    Quene *ret = NULL;
    if (capacity <= 0)
        return  ret;
    ret = (Quene *)malloc(sizeof(Quene) + sizeof(QueElementType) * (capacity + 1));
    if (ret == NULL)
        return ret;

    ret->capacity = capacity;
    ret->front = 0;
    ret->rear = 0;
    ret->node = (QueElementType *)(ret + 1);

    return ret;
}
void queneDestory(Quene *quene)
{
    free(quene);
}
bool queneIsFull(Quene *quene)
{
    if (quene == NULL)
        return true;

    if ((quene->rear + 1) % (quene->capacity + 1) == quene->front)
        return true;
    else
        return false;
}
bool queneIsEmpty(Quene *quene)
{
    if (quene == NULL)
        return false;

    if (quene->front == quene->rear)
        return true;
    else
        return false;
}
bool quenePush(Quene *quene, QueElementType elem)
{
    if (quene == NULL)
        return false;

    if (queneIsFull(quene))
        return false;

    quene->node[quene->rear] = elem;
    quene->rear = (quene->rear + 1) % (quene->capacity + 1);
    return true;
}

QueElementType quenePop(Quene *quene)
{
    QueElementType ret;

    if (queneIsEmpty(quene))
        return Null;

    ret = quene->node[quene->front];
    quene->front = (quene->front + 1) % (quene->capacity + 1);
    return ret;
}

Tree buildTree(TreeNode *tree)
{
    int nodeNum;
    char left, right;
    int check[MAXTREE];
    memset(check, 0, sizeof(check));

    scanf("%d\n", &nodeNum);
    if (nodeNum <= 0)
        return Null;

    for (int i = 0; i < nodeNum; i++)
    {
        scanf("%c %c\n", &left, &right);

        if (left != '-')
        {
            tree[i].left = left - '0';
            check[tree[i].left] = 1;
        }
        else
            tree[i].left = Null;

        if (right != '-')
        {
            tree[i].right = right - '0';
            check[tree[i].right] = 1;
        }
        else
            tree[i].right = Null;
    }

    for (int i = 0; i < nodeNum; i++)
    {
        if (check[i] == 0)
            return i;
    }
    return Null;
}

void listLeaves(TreeNode *tree, Tree root)
{
    Quene *quene = queneCreate(MAXTREE);
    Tree node;
    int flag = 1;

    quenePush(quene, (QueElementType)root);
    while (!queneIsEmpty(quene))
    {
        node = (Tree)(quenePop(quene));
        if (tree[node].left == Null && tree[node].right == Null)
        {
            if (flag)
            {
                flag = 0;
                printf("%d", node);
            }  
            else
            {
                printf(" %d", node);
            }
        }
        if(tree[node].left != Null)
            quenePush(quene, tree[node].left);
        if (tree[node].right != Null)
            quenePush(quene, tree[node].right);
    }
    queneDestory(quene);
}
int main()
{
    Tree root;
    TreeNode tree[MAXTREE];
    root = buildTree(tree);

    listLeaves(tree, root);
    
    return 0;
}

