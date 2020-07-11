

#ifndef TIME_H
#define TIME_H

class Date
{
public:
    Date(int year, int month, int day);
    bool is_leap_year(int year) const;
    int days_in_month(int year, int month) const;
    void print(std::ostream& os, struct Date const& d);

private:
    int year;
    int month;
    int day;
};




#endif
