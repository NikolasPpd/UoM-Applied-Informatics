#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long teli, varos;

    varos = (printf("Dwse to varos: "), GetLong());
    printf("Ta taxydromika telh einai %d", (varos > 0 && varos < 21) ? 250 : (varos > 20 && varos < 201) ? 600 : 4*varos);

    return 0;
}
