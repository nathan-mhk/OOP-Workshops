/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-01
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Vendor.h"
#include "Utils.h"
#include <iostream>

using namespace std;

#define TAX 0.13

namespace seneca {
    // Vendor Private Member Functions
    // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

    void Vendor::calTotalPrice() {
        for (int i = 0; i < numIceCream; ++i) {
            totalPrice += iceCreams[i].getTotalPrice();
        }
    }

    // ʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌ
    
    // Vendor Public Member Functions
    // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

    /**
     * A member function to set the Vendor object to an empty state.
    */
    void Vendor::setEmpty() {
        clearData();
        iceCreams = nullptr;

        numIceCream = 0;
    }

    /**
     * A member function responsible for taking customer orders.
     * This function interacts with customers to gather order details.
     * - It will get the number of orders for Icecreams
     * - Gets each order for the Icecream
    */

    void Vendor::takeOrders() {
        cout << "Seneca Icecream shop" << endl;
        cout << "          @" << endl;
        cout << "        (' .)" << endl;
        cout << "       (*.`. )" << endl;
        cout << "        \\###/" << endl;
        cout << "         \\#/" << endl;
        cout << "          V" << endl;
        cout << "How many Icecreams?" << endl;

        while (true) {
            cout << "> ";

            if ((cin >> numIceCream) && numIceCream > 0) {
                break;;
            }
        }

        iceCreams = new Icecream[numIceCream];

        for (int i = 0; i < numIceCream; ++i) {
            cout << "Order number " << i + 1 << ":" << endl;
            iceCreams[i].getOrder();
        }
        cout << endl;
        calTotalPrice();
    }

    /**
     * - Prints the details of all the orders
     * - Prints the total price, tax (13%) and the Total price after tax.
    */
    void Vendor::displayOrders() const {
        cout << "********** Order Summary **********" << endl;

        for (int i = 0; i < numIceCream; ++i) {
            cout << "Order No: " << i + 1 << ":" << endl;
            iceCreams[i].printOrder();

            if (i < numIceCream - 1) {
                cout << endl;
            }
        }
        printLongBar();
        printRow("Price: ", totalPrice);
        printRow("Tax: ", totalPrice * TAX);
        printRow("Total Price ($): ", totalPrice + totalPrice * TAX);
    }

    /**
     * A member function for cleaning up and releasing resources associated
     * with the Vendor object. This function is used to avoid memory leaks
     * and perform cleanup when the Vendor object is no longer needed.
    */
    void Vendor::clearData() {
        // for (int i = 0; i <numIceCream; ++i) {
        //     iceCreams[i].setEmpty();
        // }
        delete[] iceCreams;
    }
    // ʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌ
}
