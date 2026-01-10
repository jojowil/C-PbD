#include <stdio.h>

int main(void) {
    int month;
    char month_str[20], *s;

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    if (month == 1)
        s = "January";
    else if (month == 2)
        s = "February";
    else if (month == 3)
        s = "March";
    else if (month == 4)
        s = "April";
    else if (month == 5)
        s = "May";
    else if (month == 6)
        s = "June";
    else if (month == 7)
        s = "July";
    else if (month == 8)
        s = "August";
    else if (month == 9)
        s = "September";
    else if (month == 10)
        s = "October";
    else if (month == 11)
        s = "November";
    else if (month == 12)
        s = "December";
    else
        s = "AN UNKNOWN MONTH";

    snprintf(month_str, sizeof month_str, "%s", s);
    printf("The month selected is %s\n", month_str);
    return 0;
}
