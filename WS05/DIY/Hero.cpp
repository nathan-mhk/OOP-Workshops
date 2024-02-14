/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Hero.h"
#include <cstring>

namespace seneca {
    Hero::Hero(const char* name, Power* powers, int numPowers) : m_numPowers(numPowers) {
        strcpy(m_name, name);

        // TODO: Deep copy powers to m_powers
    }

    // Display Function
    std::ostream& Hero::display(std::ostream& ostr) const {
        return ostr;
    }

    // Operator and Conversion Overloads

    /**
     * The power should be added to the dynamic list of powers of your hero.
     * Your heroes' power level and power count should be updated too.
    */
    const Hero& Hero::operator+=(const Power& power) {
        return *this;
    }

    /**
     * This operator will decrease the power level of the hero by the integer
     * value received.
    */
    const Hero& Hero::operator-=(const int& powerLevel) {
        return *this;
    }

    // Logical Operators

    /**
     *  Return true if the first hero's power level is less than the second
     * hero's power level
    */
    bool Hero::operator<(const Hero& that) const {
        return true;
    }

    /**
     *  Return true if the first hero's power level is greater than the second
     * hero's power level
    */
    bool Hero::operator>(const Hero& that) const {
        return true;
    }

    // Insertion/Extraction Operator Overloads
    Hero& Hero::operator<<(Power& rhs) {
        return *this;
    }

    // Insertion/Extraction Operator Overloads
    const Power& operator>>(const Power& lhs, Hero& rhs) {
        return lhs;
    }
}
