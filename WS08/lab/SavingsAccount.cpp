/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-18
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "SavingsAccount.h"

namespace seneca {
    /**
     * Constructor receives a double holding the initial account 
     * balance and a double holding the interest rate to be applied 
     * to the balance. If the interest rate received is 
     * positive-valued, this function stores the rate. If not, this 
     * function stores 0.0 as the rate to be applied.
    */
    SavingsAccount::SavingsAccount(double bal, double intRt) : Account(bal) {
        if (intRt < 0) intRt = 0;
        m_interest = intRt;
    }

    /**
     * This modifier calculates the interest earned on the current 
     * balance and credits the account with that interest.
    */
    void SavingsAccount::monthEnd() {
        credit(balance() * m_interest);
    }

    /**
     * Receives a reference to an ostream object and inserts the 
     * following output on separate lines to the object. The values 
     * marked in red are fixed format with 2 decimal places and no 
     * fixed field width:
     * 
     * ```
     * Account type: Savings
     * Balance: $xxxx.xx
     * Interest Rate (%): x.xx
     * ```
    */
    void SavingsAccount::display(std::ostream& ostr) const {
        ostr.precision(2);
        ostr << "Account type: Savings" << std::endl;
        ostr << "Balance: $" << std::fixed << balance() << std::endl;
        ostr << "Interest Rate (%): " << m_interest * 100 << std::endl;
    }
}
