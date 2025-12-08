#ifndef P12_H
#define P12_H

#define HOURS   24
#define MINUTES 60
#define SECONDS 60

typedef struct
{
    int hour;
    int minute;
    int second;
} Time;

void afisare(Time t);

#endif