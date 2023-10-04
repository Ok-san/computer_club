#include "../include/MyTime.h"

bool MyTime::checkTimeFormat(std::string &inputLine)
{
    std::regex regFormat("([01][0-9]|2[0-3]):([0-5][0-9])");
    std::cmatch resultOfCheck;

    if (std::regex_match(inputLine.c_str(), resultOfCheck, regFormat))
    {
        hour = stoi(resultOfCheck[1].str());
        min = stoi(resultOfCheck[2].str());
        return true;
    }
    else
        return false;
}

unsigned int MyTime::timeToMinutes()
{
    return hour * 60 + min;
}

std::string MyTime::timeToString()
{
    std::string time;
    if (hour < 10)
        time = '0' + std::to_string(hour);
    else
        time = std::to_string(hour);
    time += ":";
    if (min < 10)
        time += '0' + std::to_string(min);
    else
        time += std::to_string(min);
    return time;
}