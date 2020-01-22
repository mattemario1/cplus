#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

enum Specie
{
    Human, Elf, Orc, Halfling, Ogre, Lizardman
};

enum EyeColor
{
    Blue, Green, Brown, Gray, Yellow, Red, Black, Crazy
};

struct Hero
{
    string name;
    int age;
    char sex;
    int weight;
    string hairColor;
    Specie specie;
    EyeColor eyeColor;
    vector<int> interests;
};

struct less_than_key
{
    inline bool operator() (Hero &h1, Hero &h2)
    {
        return (h1.name < h2.name);
    }
};

vector<Hero> GetHeroRegister(ifstream& in_file);
vector<int> GetInterests(string line);
Specie ToSpecie(string value);
string FromSpecie(Specie value);
EyeColor ToEyeColor(string value);
string FromEyeColor(EyeColor value);
vector<Hero> FindMatchingHeros(int in, vector<Hero> heros);
void WriteToFile(vector<Hero> &heros, string fileName);
Hero GetNewHero(string line);
vector<Hero> AddToHeroRegister(vector<Hero> &heroRegister, Hero hero);

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

// vector<Hero> AddToHeroRegister(vector<Hero>& heroRegister, Hero hero)
// {
//     size_t size{heroRegister.size()};
//     for (int i = 0; i < size; i++)
//     {
//         cout << "size: " << size << "& i= " << i << endl;
//         if (hero.name <= heroRegister[i].name)
//         {
//             cout << "ska in före: " << heroRegister[i].name << endl;
//             heroRegister.insert(heroRegister.begin() + i, hero);
//             return heroRegister;
//         }
//         else if (i == size - 1)
//         {
//             cout << "ska in på slutet" << endl;
//             heroRegister.push_back(hero);
//             return heroRegister;
//         }
//     }
//     cout << "return nu!" << endl;
//     return heroRegister;
// }

vector<Hero> AddToHeroRegister(vector<Hero>& heroRegister, Hero hero)
{
    heroRegister.push_back(hero);
    cout << "hero added!" << endl;
    sort(heroRegister.begin(), heroRegister.end(), less_than_key());
    cout << "list sorted" << endl;

    return heroRegister;
}

vector<Hero> FindMatchingHeros(int interest, vector<Hero> heros)
{
    vector<Hero> matchingHeros;

    for (Hero hero : heros)
    {
        if (find(hero.interests.begin(), hero.interests.end(), interest) != hero.interests.end())
        {
            matchingHeros.push_back(hero);
            cout << "found hero " << hero.name << " with interest: " << interest << endl;
        }
    }

    return matchingHeros;
}

void WriteToFile(vector<Hero>& heros, string fileName)
{
    ofstream out_file{fileName};
    cout << "filename: " << fileName << endl;

    for (Hero hero : heros)
    {
        out_file << hero.name;
        out_file << " ";
        out_file << hero.age;
        out_file << " ";
        out_file << hero.sex;
        out_file << " ";
        out_file << hero.weight;
        out_file << " ";
        out_file << FromSpecie(hero.specie);
        out_file << " ";
        out_file << FromEyeColor(hero.eyeColor);
        out_file << " ";
        for (int interest : hero.interests)
        {
            out_file << interest;
            out_file << " ";
        }
        out_file << endl;
    }

    out_file.close();
}

Hero GetNewHero(string line)
{
    string interests;
    stringstream ss(line);
    Hero hero;
    string specie{""};
    string eyeColor{""};

    while(ss >> hero.name)
    {
        ss >> hero.age;
        ss >> hero.sex;
        ss >> hero.weight;
        ss >> hero.hairColor;
        ss >> specie;
        hero.specie = ToSpecie(specie);
        ss >> eyeColor;
        hero.eyeColor = ToEyeColor(eyeColor);
        getline(ss, interests);
        hero.interests = GetInterests(interests);
    }

    return hero;
}

vector<Hero> GetHeroRegister(ifstream& in_file)
{
    string line;
    Hero hero;
    vector<Hero> heros{};
    string specie;
    string eyeColor;

    while(in_file >> hero.name)
    {
        in_file >> hero.age;
        in_file >> hero.sex;
        in_file >> hero.weight;
        in_file >> hero.hairColor;
        in_file >> specie;
        hero.specie = ToSpecie(specie);
        in_file >> eyeColor;
        hero.eyeColor = ToEyeColor(eyeColor);
        getline(in_file, line);
        hero.interests = GetInterests(line);
        heros.push_back(hero);
    }

    return heros;
}

vector<int> GetInterests(string line)
{
    vector<int> interests;
	stringstream ss(line);
    int n{};
    while(ss >> n)
    {
        interests.push_back(n);
    }

    return interests;
}

Specie ToSpecie(string value)
{
    // Human, Elf, Orc, Halfling, Ogre, Lizardman
    string toLowerValue;
    for (auto c : value)
    {
        toLowerValue += tolower(c);
    }

    if (toLowerValue == "human") { return Human; }
    else if (toLowerValue == "elf") { return Elf; }
    else if (toLowerValue == "orc") { return Orc; }
    else if (toLowerValue == "halfling") { return Halfling; }
    else if (toLowerValue == "ogre") { return Ogre; }
    else if (toLowerValue == "lizardman") { return Lizardman; }
}

string FromSpecie(Specie value)
{
    switch (value)
    {
        case Human:
            return "Human";
        case Elf:
            return "Elf";
        case Orc:
            return "Orc";
        case Halfling:
            return "Halfling";
        case Ogre:
            return "Ogre";
        case Lizardman:
            return "Lizardman";
        default:
            return "";
    }
}

EyeColor ToEyeColor(string value)
{
    // Blue, Green, Brown, Gray, Yellow, Red, Black, Crazy
    string toLowerValue;
    for (auto c : value)
    {
        toLowerValue += tolower(c);
    }

    if (toLowerValue == "blue") { return Blue; }
    else if (toLowerValue == "green") { return Green; }
    else if (toLowerValue == "brown") { return Brown; }
    else if (toLowerValue == "gray") { return Gray; }
    else if (toLowerValue == "yellow") { return Yellow; }
    else if (toLowerValue == "red") { return Red; }
    else if (toLowerValue == "black") { return Black; }
    else if (toLowerValue == "crazy") { return Crazy; }
}

string FromEyeColor(EyeColor value)
{
    switch (value)
    {
        case Blue:
            return "Blue";
        case Green:
            return "Green";
        case Brown:
            return "Brown";
        case Gray:
            return "Gray";
        case Yellow:
            return "Yellow";
        case Red:
            return "Red";
        case Black:
            return "Black";
        case Crazy:
            return "Crazy";
        default:
            return "";
    }
}
