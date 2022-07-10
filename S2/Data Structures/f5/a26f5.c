#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILE1 "foitites.dat"
#define NAME_LENGTH 21

typedef struct{
    int am;
    int line;
} BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

typedef struct{
        int am, year;
        char onoma[NAME_LENGTH], eponymo[NAME_LENGTH];
        char fylo;
        float vathmos;
}karkantela;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);
void printStudentsWithGrade(float theGrade);

int main(){
    BinTreePointer Root1;
    int nodeCount;
    BinTreeElementType student;
    BinTreePointer LocPtr;
    boolean Found;

    FILE *fp1;
    int nscan;
    karkantela temp;
    char termch;
    float grade;

    CreateBST(&Root1);

    //1
    printf("Q1. Build BST from a file\n");
    nodeCount = BuildBST(&Root1);

    //2
    printf("Q2. Print size and BST\n");
    printf("Size=%d\n", nodeCount);
    printf("Nodes of BST\n");
    RecBSTInorder(Root1);
    printf("\n");

    //3
    printf("Q3. Write new students, update file and BST\n");
    writeNewStudents(&Root1,&nodeCount);

    //4
    printf("Q4. Print size and BST\n");
    printf("Size=%d\n", nodeCount);
    printf("Nodes of BST\n");
    RecBSTInorder(Root1);
    printf("\n");

    //5
    printf("Q5. Search for a student\n");
    printf("Give student's code? ");
    scanf("%d", &student.am);
    RecBSTSearch(Root1, student, &Found, &LocPtr);

    if(Found){
        fp1 = fopen(FILE1, "r");

        while(TRUE){
            nscan = fscanf(fp1, "%d,%21[^,],%21[^,],%c,%d,%f%c", &temp.am, temp.onoma, temp.eponymo, &temp.fylo, &temp.year, &temp.vathmos, &termch);
            if(nscan == EOF){
                break;
            }
            if(temp.am == student.am){
                printf("%d, %s, %s, %c, %d, %.1f\n", temp.am, temp.eponymo, temp.onoma, temp.fylo, temp.year, temp.vathmos);
                break;
            }
        }
        fclose(fp1);
    }
    else{
        printf("TO STOIXEIO DEN YPARXEI\n");
    }
    printf("\n");

    //6
    printf("Q6. Print size and BST\n");
    printf("Size=%d\n", nodeCount);
    printf("Nodes of BST\n");
    RecBSTInorder(Root1);
    printf("\n");

    //7
    printf("Q7. Print students with grades >= given grade\n");
    printf("Give the grade: ");
    scanf("%f",&grade);
    printStudentsWithGrade(grade);

    return 0;
}


void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.am < (*Root) ->Data.am)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.am > (*Root) ->Data.am)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.am < Root->Data.am)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.am > Root->Data.am)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ΑΔΕΙΟ ΔΕΝΔΡΟ ΤΟ KeyValue ΔΕ ΘΑ ΒΡΕΘΕΙ *)
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
         //* αναζήτησε αναδρομικά τον κόμβο που περιέχει την τιμή KeyValue και διάγραψέ τον
          if (KeyValue.am < (*Root)->Data.am)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΔΡΟ *
          else
            if (KeyValue.am > (*Root)->Data.am)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ΔΕΞΙ  ΥΠΟΔΕΝΔΡΟ *
            else                                       //* TO KeyValue ΒΡΕΘΗΚΕ ΔΙΑΓΡΑΦΗ ΤΟΥ ΚΟΜΒΟΥ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ΔΕΝ ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ, ΑΛΛΑ ΟΧΙ ΔΕΞΙ *)
                        free(TempPtr);
                   }
                   else                               //* ΕΧΕΙ 2 ΠΑΙΔΙΑ *)
                   {
                        //* ΕΥΡΕΣΗ ΤΟΥ INORDER ΑΠΟΓΟΝΟΥ ΤΟΥ *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ΜΕΤΑΚΙΝΗΣΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΤΗς ΡΙΖΑΣ ΤΟΥ ΥΠΟΔΕΝΔΡΟΥ
                        ΠΟΥ ΕΞΕΤΑΖΕΤΑΙ ΚΑΙ ΔΙΑΓΡΑΦΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΚΟΜΒΟΥ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("(%d, %d), ", Root->Data.am, Root->Data.line);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί προδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        printf("(%d, %d), ", Root->Data.am, Root->Data.line);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί μεταδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("(%d, %d), ", Root->Data.am, Root->Data.line);
    }
   // printf("U");
}

int BuildBST(BinTreePointer *Root)
{
    int nscan, i=0;
    char termch;
    FILE *fp1;
    BinTreeElementType item;
    karkantela temp;

    fp1 = fopen(FILE1, "r");


    while(TRUE){
        nscan = fscanf(fp1, "%d,%21[^,],%21[^,],%c,%d,%f%c", &temp.am, temp.onoma, temp.eponymo, &temp.fylo, &temp.year, &temp.vathmos, &termch);
        if(nscan == EOF){
            break;
        }
        item.am = temp.am;
        item.line = i;
        RecBSTInsert(Root, item);
        i++;
    }
    fclose(fp1);
    return i;
}

void writeNewStudents(BinTreePointer *Root, int *size)
{
    FILE *fp1;
    karkantela temp;
    fp1 = fopen(FILE1,"a");
    BinTreeElementType temp2;
    BinTreePointer LocPtr;
    boolean found;
    char checker;
    do{
        printf("Give student's AM? ");
        scanf("%d",&temp.am);
        temp2.am=temp.am;
        RecBSTSearch(*Root, temp2, &found, &LocPtr);
        if(!found){
            printf("Give student surname? ");
            scanf("%s",temp.eponymo);
            getchar();
            printf("Give student name? ");
            scanf("%s",temp.onoma);
            getchar();
            printf("Give student sex F/M? ");
            scanf("%c",&temp.fylo);
            getchar();
            printf("Give student's registration year? ");
            scanf("%d",&temp.year);
            printf("Give student's grade? ");
            scanf("%f",&temp.vathmos);
            temp2.line=*size;
            RecBSTInsert(Root,temp2);
            (*size)++;
            fprintf(fp1,"%d,%s,%s,%c,%d,%.1f\n", temp.am, temp.onoma, temp.eponymo, temp.fylo, temp.year, temp.vathmos);
        }
        else{
            printf("Code already in BST\n");
        }
        printf("Size=%d\n",*size);
        printf("\nContinue Y/N: ");
        scanf(" %c",&checker);
        while(tolower(checker)!='y' && tolower(checker)!='n'){
            printf("Invalid character. Try again: ");
            scanf(" %c",&checker);
        }

    } while(tolower(checker)=='y');

    fclose(fp1);
}

void printStudentsWithGrade(float theGrade)
{

    FILE *fp1;
    int nscan;
    karkantela temp;
    fp1 = fopen(FILE1,"r");
    char termch;
        while(TRUE){
            nscan = fscanf(fp1, "%d,%21[^,],%21[^,],%c,%d,%f%c", &temp.am, temp.onoma, temp.eponymo, &temp.fylo, &temp.year, &temp.vathmos, &termch);
            if(nscan == EOF){
                break;
            }
            if(temp.vathmos>=theGrade){
                printf("%d, %s, %s, %c, %d, %.1f\n", temp.am, temp.onoma, temp.eponymo, temp.fylo, temp.year, temp.vathmos);
            }
        }
        fclose(fp1);
}
