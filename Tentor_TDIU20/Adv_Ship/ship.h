#include <string>
#include <ostream>

#ifndef TIME_H
#define TIME_H


class Ship
{
public:
    virtual ~Ship() = default;
    Ship(std::string const& name, int const& weight);
    std::string print_string() const;
    virtual int get_power() const = 0;
protected:
    std::string name;
    int weight;
};


class CargoShip: public Ship
{
public:
    CargoShip(std::string const& name, int const& weight, int const& cargo_capacity);
    int get_power() const override;
private:
    int cargo_capacity;
};


class WarShip: public Ship
{
public:
    WarShip(std::string const& name, int const& weight, int const& guns);
    int get_power() const override;
private:
    int guns;
};




#endif
