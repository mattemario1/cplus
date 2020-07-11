using namespace std;

#include "ship.h"

Ship::Ship(string const& n, int const& w): name{n}, weight{w}
{}

CargoShip::CargoShip(string const& n, int const& w, int const& c): Ship{n, w}, cargo_capacity{c}
{}

WarShip::WarShip(string const& n, int const& w, int const& g): Ship{n, w}, guns{g}
{}

int CargoShip::get_power() const
{
    return weight + cargo_capacity;
}

int WarShip::get_power() const
{
    return weight * guns;
}

string Ship::print_string() const
{
    return "name: " + name + ", weight:" +  to_string(weight);
}
