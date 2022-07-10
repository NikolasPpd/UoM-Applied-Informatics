#include <stdio.h>

#define QueueLimit 4  //το όριο μεγέθους της ουράς

typedef struct {
    int arrivalTime;
    int stayDuration;
    int startTime;
    int endTime;
} customerStr;

typedef customerStr QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void ReadData(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);
void PrintInfo(char QName[], QueueType Queue);

int main()
{
    QueueType WaitingQ;
    QueueType ServiceQ;
    CreateQ(&WaitingQ);
    CreateQ(&ServiceQ);

    ReadData(&WaitingQ);
    PrintInfo("Waiting Queue", WaitingQ);
    ServiceQ = TimesInQueue(&WaitingQ);
    PrintInfo("Waiting Queue", WaitingQ);
    PrintInfo("Service Queue", ServiceQ);

    return 0;
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
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
	}
	else
		printf("Empty Queue");
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
	}
	else
		printf("Full Queue");
}

void ReadData(QueueType *Queue)
{
    QueueElementType temp;

    for(int i=0; i<QueueLimit-1; i++)
    {
        printf("Give: arrival time,stay time for client %d: ", i+1);
        scanf(" %d,%d", &temp.arrivalTime, &temp.stayDuration);
        temp.startTime = temp.endTime = -1;
        AddQ(Queue, temp);
    }
}

QueueType TimesInQueue(QueueType *Queue)
{
    QueueElementType tempCurr, tempPrev;
    QueueType tempQ;
    CreateQ(&tempQ);

    for(int i=0; i<QueueLimit-1; i++)
    {
        if(i==0) // 1st Client
        {
            RemoveQ(Queue, &tempCurr);
            tempPrev = tempCurr;
            tempCurr.startTime = tempCurr.arrivalTime;
        }
        else
        {
            RemoveQ(Queue, &tempCurr);
            tempCurr.startTime = tempPrev.endTime;
        }
        tempCurr.endTime = tempCurr.startTime + tempCurr.stayDuration;
        AddQ(&tempQ, tempCurr);
        tempPrev = tempCurr;
    }

    return tempQ;
}

void PrintInfo(char QName[], QueueType Queue)
{
    if(EmptyQ(Queue))
    {
        printf("\n%s is empty", QName);
    }
    else
    {
        QueueElementType temp;

        printf("\n%s", QName);
        printf("\nClient \t\tStart\tEnd\tArrival\tStay\n");
        //printf("\n%s %22s %6s %12s %5s\n", "Client", "Start", "End", "Arrival", "Stay");
        for(int i=0; i<QueueLimit-1; i++)
        {
            RemoveQ(&Queue, &temp);
            //printf("Client %-16d %-8d %-8d %-8d %-5d\n", i+1, temp.startTime, temp.endTime, temp.arrivalTime, temp.stayDuration);
            printf("Client %d \t%d\t%d\t%d\t%d\n", i+1, temp.startTime, temp.endTime, temp.arrivalTime, temp.stayDuration);
        }
    }
}
