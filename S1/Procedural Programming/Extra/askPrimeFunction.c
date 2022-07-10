#include <stdio.h>
#include <math.h>


char isPrime(int a)
{
    int j;
    int sq;

   // printf ("Entering isPrime\n");

    if (a<2 || (a%2==0 && a!=2))
    {
     //   printf ("Leaving isPrime1\n");
        return 0;
    }

    sq = sqrt(a);

    for (j=3; j<=sq; j+=2)
        if (a%j==0)
        {
       //     printf ("Leaving isPrime2\n");
            return 0;
        }

    //printf ("Leaving isPrime3\n");
    return 1;
}



int main() 
{
    int k,i,j;
    char prime=0;
    scanf("%d", &k);

    if (k>=2)
        printf ("2 is prime\n");

    for (i=3; i<=k; i+=2)
    {
        // AN TO Ι EINAI ΠΡΩΤΟΣ
        if (isPrime(i)==1)
            printf ("%d is prime\n",i);
        else 
            printf ("%d is not prime\n",i);

    }
    return 0;
}