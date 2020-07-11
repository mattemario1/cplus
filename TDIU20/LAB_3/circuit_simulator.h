#include <iostream>
#include <vector>
#include <map>

#ifndef CIRCUIT_SIMULATOR_H
#define CIRCUIT_SIMULATOR_H

class connection
{
public:
    double potential;
};

class component
{
public:
    virtual ~component() = default;
    component(std::string const &_name, connection &n, connection &p);
    std::string get_name() const;
    void set_name(std::string new_name);
    virtual void simulate(double time) = 0;
    virtual double get_electric_current() const = 0; // ström
    virtual double get_voltage() const = 0;          // spänning

private:
    std::string name;

protected:
    connection &c1;
    connection &c2;
};

class battery : public component
{
public:
    battery(std::string const &_name, double _voltage, connection &n, connection &p);
    void simulate(double time) override;
    double get_electric_current() const override; // ström
    double get_voltage() const override;          // spänning

private:
    double voltage;
};

class resistor : public component
{
public:
    resistor(std::string const &_name, double _resistance, connection &n, connection &p);
    void simulate(double time) override;
    double get_electric_current() const override; // ström
    double get_voltage() const override;

private:
    double resistance;
};

class condensator : public component
{
public:
    condensator(std::string const &_name, double _capacitance, connection &n, connection &p);
    void simulate(double time) override;
    double get_electric_current() const override; // ström
    double get_voltage() const override;

private:
    double e_current{0};
    double capacitance{0};
    double voltage{0};
};

class circuit
{
public:
    ~circuit();
    void add_con(connection con, std::string name);
    void add_bat(std::string const &_name, double _voltage, std::string c1, std::string c2);
    void add_res(std::string const &_name, double _resistance, std::string c1, std::string c2);
    void add_cond(std::string const &_name, double _capacitance, std::string c1, std::string c2);
    void simulate(int iterations, int rows, double time);

private:
    void simulate(std::vector<component *> net, int iterations, int rows, double time);
    std::map<std::string, connection> connections;
    std::vector<component *> components;
};

#endif
