#include <stdlib.h>
#include <stdio.h>

typedef struct stack
{
    int top;
    int size;
    int *array;
} stack;

stack *new_stack(int size)
{
    int *array = (int*)malloc(size*sizeof(int));
    stack *stk = (stack*)malloc(sizeof(stack));
    // insert code
    if (!array || !stk)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    stk->top = -1;
    stk->size = size;
    stk->array = array;
    return stk;
    // end insert code
}

void push(stack *stk, int val) {
    // insert code
    if (stk->top == stk->size - 1)
    {
        printf("Stack overflow! Cannot push %d\n", val);
        return;
    }
    stk->array[++stk->top] = val;
    // end insert code
}

int pop(stack *stk) {
    // insert code
    if (stk->top == -1)
    {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    return stk->array[stk->top--];
    // end insert code
}

int main()
{
    stack *stk = new_stack(4);

    push(stk, 1);
    push(stk, 2);
    push(stk, 3);
    push(stk, 4);
    push(stk, 5);
    push(stk, 6);
    push(stk, 7);
    push(stk, 8);



    printf("pop : %d\n", pop(stk));


    // inserted code, free allocated memory
    free(stk->array);
    free(stk);

    return 0;
}