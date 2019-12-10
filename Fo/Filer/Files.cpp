#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile{"A.txt"};   //kan heta vad som hälst
                                //gör infile.open("A.txt"); sammtidigt

    if (!infile)                //if (infile.fail()) går också
    {
        cout << "Error file could not be read" << endl;
        return 1;
    }
    int x;
    char c;
    infile >> x >> c;
    string word;
    cout << word << endl;
    infile.close();

    ofstream outfile{"B.txt"};
    if (!outfile)
    {
        cout << "Error, Can't write" << endl;
        return 2;
    }
    outfile << "Tjena" << endl; //kommer skriva över
    outfile.close();
    //kan skriva och läsa om man skriver fstream file{"A.txt", fstream::in}
    return 0;
}
