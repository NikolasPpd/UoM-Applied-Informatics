#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int katigoriaTim, pagio;
    long endeixh, oldEndeixh, katanalosiRev, axiaRev;
    double FPA, synolikoPoso;

    printf("Dwse ton kwdiko kathgorias timologiou: ");
    katigoriaTim = GetInteger();
    printf("Dwse thn parousa endeixh toy metrhth: ");
    endeixh = GetLong();
    printf("Dwse thn prohgoumenh endeixh toy metrhth: ");
    oldEndeixh = GetLong();

//Ypologismos katanalosis revmatos (monades)
    katanalosiRev = endeixh - oldEndeixh;

//Ypologismos axias revmatos (cent)
    if (katanalosiRev > 200){
        axiaRev = 2400;
        if (katanalosiRev > 500){
            axiaRev += 4500;
            if (katanalosiRev > 1500 && katanalosiRev < 10001){
                axiaRev += 20000;
                axiaRev += (katanalosiRev-1500)*30;
            }
            else {
                axiaRev += (katanalosiRev-500)*20;
            }
        }
        else {
            axiaRev += (katanalosiRev-200)*15;
        }
    }
    else {
        axiaRev = katanalosiRev*12;
    }

//Ypologismos pagiou
    pagio = (katigoriaTim == 3 ? 100 : 20);

//Ypologismos FPA
    FPA = (axiaRev + pagio*100)*0.0018;

//Ypologismos synolikou posou (euro)
    synolikoPoso = ((double)axiaRev)/100 + pagio + FPA;

    printf("Katanalwsh reymatos se monades: %d\n", katanalosiRev);
    printf("Axia reumatos (cent): %d\n", axiaRev);
    printf("Pagio (eyro): %d\n", pagio);
    printf("FPA (euro): %g\n", FPA);
    printf("Synoliko poso plhrwmhs (euro): %g\n", synolikoPoso);

    return 0;
}
