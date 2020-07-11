#include <ostream>

#ifndef SORTED_LIST_H
#define SORTED_LIST_H



/*
TODO:

8-1. Möjlig minnesläcka. Visar också att era tester inte är
tillräckliga eftersom de inte ger det. --KLAR

Comment:
iterator::operator* bör returnera en referens och därav bör
inte begin() och end() vara const -- KLAR

 */


class sorted_list
{
public:
    ~sorted_list();
    sorted_list();
    sorted_list(sorted_list const& rhs);
    sorted_list(sorted_list && rhs);
    sorted_list(std::initializer_list<int> list);
    void insert(int n);
    void remove(int index);
    int at(int index)const;
    void print_list(std::ostream &os) const;
    int length() const;
    sorted_list& operator = (sorted_list const& rhs);
    sorted_list& operator = (sorted_list && rhs);

private:
    class element
    {
    public:
        ~element();
        element *prev{};
        int value{};
        element *next{};
    };
    element *first{};
    element *last{};
    bool is_empty_list() const;
    element* find_node_at(int index) const;
    std::string to_string() const;

public:
    class iterator
    {
    public:
        iterator(element *element);
        bool operator != (iterator i) const;
        iterator& operator ++ ();
        int& operator * ();
    private:
        element *current{};
    };
    iterator begin();
    iterator end();
};


#endif
