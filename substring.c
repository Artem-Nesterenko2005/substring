#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define LIMITATION_LENGTH_STRING 100

int calculatingOccurrencesOfSubstrings(char mainString[], char subString[])
{
    int const lengthMainString = strlen(mainString);
    int const lengthSubString = strlen(subString);
    int numberOccurrences = 0;
    for (int elementNumber1 = 0; elementNumber1 < lengthMainString; ++elementNumber1)
    {
        int counter = 0;
        for (int elementNumber2 = 0; elementNumber2 < lengthSubString; ++elementNumber2)
        {
            if (mainString[elementNumber1 + elementNumber2] == subString[elementNumber2])
            {
                ++counter;
            }
            else
            {
                break;
            }
            if (counter == lengthSubString - 1)
            {
                ++numberOccurrences;
                break;
            }
        }
    }
    return numberOccurrences;
}
int testOfProgramm()
{
    char mainString[LIMITATION_LENGTH_STRING] = "123123\n";
    char subString[LIMITATION_LENGTH_STRING] = "123\n";
    int testResult = calculatingOccurrencesOfSubstrings(mainString, subString);
    return testResult;
}

int main()
{
    int test = testOfProgramm();
    if (!test)
    {
        printf("Test is error: the main string does not contain a substring");
        return 1;
    }
    char mainString[LIMITATION_LENGTH_STRING] ="";
    char subString[LIMITATION_LENGTH_STRING] = "";
    printf("Enter first string ");
    fgets(mainString, 99, stdin);
    printf("Enter second string ");
    fgets(subString, 99, stdin);
    int result = calculatingOccurrencesOfSubstrings(mainString, subString);
    printf("Number of occurrences %d", result);
}