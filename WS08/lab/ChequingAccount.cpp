/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the ChequingAccount class
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

#include "ChequingAccount.h"

namespace seneca {
    /**
     * Constructor receives a double holding the initial account 
     * balance, a double holding the transaction fee to be applied 
     * to the balance and a double holding the month-end fee to be 
     * applied to the account. If the transaction fee received is 
     * positive-valued, this function stores the fee. If not, this 
     * function stores 0.0 as the fee to be applied. If the monthly 
     * fee received is positive-valued, this function stores the 
     * fee. If not, this function stores 0.0 as the fee to be 
     * applied.
    */
    ChequingAccount::ChequingAccount(
        double bal, double transacFee, double monthlyFee
    ) : Account(bal) {
        if (transacFee < 0) transacFee = 0;
        if (monthlyFee < 0) monthlyFee = 0;
        m_transacFee = transacFee;
        m_monthlyFee = monthlyFee;
    }

    /**
     * This modifier credits the balance by the amount received and 
     * if successful debits the transaction fee from the balance. 
     * This function returns true if the transaction succeeded; 
     * false otherwise.
    */
    bool ChequingAccount::credit(double bal) {
        if (Account::credit(bal)) return Account::debit(m_transacFee);
        return false;
    }

    /**
     * This modifier debits the balance by the amount received and 
     * if successful debits the transaction fee from the balance. 
     * This function returns true if the transaction succeeded; 
     * false otherwise.
    */
    bool ChequingAccount::debit(double bal) {
        if (Account::debit(bal)) return Account::debit(m_transacFee);
        return false;
    }

    /**
     * This modifier debits the monthly fee from the balance, but 
     * does not charge a transaction fee for this debit.
    */
    void ChequingAccount::monthEnd() {
        Account::debit(m_monthlyFee);
    }

    /**
     * Receives a reference to an ostream object and inserts the 
     * following output on separate lines to the object. The values 
     * marked in red are fixed format with 2 decimal places and no 
     * fixed field width:
     * 
     * ```
     * Account type: Chequing
     * Balance: $xxxx.xx
     * Per Transaction Fee: x.xx
     * Monthly Fee: x.xx
     * ```
    */
    void ChequingAccount::display(std::ostream& ostr) const {
        ostr.precision(2);

        ostr << "Account type: Chequing" << std::endl;
        ostr << "Balance: $" << std::fixed << balance() << std::endl;
        ostr << "Per Transaction Fee: " << m_transacFee << std::endl;
        ostr << "Monthly Fee: " << m_monthlyFee << std::endl;
    }
}
