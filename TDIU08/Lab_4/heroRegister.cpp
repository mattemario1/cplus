#include "heroRegister.h"

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
        out_file << hero.hairColor;
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
        cin.ignore(256,'\n');
    }

    out_file.close();
}

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
