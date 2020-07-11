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

void shuffleItems(vector<Participant>& participants)
{
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
    vector<Participant> participants;
    Participant participant;

    cout << "Anmälning, mata in deltagare: " << endl;


    while(cin >> participant.firstName)
    {
        cin >> participant.lastName;
        getline(cin, participant.clubName);

        participants.push_back(participant);
    }
    shuffleItems(participants);
    printStartList(participants);

    return 0;
}
