#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int weekWorkHours;
    long employeeID;
    double annualSalary, hourlyWage;

    printf("Dwse ton kwdiko: ");
    employeeID = GetLong();

    if (employeeID >= 1000){
        printf("Dwse ton ethsio mistho: ");
        annualSalary = GetReal();
        printf("H ebdomadiaia amoibh einai %g\n",annualSalary/52);
    }
    else {
        printf("Dwse tis wres ebdomadiaias ergasias: ");
        weekWorkHours = GetInteger();
        printf("Dwse thn amoibh ana wra: ");
        hourlyWage = GetReal();

        printf("H ebdomadiaia amoibh einai %g\n",(weekWorkHours < 41) ? weekWorkHours*hourlyWage : ((40*hourlyWage)+((weekWorkHours-40)*hourlyWage*1.5)));
    }
    return 0;
}
