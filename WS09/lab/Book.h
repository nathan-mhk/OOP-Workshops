/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-22
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

namespace seneca {
    class Book : public LibraryItem {
        char* m_author {};

        void copyAuthor(const char* author);

    public:
        Book(const char* title, const int year, const char* author);

        Book(const Book& other);
        Book& operator=(const Book& other);
        virtual ~Book();

        virtual std::ostream& display(std::ostream& ostr = std::cout) const;
        bool operator>(const Book& other) const;
    };
}

#endif
