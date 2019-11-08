#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;
int main()
{
     int a, b, c, d, e;
    cout << "Skriv in ett heltal: ";
    cin >> a;
    cout << "Du skrev in talet: " << a << endl << '\n';

    cout << "Skriv in fem heltal: ";
    cin >> a >> b >> c >> d >> e;
    cout << "Du skrev in talen: " << setw(2) << a << b << c << d << e << endl << '\n';
    
}
