using namespace std;

#include "ship.h"

ship::ship(string const& n, int const& w): name{n}, weight{w}
{}

CargoShip::Cargoship(string const& n, int const& w, int const& c): ship{n, w}, cargo_capacity{c}
{}

WarShip::Warship(string const& n, int const& w, int const& g): ship{n, w}, guns{g}
{}

int CargoShip::get_power() const
{
    return weight + cargo_capacity;
}

int WarShip::get_power() const
{
    return weight * guns;
}
