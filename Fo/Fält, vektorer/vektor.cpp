#include <iostream>
#include <vector>
using namespace std;

void add_to_vector (vector<int> & v, int const value);

int main(int argc, char const *argv[])
{
    vector <int> v_1;
    vector <int> v_2{1, 2, 3, 4};
    vector <int> v_3{v_2};
    v_2.at(3) = 5;  //sista värdet i v_2 blir 5
    v_2[10] = 10;     går att göra men borde inte göras
    for (int i{}; i < v_2.size(); ++i)
    {
        cout << v_2.at(i) << endl;
    }

    add_to_vector(v_2, 5)   //lägger till 5 på alla värden i v_2

    v_2.push_back(10);  //lägger till ett värde i slutet av vetorn
    v_2.clear();    //tar bort allt
    v_2.erase(begin(v_2)); //tar bort första i v_2
    v_2.erase(begin(v_2), begin(v_2) + 3);  //tar bort för första till den tredje i v_2

    return 0;
}

add_to_vector (vector<int> &v, int const value)
{
    for(int &x: v)     //x antar alla värden från v
    {
        x += value;
    }
}
