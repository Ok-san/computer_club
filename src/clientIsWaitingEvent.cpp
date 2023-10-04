#include "../include/ComputerClub.h"

void ComputerClub::clientIsWaitingEvent(InfoEvent &event)
{
    // Если есть свободные столы
    if (countOccupiedTable < numOfTables)
    {
        std::cout << "\n"
                  << event.time.timeToString() << " 13 "
                  << "ICanWaitNoLonger!";
        return;
    }

    // Если в очереди число клиентов больше числа столов
    if (queueClients.size() > numOfTables)
    {
        std::cout << "\n"
                  << event.time.timeToString() << " 11 "
                  << event.clientName;
        return;
    }
    queueClients.push(event.clientName);
}