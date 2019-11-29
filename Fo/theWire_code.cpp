#include <iostream>
using namespace std;

int decode(char const input);

int main(int argc, char const *argv[])
{
    cout << "Mata in kodat medelande: ";
    char input{};
    while (cin >> input)
    {
        cout << decode(input);
    }
    return 0;
}

int decode(char const input)
{
    if (input == '5' || input == '0')
    {
        return ('5' - (int)input);
    }
    else
    {
        return (58 - (int)input);   //58 är asscikoden efter 9 i ascii
    }
}
