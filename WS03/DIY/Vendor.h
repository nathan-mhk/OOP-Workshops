/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-01
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef VENDOR_H
#define VENDOR_H

#include "IceCream.h"

namespace seneca {
    class Vendor {
        private:
            int numIceCream;
            Icecream* iceCreams;
            double totalPrice;

            void calTotalPrice();

        public:
            Vendor() : 
                numIceCream(0),
                iceCreams(nullptr)
            {};
            void setEmpty();
            void takeOrders();
            void displayOrders() const;
            void clearData();
    };

}

#endif
