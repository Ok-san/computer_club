#include "../include/InfoEvent.h"

bool InfoEvent::checkEventFormat(std::string &inputLine, unsigned int &maxTableNum)
{
    std::regex regLineEventFormatEvent("([01][0-9]|2[0-3]):([0-5][0-9])" // время события
                                       " ([134])"                         // номер события
                                       " ([a-z0-9_-]+)$");                // имя клиента
    /*Для второго события*/
    std::regex regLineEventFormatEvent_2("([01][0-9]|2[0-3]):([0-5][0-9])"
                                         " ([2])"
                                         " ([a-z0-9_-]+)"
                                         " ([1-9]{1}[0-9]*)$"); // номер стола
    std::cmatch resultOfCheck;

    if (std::regex_match(inputLine.c_str(), resultOfCheck, regLineEventFormatEvent))
    {
        initEvent(resultOfCheck);
        tableNum = 0;
        return true;
    }
    else if (std::regex_match(inputLine.c_str(), resultOfCheck, regLineEventFormatEvent_2))
    {
        initEvent(resultOfCheck);
        tableNum = stoi(resultOfCheck[5].str());
        if (tableNum > maxTableNum)
            return false;

        return true;
    }
    else
        return false;
}

void InfoEvent::initEvent(std::cmatch &resultOfCheck)
{
    time.hour = stoi(resultOfCheck[1].str());
    time.min = stoi(resultOfCheck[2].str());
    id = stoi(resultOfCheck[3].str());
    clientName = resultOfCheck[4];
}