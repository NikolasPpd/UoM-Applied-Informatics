#include <stdio.h>

#define StackLimit 50   // το όριο μεγέθους της στοίβας

typedef char StackElementType;   // ο τύπος των στοιχείων  της στοίβας

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

int main()
{
    int enteredC = 0;
    int correct = 1;
    char ch, temp;
    int firstChar = 1;

    StackType StringStack;

    CreateStack(&StringStack);

    printf("Enter string:\n");

    while(1)
    {
        //Διάβασμα χαρακτήρων
        scanf("%c", &ch); getchar();

        //Αν ch = '#' σταμάτα το loop
        if(ch == '#')
        {
            // Περίπτωση που ο πρώτος χαρακτήρας είναι το '#'
            if(firstChar)
            {
                return 0;
            }
            else
            {
                if(!EmptyStack(StringStack))
                {
                    correct = 0;
                }
                break;
            }
        }
        //Αλλιώς αν ch = 'C' ξεκίνα να ελέγχεις αν το 2ο string είναι το αντίστροφο του 1ου
        else if(ch == 'C')
        {
            enteredC = 1;
            firstChar = 0;
            continue;
        }

        firstChar = 0;
        //Αν δεν έχει εισαχθεί ακόμα το 'C', βάζε τους χαρακτήρες στο Stack
        if(!enteredC)
        {
            Push(&StringStack, ch);
        }
        else
        {
            if(!EmptyStack(StringStack))
            {
                //Εξαγωγή χαρακτήρος από το Stack για σύγκριση
                Pop(&StringStack, &temp);
                if(!(ch == temp))
                {
                    correct = 0;
                    break;
                }
            }
            else
            {
                correct = 0;
                break;
            }
        }
    }

    //Εκτύπωση αποτελέσματος
    printf("%s",(correct? "TRUE": "FALSE"));

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
