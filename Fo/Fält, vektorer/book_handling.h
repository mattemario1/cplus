#include <string>

struct Book_Type
{
    std::string titel;
    std::string genre;
    std::string author;
    int pages;
};  //glöm inte semicolon

void put(Book_Type const &book);
void get(Book_Type &book);
bool operator < (Book_Type const &left, Book_Type const &right);

//  ^ är i packetet book_handling.h
