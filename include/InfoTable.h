#ifndef __INFO_TABLE_H__
#define __INFO_TABLE_H__

#include "MyTime.h"
#include "InfoEvent.h"

struct InfoTable
{
    MyTime startTime;
    bool status = false;
    std::string clientName = "";

private:
    unsigned int revenue = 0;
    unsigned int busyTimeMinutes = 0;

public:
    void revenueCalculation(unsigned int startTimeEvent, unsigned int endTimeEvent, unsigned int &costPerHour);
    void initTable(InfoEvent &event);
    void clearTable();
    MyTime getBusyTime();
    unsigned int getRevenue() { return revenue; }
};
#endif