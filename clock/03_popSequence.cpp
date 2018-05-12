#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct {
    unsigned int *element;
    int cap;
    int top;
} Stack;
inline unsigned int topOfStack(Stack *stack)
{
    if (stack->top < 0)
        return -1;
    return stack->element[stack->top];
}
bool stackIsFull(Stack *stack)
{
    if (stack->top + 1 < stack->cap)
        return false;
    else
        return true;
}
bool push(Stack *stack, int num)
{
    if (stack->top + 1 == stack->cap)
        return false;

    stack->element[++stack->top] = num;

    return true;
}
int pop(Stack *stack)
{
    if (stack->top == -1)
        return -1;

    return (unsigned int)stack->element[stack->top--];
}
bool judge(unsigned int *input, int maxCap, int squeLen, int inputLine)
{
    Stack stack;
    stack.element = (unsigned int *)malloc(maxCap * sizeof(unsigned int));
    stack.cap = maxCap;
    stack.top = -1;
    unsigned int squeNum = 1;
    for (int i = 0; i < squeLen; i++)
    {
        while (squeNum <= input[i] && !stackIsFull(&stack))
        {
            (void)push(&stack, squeNum);
            squeNum++;
        }
        if (pop(&stack) != input[i])
        {
            free(stack.element);
            return false;
        }
    }
    free(stack.element);
    return true;
}
int main()
{
    int maxCap, squeLen, inputLine;
    unsigned int *input;

    scanf("%d %d %d", &maxCap, &squeLen, &inputLine);
    
    for (int i = 0; i < inputLine; i++)
    {
        input = (unsigned int*)malloc(squeLen * sizeof(unsigned int));
        for (int j = 0; j < squeLen; j++)
        {
            scanf("%d", input + j);
        }
        judge(input, maxCap, squeLen, inputLine) ? printf("YES\n") : printf("NO\n");
    }
    free(input);

    return 0;
}