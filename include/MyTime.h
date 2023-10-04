#ifndef __TIME_H__
#define __TIME_H__

#include <regex>
#include <string>

struct MyTime
{
    short hour;
    short min;

    bool checkTimeFormat(std::string &inputLine);
    unsigned int timeToMinutes();
    std::string timeToString();
};
#endif