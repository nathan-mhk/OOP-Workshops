/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"
#include <iostream>

namespace seneca {
    class Hero {
        char m_name[MAX_NAME_LENGTH]{};
        Power* m_powers;
        int m_numPowers;
        int m_powerLevel; // Calculated as SUM(Power::m_rarity) * m_numPowers

    public:

        // Constructors
        Hero() :
        m_powers(nullptr),
        m_numPowers(0),
        m_powerLevel(0)
        {};

        Hero(const char* name, Power* powers, int numPowers);

        // Display Function
        std::ostream& display(std::ostream& ostr) const;

        // Operator and Conversion Overloads

        /**
         * The power should be added to the dynamic list of powers of your hero.
         * Your heroes' power level and power count should be updated too.
        */
        const Hero& operator+=(const Power& power);

        /**
         * This operator will decrease the power level of the hero by the integer
         * value received.
        */
        const Hero& operator-=(const int& powerLevel);

        // Logical Operators

        /**
         *  Return true if the first hero's power level is less than the second
         * hero's power level
        */
        bool operator<(const Hero& that) const;

        /**
         *  Return true if the first hero's power level is greater than the second
         * hero's power level
        */
        bool operator>(const Hero& that) const;

        // Insertion/Extraction Operator Overloads
        Hero& operator<<(Power& rhs);

    };

    // Insertion/Extraction Operator Overloads
    const Power& operator>>(const Power& lhs, Hero& rhs);
}

#endif
