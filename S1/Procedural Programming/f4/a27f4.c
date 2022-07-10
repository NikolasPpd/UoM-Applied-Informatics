#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

long encode(long code);
bool check(long codeToCheck);

int main() {

    long lowerLim, upperLim, i;

    lowerLim = (printf("Lower Limit: "), GetLong());
    upperLim = (printf("Upper Limit: "), GetLong());

    for (i=lowerLim; i<=upperLim; i++){
        printf("Code: %ld Encoding: %ld isValid:%s\n",i,encode(i),(check(encode(i))?"yes":"no"));
    }
    return 0;
}

long encode(long code){

    code = (code*100) + ((98 - (code*100)%97)%97);
    return code;
}

bool check(long codeToCheck){

    return ((codeToCheck%97)==1?TRUE:FALSE);
}
