#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

class Queue
{
public:
    Queue();
    ~Queue();
    std::string to_string() const;
    void enqueue(std::string t); //Enqueues element last in que
    void dequeue(); //Removes first element in que
    void execute(); //Prints and removes first element in que

    Queue(Queue const& rhs);
    Queue operator = (Queue const& rhs);
    Queue(Queue &&rhs);
    Queue operator = (Queue &&rhs);

private:
    struct Task
    {
        ~Task();
    	std::string task;
    	Task* next;
    };
    Task* first;

};
#endif
