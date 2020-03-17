#include <iostream>
#include <vector>

#include "ship.h"

using namespace std;

void print_fleet(string const& name, vector<Ship> fleet)
{
    cout << "name: " << name << "\n";
    unsigned int power{};

    // for (Ship* p: fleet)
    // {
    //     power += p.get_power();
    // }

    cout << "Total power: " << power << "\n";

    for (Ship* s: fleet)
    {
    	cout << s.print_string() << "\n";
    }
    cout << endl;
}

int main()
{
    vector<Ship> fleet;

    fleet.push_back(WarShip{"Defiant", 8, 4});
    fleet.push_back(WarShip{"Valiant", 8, 4});
    fleet.push_back(CargoShip{"Yoshiro", 40, 3});
    fleet.push_back(WarShip{"Enterprise", 20, 6});
}
