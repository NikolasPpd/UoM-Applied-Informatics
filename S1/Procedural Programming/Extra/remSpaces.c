#include <stdio.h>
#include <string.h>

int main()
{
    char originalText[10], blankText[10];
    int c = 0, d = 0, firstLetterFound = 0;

    printf("Enter some text\n");
    gets(originalText);

    while (originalText[c] != '\0'){
        if (originalText[c] != ' '){
            blankText[d] = originalText[c];
            //printf("No spaces found: %s\n", originalText);
            d++;
        }
        else if (originalText[c] == ' ' && originalText[c+1] != ' '){
            blankText[d] = originalText[c+1];
            d++;
            c++;
        }
        c++;
    }
    blankText[d] = '\0';

    printf("Original text after removing spaces in front: \n%s\n", blankText);

    return 0;
}
