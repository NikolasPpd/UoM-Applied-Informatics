#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define megisto_plithos 201          //Μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean isPrime(int n);
void createPrimeSet(int first, int last, typos_synolou synolo);
void displaySet(int first, int last, typos_synolou synolo);

int main()
{
    typos_synolou primeSet;
    int first, last;

    do
    {
        printf("First number [2-199]: ");
        scanf("%d", &first);
    } while (!(first>=2 && first<=199));

    do
    {
        printf("Last number [%d-200]: ", first+1);
        scanf("%d", &last);
    } while (!(last>first && last<=200));

    createPrimeSet(first, last, primeSet);
    displaySet(first, last, primeSet);

    return 0;
}

boolean isPrime(int n)
{
/* Λειτουργία: Ελέγχει αν ο αριθμός n είναι πρώτος αριθμός
   Επιστρέφει: TRUE αν είναι πρώτος αριθμός ή FALSE αν δεν είναι πρώτος αριθμός
*/

    int j;
    int sq;

    if (n<2 || (n%2==0 && n!=2))
    {
        return FALSE;
    }

    sq = sqrt(n);

    for (j=3; j<=sq; j+=2)
        if (n%j==0)
        {
            return FALSE;
        }
    return TRUE;
}

void createPrimeSet(int first, int last, typos_synolou synolo)
{
    int i;
    int start;

    //Δημιουργία συνόλου
    Dimiourgia(synolo);

    //Έλεγχος πρώτου στοιχείου
    if(first==2)
    {
        Eisagogi(2, synolo);
        start = 3;
    }
    else if(first%2==0)
    {
        start = first + 1;
    }
    else
    {
        start = first;
    }

    //Εύρεση πρώτων αριθμών
    for(i=start; i<=last; i+=2)
    {
        if(isPrime(i))
        {
            Eisagogi(i, synolo);
        }
    }

}

void displaySet(int first, int last, typos_synolou synolo)
{
	stoixeio_synolou i;

	for (i=first; i<=last; i++)
	{
		if(Melos(i, synolo))
        {
            printf(" %d",i);
        }
	}
	printf("\n");
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
