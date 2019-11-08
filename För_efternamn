#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main()
{
	string f_name, l_name, hobby;
	cout << "Mata in förnamn och efternamn: ";
	cin >> f_name >> l_name;
	cout << "Mata in hobby: ";
	cin.ignore(1000, '\n');	//???
	getline(cin, hobby);	//Första är vad ska den läsa från och andra är vad den ska läsa in till.
	char c;
	int num{};
	while(cin.get(c))
	{
		if(isspace(c))
		{
			++num;
		}
	}
	cout << "Du skrev in. " << num << "vita tecken" << endl;
}