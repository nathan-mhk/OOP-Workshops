/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the Account class
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

#include "Account.h"

namespace seneca {
    /**
     * Constructor receives either a double holding the initial 
     * account balance or nothing. If the amount received is not 
     * positive-valued or no amount is received, this function 
     * initializes the current balance to 0.0. If the amount 
     * received is positive-valued, this function initializes the 
     * current account balance to the received amount.
    */
    Account::Account(double bal) {
        if (bal < 0) bal = 0;
        m_balance = bal;
    }

    /**
     * Receives an amount to be credited (added) to the account
     * balance and returns the success of the transaction. If the
     * amount received is positive-valued, the transaction succeeds 
     * and this function adds the amount received to the current 
     * balance. If the amount is not positive-valued, the 
     * transaction fails and this function does not add the amount 
     * received.
    */
    bool Account::credit(double amt) {
        if (amt < 0) return false;
        m_balance += amt;
        return true;
    }

    /**
    * Receives an amount to be debited (subtracted) from the 
    * account balance and returns the success of the transaction. 
    * If the amount received is positive-valued, the transaction 
    * succeeds and this function subtracts the amount received from 
    * the current balance. If the amount is not positive-valued, 
    * the transaction fails and this function does not subtract the 
    * amount received.
    */
    bool Account::debit(double amt) {
        if (amt < 0) return false;
        m_balance -= amt;
        return true;
    }

    /**
     * Returns the current balance of the account.
    */
    double Account::balance() const {
        return m_balance;
    }
}
