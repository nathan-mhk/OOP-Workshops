/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-22
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Book.h"
#include <cstring>
namespace seneca {

    void Book::copyAuthor(const char* author) {
        m_author = new char[strlen(author) + 1];
        strcpy(m_author, author);
    }

    Book::Book(const char* title, const int year, const char* author)
    : LibraryItem(title, year) {
        copyAuthor(author);
    }

    Book::Book(const Book& other) : LibraryItem(other) {
        copyAuthor(other.m_author);
    }

    Book& Book::operator=(const Book& other) {
        if (this != &other) {
            this->LibraryItem::operator=(other);

            delete[] m_author;
            copyAuthor(other.m_author);
        }
        return *this;
    }

    Book::~Book() {
        delete[] m_author;
        m_author = nullptr;
    }

    std::ostream& Book::display(std::ostream& ostr) const {
        return LibraryItem::display(ostr) << std::endl << "Author: " << m_author;
    }

    bool Book::operator>(const Book& other) const {
        if (m_author && other.m_author) {
            return strcmp(m_author, other.m_author) > 0;
        }
        return false;
    }
}
