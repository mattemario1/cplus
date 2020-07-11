#include <iostream>
#include <string>

#include "queue.h"

Queue::Queue() : first{nullptr} {}

Queue::~Queue()
{
    delete first;
}

Queue::Task::~Task()
{
    delete next;
}

std::string Queue::to_string() const
{
    std::string s{"[ "};
    Task* curr{first};
    while ( curr )
    {
	s += curr -> task;
	s += " ";
	curr = curr -> next;
    }
    s += "]";
    return s;
}

void Queue::enqueue(std::string t)
{
    if ( first == nullptr)
    {
	first = new Task{t, first};
    }
    else
    {
	Task* curr{first};
	while ( curr -> next )
	{
	    curr = curr -> next;
	}
	curr -> next = new Task{t, nullptr};
    }
}

void Queue::dequeue()
{
    if( first )
    {
	Task* tmp{first->next};
	first -> next = nullptr;
	delete first;
	first = tmp;
    }
}

void Queue::execute()
{
    if (first)
    {
	std::cout << first->task << std::endl;
	dequeue();
    }
    else
    {
	std::cout << "Queue is empty, no task to run" << std::endl;
    }
}

//copy
Queue::Queue(Queue const& rhs)
{
    *this = rhs;
}

Queue Queue::operator = (Queue const& rhs)
{
    if (rhs.first == nullptr)
    {
        first = nullptr;
        std::cout << "foo" << std::endl;
    }
    else
    {
        while (first -> next)
        {
            dequeue();
            std::cout << "faa" << std::endl;

        }
        Task* rhs_curr{rhs.first};
        while (rhs_curr -> next)
        {
            enqueue(rhs_curr -> task);
            rhs_curr = rhs_curr -> next;
            std::cout << "fii" << std::endl;

        }
    }
    return *this;
}

//move

Queue::Queue(Queue &&rhs) : Queue()
{
    *this = std::move(rhs);
}

Queue Queue::operator = (Queue &&rhs)
{
    std::swap(first, rhs.first);
    rhs.~Queue();
    rhs.first = nullptr;
    return *this;
}
