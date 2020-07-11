#include <string>

#ifndef TIME_H
#define TIME_H

class ComputerRoom
{
public:
    int chairs;
    int computers;
};

class TentaRoom
{
public:
    TentaRoom(std::string Name, int NumOfChairs, int NumOfComputers);
    TentaRoom(std::string Name);
    // int get_computer();
    // int get_chairs();
    // bool same_num();
private:
    std::string Name;
    ComputerRoom RoomMaterials;
};

#endif
