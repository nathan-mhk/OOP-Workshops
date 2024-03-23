/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-22
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "LibraryItem.h"
#include <cstring>

namespace seneca {
    void LibraryItem::copyName(const char* title) {
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
    }

    LibraryItem::LibraryItem() : m_title(nullptr), m_year(0) {}

    LibraryItem::LibraryItem(const char* title, const int year) : m_year(year) {
        copyName(title);
    }

    LibraryItem::LibraryItem(const LibraryItem& other) : m_year(other.m_year) {
        copyName(other.m_title);
    }

    LibraryItem& LibraryItem::operator=(const LibraryItem& other) {
        if (this != &other) {
            delete[] m_title;
            copyName(other.m_title);
            
            m_year = other.m_year;
        }
        return *this;
    }

    LibraryItem::~LibraryItem() { 
        delete[] m_title;
        m_title = nullptr;
    }

    std::ostream& LibraryItem::display(std::ostream& ostr) const {
        return ostr << "Title: " << m_title << " (" << m_year << ")";
    }
}
