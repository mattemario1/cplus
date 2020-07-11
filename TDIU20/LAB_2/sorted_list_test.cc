using namespace std;
#include <string>
#include <iostream>
#include <ostream>
#include <sstream>

#include "catch.hpp"
#include "sorted_list.h"



/*
TODO:
Dela upp test_casen efter vad ni testar. Inte okej att lägga allt i samma. --KLAR
 */


TEST_CASE ("Basic input")
{
    sorted_list l;
    stringstream ss;

    l.insert(5);
    l.insert(4);
    l.insert(2);
    l.insert(3);
    l.insert(6);
    l.insert(0);
    l.insert(9);

    l.print_list(ss);

    CHECK(ss.str() == "{0, 2, 3, 4, 5, 6, 9}");
    CHECK(l.length() == 7);
    CHECK(l.at(0) == 0);
    CHECK(l.at(1) == 2);
    CHECK(l.at(5) == 6);
    CHECK_THROWS(l.at(9));
}


TEST_CASE ("Remove function")
{
    sorted_list l{0,2,3,4,5,6,9};
    stringstream ss1;
    stringstream ss2;
    CHECK(l.length() == 7);


    //TODO: Räcker inte att köra remove 1 gång för att anse att man testat den -- Klar
    l.remove(2);
    CHECK(l.length() == 6);
    l.print_list(ss1);
    CHECK(ss1.str() == "{0, 2, 4, 5, 6, 9}");
    l.remove(0);
    CHECK(l.length() == 5);
    l.print_list(ss2);
    CHECK(ss2.str() == "{2, 4, 5, 6, 9}");
    CHECK_THROWS(l.remove(10));
}


TEST_CASE ("print")
{
    stringstream ss2;
    sorted_list l2{7, 8, 9, 10};
    l2.print_list(ss2);
    CHECK(ss2.str() == "{7, 8, 9, 10}");

    sorted_list l1{l2};
    stringstream ss3;
    l1.print_list(ss3);
    CHECK(ss3.str() == "{7, 8, 9, 10}");
}

TEST_CASE ("Copy list")
{
    //TODO: Detta testar inte =operatorn utan konstruktorn kommer kallas. Måste först skapa l5 sen sätta l5 = l4; --klar
    sorted_list l4{};
    sorted_list l5{};
    l4 = l5;
    stringstream ss4;
    l5.print_list(ss4);
    CHECK(ss4.str() == "{}");

//TODO: Ni ska testa att de inte är kopplade och att det blev en djup kopia. -- klar

    sorted_list l1{5, 6, 7};
    sorted_list l6{1, 3, 2};
    l1 = l6;
    stringstream ss5;
    l1.print_list(ss5);
    CHECK(ss5.str() == "{1, 2, 3}");

    sorted_list l16{0, 67, 12};
    sorted_list l11{l16};

    stringstream ss15;
    stringstream ss16;
    l11.print_list(ss15);
    l16.print_list(ss16);
    CHECK(ss15.str() == "{0, 12, 67}");
    CHECK(ss16.str() == "{0, 12, 67}");

    l11.remove(1);
    l16.remove(2);

    stringstream ss17;
    stringstream ss18;
    l11.print_list(ss17);
    l16.print_list(ss18);
    CHECK(ss17.str() == "{0, 67}");
    CHECK(ss18.str() == "{0, 12}");
}

//TODO Testar inte move assignment vad jag kan se -- KLAR
TEST_CASE ("MOVE_LIST")
{
    sorted_list l16{3, 4, 5, 6};
    sorted_list l21{4, 91, 23};

    sorted_list l17{move(l16)};
    sorted_list l20{1, 4, 2};
    l20 = std::move(l21);

    stringstream ss115;
    l16.print_list(ss115);

    stringstream ss16;
    l17.print_list(ss16);

    stringstream ss19;
    l20.print_list(ss19);

    CHECK(ss115.str() == "{}");
    CHECK(ss16.str() == "{3, 4, 5, 6}");
    CHECK(ss19.str() == "{4, 23, 91}");

    sorted_list l18{};
    sorted_list l19{move(l16)};
    stringstream ss17;
    stringstream ss18;
    l18.print_list(ss17);
    l19.print_list(ss18);
    CHECK(ss17.str() == "{}");
    CHECK(ss18.str() == "{}");

    sorted_list lista{2, 5, 7};

    for(sorted_list::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        cout << *it << endl;
    }
}
