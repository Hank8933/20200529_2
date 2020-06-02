#include <stdio.h>

struct time {
    int hours, minutes, seconds;
    };

struct time split_time(long total_seconds)
{
    struct time t;
    t.seconds = total_seconds % 60;
    t.minutes = total_seconds / 60;
    t.hours = total_seconds / 360;
    return t;
}

int main()
{
    printf("%d", split_time(1000).minutes);
    return 0;
}
