// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
using namespace std;
#include "Time.h"
#include <iomanip>
#include <iostream>
#include <cmath>

Time::Time(int hour, int minute, int second):hour{hour}, minute{minute}, second{second}
{
    validate_time();
}

Time::Time():hour{0}, minute{0}, second{0}
{}

Time::Time(string const& time):hour{stoi(time.substr(0, 2))}, minute{stoi(time.substr(3, 2))}, second{stoi(time.substr(6, 2))}
{
    validate_time();
}

int Time::get_hour()const
{
    return hour;
}

int Time::get_minute()const
{
    return minute;
}

int Time::get_second()const
{
    return second;
}

void Time::set_hour(int h)
{
    if (h > 23 || h < 0)
        throw std::logic_error{"out of bound hour!"};
    else
        hour = h;
}

void Time::set_minute(int m)
{
    if (m > 59 || m < 0)
        throw std::logic_error{"out of bound minute!"};
    else
        minute = m;
}

void Time::set_second(int s)
{
    if (s > 59 || s < 0)
        throw std::logic_error{"out of bound second!"};
    else
        second = s;
}

//TODO Ni ska kasta ett standard undantag. Tex std::logic_error{"out of bound hour!"} -- FIXED
void Time::validate_time() const
{
    if ( hour < 0 || hour > 23 )
    {
        throw std::logic_error{"out of bound hour!"};
    }

    if ( minute < 0 || minute > 59 )
    {
        throw std::logic_error{"out of bound minute!"};
    }

    if ( second < 0 || second > 59 )
    {
        throw std::logic_error{"out of bound second!"};
    }
}

bool Time::is_am()const
{
    if ( hour < 12 )
        return true;
    else
        return false;
}

bool Time::is_pm()const
{
    return !is_am();
}


string Time::to_string(bool american)const
{
    int tempH = hour;
    if (american)
    {
        if (hour == 0)
        {
            tempH = 12;
        }
        else if (hour > 12)
        {
            tempH = hour - 12;
        }
    }

    ostringstream oss;
    oss << setw(2) << setfill('0') << tempH << ":"
        << setw(2) << setfill('0') << minute << ":"
        << setw(2) << setfill('0') << second;

    if (american)
    {
        if ( hour < 12 )
        {
            return  oss.str() + " am";
        }
        else
        {
            return oss.str() + " pm";
        }
    }
    return oss.str();
}

Time Time::operator+(int rhs) const
{   //Kommentar: floor är onödigt då både rhs och det du delar med är intar så du kommer alltid få tillbaka ett (trunkerat)  heltal. -- FIXED
    int tmp_hour = rhs / 3600;
    int tmp_minute = rhs / 60 % 60;
    int tmp_second = rhs % 60;

    int new_second = second + tmp_second;
    int new_minute = minute + tmp_minute + (new_second/60);
    int new_hour = hour + tmp_hour + (new_minute/60);

    int numOfDays = 1;
    if (tmp_hour > 24)
    {
        numOfDays = tmp_hour / 24;
    }

    if (new_hour == 24 * numOfDays)
    {
        new_hour = 0;
    }

    new_minute = new_minute % 60;
    new_second = new_second % 60;

    return Time{new_hour, new_minute, new_second};
}

Time& Time::operator++()
{
    Time tmp{*this};
    tmp = tmp + 1;
    hour = tmp.get_hour();
    minute = tmp.get_minute();
    second = tmp.get_second();

    return *this;
}

//TODO Kolla kommentareren vid testfallen för att se hur det ska -- FIXED
//fungera
Time Time::operator++(int)
{
    Time result{*this};
    ++(*this);
    return result;
}

 //TODO Använd inte tenary operatorn (? operatorn) -- FIXED
//TODO Funkar inte för flera dagar. -- FIXED
Time Time::operator-(int rhs) const
{
    int h2 = floor(rhs / 3600);
    h2 = h2 == 24 ? 0 : h2;
    int m2 = floor(rhs / 60 % 60);
    int s2 = floor(rhs % 60);

    int h1 = hour;
    int m1 = minute;
    int s1 = second;

    int new_second{};
    int new_minute{};
    int new_hour{};

    if (s2 > s1)
    {
        new_second = 60 + (s1 - s2);
        --m1;
    }
    else
    {
        new_second = s1 - s2;
    }

    if (m2 > m1)
    {
        new_minute = 60 + (m1 - m2);
        --h1;
    }
    else
    {
        new_minute = m1 - m2;
    }

    if (h2 > h1)
    {
        int numOfDays = 1;
        if (h2 > 24)
        {
            numOfDays = h2 / 24;
        }

        new_hour = 24 * numOfDays + (h1 - h2);
        if (new_hour == 24 * numOfDays)
        {
            new_hour = 0;
        }
    }
    else
    {
        new_hour = h1 - h2;
    }
    //TODO Ta bort kod som endast är där för debugging -- FIXED

    return Time{new_hour, new_minute, new_second};
}

Time& Time::operator--()
{
    Time tmp{*this};
    tmp = tmp - 1;
    hour = tmp.get_hour();
    minute = tmp.get_minute();
    second = tmp.get_second();

    return *this;
}

//TODO Kolla kommentareren vid testfallen för att se hur det ska -- FIXED
//fungera
Time Time::operator--(int)
{
    Time result{*this};
    --(*this);
    return result;
}

bool Time::operator==(Time rhs)const
{
    return hour == rhs.get_hour() &&
            minute == rhs.get_minute() &&
            second == rhs.get_second();
}

bool Time::operator!=(Time const& rhs)const
{
    return !(*this == rhs);
}

//TODO 1-2 -- förstår inte?
//TODO Felaktig implementation -- FIXED
bool Time::operator<(Time rhs)const
{
    int lhs_in_seconds = hour * 3600 + minute * 60 +second;
    int rhs_in_seconds = rhs.get_hour() * 3600 + rhs.get_minute() * 60 + rhs.get_second();

    return lhs_in_seconds < rhs_in_seconds;
}

bool Time::operator>(Time const& rhs)const
{
    return !(*this < rhs);
}

bool Time::operator<=(Time const& rhs)const
{
    return (*this < rhs) || (*this == rhs);
}

bool Time::operator>=(Time const& rhs)const
{
    return (*this > rhs) || (*this == rhs);
}

Time::operator string() const
{
    return (*this).to_string();
}

ostream& operator<<(ostream& lhs, Time const& rhs)
{
    lhs << rhs.to_string();
    return lhs;
}

//TODO Se över chained input och vad ni ska returnera -- FIXED
istream& operator>>(istream& stream, Time& time)
{
    char s{};
    int tmp_hour{};
    stream >> tmp_hour;
    stream >> s;
    if ( tmp_hour < 0 || tmp_hour > 23 || stream.fail()) // invalid intervall or invalid input
    {
        stream.setstate(std::ios_base::failbit);
        return stream;
    }

    int tmp_minute{};
    stream >> tmp_minute;
    stream >> s;
    if ( tmp_minute < 0 || tmp_minute > 59 || stream.fail()) // invalid intervall or invalid input
    {
        stream.setstate(std::ios_base::failbit);
        return stream;
    }

    int tmp_second{};
    stream >> tmp_second;
    if ( tmp_second < 0 || tmp_second > 59 || stream.fail()) // invalid intervall or invalid input
    {
        stream.setstate(std::ios_base::failbit);
        return stream;
    }


    time.set_hour(tmp_hour);
    time.set_minute(tmp_minute);
    time.set_second(tmp_second);

    return stream;
}
