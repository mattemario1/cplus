using namespace std;
#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    string input;
    int numOfWords = 0;
    string shortestWord;
    int shortestWordLength = numeric_limits<int>::max();
    string longestWord;
    int longestWordLength = 0;
    int averageLength;
    int totalLength = 0;

    cout << "Mata in texten: " << endl;
    while (cin >> input)
    {
        if (input.empty())
        {
            cout << "No words found!" << endl;
        }
        else
        {
            numOfWords++;
            if (input.length() <= shortestWordLength)
            {
                shortestWord = input;
                shortestWordLength = input.length();
            }
            if (input.length() >= longestWordLength)
            {
                longestWord = input;
                longestWordLength = input.length();
            }
            totalLength += input.length();
        }
    }
    averageLength = totalLength/numOfWords;

    cout << "Texten innehöll " << numOfWords << " ord." << endl;
    cout << "Det kortaste ordet var \"" << shortestWord <<"\" med " << shortestWordLength << " bokstäver." << endl;
    cout << "Det längsta ordet var \"" << longestWord <<"\" med " << longestWordLength << " bokstäver." << endl;
    cout << "Medelordlängden var " << averageLength << " bokstäver." << endl;
}
