#include "../include/ComputerClub.h"

void ComputerClub::processingIncomingEvents(std::ifstream &inputFile)
{
    std::cout << startTime.timeToString() << "\n";

    while (!queueEvents.empty())
    {
        InfoEvent event = queueEvents.front();
        queueEvents.pop();

        std::cout << event.time.timeToString() << " " << (int)event.id << " " << event.clientName;
        
        if (event.id == 1)
        {
            clientArrivedEvent(event);
        }
        else if (event.id == 2)
        {
            std::cout << " " << event.tableNum;
            clientSatDownTableEvent(event);
        }
        else if (event.id == 3)
        {
            clientIsWaitingEvent(event);
        }
        else if (event.id == 4)
        {
            clientLeftEvent(event);
        }
        std::cout << "\n";
    }

    // если в клубе остались клиенты -> событие 11 в алфавитном порядке имен
    if (!clientsInClub.empty())
    {
        sort(clientsInClub.begin(), clientsInClub.end());
        for (unsigned int i = 0; i < clientsInClub.size(); i++)
            std::cout << endTime.timeToString() << " 11 " << clientsInClub[i] << "\n";
    }

    std::cout << endTime.timeToString() << "\n";

    // для каждого стола вывод выручки и времени, которое он был занят.
    for (unsigned int idTable = 0; idTable < numOfTables; idTable++)
    {
        if (allTables[idTable].status)
        {
            allTables[idTable].clearTable();
            allTables[idTable].revenueCalculation(endTime.timeToMinutes(), allTables[idTable].startTime.timeToMinutes(), costPerHour);
        }

        std::cout << idTable + 1 << " " << allTables[idTable].getRevenue() << " " << allTables[idTable].getBusyTime().timeToString() << "\n";
    }
}