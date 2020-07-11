using namespace std;
#include <iostream>
#include <iomanip>

int main()
{
	double Start, End;

	cout << "Ange startvärde: ";
	cin >> Start;
	while (Start < -273.15)
	{
		cout << "Felaktigt startvärde!" << endl;
		cout << "Ange startvärde: ";
		cin >> Start;
	}

	cout << "Ange slutvärde: ";
	cin >> End;

	while (End < Start)
	{
		cout << "Felaktigt slutvärde!" << endl;
		cout << "Ange slutvärde: ";
		cin >> End;
	}

	cout << "Celsius     Kelvin  Farenheit   Réaumur" << endl;
	cout << setw(39) << setfill('-') << "-" << endl;
	
	for (double i = Start; i <= End; i++)
	{
		cout << setw(7) << setfill(' ') << fixed << setprecision(0) << i;
		cout << setw(11) << fixed << setprecision(2) << i + 273.15;
		cout << setw(11) << i * 1.8 + 32;
		cout << setw(10) << i * 0.8 << endl;
	}

	return 0;
}
