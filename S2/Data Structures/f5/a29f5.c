#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    int age,amka,afm;
} BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

    int main(){
        BinTreePointer neoi,geroi,LocPtr;
        BinTreeElementType temp;
        char check;
        boolean found=FALSE;

        CreateBST(&neoi);
        CreateBST(&geroi);

        printf("Give AMKA? ");
        scanf("%d", &temp.amka);
        printf("Give AFM? ");
        scanf("%d", &temp.afm);
        printf("Give age? ");
        scanf("%d", &temp.age);
        if(temp.age<60){
            BSTInsert(&neoi,temp);
        }else{
            BSTInsert(&geroi,temp);
        }
        printf("\nContinue Y/N: ");
        scanf(" %c",&check);
        while(tolower(check)!='y' && tolower(check)!='n'){
            printf("Invalid character. Try again: ");
            scanf(" %c",&check);
        }
        while(tolower(check)=='y'){
            printf("Give AMKA? ");
            scanf("%d", &temp.amka);
            printf("Give AFM? ");
            scanf("%d", &temp.afm);
            printf("Give age? ");
            scanf("%d", &temp.age);
            if(temp.age<60){
            BSTInsert(&neoi,temp);
            }
            else{
            BSTInsert(&geroi,temp);
            }
            printf("\nContinue Y/N: ");
            scanf(" %c",&check);
            while(tolower(check)!='y' && tolower(check)!='n'){
                printf("Invalid character. Try again: ");
                scanf(" %c",&check);
            }
        }
        printf("People with age less-equal 60\n");
        InorderTraversal(neoi);
        printf("\n\nPeople with age greater than 60\n");
        InorderTraversal(geroi);
        printf("\n");

        for(int i=0; i<3; i++)
        {
            printf("Give AMKA: ");
            scanf("%d",&temp.amka);
            printf("Give age: ");
            scanf("%d",&temp.age);
            if(temp.age<60){
                BSTSearch(neoi,temp,&found,&LocPtr);
            }
            else{
                BSTSearch(geroi,temp,&found,&LocPtr);
            }

            if(found==TRUE && (LocPtr->Data.age == temp.age)){
                printf("The person with AMKA %d, AFM %d and age %d is the catalogue\n",LocPtr->Data.amka,LocPtr->Data.afm,LocPtr->Data.age);
            }
            else if(found==TRUE){
                printf("The person with AMKA %d has age %d different from the person you are looking for\n",LocPtr->Data.amka,LocPtr->Data.age);
            }
            else{
                printf("The person with AMKA %d and age %d not found\n", temp.amka, temp.age);
                printf("The person with AMKA %d and age %d is Unknown\n", temp.amka, temp.age);
            }
        }
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

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
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
        if (Item.amka < (LocPtr->Data.amka))
            LocPtr = LocPtr ->LChild;
        else if (Item.amka > (LocPtr ->Data.amka))
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.amka);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.amka < Parent ->Data.amka)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
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
        if (KeyValue.amka < (*LocPtr)->Data.amka)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
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
        if (KeyValue.amka < (*LocPtr)->Data.amka) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
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
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue.amka);
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
                n->Data = nNext->Data;
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
        printf("(%d, %d, %d) ",Root->Data.amka,Root->Data.afm,Root->Data.age);
        InorderTraversal(Root->RChild);
    }
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
