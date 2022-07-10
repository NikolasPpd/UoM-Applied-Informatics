#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 1001          //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean isFibonacci(int n, typos_synolou synolo);
void createFibonacciSet(int threshold, typos_synolou synolo);
void displaySet(int max, typos_synolou synolo);

int main()
{
    int max;
    int number;
    typos_synolou fibSeq;

    do
    {
        printf("Dwse to megistoarithmo. ");
        scanf("%d", &max);
    } while(!(max>=2 && max<=1000));

    createFibonacciSet(max, fibSeq);
    displaySet(max, fibSeq);

    while(1)
    {
        printf("Enter a number to check: ");
        scanf("%d", &number);
        if(number<0) break;
        (isFibonacci(number, fibSeq)? printf("Fibonacci!\n"): printf("Not Fibonacci...\n"));
    }

    return 0;
}

boolean isFibonacci(int n, typos_synolou synolo)
{
    return Melos(n, synolo);
}

void createFibonacciSet(int threshold, typos_synolou synolo)
{
    Dimiourgia(synolo);

    int term1 = 0, term2 = 1, nextTerm = 0;

    Eisagogi(0, synolo);
    Eisagogi(1, synolo);

    nextTerm = term1 + term2;

    while (nextTerm <= threshold) {
        Eisagogi(nextTerm, synolo);
        term1 = term2;
        term2 = nextTerm;
        nextTerm = term1 + term2;
    }
}


void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}


boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}

void displaySet(int max, typos_synolou synolo)
{
	stoixeio_synolou i;

	for (i=0; i<=max; i++)
	{
		if(Melos(i, synolo))
        {
            printf(" %d",i);
        }
	}
	printf("\n");
}
