#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct Participant
{
    string firstName;
    string lastName;
    string clubName;
};

vector<string> GetInput(string& line)
{
    vector<string> words;
    string delimiter = " ";
    size_t pos = 0;
    string token;

    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        words.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    words.push_back(line);

    return words;
}

Participant GetParticipant(const vector<string> words)
{
    Participant participant;
    for (int i = 0; i < words.size(); i++)
    {
        if (i == 0)
        {
            participant.firstName = words[i];
        }
        else if (i == 1)
        {
            participant.lastName = words[i];
        }
        else if (i == words.size() - 1)
        {
            participant.clubName += words[i];
        }
        else
        {
            participant.clubName += words[i] + " ";
        }
    }

    return participant;
}

void printStartList(const vector<Participant> participants)
{
    cout << "\n";
    cout << "Startlista:" << endl;
    cout << "Startnummer Förnamn Efternamn Klubb" << endl;
    for (int i = 0; i < participants.size(); i++)
    {
        cout << i + 1 << " ";
        cout << participants[i].firstName + " ";
        cout << participants[i].lastName + " ";
        cout << participants[i].clubName << endl;
    }
}

void shuffleItems(vector<Participant>& participants){
    srand(time(0));
    for (int i = 1; i < 1000; i++)
    {
        int n1 = rand() % participants.size();
        int n2 = rand() % participants.size();
        Participant temp = participants[n1];
        participants[n1] = participants[n2];
        participants[n2] = temp;
    }
}

int main()
{
    string line;
    vector<Participant> participants;

    cout << "Anmälning, mata in deltagare: " << endl;
    while (getline(cin, line))
    {
        vector<string> words = GetInput(line);
        if (!words.empty())
        {
            participants.push_back(GetParticipant(words));
        }
    }

    shuffleItems(participants);
    printStartList(participants);

    return 0;
}
