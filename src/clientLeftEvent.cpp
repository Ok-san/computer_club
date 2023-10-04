#include "../include/ComputerClub.h"

void ComputerClub::clientLeftEvent(InfoEvent &event)
{
    // Клиент не находится в компьютерном клубе
    std::deque<std::string>::iterator iter = clientsInClub.begin();
    if (!findClientInClub(event.clientName, iter))
    {
        std::cout << "\n"
                  << event.time.timeToString() << " 13 "
                  << "ClientUnknown";
        return;
    }

    // Когда клиент уходит, стол, за которым он сидел освобождается и его занимает первый клиент из очереди ожидания (ID 12).
    unsigned int idTable = findClientAtTable(event.clientName);
    if (idTable > 0)
    {
        idTable--;
        allTables[idTable].clearTable();
        // Подсчет выручки
        allTables[idTable].revenueCalculation(event.time.timeToMinutes(), allTables[idTable].startTime.timeToMinutes(), costPerHour);
        countOccupiedTable--;

        // клиент из очереди садится за стол
        if (!queueClients.empty())
        {
            event.clientName = queueClients.front();
            queueClients.pop();
            allTables[idTable].initTable(event);
            std::cout << "\n"
                      << event.time.timeToString()
                      << " 12 " << event.clientName << " " << idTable + 1;
            countOccupiedTable++;
        }
    }
    clientsInClub.erase(iter);
}