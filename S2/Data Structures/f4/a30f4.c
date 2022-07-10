#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10    /*όριο μεγέθους της συνδεδεμένης λίστας,
                            ενδεικτικά τέθηκε ίσο με 50*/
#define StackLimit 10   // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 50

#define NilValue -1          // ειδική μεδενικη τιμη δείχνει το τέλος της Συνδ.λίστας

typedef struct
{
    int ID;
    float grade;
} StudentType;

typedef StudentType ListElementType; /*τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας,
                                    ενδεικτικά επιλέχθηκε ο τύπος int */
typedef StudentType StackElementType;   // ο τύπος των στοιχείων  της στοίβας
                                        //ενδεικτικά τύπος int
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

void PrintStoragePool(ListPointer List, ListPointer FreePtr, NodeType Node[]);
float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

int main()
{
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr, PredPtr;
    ListPointer Alist;
    ListElementType Item;
    StackType Stack;
    StackElementType tempItem;
    float minGrade;

    // A
    InitializeStoragePool(Node, &FreePtr);

    // B
    CreateList(&Alist);
    CreateStack(&Stack);

    // C
    printf("---------------Question C--------------------\n");
    PrintStoragePool(Alist, FreePtr, Node);

    // D
    printf("---------------Question D--------------------");
    printf("\n--------------Linked list--------------------\n");
    TraverseLinked(Alist, Node);

    // Ε
    printf("---------------Question E--------------------\n");
    for(int i=0; i<5; i++)
    {
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf(" %d", &Item.ID);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf(" %f", &Item.grade);
        PredPtr = NilValue;
        Insert(&Alist, Node, &FreePtr, PredPtr, Item);
    }

    // F
    printf("---------------Question F--------------------\n");
    PrintStoragePool(Alist, FreePtr, Node);

    // G
    printf("---------------Question G--------------------\n");
    printf("--------------Linked list--------------------\n");
    TraverseLinked(Alist, Node);

    // H
    printf("---------------Question H--------------------\n");
    printf("%sEmpty List\n", (EmptyList(Alist)?"":"Not an "));

    // I
    printf("---------------Question I--------------------\n");
    printf("%sFull List\n", (FullList(Alist)?"":"Not a "));

    // J
    printf("---------------Question J--------------------\n");
    minGrade = FindMins(Alist, Node, &Stack);
    printf("Min value=%.1f\n", minGrade);
    printf("AM with min grade are: ");
    while(!EmptyStack(Stack))
    {
        Pop(&Stack, &tempItem);
        printf("%d ", tempItem.ID);
    }
    printf("\n");

    // K
    printf("---------------Question K--------------------\n");
    TraverseStack(Stack);

    // L
    printf("---------------Question L--------------------\n");
    PrintStoragePool(Alist, FreePtr, Node);

    // M
    printf("---------------Question M--------------------\n");
    TraverseLinked(Alist, Node);

    return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1; i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.ID=-1;    /* δεν είναι αναγκαίο η απόδοση αρχικής τιμής στο πεδίο των δεδομένων, βοηθάει στην εκτύπωση */
        Node[i].Data.grade=-1.0;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.ID=-1;
    Node[NumberOfNodes-1].Data.grade=-1.0;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data.ID = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
                        εκτύπωση οι διαγραμμένοι κόμβοι */
  Node[P].Data.grade = -1.0;
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
*/
{
  ListPointer TempPtr ;

  if (!EmptyList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:<%d,%.1f> ->%d) ", CurrPtr, Node[CurrPtr].Data.ID, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
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
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("(<%d,%.1f>) ", Stack.Element[i].ID, Stack.Element[i].grade);
    }
    printf("\n");
}

void PrintStoragePool(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    printf("--------------Storage pool------------------\n");
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (int i=0;i<NumberOfNodes;i++)
    {
        printf("(%d:<%d,%.1f> ->%d) ", i, Node[i].Data.ID, Node[i].Data.grade, Node[i].Next);
    }
    printf("\n");
}

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack)
{
    ListPointer CurrPtr;
    float minGrade;
    StackElementType tempItem;

    if (!EmptyList(List))
    {
        CurrPtr = List;
        minGrade = Node[CurrPtr].Data.grade;
        tempItem.grade = minGrade;
        tempItem.ID = Node[CurrPtr].Data.ID;
        Push(Stack, tempItem);
        CurrPtr = Node[CurrPtr].Next;

        while (CurrPtr != NilValue)
        {
            if(Node[CurrPtr].Data.grade < minGrade)
            {
                // Empty the Stack
                while(!EmptyStack(*Stack))
                {
                    Pop(Stack, &tempItem);
                }
                minGrade = Node[CurrPtr].Data.grade;
                tempItem.grade = minGrade;
                tempItem.ID = Node[CurrPtr].Data.ID;
                Push(Stack, tempItem);
            }
            else if(Node[CurrPtr].Data.grade == minGrade)
            {
                tempItem.grade = minGrade;
                tempItem.ID = Node[CurrPtr].Data.ID;
                Push(Stack, tempItem);
            }
            CurrPtr = Node[CurrPtr].Next;
        }

        return minGrade;
    }
    return -1.0;
}
