/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-01-25
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Room.h"
#include <string.h>
#include <iostream>

using namespace std;

namespace seneca {
    // sets the Room by allocating a dynamic array of guests and setting the room number 
    // (no validation is done for room number)
    void set(Room& room, int numberOfGuests, const char* roomNumber) {
        if (
            numberOfGuests <= 0 ||
            roomNumber == nullptr || strcmp(roomNumber, "") == 0
        ) {
            // Initialize to null and empty values
            strcpy(room.m_roomNumber, "");
            room.m_noOfGuests = 0;
            room.m_guests = nullptr;
        } else {
            // Initialize to the provided values
            strcpy(room.m_roomNumber, roomNumber);
            room.m_noOfGuests = numberOfGuests;
            
            room.m_guests = new Guest[numberOfGuests];
            for (int i = 0; i < numberOfGuests; ++i) {
                set(room.m_guests[i], nullptr, nullptr, 0);
            }
        }
    }

    // Prints the room number and names of the guests in the following lines with four 
    // spaces of indentaion 
    // See correct_output.txt for the exact format
    void print(const Room& room) {
        if (
            room.m_roomNumber == nullptr ||
            strcmp(room.m_roomNumber, "") == 0 ||
            room.m_noOfGuests == 0 ||
            room.m_guests == nullptr
        ) {
            cout << "Empty Room!" << endl;
        } else {
            cout << "Room Number: " << room.m_roomNumber << endl;

            for (int i = 0; i < room.m_noOfGuests; ++i) {
                cout << "    ";
                print(room.m_guests[i]);
            }
        }
    }

    // Books a room by receiving the room number, number of guests and the guest information.
    // See correct_output.txt for the exact format
    void book(Room& room) {
        int tempNumGuests = 0;
        char tempRoomNum[6] = { '\0' };

        cout << "Room number: ";
        cin >> tempRoomNum;

        cout << "Number of guests: ";
        cin >> tempNumGuests;

        set(room, tempNumGuests, tempRoomNum);
        for (int i = 0; i < tempNumGuests; ++i) {
            cout << i + 1 << ":" << endl;
            book(room.m_guests[i]);
        }
    }

    // vacates the room by de-allocating all the memory used.
    void vacate(Room& room) {
        strcpy(room.m_roomNumber, "");

        for (int i = 0; i < room.m_noOfGuests; ++i) {
            vacate(room.m_guests[i]);
        }
        room.m_noOfGuests = 0;

        delete[] room.m_guests;
        room.m_guests = nullptr;
    }
}
