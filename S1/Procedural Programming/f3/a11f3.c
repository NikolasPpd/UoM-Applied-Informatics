#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    //variable declaration
    int maxStars, i, even, spacesToFill, starsToFill, halfLines, allLines, printedLines;
    char star;

    //variable initialization
    star = '*';
    spacesToFill = printedLines = starsToFill = 0;
    maxStars = GetInteger();

    //check if stars number is odd or even
    if (maxStars%2 == 0){ //even stars
        even = TRUE;
        allLines = maxStars-1;
        starsToFill = 2;
        spacesToFill = maxStars/2 - 1;
    }
    else{ //odd stars
        even = FALSE;
        allLines = maxStars;
        starsToFill = 1;
        spacesToFill = maxStars/2;
    }

    halfLines = allLines/2 + 1; //halfLines include the max line

    while (printedLines<allLines){ //while TRUE the program is still on "print mode"
        if (printedLines<halfLines){ //while TRUE the program hasn't printed the max line and every previous line
            for (i=1; i<=spacesToFill; i++){ //printing the spaces needed before the stars of each line
                    printf(" ");
            }
            for (i=1; i<=starsToFill; i++){ //printing the stars of each line
                    printf("%c",star);
            }
            printf("\n");
            printedLines ++;
            if (printedLines == halfLines){
                starsToFill -=2;
                spacesToFill ++;
            }
            else {
                starsToFill += 2;
                spacesToFill --;
            }
        }
        else {
            for (i=1; i<=spacesToFill; i++){ //printing the spaces needed before the stars of each line
                printf(" ");
            }
            for (i=1; i<=starsToFill; i++){ //printing the stars of each line
                printf("%c",star);
            }
            printf("\n");
            starsToFill -= 2;
            spacesToFill ++;
            printedLines ++;
        }
    }

    printf("\nFin.");
    return 0;
}
