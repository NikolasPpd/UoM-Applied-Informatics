#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long hourlyWage;
    double posostoKratiseon, akatharistesApodoxes, kratiseis, katharesApodoxes;
    int workHours;

    printf("Dwse ton arithmo twn wrwn: ");
    workHours = GetInteger();
    printf("Dwse thn wriaia antimisthia: ");
    hourlyWage = GetLong();
    printf("Dwse to pososto twn krathsewn: ");
    posostoKratiseon = GetReal();

    katharesApodoxes = workHours*hourlyWage;
    kratiseis = katharesApodoxes*posostoKratiseon;
    akatharistesApodoxes = katharesApodoxes + kratiseis;

    printf("Oi akatharistes apodoxes einai %g\n", akatharistesApodoxes);
    printf("Oi kratiseis einai %g\n", kratiseis);
    printf("Oi kathares apodoxes einai %g\n", katharesApodoxes);

    return 0;

}
