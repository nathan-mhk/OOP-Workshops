/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-03
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef ICECREAM_H
#define ICECREAM_H

#include "Utils.h"

#define NUM_FLAVS 5
#define MAX_SCOOPS 3

namespace seneca {
    void displayShortBar();

    class Icecream {
        private:
            const char* flavStr[NUM_FLAVS];
            int flavOpt, numScoops;
            bool waferCone, isChoco;
            double scoopsPrice, totalPrice;

            void displayFlavs() const;
            void calTotalPrice();

        public:
            void setEmpty();
            void getOrder();
            void printOrder() const;

            const double& getTotalPrice() const;

            Icecream() :
                flavStr{
                    "Chocolate",
                    "Strawberry",
                    "Mango",
                    "Tutti fruit",
                    "Almond crunch"
                },
                flavOpt(-1), numScoops(0),
                waferCone(false), isChoco(false),
                scoopsPrice(0), totalPrice(0)
            {};
    };
}

#endif
