#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int tag;
    int num;
} Node;

int main()
{
    int n;
    scanf("%d", &n);
    int flag = 0;
    int topOfStack = 0;
    Node *stack = (Node *)malloc(n * sizeof(Node));
    char sinput[10];

    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%s", sinput);
        if (sinput[1] == 'u')   //push
        {
            stack[topOfStack].tag = 1;
            scanf("%d", &(stack[topOfStack].num));
            topOfStack++;
        }
        else
        {                       //pop
            //依次弹出左子树
            while (topOfStack > 0 && stack[topOfStack - 1].tag == 2)
            {
                if (flag)
                    printf(" ");
                else
                    flag = 1;
                printf("%d", stack[--topOfStack].num);
            }
            //中序遍历的根节点pop后再push，等右子树处理完再弹出，所以只需要记录标记为2
            if (topOfStack > 0)
                stack[topOfStack - 1].tag = 2;
        }
    }

    while (topOfStack)
    {
        if (flag)
            printf(" ");
        else
            flag = 1;
        printf("%d", stack[--topOfStack].num);
    }
    free(stack);
    return 0;
}