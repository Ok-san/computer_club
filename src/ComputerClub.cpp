#include "../include/ComputerClub.h"

ComputerClub::ComputerClub(std::ifstream &inputFile)
{
    std::string inputLine;
    inputFile >> inputLine;
    numOfTables = stoul(inputLine);

    if (std::to_string(numOfTables) != inputLine || numOfTables == 0)
        throw inputLine;

    std::string inputStartTime, inputEndTime;
    inputFile >> inputStartTime >> inputEndTime;

    if (!startTime.checkTimeFormat(inputStartTime) || !endTime.checkTimeFormat(inputEndTime))
        throw inputStartTime + " " + inputEndTime;

    inputFile >> inputLine;
    costPerHour = stoul(inputLine);

    if (std::to_string(costPerHour) != inputLine || costPerHour == 0)
        throw inputLine;

    while (getline(inputFile, inputLine, '\n'))
    {
        if (!inputLine.empty())
        {
            InfoEvent event;
            if (event.checkEventFormat(inputLine, numOfTables))
            {
                queueEvents.push(event);
            }
            else
                throw inputLine;
        }
    }
    if(startTime.timeToMinutes() > endTime.timeToMinutes())
        isOpenAtNight = true;

    allTables = new (std::nothrow) InfoTable[numOfTables];
    if (allTables == nullptr)
        throw;
}

ComputerClub::~ComputerClub()
{
    while (!queueClients.empty())
        queueClients.pop();

    if (!clientsInClub.empty())
        clientsInClub.clear();

    delete[] allTables;
}