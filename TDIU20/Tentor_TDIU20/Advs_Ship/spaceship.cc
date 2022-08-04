#include "spaceship.h"

#include <string>
#include <vector>
#include <iostream>

//Crew implementation
Crew::Crew(std::string n, std::string r): name{n}, rank{r} {}

std::ostream& operator<<(std::ostream & os, Crew const& c)
{
    os << c.name << " - " << c.rank << std::endl;
    return os;
}


Ship::Ship(std::string const& n, int l): name{n}, length{l}, crew{} {}

void Ship::add_crew_member(Crew const& c)
{
    crew.push_back(c);
}

void Ship::print(std::ostream & os) const
{
    os << "name: " << name << "\nlength: " << length << "\ncrew: \n";
    for (auto c: crew)
    {
	os << c;
    }
}