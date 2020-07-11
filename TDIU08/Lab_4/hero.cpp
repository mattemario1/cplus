#include "hero.h"

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
