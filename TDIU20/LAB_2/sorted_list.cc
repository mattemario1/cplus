using namespace std;
#include <iostream>
#include <sstream>

#include "sorted_list.h"

sorted_list::~sorted_list()
{
    delete first;
}

sorted_list::element::~element()
{
    delete next;
}

sorted_list::sorted_list()
{
    first = new element{nullptr, 0, nullptr};
    last = new element{first, 0, nullptr};
    first->next = last;
}

sorted_list::sorted_list(std::initializer_list<int> list) : sorted_list()
{
    //TODO: Bör kalla på default-konstruktorn istället för att skriva detta här igen -KLAR
    if (list.size() > 0)
    {
        for (auto e : list)
        {
            insert(e);
        }
    }
}

sorted_list::sorted_list(sorted_list const &rhs)
{
    *this = rhs;
}

/*
TODO:
För ineffektivt att göra såhär. Ni vet att rhs är sorterad ändå
går ni igenom hela listan varje gång ni gör en insättning. Fast ni vet
att den alltid komma läggas sist.

Samma när ni tar bort. Ni tar alltid bort sista elementet så ni måste gå igenom hela listan varje gång. (2 gånger dessutom med tanke på hur eran find_node fungerar)

--- KLAR!
 */
sorted_list &sorted_list::operator=(sorted_list const &rhs)
{
    if (first == nullptr)
    {
        first = new element{nullptr, 0, nullptr};
        last = new element{first, 0, nullptr};
        first->next = last;
    }

    if (first != rhs.first)
    {
        int len = length();
        for (int i = 0; i < len; i++)
        {
            remove(0);
        }

        element *current = rhs.last->prev;
        for (int i = rhs.length() - 1; i >= 0; i--)
        {
            insert(current->value);
            current = current->prev;
        }
    }

    return *this;
}

// move constructor
sorted_list::sorted_list(sorted_list &&rhs) : sorted_list()
{
    *this = move(rhs);
}

// move assignment operator
sorted_list &sorted_list::operator=(sorted_list &&rhs)
{
    swap(first, rhs.first);
    swap(last, rhs.last);
    rhs.~sorted_list(); // ekvivalent med -> delete rhs.first;
    rhs.first = nullptr;
    rhs.last = nullptr;

    return *this;
}

void sorted_list::insert(int n)
{
    if (is_empty_list())
    {
        first->next = new element{first, n, last};
        last->prev = first->next;
    }
    else
    {
        element *current_elem = first;
        while (current_elem->next != last && current_elem->next->value < n)
        {
            current_elem = current_elem->next;
        }

        element *new_elem = new element{current_elem, n, current_elem->next};
        current_elem->next->prev = new_elem;
        current_elem->next = new_elem;
    }
}

void sorted_list::remove(int index)
{
    element *elem = find_node_at(index);
    elem->next->prev = elem->prev;
    elem->prev->next = elem->next;
    elem->next = nullptr;
    delete elem;
}

bool sorted_list::is_empty_list() const
{
    return first->next == last;
}

void sorted_list::print_list(std::ostream &os) const
{
    os << (*this).to_string();
}

string sorted_list::to_string() const
{
    string str_builder{"{"};
    if (first != nullptr)
    {
        element *curr_elem = first->next;

        while (curr_elem != last)
        {
            stringstream ss;
            ss << curr_elem->value;
            str_builder += ss.str();
            if (curr_elem->next != last)
            {
                str_builder += ", ";
            }
            curr_elem = curr_elem->next;
        }
    }
    str_builder += "}";

    return str_builder;
}

int sorted_list::length() const
{
    int counter{0};
    if (first != nullptr)
    {
        element *curr_elem = first->next;
        while (curr_elem != last)
        {
            curr_elem = curr_elem->next;
            ++counter;
        }
    }

    return counter;
}

int sorted_list::at(int index) const
{
    element *elem = find_node_at(index);
    return elem->value;
}

//TODO: Här går ni igenom listan 2 gånger. 1 gång för att kolla sizen
//och 1 gång för att hämta ut elementet. Inte ok.
// Ni kan lösa det genom att tex spara length som en variabel
sorted_list::element *sorted_list::find_node_at(int index) const
{
    if (is_empty_list())
    {
        throw out_of_range("list is empty!");
    }

    if (index < 0)
    {
        throw out_of_range("Out of rang!");
    }

    int counter{0};
    element *curr_elem = first->next;
    while (counter != index)
    {
        if (curr_elem == last) {
            throw out_of_range("Out of rang!");
        }
        curr_elem = curr_elem->next;
        ++counter;
    }

    return curr_elem;
}

sorted_list::iterator::iterator(element *element) : current{element}
{}

bool sorted_list::iterator::operator != (iterator i) const
{
    return current != i.current;
}

sorted_list::iterator &sorted_list::iterator::operator ++ ()
{
    current = current->next;
    return *this;
}

int& sorted_list::iterator::operator * ()
{
    return current->value;
}

sorted_list::iterator sorted_list::begin()
{
    iterator itr = iterator{first->next};

    return itr;
}

sorted_list::iterator sorted_list::end()
{
    iterator itr = iterator{last};

    return itr;
}
