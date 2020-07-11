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

vector<int> GetInterests(string line);
Specie ToSpecie(string value);
string FromSpecie(Specie value);
EyeColor ToEyeColor(string value);
string FromEyeColor(EyeColor value);
Hero GetNewHero(string line);
