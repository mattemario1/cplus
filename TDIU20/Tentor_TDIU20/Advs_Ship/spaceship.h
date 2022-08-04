#ifndef SPACESHIP_H
#define SPACESHIP_H

#include<string>
#include<vector>
#include<ostream>

struct Crew
{
public:
    Crew(std::string n, std::string r);
    
    friend std::ostream& operator<<(std::ostream & os, Crew const& c);
private:
    std::string name;
    std::string rank;    
};

class Ship
{
public:
    Ship(std::string const& n, int l);
    
    void add_crew_member(Crew const& c);
    void print(std::ostream & os) const;
private:
    std::string name;
    int length;
    std::vector<Crew> crew;
};

#endif