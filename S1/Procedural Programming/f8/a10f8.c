#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define ENTRIES 100

typedef struct
{
    char name[60];
    int start;
    int duration;
} WPack;

int ReadWorkpackages(WPack packages[]);
WPack FindFirstWp(int _totalPackages, WPack packages[]);
int FindMakespan(int _totalPackages, WPack packages[]);

int main()
{
    int totalPackages;
    int totalDuration;
    WPack packages[ENTRIES];
    WPack firstWP;

    totalPackages = ReadWorkpackages(packages);
    firstWP = FindFirstWp(totalPackages, packages);
    totalDuration = FindMakespan(totalPackages, packages);

    printf("FIRST WP: %s start: %d duration: %d\n", firstWP.name, firstWP.start, firstWP.duration);
    printf("Total duration = %d\n", totalDuration);

    return 0;
}

int ReadWorkpackages(WPack packages[])
{
    int _totalPackages;
    printf("Total work packages: ");
    _totalPackages = GetInteger();

    for (int i=0; i<_totalPackages; i++)
    {
        printf("WP Name:");
        gets(packages[i].name);
        printf("WP Start Month:");
        packages[i].start = GetInteger();
        printf("WP Duration:");
        packages[i].duration = GetInteger();
    }

    return _totalPackages;
}

WPack FindFirstWp(int _totalPackages, WPack packages[])
{
    int i, first=0;
    WPack firstPack;

    firstPack = packages[0];

    for (i=1; i<_totalPackages; i++)
    {
        if (packages[i].start < firstPack.start)
        {
            firstPack = packages[i];
        }
    }

    return firstPack;
}

int FindMakespan(int _totalPackages, WPack packages[])
{
    int i, makespan=0;

    for (i=0; i<_totalPackages; i++)
    {
        if (packages[i].start + packages[i].duration > makespan)
        {
            makespan = packages[i].start + packages[i].duration;
        }
    }

    return makespan;
}
