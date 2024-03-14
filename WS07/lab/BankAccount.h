/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-13
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "DepositUtility.h"
#include <iostream>

using namespace std;

namespace seneca {
    const int NAME_LEN = 50;
    class BankAccount {
        char m_name[NAME_LEN + 1]{};
        Date m_openDate{};
        DepositInfo m_depInfo{};
        double m_balance{};

    protected:
        double getBalance() const;
        void setBalance(double balance);

        /**
         * A utility method that inserts into `out` a formatted dollar amount.
         * The amount is written with a leading '$' sign and a precision of 2.
         * For example, if `amount` is 1.2, $1.20 is written to out.
        */
        void writeCurrency(ostream& out, double amount) const;

    public:
        BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);

        /**
         * A query that inserts into out the content of the object as formatted
         * below. The method will use writeCurrency() to output the account balance.
         * 
         * ```
         * >> [Name] | [Balance] | [Date Opened] | [Deposit Info]
         * ```
        */
        ostream& write(ostream& out) const;

        /**
         * A mutator that reads from the stream in the data for the current object.
         * 
         * ```
         * Name: [USER TYPES HERE]
         * Opening Balance: [USER TYPES HERE]
         * Date Opened (year month day): [USER TYPES HERE]
         * Transit #: [USER TYPES HERE]
         * Institution #: [USER TYPES HERE]
         * Account #: [USER TYPES HERE]
        */
        istream& read(istream& in);

        /**
         *  Overload the extraction operator to extract a `BankAccount` from a stream.
         * The extraction operator will call the `read` member function in the class
         * `BankAccount`.
        */
        friend istream& operator>>(istream& in, BankAccount& acct);

        /**
         * Overload the insertion operator to insert a `BankAccount` into a stream.
         * The insertion operator will call the `write` member function in the class
         * `BankAccount`.
        */
        friend ostream& operator<<(ostream& out, const BankAccount& acct);
    };
}

#endif