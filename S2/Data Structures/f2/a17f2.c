#include <stdio.h>

#define StackLimit 20   // το όριο μεγέθους της στοίβας

typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

StackType CopyStack(StackType *s1);


int main()
{
    StackType s1, s2;

    CreateStack(&s1);
    CreateStack(&s2);

    for(int i=0; i<StackLimit; i++)
    {
        Push(&s1, i);
    }

    printf("Stack s1\n");
    TraverseStack(s1);

    printf("After copying s1 to s2\n");
    s2 = CopyStack(&s1);
    printf("Stack s1\n");
    TraverseStack(s1);
    printf("Stack s2\n");
    TraverseStack(s2);

    return 0;
}


void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

StackType CopyStack(StackType *s1)
{
    StackType tempStack;
    StackType _s2;
    CreateStack(&tempStack);
    CreateStack(&_s2);

    int tempItem;

    //Empty s1 into tempStack
    while(!EmptyStack(*s1))
    {
        Pop(s1, &tempItem);
        Push(&tempStack, tempItem);
    }

    //Push tempStack items into s1 & _s2
    while(!EmptyStack(tempStack))
    {
        Pop(&tempStack, &tempItem);
        Push(s1, tempItem);
        Push(&_s2, tempItem);
    }

    return _s2;
}
