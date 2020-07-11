
using namespace std;

#include "cargo.h"

Cargo::Cargo(string n, int v): name{n}, value{v}
{}

string Cargo::get_name() const
{
    return name;
}

int Cargo::get_value() const
{
    return value;
}

Cargo Cargo::operator +(Cargo rhs)
{
    int new_value = value + rhs.get_value();
    string new_name = name + rhs.get_name();
    return Cargo{new_name, new_value};
}

ostream& operator <<(ostream& lhs, Cargo const& rhs)
{
    lhs << rhs.get_name() << " " << rhs.get_value();
    return lhs;
}
