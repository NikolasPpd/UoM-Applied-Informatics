#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"

#define MAX_NAME_LENGTH 31
#define MAX_FILE_NAME_LENGTH 31
#define MAX_COMMENT_LENGTH 69
#define M 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int truancies;
} studentT;

void readInput(FILE* infile, studentT students[], int *pApousies, int *pStudents);
void writeOutput(FILE* outfile, int size, studentT students[], int total);

int main()
{
    FILE* infile;
    FILE* outfile;

    char inputFile[MAX_FILE_NAME_LENGTH];
    char outputFile[MAX_FILE_NAME_LENGTH];
    int pApousies, pStudents;

    printf("Input file name: ");
    gets(inputFile);
    printf("Output file name: ");
    gets(outputFile);

    infile = fopen(inputFile, "r");
    if (infile == NULL)
    {
        printf("Cannot open input file %s\n", inputFile);
        exit(1);
    }

    outfile = fopen(outputFile, "w");
    if (outfile == NULL)
    {
        printf("There was an error creating the output file.\n");
        exit(1);
    }

    studentT students[M];

    readInput(infile, students, &pApousies, &pStudents);
    writeOutput(outfile, pApousies, students, pStudents);

    fclose(infile);
    fclose(outfile);
    return 0;
}

void readInput(FILE* infile, studentT students[], int *pApousies, int *pStudents)
{
    int nscan, truancies, line;
    char name[MAX_FILE_NAME_LENGTH], comments[MAX_COMMENT_LENGTH], termch;

    *pApousies = 0;
    *pStudents = 0;

    line = 0;
    while(TRUE)
    {
        nscan = fscanf(infile, "%30[^,], %d, %68[^\n]%c", name, &truancies, comments, &termch);
        if (nscan == EOF) break;
        line++;

        if (nscan != 4 || termch != '\n')
        {
            printf("Error in line %d. Program termination.\n", line);
            exit(1);
        }
        if (truancies > 100)
        {
            strcpy(students[*pApousies].name, name);
            students[*pApousies].truancies = truancies;
            (*pApousies)++;
        }
        (*pStudents)++;
    }
}

void writeOutput(FILE* outfile, int size, studentT students[], int total)
{
    int i;
    fprintf(outfile, "%-30s%-9s\n", "ONOMATEPWNYMO", "APOYSIES");

    for(i=0; i<39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    for(i=0; i<size; i++)
    {
        fprintf(outfile, "%-30s%9d\n", students[i].name, students[i].truancies);
    }

    for(i=0; i<39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    fprintf(outfile, "%-30s%9d\n", "SYNOLO MATHITWN:", total);
    fprintf(outfile, "%-30s%9d\n", "SYNOLO APONTWN:", size);
}
