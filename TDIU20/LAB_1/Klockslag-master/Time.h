// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#include <string>
#include <ostream>

#ifndef TIME_H
#define TIME_H

/*  KVAR!
TODO:
Hjälpfunktioner ska inte vara en del av det publika gränssnittet -- FIXED

Funktioner/operatorer som inte ska modiferar objektet ska vara const -- FIXED

Gränssnittet till klassen ska garantera att klockslaget alltid är korrekt (Ska inte kunna gå att sätta timmarna till 52 tex) --FIXED
*/

class Time
{
    public:
        Time();
        Time(std::string const& time);
        Time(int hour, int minute, int second);
        int get_hour() const;
        int get_minute() const;
        int get_second() const;
        void set_hour(int h);
        void set_minute(int m);
        void set_second(int s);
        bool is_am() const;
        bool is_pm() const;
        std::string to_string(bool american = false) const;

        Time operator +(int rhs) const;
        Time operator -(int rhs) const;
        Time& operator ++();
        Time operator ++(int);
        Time& operator --();
        Time operator --(int);
        bool operator ==(Time rhs) const;
        bool operator !=(Time const& rhs) const;
        bool operator <(Time rhs) const;
        bool operator >(Time const& rhs) const;
        bool operator <=(Time const& rhs) const;
        bool operator >=(Time const& rhs) const;
        operator std::string() const;
    
    private:
        int hour;
        int minute;
        int second;
        void validate_time() const;
};

std::ostream& operator<<(std::ostream& lhs, Time const& rhs);
std::istream& operator>>(std::istream& stream, Time& time);

#endif
