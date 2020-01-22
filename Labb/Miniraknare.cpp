#include <iostream>

using namespace std;

int factorial (int n);
int add(int a, int b);
double add(double a, double b);
double add(double a, int b);
void swap(double &a, int &b);

int main(int argc, char const *argv[])
{
    double doubleValue1{};
    double doubleValue2{};
    int intValue1{};
    int intValue2{};
    int input;
    bool b = true;


    while (b)
    {
        cout << "1. Beräkna n fakultet: " << endl;
        cout << "2. Addera två heltal: " << endl;
        cout << "3. Addera ett heltal och ett flyttal: " << endl;
        cout << "4. Addera ett flyttal och ett heltal:  " << endl;
        cout << "5. Addera två flyttal: " << endl;
        cout << "6. Byt plats:"  << endl;

        cin >> input;
        switch (input) {
            case 1:
                cout << "mata in n: ";
                cin >> intValue1;
                cout << "= " << factorial(intValue1) << endl;
                break;
            case 6:
                b = false;
                break;
        }
    }


    cout << "Addera två heltal: ";
    cin >> intValue1;
    cin >> intValue2;
    cout << "= " << add(intValue1, intValue2) << endl;


    cout << "Addera ett heltal och ett flyttal: ";
    cin >> intValue1;
    cin >> doubleValue1;
    cout << "= " << add(doubleValue1, intValue1) << endl;

    cout << "Addera ett flyttal och ett heltal: ";
    cin >> doubleValue1;
    cin >> intValue1;
    cout << "= " << add(doubleValue1, intValue1) << endl;

    cout << "Addera två flyttal: ";
    cin >> doubleValue1;
    cin >> doubleValue2;
    cout << "= " << add(doubleValue1, doubleValue2) << endl;

    cout << "Byt plats på heltal och flyttal: "  << endl;
    cin >> intValue1;
    cin >> doubleValue1;
    swap(doubleValue1, intValue1);
    cout << intValue1 << " " << doubleValue1 << endl;

    return 0;
}


int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

double add(double a, int b)
{
    return a+b;
}

int add(int a, int b)
{
    return a+b;
}

double add(double a, double b)
{
    return a+b;
}

void swap(double &a, int &b)
{
    double c{a};
    a = b;
    b = c;
}
