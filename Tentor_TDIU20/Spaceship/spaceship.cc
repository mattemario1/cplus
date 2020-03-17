using namespace std;

#include "spaceship.h"


Ship::Ship(std::string name, int length) : name{name}, length{length}
{}

Crew::Crew(std::string name, std::string rank) : name{name}, rank{rank}
{}



void Ship::add_crew_member(Crew new_crew)
{
    crew_members.push_back(new_crew);
}


string Ship::get_name() const
{
    return name;
}

int Ship::get_length() const
{
    return length;
}

string Crew::get_name() const
{
    return name;
}

string Crew::get_rank() const
{
    return rank;
}

void Ship::print(std::ostream &os)const
{
    os << "name: " << get_name() << endl;
    os << "length: " << get_length() << endl;
    os << "crew:" << endl;

    for (auto person : crew_members)
    {
        os << person.get_name() << " - " << person.get_rank() << endl;
    }
}
