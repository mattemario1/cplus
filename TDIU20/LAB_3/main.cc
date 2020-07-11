
using namespace std;

#include "circuit_simulator.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        cout << "Ogiltigt antal argument!" << endl;
        return 1;
    }

    int iterations{};
    int rows{};
    int voltage{};
    double time{};

    try {
        iterations = stoi(string(argv[1]));
        rows = stoi(string(argv[2]));
        time = stod(string(argv[3]));
        voltage = stoi(string(argv[4]));
    }
    catch (exception const &ex) {
        cout << "Ogiltigt värde upptäktes: " << ex.what() << endl;
        return 1;
    }

    circuit net{};
    connection p{};
    connection n{};
    connection q124{};
    connection q23{};
    net.add_con(p, "p");
    net.add_con(n, "n");
    net.add_con(q124, "q124");
    net.add_con(q23, "q23");
    net.add_bat("Bat", voltage, "n", "p");
    net.add_res("R1", 6.0, "p", "q124");
    net.add_res("R2", 4.0, "q124", "q23");
    net.add_res("R3", 8.0, "q23", "n");
    net.add_res("R4", 12.0, "q124", "n");

    cout << "  Krets 1: " << endl;
    net.simulate(iterations, rows, time);

    cout << endl;

    circuit net1{};
    connection n1{};
    connection p1{};
    connection l{};
    connection r{};
    net1.add_con(p1, "p1");
    net1.add_con(n1, "n1");
    net1.add_con(l, "l");
    net1.add_con(r, "r");
    net1.add_bat("Bat", voltage, "n1", "p1");
    net1.add_res("R1", 150.0, "p1", "l");
    net1.add_res("R2", 50.0, "p1", "r");
    net1.add_res("R3", 100.0, "r", "l");
    net1.add_res("R4", 300.0, "l", "n1");
    net1.add_res("R4", 250.0, "r", "n1");

    cout << "  Krets 2: " << endl;
    net1.simulate(iterations, rows, time);

    cout << endl;

    circuit net2{};
    connection n2{};
    connection p2{};
    connection l1{};
    connection r1{};
    net2.add_con(p2, "p2");
    net2.add_con(n2, "n2");
    net2.add_con(l1, "l1");
    net2.add_con(r1, "r1");
    net2.add_bat("Bat", voltage, "n2", "p2");
    net2.add_res("R1", 150.0, "p2", "l1");
    net2.add_res("R2", 50.0, "p2", "r1");
    net2.add_cond("C3", 1.0, "r1", "l1");
    net2.add_res("R4", 300.0, "l1", "n2");
    net2.add_cond("C5", 0.75, "r1", "n2");

    cout << "  Krets 3: " << endl;
    net2.simulate(iterations, rows, time);

    return 0;
}
