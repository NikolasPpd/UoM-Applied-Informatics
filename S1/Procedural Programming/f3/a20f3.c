#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    //dilosi metavliton
    int age, ageMin, ageMax;

    //arxikopoiisi metavliton
    ageMin = ageMax = 0;

    //sygkrisi ilikion kai epilogi megaliteris kai mikroteris. eksodos an age=-1
    while (TRUE){
        age = (printf("Dwse ilikia: "), GetInteger());
        if (age==-1) break;
        if (ageMax==0){
            ageMin = ageMax = age;
        }
        if (age>ageMax){
            ageMax = age;
        }
        else if (age<ageMin){
            ageMin = age;
        }
    }

    printf("H megalyteri ilikia einai %d\n", ageMax);
    printf("H mikroteri ilikia einai %d\n", ageMin);

    return 0;
}
