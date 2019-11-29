// #string <string>
//
// struct Book_Type
// {
//     std::string titel;
//     std::string genre;
//     std::string author;
//     int pages;
// };  //glöm inte semicolon
//
// void put(Book_Type const &book);
// void get(Book_Type &book);
// bool operator < (Book_Type const &left, Book_Type const &right);

//  ^ är i packetet book_handling.h

#include <iostream>
#include "book_handling.h"  //egna paket
using namespace std;

int main()
{
    Book_Type b_1{};
    Book_Type b_2{"Ada 95", "Fiction", "Torbjörn Jonsson", 666};
    Book_Type b_3{"Harry Potter 1", "sci-fi", "JK Rowlingson"};     //Kan utelämna det längst till höger

    b_2.author = "Erik Nilsson";
    b_3 = b_2;

    put(b_3);
    get(b_2);
    if(b_2 < b_3)
    {
        cout << "b_2 mindre" << endl;
    }
    return 0;
}
//#include <iostream>
//#include "book_handling.h"
//using namespace std;
// void get (Book_Type const &book)
// {
//     getline(cin, book.title);
//     getline(cin, book.author);
//     getline(cin, book.genre);
//     cin << book.pages;
// }
//
// bool operator < (Book_Type const &left, Book_Type const &right)
// {
//     if(left.title < right.title)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// ^ är i filen book_handling.cc
