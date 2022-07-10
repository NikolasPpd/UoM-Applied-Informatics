/*
    Author: Nikolas Papadopoulos
*/

#include <stdio.h>

#define FRIENDS 13
#define MAX_NAME_LENGTH 11

void fillIntArray(int SIZE, int arr[], int NUM);
void sequenceFill(int SIZE, int arr[], int start, int excludedPos[]);
void comboLoop(int SIZE, int arr[], int groupSize, int nameRows, int nameCols, char names[nameRows][nameCols], int disSize, int disMatrix[disSize][disSize]);
void calculateCombos(int arr[], int currCombo[], int start, int end, int index, int groupSize, int nameRows, int nameCols, char names[nameRows][nameCols],
                     int disSize, int disMatrix[disSize][disSize]);
void maxFriendsLoop(int SIZE, int arr[], int groupSize, int disSize, int disMatrix[disSize][disSize], int *validCombSize);
void comboExists(int arr[], int currCombo[], int start, int end, int index, int groupSize, int disSize, int disMatrix[disSize][disSize], int *validCombSize);

int main()
{
    int dislikeMatrix[FRIENDS][FRIENDS] = {{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // Nikos
                                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // Lydia
                                           {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // Giannis
                                           {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},  // Akis
                                           {0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0},  // Manos
                                           {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},  // Eva
                                           {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},  // Alex
                                           {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0},  // Maria
                                           {0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0},  // Eleni
                                           {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},  // Petros
                                           {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},  // Anna
                                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},  // Dimitris
                                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; // Zoi

    char names[FRIENDS][MAX_NAME_LENGTH] = {
        "Nikos",
        "Lydia",
        "Giannis",
        "Akis",
        "Manos",
        "Eva",
        "Alexandros",
        "Maria",
        "Eleni",
        "Petros",
        "Anna",
        "Dimitris",
        "Zoi"};

    // Variable declaration
    int approxFriends = 1;
    int maxFriends;
    int zeroEdgesPos[FRIENDS];
    fillIntArray(FRIENDS, zeroEdgesPos, 0);
    int zeroEdgesPosTemp[FRIENDS];
    fillIntArray(FRIENDS, zeroEdgesPosTemp, 0);
    int edgeCount[FRIENDS];
    int friendRemoved[FRIENDS];
    fillIntArray(FRIENDS, friendRemoved, 0);
    int mostEdges, mostEdgesPos;
    int allZero;
    int i, j;
    int zeroEdges = 0;
    int validCombSize;

    // Calculate initial number of friends with 0 edges
    for (i = 0; i < FRIENDS; i++) // rows
    {
        allZero = 1;
        for (j = 0; j < FRIENDS; j++) // cols
        {
            if (dislikeMatrix[i][j] != 0)
            {
                allZero = 0;
                break;
            }
        }
        if (allZero)
        {
            zeroEdges++;
            zeroEdgesPos[i] = 1;
            zeroEdgesPosTemp[i] = 1;
        }
    }

    // Calculate the maximum number of friends Stathis can invite to his party (friends with 0 edges are excluded to avoid redundant iterations)
    if (zeroEdges == FRIENDS)
    {
        maxFriends = FRIENDS;
    }
    else
    {
        if (FRIENDS > 8) // Optimization to reduce redundant iterations
        {
            approxFriends = 0;
            do
            {
                fillIntArray(FRIENDS, edgeCount, 0);
                mostEdges = mostEdgesPos = 0;
                allZero = 1;
                for (i = 0; i < FRIENDS; i++) // rows
                {
                    if (friendRemoved[i] || zeroEdgesPosTemp[i])
                        continue;                 // Skips row if the current person is removed from the list or has 0 edges left
                    for (j = 0; j < FRIENDS; j++) // cols
                    {
                        if (friendRemoved[j] || zeroEdgesPosTemp[i])
                            continue;                        // Skips col if the current person is removed from the list or has 0 edges left
                        edgeCount[i] += dislikeMatrix[i][j]; // Calculates how many people a person dislikes
                    }
                    if (edgeCount[i] > mostEdges)
                    {
                        mostEdges = edgeCount[i];
                        mostEdgesPos = i;
                        allZero = 0;
                    } // Decides which row and col (which person) are going to be removed next
                    else if (edgeCount[i] == 0)
                    {
                        zeroEdgesPosTemp[i] = 1;
                    }
                } // Current round's edges calculated
                if (!allZero)
                {
                    friendRemoved[mostEdgesPos] = 1; // Removes the person with the most edges
                }
            } while (!allZero); // After exiting this loop the remaining people don't hate each other

            // Calculate an approximate number of friends Stathis can invite to his party
            for (i = 0; i < FRIENDS; i++)
            {
                if (zeroEdgesPosTemp[i])
                {
                    approxFriends++;
                }
            }
        }
        else
        {
            approxFriends = 1;
        }

        // Create an array that contains all the IDs of friends that don't initially have 0 edges
        int nonZeroIDs[FRIENDS - zeroEdges];
        sequenceFill(FRIENDS - zeroEdges, nonZeroIDs, 1, zeroEdgesPos);
        maxFriends = approxFriends;

        for (i = approxFriends - zeroEdges + 1; i <= FRIENDS - zeroEdges; i++)
        {
            validCombSize = 0;
            maxFriendsLoop(FRIENDS - zeroEdges, nonZeroIDs, i, FRIENDS, dislikeMatrix, &validCombSize);

            if (validCombSize)
            {
                maxFriends++;
            }
            else
            {
                break;
            }
        }
    }

    // Create an array that contains all the IDs
    // and reset the zeroEdgesPos array to 0
    int allIDs[FRIENDS];
    fillIntArray(FRIENDS, zeroEdgesPos, 0);
    sequenceFill(FRIENDS, allIDs, 1, zeroEdgesPos);

    // Print the results
    printf("The maximum number of friends Stathis can invite to his party is %d.\n", maxFriends);
    printf("All the possible combinations of %d friends he can invite to his party are the following:\n\n", maxFriends);
    comboLoop(FRIENDS, allIDs, maxFriends, FRIENDS, MAX_NAME_LENGTH, names, FRIENDS, dislikeMatrix);

    return 0;
}

void fillIntArray(int SIZE, int arr[], int NUM)
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = NUM;
    }
}

