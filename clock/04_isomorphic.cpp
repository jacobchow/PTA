#include <stdlib.h>
#include <stdio.h>

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

}
bool isomorphic(TreeNode *tree1, TreeNode *tree2, Tree root1, Tree root2)
{

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
