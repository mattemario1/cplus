using namespace std;

#include "tenta.h"

TentaRoom::TentaRoom(string Name, int NumOfChairs, int NumOfComputers):
Name{Name}, RoomMaterials.chairs{NumOfChairs}, RoomMaterials.computers{NumOfComputers}
{}

TentaRoom::TentaRoom(string Name)
{
    cout << "No computers or chairs? Seems like a bad room for a test." << endl;
}

//
// int get_computer()
// {
//     return RoomMaterials.computers;
// }
//
// int get_chairs()
// {
//     return RoomMaterials.chairs;
// }
//
// bool same_num()
// {
//     return RoomMaterials.computers == RoomMaterials.chairs;
// }
