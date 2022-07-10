#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

typedef struct
{
    int width;
    int height;
    int depth;
    int area;
    int volume;
} box;

box readData();
void calculateArea(box *myBox);
void calculateVolume(box *myBox);

int main()
{
    box myBox;

    myBox = readData();
    calculateArea(&myBox);
    calculateVolume(&myBox);

    printf("To emvadon tou koutiou einai %d cm2\n", myBox.area);
    printf("O ogos tou koutiou einai %d cm3\n", myBox.volume);

    return 0;
}

box readData()
{
    box currentBox;

    printf("Dose to mikos tou koutiou se cm: ");
    currentBox.width = GetInteger();
    printf("Dose to ypsos tou koutiou se cm: ");
    currentBox.height = GetInteger();
    printf("Dose to vathos tou koutiou se cm: ");
    currentBox.depth = GetInteger();

    return currentBox;
}

void calculateArea(box *myBox)
{
    myBox->area = ((myBox->height)*(myBox->width) + (myBox->height)*(myBox->depth) + (myBox->width)*(myBox->depth))*2;
}

void calculateVolume(box *myBox)
{
    myBox->volume = myBox->height * myBox->width * myBox->depth;
}
