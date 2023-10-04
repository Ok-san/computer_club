cmake_minimum_required (VERSION 3.27.0)

set(Project Computer_Club)
set(CMAKE_CXX_STANDARD  17)

project (${Project}
        LANGUAGES CXX)

set(Sources
    src/MyTime.cpp
    src/InfoEvent.cpp
    src/InfoTable.cpp
    src/ComputerClub.cpp
    src/clientArrivedEvent.cpp
    src/clientIsWaitingEvent.cpp
    src/clientLeftEvent.cpp
    src/clientSatDownTableEvent.cpp
    src/findClient.cpp
    src/processingIncomingEvents.cpp
)

add_executable(${Project} main.cpp ${Sources})