#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream message ("MESSAGE2.TXT");
    ifstream reference ("REFERENCE2.TXT");
    int wordNr{};
    int letterNr{};
    string secretMessage;
    while(message >> wordNr)
    {
        message >> letterNr; 
        string temp{};
        for (int i{0}; i < wordNr; i++)
        {
            reference >> temp;
        }
        if (letterNr == 0)
        {
            cout << " ";
        }
        else
        {
            char letter{temp.at(letterNr - 1)};
            cout << letter;
        }
        reference.seekg(0); //Får den att börja från början av reference igen
    }
    cout << endl;
    reference.close();
    message.close();   
    return 0;
}
