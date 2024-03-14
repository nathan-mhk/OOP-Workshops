/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-13
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "SavingsAccount.h"

namespace seneca {
    /**
     * A query that inserts into `out` interest rate (m_interest) formatted so that the
     * precision is 3 and a '%' sign follows. For example, if `m_interest` is 0.12,
     * `0.120%` is written to `out`.
    */
    void SavingsAccount::writeInterest(ostream& out) const {
        out.precision(3);
        out << m_interest << "%";
    }

    SavingsAccount::SavingsAccount(
        const char* name, Date openDate, DepositInfo depInfo,
        double balance, double interest, Date interestDate
    ) : BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}

    
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
    void SavingsAccount::applyInterest(Date& dt) {
        double bal = getBalance();
        double interest = bal * m_interest;
        double newBal = bal + interest;

        cout << "   ";
        writeCurrency(cout, bal);

        cout << " + ";
        writeCurrency(cout, interest);

        cout << " (";
        writeInterest(cout);

        cout << ") = ";
        writeCurrency(cout, newBal);

        cout << " | " << m_interestDate << " => " << dt << endl;

        setBalance(newBal);
        m_interestDate = dt;
    }

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
    ostream& SavingsAccount::write(ostream& out) const {
        BankAccount::write(out) << " | ";

        writeInterest(out);

        out << " | " << m_interestDate;

        return out;
    }

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
    istream& SavingsAccount::read(istream& in) {
        BankAccount::read(in);

        cout << "Interest Date ";
        in >> m_interestDate;

        cout << "Interest Rate: ";
        in >> m_interest;

        return in;
    }

    /**
     * Overload the extraction operator to extract a `SavingsAccount` from a stream.
     * The extraction operator will call the `read` member function in the class
     * `SavingsAccount`.
    */
    istream& operator>>(std::istream& in, SavingsAccount& acct) {
        return acct.read(in);
    }

    /**
     * Overload the insertion operator to insert a `SavingsAccount` into a stream.
     * The insertion operator will call the `write` member function in the class
     * `SavingsAccount`.
    */
    ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
        return acct.write(out);
    }
}
