using namespace std;
#include <iostream>
#include <iomanip>

int main()
{
    int i;
    float f;
    char c;
    string s;

    cout << "Skriv in ett heltal: ";
    cin >> i;
    cout << "Du skrev in talet: " + to_string(i) << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in fem heltal: ";
    cin >> i;
    cout << "Du skrev in talet: " + to_string(i) + " ";
    cin >> i;
    cout << to_string(i) + " ";
    cin >> i;
    cout << to_string(i) + " ";
    cin >> i;
    cout << to_string(i) + " ";
    cin >> i;
    cout << i << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett flyttal: ";
    cin >> f;
    cout << "Du skrev in flyttalet: ";
    cout << fixed;
    cout << setprecision(3);
    cout << f << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett heltal och ett flyttal: ";
    cin >> i;
    cin >> f;
    cout << "Du skrev in heltalet:";
    cout << setfill(' ') << setw(10) << right << i << endl;
    cout << "Du skrev in flyttalet:";
    cout << setfill(' ') << setw(9) << right;
    cout << fixed << setprecision(4) << f << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett flyttal och ett heltal: ";
    cin >> f;
    cin >> i;
    cout << "Du skrev in heltalet:";
    cout << setfill('-') << setw(10) << right;
    cout << i << endl;
    cout << "Du skrev in flyttalet:";
    cout << setfill('-') << setw(9) << right;
    cout << fixed << setprecision(4) << f << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett tecken: ";
    cin >> c;
    cout << "Du skrev in tecknet: ";
    cout << c << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett ord: ";
    cin >> s;
    cout << "Du skrev in ordet: " + s << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett heltal och ett ord: ";
    cin >> i;
    cin >> s;
    cout << "Du skrev in talet |" + to_string(i) + "| och ordet |" + s + "|." << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett tecken och ett ord: ";
    cin >> c;
    cin >> s;
    cout << "Du skrev in \"" + s + "\" och \'" + c + "\'." << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett ord och ett tecken: ";
    cin >> s;
    cin >> c;
    cout << "Du skrev in \"" + s + "\" och \'" + c + "\'." << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in en textrad: ";
    getline(cin, s);
    cout << "Du skrev in \"" + s + "\"." << endl;

    cout << "Skriv in en till rad text: ";
    getline(cin, s);
    cout << "Du skrev in \"" + s + "\"." << endl;

    cout << "Skriv en rad med tre ord: ";
    cin >> s;
    cout << "Du skrev in \"" + s + "\", ";
    cin >> s;
    cout <<  "\"" + s + "\" och ";
    cin >> s;
    cout << "\"" + s + "\"." << endl;


    return(0);
}
