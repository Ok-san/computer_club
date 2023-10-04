#include "../include/ComputerClub.h"

bool ComputerClub::findClientInClub(std::string &clientName, std::deque<std::string>::iterator &iter)
{
    for (iter; iter < clientsInClub.end(); iter++)
        if (*iter == clientName)
            return true;

    return false;
}

unsigned int ComputerClub::findClientAtTable(std::string &clientName)
{
    for (unsigned int i = 0; i < numOfTables; i++)
        if (allTables[i].clientName == clientName)
            return i + 1;

    return 0;
}