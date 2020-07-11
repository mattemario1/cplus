#include "hero.h"

vector<Hero> GetHeroRegister(ifstream& in_file);
void WriteToFile(vector<Hero> &heros, string fileName);
vector<Hero> AddToHeroRegister(vector<Hero> &heroRegister, Hero hero);
vector<Hero> FindMatchingHeros(int in, vector<Hero> heros);
