#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define LIMITATION1 20
#define LIMITATION2 4

int algorithm (char string1[], char string2[])
{
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int result = 0;
    for (int elementNumber1 = 0; elementNumber1 < length1; ++elementNumber1)
    {
        int counter = 0;
        for (int elementNumber2 = 0; elementNumber2 < length2; ++elementNumber2)
        {
            if (string1[elementNumber1 + elementNumber2] == string2[elementNumber2])
            {
                ++counter;
            }
            else
            {
                break;
            }
            if (counter == length2 - 1)
            {
                ++result;
                break;
            }
        }
    }
    return result;
}

int random()
{
    char alphabets[] = { '1','2','3','4','5','6','7','8','9','0' };
    srand(time(NULL));
    char string1[20];
    char string2[4];
    int counter1 = 0;
    int counter2 = 0;
    while (counter1 < 20)
    {
        int symbol = rand() % 10;
        string1[counter1] = alphabets[symbol];
        ++counter1;
    }
    while (counter2 < 4)
    {
        int symbol = rand() % 10;
        string2[counter2] = alphabets[symbol];
        ++counter2;
    }
    int result = algorithm(string1, string2);
    if (result)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{    
    int test = random();
    if (test == 1)
    {
        char string1[100];
        char string2[100];
        printf("Enter first string ");
        fgets(string1, 99, stdin);
        printf("Enter second string ");
        fgets(string2, 99, stdin);
        int result = algorithm(string1, string2);
        printf("Number of occurrences %d", result);
    }
    else
    {
        printf("Error");
    }
}