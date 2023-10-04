#ifndef __COMPUTERCLUB_H__
#define __COMPUTERCLUB_H__

#include "MyTime.h"
#include "InfoEvent.h"
#include "InfoTable.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <deque>

class ComputerClub
{
    unsigned int numOfTables;
    MyTime startTime, endTime;
    unsigned int costPerHour;
    std::queue<InfoEvent> queueEvents;
    std::queue<std::string> queueClients;
    std::deque<std::string> clientsInClub;
    InfoTable *allTables;
    unsigned int countOccupiedTable = 0;
    bool isOpenAtNight = false;

public:
    ComputerClub(std::ifstream &inputFile);
    void processingIncomingEvents(std::ifstream &inputFile);
    ~ComputerClub();

private:
    void clientArrivedEvent(InfoEvent &event);
    void clientSatDownTableEvent(InfoEvent &event);
    void clientIsWaitingEvent(InfoEvent &event);
    void clientLeftEvent(InfoEvent &event);
    bool findClientInClub(std::string &clientName, std::deque<std::string>::iterator &iter);
    unsigned int findClientAtTable(std::string &clientName);
};
#endif