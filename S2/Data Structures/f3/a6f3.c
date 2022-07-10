#include <stdio.h>

#define QueueLimit 10  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	int Count;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main()
{
    QueueType Queue;
    QueueElementType temp;

    // a
    CreateQ(&Queue);

    for(int i=0; i<QueueLimit; i++)
    {
        AddQ(&Queue, i);
    }

    printf("---a---\n");
    printf("Queue: ");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);

    // b
    printf("---b---\n");
    AddQ(&Queue, 69);
    printf("Queue: ");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);

    // c
    printf("---c---\n");
    RemoveQ(&Queue, &temp);
    printf("Queue: ");
    TraverseQ(Queue);
    printf("Removed item=%d ", temp);
    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);

    // d
    printf("---d---\n");
    AddQ(&Queue, 25);
    printf("Queue: ");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);

    // e
    printf("---e---\n");
    AddQ(&Queue, 69);
    printf("Queue: ");
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);

    // f
    printf("---f---\n");
    while(!EmptyQ(Queue))
    {
        RemoveQ(&Queue, &temp);
        printf("Queue: ");
        TraverseQ(Queue);
        printf("Removed item=%d ", temp);
        printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);
    }

    return 0;
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return (Queue.Count == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue ->Count -= 1;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Count += 1;
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue) {
	int current;
	if(EmptyQ(Queue))
    {
        printf("Empty Queue\n");
    }
    else
    {
        current = Queue.Front;
        printf("%d ", Queue.Element[current]);
        current = (current + 1) % QueueLimit;
        while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
            current = (current + 1) % QueueLimit;
        }
        printf("\n");
    }
}