void sequenceFill(int SIZE, int arr[], int start, int excludedPos[])
{
    int counter = start;
    for (int i = 0; i < SIZE; i++)
    {
        // Skip excluded IDs
        while (excludedPos[counter - 1])
        {
            counter++;
        }
        arr[i] = counter;
        counter++;
    }
}

void comboLoop(int SIZE, int arr[], int groupSize, int nameRows, int nameCols, char names[nameRows][nameCols], int disSize, int disMatrix[disSize][disSize])
{
    int temp[groupSize];
    calculateCombos(arr, temp, 0, SIZE - 1, 0, groupSize, nameRows, nameCols, names, disSize, disMatrix);
}

void calculateCombos(int arr[], int currCombo[], int start, int end, int index, int groupSize, int nameRows, int nameCols, char names[nameRows][nameCols],
                     int disSize, int disMatrix[disSize][disSize])
{
    if (index == groupSize)
    {
        int allowedComb = 1;
        int j, k;

        // Check if current combination is allowed based on the dislikeMatrix
        for (j = 0; j < groupSize - 1; j++)
        {
            if (allowedComb)
            {
                for (k = j + 1; k < groupSize; k++)
                {
                    if (disMatrix[currCombo[j] - 1][currCombo[k] - 1]) // If true the 2 friends being tested dislike each other
                    {
                        allowedComb = 0;
                    }
                }
            }
        }

        // Print the list of names that correspond to the current combination
        if (allowedComb)
        {
            for (j = 0; j < groupSize; j++)
            {
                printf("%2d) %s\n", j + 1, names[currCombo[j] - 1]);
            }
            printf("\n");
        }
        return;
    }

    // end-i-1 : Number of available elements in arr[] that can be used to create a combination
    // groupSize-index : Number of available cells in currCombo[]. That is the combo we are currently creating
    for (int i = start; i <= end && end - i + 1 >= groupSize - index; i++)
    {
        currCombo[index] = arr[i];
        calculateCombos(arr, currCombo, i + 1, end, index + 1, groupSize, nameRows, nameCols, names, disSize, disMatrix);
    }
}

void maxFriendsLoop(int SIZE, int arr[], int groupSize, int disSize, int disMatrix[disSize][disSize], int *validCombSize)
{
    int temp[groupSize];
    comboExists(arr, temp, 0, SIZE - 1, 0, groupSize, disSize, disMatrix, validCombSize);
}

void comboExists(int arr[], int currCombo[], int start, int end, int index, int groupSize, int disSize, int disMatrix[disSize][disSize], int *validCombSize)
{
    if (index == groupSize)
    {
        int allowedComb = 1;
        int j, k;

        // Check if current combination is allowed based on the dislikeMatrix
        for (j = 0; j < groupSize - 1; j++)
        {
            if (allowedComb)
            {
                for (k = j + 1; k < groupSize; k++)
                {
                    if (disMatrix[currCombo[j] - 1][currCombo[k] - 1]) // If true the 2 friends being tested dislike each other
                    {
                        allowedComb = 0;
                    }
                }
            }
        }

        // If an allowed combination is found the function "returns" 1
        if (allowedComb)
        {
            *validCombSize = 1;
        }
        return;
    }

    // end-i+1 : Number of available elements in arr[] that can be used to create a combination
    // groupSize-index : Number of available cells in currCombo[]. That is the combo we are currently creating
    for (int i = start; i <= end && end - i + 1 >= groupSize - index; i++)
    {
        currCombo[index] = arr[i];
        if (!(*validCombSize))
        {
            comboExists(arr, currCombo, i + 1, end, index + 1, groupSize, disSize, disMatrix, validCombSize);
        }
        else
        {
            return;
        }
    }
}
