#include "../include/ComputerClub.h"

void ComputerClub::clientSatDownTableEvent(InfoEvent &event)
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

    // Если стол занят + клиент не может пересесть за тот же стол
    if (allTables[event.tableNum - 1].status)
    {
        std::cout << "\n"
                  << event.time.timeToString() << " 13 "
                  << "PlaceIsBusy";
        return;
    }

    // Если клиент уже сидит за столом -> освобождает стол
    unsigned int idTable = findClientAtTable(event.clientName);
    if (idTable > 0)
    {
        idTable--;
        allTables[idTable].clearTable();
        countOccupiedTable--;

        // Подсчет выручки
        allTables[idTable].revenueCalculation(event.time.timeToMinutes(), allTables[idTable].startTime.timeToMinutes(), costPerHour);
    }

    allTables[event.tableNum - 1].initTable(event);
    countOccupiedTable++;
}