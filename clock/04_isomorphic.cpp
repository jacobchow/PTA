#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXTREE 10
#define Null -1
typedef char ElementType;
typedef int Tree;
typedef struct{
    ElementType element;
    Tree left;
    Tree right;
}TreeNode;

Tree buildTree(TreeNode *tree)
{
    int nodeNum;
    ElementType inputElem;
    char left, right;
    int check[MAXTREE];
    memset(check, 0, sizeof(check));

    scanf("%d\n", &nodeNum);
    if (nodeNum <= 0)
        return Null;

    for (int i = 0; i < nodeNum; i++)
    {
        scanf("%c %c %c\n", &inputElem, &left, &right);
        
        tree[i].element = inputElem;
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
bool isomorphic(TreeNode *tree1, TreeNode *tree2, Tree root1, Tree root2)
{
    if (root1 == Null && root2 == Null)
        return true;
    if ((root1 == Null && root2 != Null)
        || (root2 == Null && root1 != Null))
        return false;

    if (tree1[root1].element != tree2[root2].element)
        return false;
    if (tree1[root1].left == Null
        && tree2[root2].left == Null)
        return isomorphic(tree1, tree2, tree1[root1].right, tree2[root2].right);
    if (tree1[root1].right == Null
        && tree2[root2].right == Null)
        return isomorphic(tree1, tree2, tree1[root1].left, tree2[root2].left);

    if (tree1[root1].left != Null
        && tree2[root2].left != Null
        && tree1[tree1[root1].left].element == tree2[tree2[root2].left].element)
        return ( isomorphic(tree1, tree2, tree1[root1].left, tree2[root2].left)
            && isomorphic(tree1, tree2, tree1[root1].right, tree2[root2].right));
    else
        return ( isomorphic(tree1, tree2, tree1[root1].left, tree2[root2].right)
            && isomorphic(tree1, tree2, tree1[root1].right, tree2[root2].left));
}
int main()
{
    Tree root1, root2;
    TreeNode tree1[MAXTREE];
    TreeNode tree2[MAXTREE];

    root1 = buildTree(tree1);
    root2 = buildTree(tree2);

    if (isomorphic(tree1, tree2, root1, root2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
