/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date:
// Author:  
// Description
// This file defines the SavingsAccount class
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

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

namespace seneca {
    class SavingsAccount : public Account {

        double m_interest{};

    public:

        /**
         * Constructor receives a double holding the initial account 
         * balance and a double holding the interest rate to be applied 
         * to the balance. If the interest rate received is 
         * positive-valued, this function stores the rate. If not, this 
         * function stores 0.0 as the rate to be applied.
        */
        SavingsAccount(double, double);

        /**
         * This modifier calculates the interest earned on the current 
         * balance and credits the account with that interest.
        */
        virtual void monthEnd();

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
        virtual void display(std::ostream&) const;
    };
}

#endif
