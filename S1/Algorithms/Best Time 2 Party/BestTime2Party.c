/*
    Author: Nikolas Papadopoulos
*/

#include <stdio.h>

int main()
{

    int i, j, totalCeleb, currentCeleb, arrivalTime, departureTime, timeTableHour, maxCeleb = 0, arrPos, depPos, onlyOnePrefHour = 1;
    int time[6] = {18, 19, 20, 21, 22, 23};
    int prefHour[6] = {0, 0, 0, 0, 0, 0}; // Array storing whether an hour is preferable or not

    do
    {
        fflush(stdin);
        printf("How many celebrities will be attending the bazaar? [1-99]: ");
        scanf("%d", &totalCeleb);
    } while (totalCeleb < 1 || totalCeleb > 99);

    int timeTable[totalCeleb][6];       // Array counting how many celebrities there are in each hour
    char celebrityList[totalCeleb][21]; // list containing all the celebrity names entered by the user

    printf("\n+-------------------------------------------+\n");
    printf("|          Create Bazaar Timetable          |\n");
    printf("+-------------------------------------------+\n");
    printf("| For each celebrity attending the bazaar,  |\n");
    printf("| enter their name, arrival time [18-23],   |\n");
    printf("| and departure time [19-24].               |\n");
    printf("|                                           |\n");
    printf("| Maximum name length is 20 characters.     |\n");
    printf("+-------------------------------------------+\n\n");

    for (i = 0; i < totalCeleb; i++)
    {
        fflush(stdin);
        arrivalTime = departureTime = 0;
        printf("%2d.     Name: ", i + 1);
        scanf("%20[^\n]", celebrityList[i]);
        fflush(stdin); // flush scanf buffer (useful in case the user enters a celebrity name with more than 20 characters)

        do
        {
            fflush(stdin);
            printf("     Arrival: ");
            scanf("%d", &arrivalTime);
        } while (!((arrivalTime >= 18) && (arrivalTime <= 23)));
        do
        {
            fflush(stdin);
            printf("   Departure: ");
            scanf("%d", &departureTime);
        } while (!((departureTime > arrivalTime) && (departureTime <= 24)));

        arrPos = arrivalTime - 18;
        depPos = departureTime - 19;

        for (j = 0; j < 6; j++)
        {
            if ((j >= arrPos) && (j <= depPos))
            {
                timeTable[i][j] = 1;
            }
            else
            {
                timeTable[i][j] = 0;
            }
        }
    } // end for loop. Timetable & Celebrity List complete

    for (timeTableHour = 0; timeTableHour < 6; timeTableHour++)
    {
        currentCeleb = 0;
        for (i = 0; i < totalCeleb; i++)
        {
            if (timeTable[i][timeTableHour])
            {
                currentCeleb++;
            }
        }
        if (currentCeleb > maxCeleb)
        {
            maxCeleb = currentCeleb;
            for (i = 0; i < 6; i++)
            {
                prefHour[i] = 0;
            } // end for loop. Nullify prefHour array
            prefHour[timeTableHour] = 1;
        }
        else if (currentCeleb == maxCeleb)
        {
            prefHour[timeTableHour] = 1;
        }
    } // end for loop. Max Celebrities & Preferable Hours found

    printf("\nThe best time for Stathis to attend the bazaar is at ");
    for (i = 0; i < 6; i++)
    {
        if (prefHour[i])
        {
            if (onlyOnePrefHour)
            {
                printf("%d:00 so that he can get pictures with the following %d celebrit%s:\n\n", time[i], maxCeleb, (maxCeleb > 1 ? "ies" : "y"));
                onlyOnePrefHour = 0;
            }
            else
            {
                printf("Or at %d:00 so that he can get pictures with th%s %d celebrit%s:\n\n", time[i], (maxCeleb > 1 ? "ese" : "is"), maxCeleb, (maxCeleb > 1 ? "ies" : "y"));
            }
            for (j = 0; j < totalCeleb; j++)
            {
                if (timeTable[j][i])
                {
                    printf("- %s\n", celebrityList[j]);
                }
            }
            printf("\n");
        }
    } // end for loop. Preferable Hours and their corresponding Celebrities printed
    return 0;
}
