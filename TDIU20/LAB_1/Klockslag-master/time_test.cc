#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Time.h"

using namespace std;

// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ("Default constructor")
{
    Time t;

    CHECK(t.get_hour() == 0);
    CHECK(t.get_minute() == 0);
    CHECK(t.get_second() == 0);
}

// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases

TEST_CASE ( "Constructor with numeric arguments" )
{
    Time t{12,13,14};
    CHECK(t.get_hour() == 12);
    CHECK(t.get_minute() == 13);
    CHECK(t.get_second() == 14);
}

TEST_CASE ("Constructor with faulty argument")
{
    CHECK_THROWS( (Time{41,0,0}) );
    CHECK_THROWS( Time{0,99,0} );
    CHECK_THROWS( Time{0,0,99} );
    CHECK_THROWS( Time{24,60,99} );
}

TEST_CASE ("String constructor")
{
    Time t{"12:23:12"};
    CHECK(t.get_hour() == 12);
    CHECK(t.get_minute() == 23);
    CHECK(t.get_second() == 12);

    SECTION ("Throws as well")
    {
        CHECK_THROWS( Time{"02:11:74"} );
        CHECK_THROWS( Time{"25:11:74"} );
        CHECK_THROWS( Time{"02:76:23"} );
    }
}

TEST_CASE ("am or pm")
{
    Time t{12,12,31};
    CHECK_FALSE(t.is_am());
    CHECK(t.is_pm());
    Time t2{1,2,3};
    CHECK(t2.is_am());
    CHECK_FALSE(t2.is_pm());
}

//TODO Inte tillräckliga testfall. Testa tex om timmen och/eller minuten är större men sekunden mindre -- kanske fixad?!
TEST_CASE ("<= >= ! < > ==" )
{
    CHECK(Time{0,0,1} > Time{0,0,0});
    CHECK(Time{2,45,1} > Time{0,0,20});
    CHECK(Time{2,0,1} > Time{0,0,20});
    CHECK_FALSE(Time{0,1,1} < Time{0,0,20});
    CHECK_FALSE(Time{0,0,1} < Time{0,0,1});
    CHECK(Time{0,0,0} == Time{0,0,0});
    CHECK_FALSE(Time{0,0,1} == Time{0,0,0});
    CHECK(Time{20,5,5} == Time{20,5,5});
    CHECK(Time{0,0,1} != Time{0,0,0});
    CHECK_FALSE(Time{0,0,1} <= Time{0,0,0});
    CHECK(Time{0,0,0} >= Time{0,0,0});
    CHECK_FALSE(Time{23,0,1} <= Time{0,0,0});
}

TEST_CASE ("Convert to string" )
{
    CHECK( Time{12, 12, 12}.to_string()     ==    "12:12:12" );
    CHECK( Time{12, 1, 2}.to_string()       ==    "12:01:02" );
    CHECK( Time{22, 52, 2}.to_string()      ==    "22:52:02" );
    CHECK( Time{14, 33, 12}.to_string(true) == "02:33:12 pm" );
    CHECK( Time{12, 1, 12}.to_string(true)  == "12:01:12 pm" );
    CHECK( Time{0, 56, 12}.to_string(true)  == "12:56:12 am" );
}

TEST_CASE ("addition operator" )
{
    CHECK( (Time{2,4,1} + 1).to_string() == "02:04:02"  );
    CHECK( (Time{0,0,0} + 50).to_string() == "00:00:50" );
    CHECK( (Time{20,59,0} + 60).to_string() == "21:00:00");
    CHECK( (Time{2,4,1} + 1).to_string() == "02:04:02"  );
    CHECK( (Time{23,59,59} + 1).to_string() == "00:00:00"  );
    CHECK( (Time{0,0,0} + 86400).to_string() == "00:00:00" );
    CHECK( (Time{0,0,0} + 86400 * 5).to_string() == "00:00:00"  );
    CHECK( (Time{0,0,0} + 86400 * 3).to_string() == "00:00:00"  );
    CHECK( (Time{0,0,0} + 3600*24).to_string() == "00:00:00"  );
}

