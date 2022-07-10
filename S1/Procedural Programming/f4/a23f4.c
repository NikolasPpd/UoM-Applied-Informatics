#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

bool Valid_Time (int hours, int minutes, int seconds);

int main() {

    int hours, minutes, seconds;

    hours = (printf("Dwse tis ores: "), GetInteger());
    minutes = (printf("Dwse ta lepta: "), GetInteger());
    seconds = (printf("Dwse ta defterolepta: "), GetInteger());

    if (Valid_Time(hours,minutes,seconds)){
        printf("WRA EGKYRH");
    }
    else {
        printf("WRA MH EGKYRH");
    }
    return 0;
}

bool Valid_Time (int hours, int minutes, int seconds){

    if (hours>=0 && hours<24){
        if (minutes>=0 && minutes<60){
            if (seconds>=0 && seconds<60){
                return TRUE;
            }
        }
    }
    return FALSE;
}
