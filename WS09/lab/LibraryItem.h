/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-22
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>

namespace seneca {
    class LibraryItem {
        char* m_title {};
        int m_year {};

        void copyName(const char* title);

    public:
        LibraryItem();
        LibraryItem(const char* title, const int year);

        LibraryItem(const LibraryItem& other);
        LibraryItem& operator=(const LibraryItem& other);
        virtual ~LibraryItem();
        
        virtual std::ostream& display(std::ostream& ostr = std::cout) const;
    };
}

#endif
