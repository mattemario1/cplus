#include <iostream>
#include "book_handling.h"
using namespace std;

void get (Book_Type const &book)
{
    getline(cin, book.title);
    getline(cin, book.author);
    getline(cin, book.genre);
    cin << book.pages;
}

bool operator < (Book_Type const &left, Book_Type const &right)
{
    if(left.title < right.title)
    {
        return true;
    }
    else
    {
        return false;
    }
}
