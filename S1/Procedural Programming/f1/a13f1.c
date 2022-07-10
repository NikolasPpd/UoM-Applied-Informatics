#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    double gradeA, gradeB, gradeC, MO;

    printf("Dose vathmo A triminou: ");
    gradeA = GetReal();
    printf("Dose vathmo B triminou: ");
    gradeB = GetReal();
    printf("Dose vathmo C triminou: ");
    gradeC = GetReal();

    MO = (gradeA + gradeB + gradeC) / 3;
    printf("O mesos oros tou mathiti einai: %.1f", MO);

    return 0;
}
