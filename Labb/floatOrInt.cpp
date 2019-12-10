#include <iostream>
#include <cmath>
using namespace std;
// SÄTT IN DIN KOD HÄR NEDAN
struct num_type
{
    int Integer{};
    float Float{};
    bool intOrFloat{};
}

num_type get (input)
{
    float temp{};
    cin >> temp;
    
}

// DU SKALL INTE ÄNDRA I DETTA HUVUDPROGRAM
int main()
{
  num_type n1, n2;
  cout << "Mata in ett tal: ";
  get(n1);
  cout << "Mata in ett till tal: ";
  get(n2);
  cout << "Summan av dessa tal är ";
  num_type n3;
  n3 = add(n1, n2);
  if (n3.is_int)
  {
    cout << "heltalet ";
  }
  else
  {
    cout << "flyttalet ";
  }
  put(n3);
  cout << "." << endl;
  
  return 0;
}
