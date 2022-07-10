#define __USE_MINGW_ANSI_STDIO 1

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define DIGITS 1000000000000000 //# of 0 = digits you want - 1

void validCC(long long ccNum);
void invalidCC(long long cNum);
long long GetLongLong(void);

int main() {

    int i,temp,digitSum=0;
    long long ccNum, ccNumTemp;
    long long ccDigits[16];

    printf("Insert card number:");
    ccNum = ccNumTemp = GetLongLong();

    if (!((ccNum/DIGITS) > 0 && (ccNum/DIGITS) < 10)){ //check if ccNum has 16 digits. There is no need to check if the first digit is 0 as CC Numbers that start with 0 are invalid.
        invalidCC(ccNum);
        return 0;
    }

    for (i=15;i>=0;i--){ //insert credit card digits into Array
        ccDigits[i] = ccNumTemp%10;
        ccNumTemp /= 10;
    }

    if (ccDigits[0] < 4 || ccDigits[0] > 7){ //check if ccNum starts with 4,5,6 or 7
        invalidCC(ccNum);
        return 0;
    }

    for (i=0;i<16;i+=2){ //duplicate odd cells and sum digits of two-digit numbers
        temp = ccDigits[i]*2;
        if (temp>9){
            temp = temp%10 + temp/10;
        }
        ccDigits[i] = temp;
    }
    for (i=0;i<16;i++){
        digitSum+= ccDigits[i];
    }
    if (!(digitSum%10)){
        validCC(ccNum);
    }
    else{
        invalidCC(ccNum);
    }
    return 0;
}

void validCC(long long ccNum){
    printf("%lld is VALID.",ccNum);
}

void invalidCC(long long ccNum){
    printf("%lld is invalid.",ccNum);
}

long long GetLongLong(void){
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}
