#include <string>

#ifndef TIME_H
#define TIME_H


class ship
{
public:
    virtual ~ship() = default;
    ship(std::string const& name, int const& weight);
    virtual int get_power() const = 0;
protected:
    std::string name;
    int weight;
};


class CargoShip: public ship
{
public:
    Cargoship(std::string const& name, int const& weight, int const& cargo_capacity);
    int get_power() const override;
private:
    int cargo_capacity;
};


class WarShip: public ship
{
public:
    Warship(std::string const& name, int const& weight, int const& guns);
    int get_power() const override;
private:
    int guns;
};


#endif
