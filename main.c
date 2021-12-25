#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void ex_1(char* Str)
{
    int FirstLit_1 = 0, FirstLit_2, LastLit_1 = -1, LastLit_2 = 1, i = 0, FirstWord_Len, LastWord_Len, Count, Len;
    char NStr;

    while (Str[i] == ' ')
    {
        i++;
        FirstLit_1++;
    }

    while (Str[i] != ' ')
    {
        i++;
        LastLit_1++;
    }

    while (Str[i] != '\0')
    {
        i++;
        LastLit_2++;
    }

    while (Str[i] != ' ')
        i--;

    FirstLit_2 = i + 1;

    Len = strlen(Str) - 1;

    FirstWord_Len = LastLit_1 - FirstLit_1 + 1;
    LastWord_Len = LastLit_2 - FirstLit_2 + 2;

    for (i = 0; i < FirstWord_Len / 2; i++)
    {
        NStr = Str[i + FirstLit_1];
        Str[i + FirstLit_1] = Str[LastLit_1 - i];
        Str[LastLit_1 - i] = NStr;
    }
    for (i = 0; i < LastWord_Len / 2; i++)
    {
        NStr = Str[i + FirstLit_2];
        Str[i + FirstLit_2] = Str[LastLit_2 - i];
        Str[LastLit_2 - i] = NStr;
    }
    for (i = 0; i < Len / 2 + 1; i++) 
    {
        NStr = Str[i];
        Str[i] = Str[Len - i];
        Str[Len - i] = NStr;
    }

    LastLit_1 = Len - LastLit_1 - 1;
    FirstLit_2 = Len - FirstLit_2 +1;
    Count = LastLit_1 - FirstLit_2 + 1;

    for (i = 0; i < Count / 2; i++) 
    {
        NStr = Str[i + FirstLit_2];
        Str[i + FirstLit_2] = Str[LastLit_1 - i];
        Str[LastLit_1 - i] = NStr;
    }
}

void ex_2()
{
    struct Ppls
    {
        char Surname[256];
        char Name[256];
        char SecondName[256];
        char Sex[256];
        char Job[256];
        int Day;
        int Month;
        int Year;
        int Age;
    };

    int N = 0;

    scanf_s("%d", &N);

    struct Ppls* Arr = (struct Ppls*)malloc(N * sizeof(struct Ppls));

    for (int i = 0; i < N; i++)
    {
        scanf_s("%s", Arr[i].Surname, 256);
        scanf_s("%s", Arr[i].Name, 256);
        scanf_s("%s", Arr[i].SecondName, 256);
        scanf_s("%s", Arr[i].Sex, 256);
        scanf_s("%s", Arr[i].Job, 256);
        scanf_s("%d", &Arr[i].Day);
        scanf_s("%d", &Arr[i].Month);
        scanf_s("%d", &Arr[i].Year);
        Arr[i].Age = 2021 - Arr[i].Year;  
    }
    for (int i = 0; i < N; i++)
    {
        if (strcmp(Arr[i].Job, "Engineer") == 0)
        {
            if (strcmp(Arr[i].Sex, "M") == 0)
            {
                if (Arr[i].Age >= 65)
                {
                    printf("%s %s %s, %s, %s, %d.%d.%d", Arr[i].Surname, \
                        Arr[i].Name, Arr[i].SecondName, Arr[i].Sex, Arr[i].Job, \
                        Arr[i].Day, Arr[i].Month, Arr[i].Year);
                }
            }
            else
            {
                if (Arr[i].Age >= 60)
                {
                    printf("%s %s %s, %s, %s, %d.%d.%d", Arr[i].Surname, \
                        Arr[i].Name, Arr[i].SecondName, Arr[i].Sex, Arr[i].Job, \
                        Arr[i].Day, Arr[i].Month, Arr[i].Year);
                }
            }
        }
    }
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char* str = malloc(sizeof(int));
	gets(str);
	ex_1(str);
	puts(str);
  
	ex_2();

	return 0;
}

  
