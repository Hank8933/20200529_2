#include <stdio.h>

struct date {
    int day, month, year;
    };

//a:
int day_of_year(struct date d)
{
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.year % 4 == 0){
        if (d.year % 100 == 0){
            if (d.year % 400 == 0) month_days[1] = 29;
        }
        else month_days[1] = 29;
    }

    for (int i = 0; i < d.month - 1; i++)
        d.day += month_days[i];

    return d.day;
}

//b:
int compare_dates(struct date d1, struct date d2)
{
    if (d1.year < d2.year) return -1;
    else if (d1.year > d2.year) return 1;
    else if (d1.month < d2.month) return -1;
    else if (d1.month > d2.month) return 1;
    else if (d1.day < d2.day) return -1;
    else if (d1.day > d2.day) return 1;
    else return 0;
}

int main()
{
    struct date d = {3, 3, 2000}, d2 = {1, 3, 2000};
    printf("%d %d", day_of_year(d), compare_dates(d2, d));

    return 0;
}
