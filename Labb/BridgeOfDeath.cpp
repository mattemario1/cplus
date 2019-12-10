#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream questions ("QUESTIONS.TXT");
    string question;
    vector <string> allQuestions;



    while (getline(questions, question))
    {
        allQuestions.push_back(question);
    }

    random_device rnd;
    mt19937 g(rnd());
    shuffle(allQuestions.begin(), allQuestions.end(), g);

    for (int i{0}; i < allQuestions.size(); i++)
    {
        cout << i+1 << ". What... ";
        cout << allQuestions.at(i) << endl;
    }
    questions.close();
    return 0;
}
