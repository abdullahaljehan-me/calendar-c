#include <stdio.h>
#include <stdbool.h>

// Function to check if a year is a leap year
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a given month and year
int getDaysInMonth(int month, int year)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // February gets 29 days in a leap year
    if (month == 1 && isLeapYear(year))
    {
        return 29;
    }
    return daysInMonth[month];
}

// Function to find the first day of the year (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
int getFirstDayOfYear(int year)
{
    int totalDays = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    return totalDays % 7;
}

int main()
{
    const char *months[] = {
        "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
        "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

    int year;

    // Professional UI Header
    printf("=============================================================\n");
    printf("                  CALENDAR APPLICATION                       \n");
    printf("=============================================================\n\n");

    printf("Enter the year: ");
    if (scanf("%d", &year) != 1 || year < 1)
    {
        printf("Invalid year entered. Please run the program again.\n");
        return 1;
    }

    printf("\n=================== %d CALENDAR ===================\n", year);

    // Get the starting weekday for January 1st of the given year
    int currentWeekDay = getFirstDayOfYear(year);

    for (int i = 0; i < 12; i++)
    {
        printf("\n    %s\n", months[i]);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");
        printf(" --- --- --- --- --- --- ---\n");

        int days = getDaysInMonth(i, year);

        // Print leading spaces for the first week
        for (int space = 0; space < currentWeekDay; space++)
        {
            printf("    "); // 4 spaces per empty day column
        }

        // Print the days of the month
        for (int d = 1; d <= days; d++)
        {
            printf("%3d ", d); // Fixed-width formatting for perfect alignment
            currentWeekDay++;

            // If it's Saturday, wrap to the next line
            if (currentWeekDay == 7)
            {
                printf("\n");
                currentWeekDay = 0;
            }
        }

        // If the month didn't end exactly on a Saturday, print a final newline
        if (currentWeekDay != 0)
        {
            printf("\n");
        }
    }

    printf("\n=============================================================\n");
    return 0;
}
