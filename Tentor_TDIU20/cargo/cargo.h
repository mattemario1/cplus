#include <ostream>

#ifndef TIME_H
#define TIME_H

class Cargo
{
public:
    Cargo(std::string name, int value);
    std::string get_name() const;
    int get_value() const;
    Cargo operator +(Cargo rhs);
private:
    std::string name;
    int value;
};

std::ostream& operator <<(std::ostream& lhs, Cargo const& rhs);

#endif
