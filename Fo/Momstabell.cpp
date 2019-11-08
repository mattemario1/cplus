#include <iostream>

using namespace std;	//Säger att man vill använda paketet std.
int main()
{
	double Fp{}; //Ger värdet 0.0 till decimalen Fp
	cout << "Mata in första pris (Mellan 0 och 100): ";
	cin >> Fp; 
	    while (Fp < 0.0 || Fp > 100.0)	// || är samma som or
	{
		cout << "Error: Mata in flrsta pris igen ";
		cin >> Fp;
	}
	double Lp{}, S{};
	do	//Det är en loop
	{
		cout << "Mata in sista pris (minst första pris): ";
		cin >> Lp;
	} while (Lp < Fp);
	cout << "Mata in steglängd";
	for(;;)
	{
		cin >> S;
		if (S > 0.0)
		{
			break;
		}
	}
	double M{};
	M = 25.0;
	
	int n;
	n = float ((Lp - Fp) / S + 1.0);

    cout << n;
    cout << M;
}
