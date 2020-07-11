#include <vector>
#include <ostream>

#ifndef TIME_H
#define TIME_H

class Crew
{
public:
    Crew(std::string name, std::string rank);
    std::string get_name() const;
    std::string get_rank() const;

private:
    std::string name;
    std::string rank;
};


class Ship
{
public:
    Ship(std::string name, int length);
    void print(std::ostream &os)const;
    void add_crew_member(Crew new_crew);
    std::string get_name() const;
    int get_length() const;
private:
    std::string name;
    int length;
    std::vector<Crew> crew_members;
};



#endif
