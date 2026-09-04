#include <stdio.h>

// FINDING THE FIRST DAY OF A YEAR USING A GREGRIAN CALENDER FORMULA

int getFirstDayOfTheYear(int year)
{
    int day = (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
}
int main(int argc, char const *argv[])
{
    char *month[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < 12; i++)
    {
        printf("\n\n==============================================================\n\t\t\t%s\n==============================================================\n\n", month[i]);
        printf("\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
        int weekDay = 0, spaceCount = 0, year;

        printf("ENTER YOUR WANTED YEAR :  ");
        scanf("%d", &year);

        printf("======================= %d CALENDAR =======================");

        // CHECKING IF IT IS LEAP YEAR OR NOT

        if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))
        {
            daysInMonth[1] = 29;
        }

        // GET THE FIRST DAY OF THE YEAR
        weekDay = getFirstDayOfTheYear(year);

        for (spaceCount = 0; spaceCount <= weekDay; spaceCount++)
        {
            printf("\t\t\t\t\t");
        }

        int totalDays = daysInMonth[i];
        for (int d = 1; d <= totalDays; d++)
        {
            printf("\t%d", d);
            weekDay++;
            if (weekDay > 6)
            {
                weekDay = 0;
                printf("\n");
            }
        }
    }

    return 0;
}
