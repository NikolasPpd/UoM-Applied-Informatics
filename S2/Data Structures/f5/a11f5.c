#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE1 "i112f5.txt" // DICTIONARY
#define FILE2 "i111f5.txt" // INPUT FILE
#define MAX_WORD_LENGTH 31

typedef char BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data[MAX_WORD_LENGTH];
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item[]);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue[], boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue[], boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue[]);
void InorderTraversal(BinTreePointer Root);

void CreateDictionary(BinTreePointer *Root, FILE *fp);
int SpellingCheck(BinTreePointer Root, FILE *fp);

int main(){

    FILE *fp1,*fp2;
    BinTreePointer Root1; // DICTIONARY
    int notfound;

    CreateBST(&Root1);

    fp1 = fopen(FILE1,"r");
    fp2 = fopen(FILE2,"r");

    CreateDictionary(&Root1, fp1);
    printf("**********Dictionary**********\n");
    InorderTraversal(Root1);

    printf("\n**********Not in Dictionary**********\n");
    notfound = SpellingCheck(Root1, fp2);
    printf("Number of words not in Dictionary: %d", notfound);



    return 0;
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item[])
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;

    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
            if (strcmp(Item, LocPtr->Data) < 0)
            {
                LocPtr = LocPtr ->LChild;
            }
            else if (strcmp(Item, LocPtr->Data) > 0)
            {
                LocPtr = LocPtr ->RChild;
            }
            else
            {
                Found = TRUE;
            }
    }

    if(Found)
    {
        printf("To %s EINAI HDH STO DDA\n", Item);
    }
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr->Data, Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item, Parent->Data) < 0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue[], boolean *Found,
                BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
       if (strcmp(KeyValue, (*LocPtr)->Data) < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue, (*LocPtr)->Data) > 0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue[], boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή TRUE, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue[])
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   boolean Found;       // TRUE AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                strcpy(n->Data, nNext->Data);
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s\n",Root->Data);
        InorderTraversal(Root->RChild);
    }
}

void CreateDictionary(BinTreePointer *Root, FILE *fp)
{
    int nscan;
    char termChar;
    char currWord[MAX_WORD_LENGTH];

    while(TRUE){
        nscan = fscanf(fp, "%[^\n]%c", currWord, &termChar);

        if(nscan == EOF){
            break;
        }
        BSTInsert(Root,currWord);

    }

}

int SpellingCheck(BinTreePointer Root, FILE *fp)
{
    int notfound;
    char currWord[MAX_WORD_LENGTH];
    int nscan;
    char termChar;
    boolean found;
    BinTreePointer LocPtr;
    notfound=0;

    while(TRUE){
        nscan = fscanf(fp, "%[^\n]%c", currWord, &termChar);
        if(nscan == EOF){
            break;
        }
        BSTSearch(Root,currWord,&found,&LocPtr);
        if(!found){
            printf("%s\n",currWord);
            notfound++;
        }
    }
 return notfound;
}

/*
   ___    ___  ___                     __         _           __       __               __
 /'___\ /'___\/\_ \                   /\ \      /' \         /\ \__   /\ \  __         /\ `\
/\ \__//\ \__/\//\ \    __  __    ____\ \ \___ /\ ,/'    ____\ \ ,_\  \_\ \/\_\    ___ \`\  \
\ \ ,__\ \ ,__\ \ \ \  /\ \/\ \  /',__\\ \  _ `\ \ \    /',__\\ \ \/  /'_` \/\ \ /' _ `\`\`\ \
 \ \ \_/\ \ \_/  \_\ \_\ \ \_\ \/\__, `\\ \ \ \ \ \ `\ /\__, `\\ \ \_/\ \L\ \ \ \/\ \/\ \`\/' \
  \ \_\  \ \_\   /\____\\ \____/\/\____/ \ \_\ \_\ `\__\/\____/ \ \__\ \___,_\ \_\ \_\ \_\/\__/
   \/_/   \/_/   \/____/ \/___/  \/___/   \/_/\/_/`\/_/ \/___/   \/__/\/__,_ /\/_/\/_/\/_/\/_/
*/
