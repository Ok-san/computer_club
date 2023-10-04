#ifndef __INFO_EVENT_H__
#define __INFO_EVENT_H__

#include "MyTime.h"

struct InfoEvent
{
    MyTime time;
    char id;
    std::string clientName;
    unsigned int tableNum;

    bool checkEventFormat(std::string &inputLine, unsigned int &maxTableNum);

private:
    void initEvent(std::cmatch &resultOfCheck);
};
#endif