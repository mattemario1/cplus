using namespace std;

#include "circuit_simulator.h"
#include <iostream>
#include <iomanip>

component::component(string const &_name, connection &n, connection &p):name{_name}, c1{n}, c2{p}
{}

void component::set_name(string new_name)
{
    name = new_name;
}

string component::get_name() const
{
    return name;
}

battery::battery(string const &_name, double _voltage, connection &n, connection &p):
    component{_name, n, p}, voltage{_voltage} {}

void battery::simulate(double)
{
    c1.potential = 0;
    c2.potential = voltage;
}

double battery::get_electric_current() const
{
    return 0;
}

double battery::get_voltage() const
{
    return voltage;
}

resistor::resistor(string const &_name, double _resistance, connection &n, connection &p):
    component{_name, n, p}, resistance{_resistance} {}

void resistor::simulate(double time)
{
    double totalToMove = get_voltage()/resistance * time;
    c1.potential -= totalToMove;
    c2.potential += totalToMove;
}

double resistor::get_electric_current() const
{
    return get_voltage()/resistance;
}

double resistor::get_voltage() const
{
    return c1.potential - c2.potential;
}

condensator::condensator(string const &_name, double _capacitance, connection &n, connection &p):
    component{_name, n, p}, capacitance{_capacitance} {}

void condensator::simulate(double time)
{
    double volt_diff = c1.potential - c2.potential;
    double chargeToStore = capacitance * (volt_diff - voltage) * time;
    c1.potential -= chargeToStore;
    c2.potential += chargeToStore;
    voltage += chargeToStore;

    // double chargeToStore{0.0};
    //
    // if (c2.potential >= c1.potential)
    // {
    //     double volt_diff = c2.potential - c1.potential;
    //     chargeToStore = capacitance * (volt_diff - voltage) * time;
    //     c2.potential -= chargeToStore;
    //     c1.potential += chargeToStore;
    // }
    // else
    // {
    //     double volt_diff = c1.potential - c2.potential;
    //     chargeToStore = capacitance * (volt_diff - voltage) * time;
    //     c1.potential -= chargeToStore;
    //     c2.potential += chargeToStore;
    // }
    // voltage += chargeToStore;
}

double condensator::get_electric_current() const
{
    return e_current;
}

double condensator::get_voltage() const
{
    return voltage;
}

void circuit::simulate(std::vector<component *> net, int iterations, int rows, double time)
{
    for (auto comp : net)
    {
        cout << setw(13) << setfill(' ') << comp->get_name();
    }
    cout << endl;

    for (int j = 0; j < (int)net.size(); j++)
    {
        cout << setw(13) << "Volt  Curr";
    }
    cout << endl;

    for (int i = 1; i <= iterations; i++)
    {
        for (int j = 0; j < (int)net.size(); j++)
        {
            net.at(j)->simulate(time);
            if (i%(iterations/rows) == 0)
            {
                cout << setw(7) << fixed << setprecision(2) << net.at(j)->get_voltage() << " ";
                cout << setw(5) << fixed << setprecision(2) << net.at(j)->get_electric_current();
                if (j == (int)net.size() - 1)
                {
                    cout << endl;
                }
            }
        }
    }
}

circuit::~circuit()
{
    for (auto comp : components)
    {
        delete comp;
    }
}

void circuit::add_con(connection con, std::string name)
{
    connections[name] = con;
}

void circuit::add_bat(std::string const &_name, double _voltage, std::string c1, std::string c2)
{
    components.push_back(new battery(_name, _voltage, connections[c1], connections[c2]));   
}

void circuit::add_res(std::string const &_name, double _resistance, std::string c1, std::string c2)
{
    components.push_back(new resistor(_name, _resistance, connections[c1], connections[c2]));   
}

void circuit::add_cond(std::string const &_name, double _capacitance, std::string c1, std::string c2)
{
    components.push_back(new condensator(_name, _capacitance, connections[c1], connections[c2]));   
}

void circuit::simulate(int iterations, int rows, double time)
{
    simulate(components, iterations, rows, time);
}
