/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-01-25
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Guest.h"
#include <string.h>
#include <iostream>

using namespace std;

#define ADULT_AGE 18
#define NAME_LEN 30

namespace seneca {
    // sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
    void set(Guest& guest, const char* first, const char* last, int age) {
        if (
            first == nullptr || last == nullptr ||
            strcmp(first, "") == 0 || strcmp(last, "") == 0
        ) {
            vacate(guest);
        } else {
            guest.m_firstName = new char[strlen(first) + 1];
            strcpy(guest.m_firstName, first);

            guest.m_lastName = new char[strlen(last) + 1];
            strcpy(guest.m_lastName, last);

            guest.m_adult = age >= ADULT_AGE;
        }
    }

    // Prints the guest name:
    // "Name Surname(child)"
    // The child flag is printed if the guest is not an adult
    // and if the names are not set, "Vacated!" is printed.
    void print(const Guest& guest) {
        if (
            guest.m_firstName == nullptr || guest.m_lastName == nullptr ||
            strcmp(guest.m_firstName, "") == 0 || strcmp(guest.m_lastName, "") == 0
        ) {
            cout << "Vacated!" << endl;
        } else {
            cout << guest.m_firstName << " " << guest.m_lastName;
            
            if (!guest.m_adult) {
                cout << "(child)";
            }
            cout << endl;
        }
    }

    // books the guest information from the console:
    // Name: Jake<ENTER>
    // Lastname: Doe<ENTER>
    // Age: 10<ENTER>
    void book(Guest& guest) {
        char tempFirst[NAME_LEN] = { '\0' };
        char tempLast[NAME_LEN] = { '\0' };
        int tempAge = 0;

        cout << "Name: ";
        cin >> tempFirst;
        
        cout << "Lastname: ";
        cin >> tempLast;

        cout << "Age: ";
        cin >> tempAge;

        set(guest, tempFirst, tempLast, tempAge);
    }

    // vacates the guest by de-allocating its memory.
    void vacate(Guest& guest) {
        delete[] guest.m_firstName;
        delete[] guest.m_lastName;

        guest.m_firstName = nullptr;
        guest.m_lastName = nullptr;
    }
}
