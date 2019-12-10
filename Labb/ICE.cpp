#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main()
{
    cout << "-------------------" << endl;

    random_device rnd;
    uniform_int_distribution<int> dist(5, 15);

    vector<int> rndNumbers;

    for (int i{0}; i <= 15; i++)
    {
        for (int u{0}; u <= 9; u++)
        {
            int rng{dist(rnd)};
            rndNumbers.push_back(rng);
            if (rndNumbers.at(u) == 0)
                cout << "v ";
            if (rndNumbers.at(u) > 0)
                cout << "| ";
            if (rndNumbers.at(u) < 0)
                cout << "  ";
            rndNumbers.at(u) -= 1;  
        }
        cout << endl;
    }
    return 0;
}


