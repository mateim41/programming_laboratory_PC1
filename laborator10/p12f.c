#include <stdio.h>
#include <stdlib.h>

#include "p12.h"

void afisare(Time t)
{
    printf("%02d:%02d:%02d", t.hour, t.minute, t.second);
}
Time suma(Time t1, Time t2)
{
    int h = t1.hour + t2.hour;
    int m = t1.minute + t2.minute;
    int s = t1.second + t2.second;
    if (s > SECONDS - 1)
    {
        m += 1;
        s %= SECONDS;
    }
    if (m > MINUTES - 1)
    {
        h += 1;
        m %= MINUTES;
    }
    return (Time){.hour = h, .minute = m, .second = s};
}
