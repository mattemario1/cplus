#include "queue.h"

using namespace std;

int main()
{
    Queue queue{};
    for(int i{}; i < 5; ++i)
    {
	queue.enqueue("task" + to_string(i));
    }
    cout << queue.to_string() << endl;
    for(int i{}; i < 2; ++i)
    {
	queue.execute();
    }
    queue.execute();
    cout << queue.to_string() << endl;


}
