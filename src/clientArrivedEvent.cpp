#include "../include/ComputerClub.h"

void ComputerClub::clientArrivedEvent(InfoEvent &event)
{
    // Клиент пришел в не рабочее время
    unsigned int eventTimeInMinutes = event.time.timeToMinutes();

    if (isOpenAtNight)
    {
        unsigned endTimeToMinutes = endTime.timeToMinutes() + 24 * 60;
        unsigned startTimeToMinutes = startTime.timeToMinutes();
        if (eventTimeInMinutes < startTimeToMinutes)
            eventTimeInMinutes += 24 * 60;

        if (eventTimeInMinutes < startTimeToMinutes || eventTimeInMinutes >= endTimeToMinutes)
        {
            std::cout << "\n"
                      << event.time.timeToString() << " 13 "
                      << "NotOpenYet";
            return;
        }
    }
    else
    {
        if (eventTimeInMinutes < startTime.timeToMinutes() || eventTimeInMinutes >= endTime.timeToMinutes())
        {
            std::cout << "\n"
                      << event.time.timeToString() << " 13 "
                      << "NotOpenYet";
            return;
        }
    }

    // Клиент уже находится в клубе
    std::deque<std::string>::iterator iter = clientsInClub.begin();
    if (findClientInClub(event.clientName, iter))
    {
        std::cout << "\n"
                  << event.time.timeToString() << " 13 "
                  << "YouShallNotPass";
        return;
    }

    clientsInClub.push_back(event.clientName);
}