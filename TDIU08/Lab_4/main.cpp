#include "heroRegister.h"

int main()
{
    char userChoice;
    int interest;
    ifstream in_file {"REGISTER.TXT"};
    vector<Hero> heroRegister = GetHeroRegister(in_file);
    in_file.close();
    vector<Hero> matchingHeros;
    string heroInput;

    cout << "Välkommen till Hero Match­Maker 3000!\nVälj ett alternativ:\n  A) Mata in en ny hjälte\n  B) Hitta matchande hjältar" << endl;
    cout << "Välj ett alternativ: ";
    cin >> userChoice;
    cout << endl;

    switch (userChoice)
    {
        case 'A':
        {
            cout << "Mata in en ny hjälte: ";
            cin.ignore(256,'\n');
            getline(cin, heroInput);
            Hero newHero = GetNewHero(heroInput);
            vector<Hero> newRegister = AddToHeroRegister(heroRegister, newHero);
            WriteToFile(newRegister, "REGISTER.TXT");

            break;
        }
        case 'B':
        {
            int counter{0};
            cout << "Mata in dina intressen: ";
            while (cin >> interest && interest != 0 && counter <= 10)
            {
                counter++;
                if (interest >= 1 && interest <= 15)
                {
                    vector<Hero> temp = FindMatchingHeros(interest, heroRegister);
                    matchingHeros.insert( matchingHeros.end(), temp.begin(), temp.end() );
                }
            }

            WriteToFile(matchingHeros, "RESULTAT.TXT");
            cout << "Klart! Nu finns de matchande hjältarna på filen RESULTAT.TXT" << endl;
            break;
        }
        default:
            cout << "Fel val prova igen!" << endl;
            break;
    }

    return 0;
}
