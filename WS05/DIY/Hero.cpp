/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-14
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Hero.h"
#include <cstring>

namespace seneca {

    void Hero::calculatePowerLevel() {
        m_powerLevel = 0;
        for (int i = 0; i < m_numPowers; ++i) {
            m_powerLevel += m_powers[i].checkRarity();
        }
        m_powerLevel *= m_numPowers;
    }

    void Hero::delPowers() {
        delete[] m_powers;
    }

    Hero& Hero::cpyPowers(Power *const destPowers, const Power *const srcPowers, const int numPowers) {
        for (int i = 0; i < numPowers; ++i) {
            destPowers[i].createPower(srcPowers[i].checkName(), srcPowers[i].checkRarity());
        }
        return *this;
    }

    Hero::Hero() : m_powers(nullptr), m_numPowers(0), m_powerLevel(0) {};

    Hero::Hero(const char* name, Power* powers, int numPowers) : m_numPowers(numPowers) {
        strcpy(m_name, name);

        m_powers = new Power[numPowers];

        cpyPowers(m_powers, powers, numPowers).calculatePowerLevel();
    }

    Hero::~Hero() {
        delPowers();
        m_powers = nullptr;
    }

    // Accessors
    const int Hero::getPowerLevel() const {
        return m_powerLevel;
    }

    // Display Function
    std::ostream& Hero::display(std::ostream& ostr) const {
        ostr << "Name: " << m_name << std::endl;

        displayDetails(m_powers, m_numPowers);

        ostr << "Power Level: " << m_powerLevel;
        return ostr;
    }

    // Operator and Conversion Overloads

    /**
     * The power should be added to the dynamic list of powers of your hero.
     * Your heroes' power level and power count should be updated too.
    */
    Hero& Hero::operator+=(const Power& power) {
        // Resize m_powers
        Power* temp = new Power[m_numPowers + 1];
        cpyPowers(temp, m_powers, m_numPowers);

        // Add the new power
        temp[m_numPowers++].createPower(power.checkName(), power.checkRarity());
        
        delPowers();
        m_powers = temp;
        calculatePowerLevel();

        return *this;
    }

    /**
     * This operator will decrease the power level of the hero by the integer
     * value received.
    */
    Hero& Hero::operator-=(const int& powerLevel) {
        m_powerLevel -= powerLevel;
        return *this;
    }

    // Logical Operators

    /**
     *  Return true if the first hero's power level is less than the second
     * hero's power level
    */
    bool Hero::operator<(const Hero& that) const {
        return m_powerLevel < that.getPowerLevel();
    }

    /**
     *  Return true if the first hero's power level is greater than the second
     * hero's power level
    */
    bool Hero::operator>(const Hero& that) const {
        return m_powerLevel > that.getPowerLevel();
    }

    // Insertion/Extraction Operator Overloads
    Hero& Hero::operator<<(Power& rhs) {
        return *this += rhs;
    }

    // Insertion/Extraction Operator Overloads
    const Power& operator>>(const Power& lhs, Hero& rhs) {
        rhs += lhs;
        return lhs;
    }
}
