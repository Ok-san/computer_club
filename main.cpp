#include "include/ComputerClub.h"
#include <iostream>
#include <fstream>


// ./main.exe test_data/test_file.txt
int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        std::cerr << "Invalid number of arguments.\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cerr << "File not found.\n";
        return 1;
    }
    else
    {
        try
        {
            ComputerClub computerClub(inputFile);
            computerClub.processingIncomingEvents(inputFile);
        }
        catch (const std::string &errorLine)
        {
            std::cerr <<"Formatiting error. Line:\n" << errorLine << "\n";
        }
        catch (...)
        {
            std::cerr << "An undentified exception was throw\n";
        }
    }
    inputFile.close();
    return 0;
}