#include <stdio.h>

#define StackLimit 15   // το όριο μεγέθους της στοίβας

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

void displayInfo(int q, int x, StackType _Stack);


int main()
{
    int x, n, temp;

    StackType Stack;
    StackType TempStack;

    CreateStack(&Stack);
    CreateStack(&TempStack);

    for(int i=0; i<15; i++)
    {
        Push(&Stack, i*10);
    }

    TraverseStack(Stack);

    printf("Give nth element (n<=%d) ", ((Stack.Top-1)/2));
    scanf("%d", &n);

    //a
    Pop(&Stack, &x); //140
    Pop(&Stack, &x); //130
    displayInfo(1, x, Stack);

    //b
    Pop(&Stack, &temp);         //120
    Push(&TempStack, temp);     //120
    Pop(&Stack, &temp);         //110
    x = temp;                   //110
    Push(&Stack, temp);         //110
    Pop(&TempStack, &temp);     //120
    Push(&Stack, temp);         //120
    displayInfo(2, x, Stack);

    //c
    for(int i=0; i<n; i++)
    {
        Pop(&Stack, &x);
    }
    displayInfo(3, x, Stack);

    //d
    Pop(&Stack, &temp);         //90
    Push(&TempStack, temp);     //90
    Pop(&Stack, &temp);         //80
    Push(&TempStack, temp);     //80
    Pop(&Stack, &temp);         //70
    x = temp;                   //70
    Push(&Stack, temp);         //70
    Pop(&TempStack, &temp);     //80
    Push(&Stack, temp);         //80
    Pop(&TempStack, &temp);     //90
    Push(&Stack, temp);         //90
    displayInfo(4, x, Stack);

    //e
    while(Stack.Top > 0)
    {
        Pop(&Stack, &temp);
        Push(&TempStack, temp);
    }
    Pop(&Stack, &temp);
    x = temp; //0
    Push(&Stack, temp);
    while(!EmptyStack(TempStack))
    {
        Pop(&TempStack, &temp);
        Push(&Stack, temp);
    }
    displayInfo(5, x, Stack);

    //f
    while(Stack.Top > 2)
    {
        Pop(&Stack, &temp);
        Push(&TempStack, temp);
    }
    Pop(&Stack, &temp);
    x = temp; //30
    Push(&Stack, temp);
    while(!EmptyStack(TempStack))
    {
        Pop(&TempStack, &temp);
        Push(&Stack, temp);
    }
    displayInfo(6, x, Stack);

    //g
    while(!EmptyStack(Stack))
    {
        Pop(&Stack, &x);
    }
    displayInfo(7, x, Stack);

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

void displayInfo(int q, int x, StackType _Stack)
{
    printf("\nQuestion ");

    switch (q)
    {
    case 1:
        printf("a");
        break;
    case 2:
        printf("b");
        break;
    case 3:
        printf("c");
        break;
    case 4:
        printf("d");
        break;
    case 5:
        printf("e");
        break;
    case 6:
        printf("f");
        break;
    case 7:
        printf("g");
        break;
    default:
        break;
    }

    printf(": x=%d\n", x);
    TraverseStack(_Stack);
}
