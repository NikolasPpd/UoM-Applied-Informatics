#include <stdio.h>

#define StackLimit 50   // το όριο μεγέθους της στοίβας

typedef struct {
    int price;
    char size;
} item;

typedef item StackElementType;   // ο τύπος των στοιχείων  της στοίβας

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
void showInBox(StackType Stack);
void showOutBox(StackType Stack);


int main()
{
    int itemCount;
    char sizeSel;
    item tempItem;
    StackType ItemStackIn;
    StackType ItemStackOut;
    int itemFound = 0;

    CreateStack(&ItemStackIn);
    CreateStack(&ItemStackOut);

    //1
    printf("Give number of items ");
    scanf("%d", &itemCount);

    //2
    printf("Give the items to store\n");

    for(int i=0; i<itemCount; i++)
    {
        printf("Give price ");
        scanf("%d", &tempItem.price);
        printf("Give size ");
        scanf(" %c", &tempItem.size);
        Push(&ItemStackIn, tempItem);
    }

    //3
    printf("\n");
    showInBox(ItemStackIn);

    //4
    printf("What size do you want? ");
    scanf(" %c", &sizeSel);

    //Search for item
    while(!EmptyStack(ItemStackIn) && !itemFound)
    {
        Pop(&ItemStackIn, &tempItem);
        Push(&ItemStackOut, tempItem);
        if(tempItem.size == sizeSel)
        {
            itemFound = 1;
        }
    }

    if(itemFound)
    {
        printf("Found the size %c\n\n", sizeSel);
        Pop(&ItemStackOut, &tempItem);
    }
    else
    {
        printf("Not Found the size %c\n\n", sizeSel);
    }

    //5
    showInBox(ItemStackIn);
    showOutBox(ItemStackOut);

    //6
    while(!EmptyStack(ItemStackOut))
    {
        Pop(&ItemStackOut, &tempItem);
        Push(&ItemStackIn, tempItem);
        if(EmptyStack(ItemStackOut)) break;
    }

    //7
    showInBox(ItemStackIn);
    showOutBox(ItemStackOut);

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
        printf("%c, %d\n", Stack.Element[i].size, Stack.Element[i].price);
    }
    printf("\n");
}

void showInBox(StackType Stack)
{
    printf("Items in the box\n");
    TraverseStack(Stack);
}

void showOutBox(StackType Stack)
{
    printf("Items out of the box\n");
    TraverseStack(Stack);
}
