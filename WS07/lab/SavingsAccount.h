/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-13
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"
#include <iostream>

using namespace std;

namespace seneca {
    class SavingsAccount: public BankAccount {
        double m_interest{};
        Date m_interestDate{};

        /**
         * A query that inserts into `out` interest rate (m_interest) formatted so that the
         * precision is 3 and a '%' sign follows. For example, if `m_interest` is 0.12,
         * `0.120%` is written to `out`.
        */
        void writeInterest(ostream& out) const;

    public:
        SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);

        /**
         * A mutator that increases the account balance by the amount of interest; updates
         * the date interest was last applied; and outputs a message to `cout`. The method
         * will use `writeCurrency()` to output the account balances and `writeInterest()`
         * to output the interest rate. **There are three spaces at the front.**
         * 
         * ```
         *    [Original Balance] + [Interest Amount] ([Interest Rate]) = [New Balance] | [Original Interest Date] => [New Interest Date]
         * ```
        */
        void applyInterest(Date& dt);

        /**
         * A query that inserts into `out` the content of the object as formatted below.
         * The method must call the `write()` function of the base class. It will call
         * `writeInterest()` to output the interest rate and the insertion operator to
         * output the interest date.
         * 
         * ```
         * >> [Name] | [Balance] | [Date Opened] | [Deposit Info] | [Interest Rate] | [Interest Date]
         * ```
        */
        ostream& write(ostream& out) const;

        /**
         * A mutator that reads from the stream `in` the data for the current object.
         * It must call the `read()` function of the base class.
         * 
         * ```
         * Name: [USER TYPES HERE]
         * Opening Balance: [USER TYPES HERE]
         * Date Opened (year month day): [USER TYPES HERE]
         * Transit #: [USER TYPES HERE]
         * Institution #: [USER TYPES HERE]
         * Account #: [USER TYPES HERE]
         * Interest Date (year month day): [USER TYPES HERE]
         * Interest Rate: [USER TYPES HERE]
         * ```
        */
       istream& read(istream& in);

        /**
         * Overload the extraction operator to extract a `SavingsAccount` from a stream.
         * The extraction operator will call the `read` member function in the class
         * `SavingsAccount`.
        */
       friend istream& operator>>(std::istream& in, SavingsAccount& acct);

        /**
         * Overload the insertion operator to insert a `SavingsAccount` into a stream.
         * The insertion operator will call the `write` member function in the class
         * `SavingsAccount`.
        */
       friend ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
    };
}

#endif
