#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define PAGIO 120

int main() {

    int countryID;
    long varos, extraXreosi;
    double epivarinsi, taxTeli;

    //eisagogi timon xristi
    varos = (printf("Dwse to baros: "), GetLong());
    countryID = (printf("Dwse ton kwdiko ths xwras apostolhs (0, 1): "), GetInteger());

    //ypologismos extra xreosis
    if (varos > 20){
        extraXreosi = 300;
        if (varos > 100){
            extraXreosi += 1600;
            extraXreosi += (varos - 100)*25;
        }
        else {
            extraXreosi += (varos-20)*20;
        }
    }
    else {
        extraXreosi = varos*15;
    }
    //ypologismos epivarinsis
    epivarinsi = (PAGIO + extraXreosi)*(countryID == 0 ? 0.12 :0.15);

    //ypologismos taxydromikon telon
    taxTeli = PAGIO + extraXreosi + epivarinsi;

    //ektyposi timon
    printf("To baros einai %d\n", varos);
    printf("H epipleon xrewsh einai %d\n", extraXreosi);
    printf("H epibarunsh einai %g\n", epivarinsi);
    printf("Ta taxydromika telh einai %g\n", taxTeli);

    return 0;
}

