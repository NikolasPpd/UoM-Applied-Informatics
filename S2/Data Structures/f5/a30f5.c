#include <stdio.h>

#define MaxElements 10          //το μέγιστο πλήθος των στοιχείων του σωρού
#define FILE1 "transactions.txt"

typedef float  HeapElementType;    //ο τύπος δεδομένων των στοιχείων του σωρού
typedef  struct {
     HeapElementType key;
    // int Data;                // οποισδήποτε τύπος για τα παρελκόμενα δεδομένα κάθε κόμβου
} HeapNode;


typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMinHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMinHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMinHeap(HeapType *Heap, HeapNode *Item);
void PrintHeap(HeapType Heap);

int main()
{
  int fores,nscan;
  HeapType Heap;
  HeapNode temp;
  HeapNode deletedNum;
  char termChar;
  float tempNum;
  
  FILE *fp1;

  fp1 = fopen(FILE1,"r");

  printf("Give m:");
  scanf("%d",&fores);
  CreateMinHeap(&Heap);
  
  
  while(TRUE){
    nscan = fscanf(fp1, "%f%c", &tempNum, &termChar);

    if(nscan == EOF){
      break;
    }
    temp.key = tempNum;
    if(Heap.Size < fores){
      InsertMinHeap(&Heap, temp);
    }
    else{
      if(temp.key > Heap.Element[1].key){
        DeleteMinHeap(&Heap,&deletedNum);
        InsertMinHeap(&Heap,temp);
      }
    }
  }

  PrintHeap(Heap);
  fclose(fp1);
  printf("\nTransactions\n");
  while(!EmptyHeap(Heap)){
    DeleteMinHeap(&Heap,&deletedNum);
    printf("%.2f ",deletedNum.key);
  }
  return 0;
}

void CreateMinHeap(HeapType *Heap)
/* Λειτουργία: Δημιουργεί ένα κενό σωρό.
   Επιστρέφει: Ένα κενό σωρό
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ελέγχει αν ο σωρός είναι κενός.
   Επιστρέφει: TRUE αν ο σωρός είναι κενός, FALSE διαφορετικά
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό.
   Λειτουργία: Ελέγχει αν ο σωρός είναι γεμάτος.
   Επιστρέφει: TRUE αν ο σωρός είναι γεμάτος, FALSE διαφορετικά
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
/*  Δέχεται:    Ένα σωρό Heap και ένα στοιχείο δεδομένου Item .
    Λειτουργία: Εισάγει το στοιχείο Item στο σωρό, αν ο σωρός δεν είναι γεμάτος.
    Επιστρέφει: Τον τροποποιημένο σωρό.
    Έξοδος:     Μήνυμα γεμάτου σωρού αν ο σωρός είναι γεμάτος
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key < Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMinHeap(HeapType *Heap, HeapNode *Item)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ανακτά και διαγράφει το μεγαλύτερο στοιχείο του σωρού.
   Επιστρέφει: Το μεγαλύτερο στοιχείο Item του σωρού και τον τροποποιημένο σωρό
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child<=(*Heap).Size && !done)
        {
            if (child<(*Heap).Size)
                if ((*Heap).Element[child].key > (*Heap).Element[child+1].key)
                    child++;
            if (last.key <= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}

void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Data Structure size =%d\n",Heap.Size);
    for (i=1; i<=Heap.Size;i++)
    {
      printf("%.2f ",Heap.Element[i].key);
    }       
}