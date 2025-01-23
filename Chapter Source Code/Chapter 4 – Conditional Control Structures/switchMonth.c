#include <stdio.h>

int main(int argc, char *argv[]) {
    int month;
    char monthStr[20], *s;

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    switch (month) {
        case 1:
            s = "January";
            break;
        case 2:
            s = "February";
            break;
        case 3:
            s = "March";
            break;
        case 4:
            s = "April";
            break;
        case 5:
            s = "May";
            break;
        case 6:
            s = "June";
            break;
        case 7:
            s = "July";
            break;
        case 8:
            s = "August";
            break;
        case 9:
            s = "September";
            break;
        case 10:
            s = "October";
            break;
        case 11:
            s = "November";
            break;
        case 12:
            s = "December";
            break;
        default:
            s = "AN UNKNOWN MONTH";
            break;
    }

    snprintf(monthStr, sizeof monthStr, "%s", s);
    printf("The month selected is %s\n", monthStr);
}