TEST_CASE ("subtraction operator" )
{
    CHECK( (Time{20,5,1} - 2).to_string() == "20:04:59"  );
    CHECK( (Time{0,0,0} - 1).to_string() == "23:59:59"  );
    CHECK( (Time{2,4,1} - 1).to_string() == "02:04:00"  );
    CHECK( (Time{2,4,0} - 1).to_string() == "02:03:59"  );
    CHECK( (Time{1,0,0} - 1).to_string() == "00:59:59"  );
    CHECK_FALSE( (Time{2,4,1} - 1).to_string() == "02:04:01"  );
    CHECK( (Time{0,0,0} - 86399).to_string() == "00:00:01"  );
    CHECK( (Time{0,0,0} - 86401 ).to_string() == "23:59:59"  );
    CHECK( (Time{0,0,0} - 3600*24).to_string() == "00:00:00"  );
    CHECK( (Time{0,0,0} - 3600*24*5).to_string() == "00:00:00"  );
}

// ----- FIXED
//TODO: Postfix increment ska returnera det omodifierade
//klockslaget. Prefix ska returnera klockslaget efter att de ha incrementerats. Se till att orginalet ändras även för
//postfix. Samma för --
/*

Exempel med int

int x{3};
cout << x++; 3
cout << x; 4
cout << ++x; 5
cout << x; 5

*/
TEST_CASE ("unär++ operator" )
{
    Time t01{20,5,1};
    Time t02{23,59,59};
    Time t03{0,0,0};

    CHECK( (++Time{0,0,0}).to_string() == "00:00:01"  );
    CHECK( (++Time{23,59,59}).to_string() == "00:00:00"  );
    CHECK( (++Time{13,59,59}).to_string() == "14:00:00"  );
    CHECK( (t03++).to_string() == "00:00:00"  );
    CHECK( (t03).to_string() == "00:00:01"  );
    CHECK( (t01++).to_string() == "20:05:01"  );
    CHECK( (t01).to_string() == "20:05:02"  );
    CHECK( (t02++).to_string() == "23:59:59"  );
    CHECK( (t02).to_string() == "00:00:00"  );
}

TEST_CASE ("unär-- operator")
{
    Time t11{0,0,1};
    Time t12{0,0,0};
    Time t13{23,0,0};

    CHECK( (--Time{0,0,1}).to_string() == "00:00:00"  );
    CHECK( (--Time{0,0,0}).to_string() == "23:59:59"  );
    CHECK( (t11--).to_string() == "00:00:01"  );
    CHECK( (t11).to_string() == "00:00:00"  );
    CHECK( (t12--).to_string() == "00:00:00"  );
    CHECK( (t12).to_string() == "23:59:59"  );
    CHECK( (t13--).to_string() == "23:00:00"  );
    CHECK( (t13).to_string() == "22:59:59"  );
}


TEST_CASE ("Conversion to string" )
{
    CHECK( string(Time{2,4,1}) == "02:04:01" );
}


TEST_CASE ("Output operator" )
{
    stringstream ss;
    SECTION("Simple output")
    {
        ss << Time{2,5,1};
        CHECK(ss.str() == "02:05:01");
    }
    SECTION("Chained output")
    {
        ss << Time{23,10,32} << "---";
        CHECK(ss.str() == "23:10:32---");
    }
    SECTION("Const time")
    {
        Time const t{23,23,23};
        ss << t;
        CHECK(ss.str() == "23:23:23");
    }
}

//TODO Ni bör testa chained input -- KVAR
//TODO Testa så att failflaggan sätts när den ska och att den inte sätts vid lyckad inläsning -- FIXED

TEST_CASE ("Input operator" )
{
    stringstream ss1{"02:05:01"};
    stringstream ss2{"32:52:01"};
    stringstream ss3{"13:41:11"};
    Time t1{};
    Time t2{};
    Time t3{};

    SECTION("Simple input")
    {
        ss1 >> t1;
        CHECK_FALSE(ss1.fail());
        CHECK(t1.to_string() == "02:05:01");
        ss2 >> t1;
        CHECK(ss2.fail());
    }
    stringstream ss4{"10:10:10 23:23:23"};
    stringstream ss5{"13:40:05"};
    stringstream ss6{"10:20:30 23:23:23"};
    stringstream ss7{"10:21:30 15:30"};
    Time t4{1,2,3};
    string s{};

    SECTION("Chained output")
    {
        ss4 >> t1 >> t2;
        CHECK(t1.to_string() == "10:10:10");
        CHECK(t2.to_string() == "23:23:23");

        ss5 >> t3 >> t4;
        CHECK(t3.to_string() == "13:40:05");
        CHECK(t4.to_string() == "01:02:03");

        ss6 >> t1 >> s;
        CHECK(t1.to_string() == "10:20:30");
        CHECK(s == "23:23:23");

        ss7 >> t1 >> t2;
        CHECK(t1.to_string() == "10:21:30");
        CHECK(ss7.fail());        
    }
}
