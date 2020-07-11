using namespace std;
#include <iostream>
#include <iomanip>
#include <cctype>

int main()
{
    string input;
    char c;
    int numOfSpaces = 0;
    int numOfAlphabetes = 0;
    int numOfNumerics = 0;
    int numOfChars = 0;

    while(cin.get(c))
    {
        if (isalpha(c))
        {
            numOfAlphabetes++;
        }
        if (isdigit(c))
        {
            numOfNumerics++;
        }
        if (isspace(c))
        {
            numOfSpaces++;
        }
        numOfChars++;
    }

    cout << "Indata innehöll:" << endl;
    cout << "Alfabatiska tecken: " << numOfAlphabetes << endl;
    cout << "Siffertecken......: " << numOfNumerics << endl;
    cout << "Vita tecken.......: " << numOfSpaces << endl;
    cout << "Tecken totalt.....: " << numOfChars << endl;

    return 0;
}
