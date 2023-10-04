#include "../include/InfoTable.h"

void InfoTable::revenueCalculation(unsigned int endTimeEvent, unsigned int startTimeEvent, unsigned int &costPerHour)
{
    unsigned int spentTimeMin;

    if (startTimeEvent > endTimeEvent)
        endTimeEvent += 24 * 60; // если клиент пришел до полуночи и ушел после полуночи.

    spentTimeMin = endTimeEvent - startTimeEvent;
    busyTimeMinutes += spentTimeMin;

    short roundOfHour = spentTimeMin / 60;
    if (spentTimeMin % 60 != 0)
        roundOfHour++;
    revenue += roundOfHour * costPerHour;
}

void InfoTable::initTable(InfoEvent &event)
{
    startTime = event.time;
    status = true;
    clientName = event.clientName;
}

void InfoTable::clearTable()
{
    status = false;
    clientName = "";
}

MyTime InfoTable::getBusyTime()
{
    MyTime busyTime;
    busyTime.hour = busyTimeMinutes / 60;
    busyTime.min = busyTimeMinutes % 60;
    return busyTime;
}