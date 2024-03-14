/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-03-13
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "BankAccount.h"
#include <cstring>

namespace seneca {
    double BankAccount::getBalance() const {
        return m_balance;
    }

    void BankAccount::setBalance(double balance) {
        m_balance = balance;
    }

    /**
     * A utility method that inserts into `out` a formatted dollar amount.
     * The amount is written with a leading '$' sign and a precision of 2.
     * For example, if `amount` is 1.2, $1.20 is written to out.
    */
    void BankAccount::writeCurrency(ostream& out, double amount) const {
        out.precision(2);
        out << "$" << fixed << amount;
    }

    BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance) : m_balance(balance) {
        strcpy(m_name, name);
        m_openDate = new Date(openDate.getDay(), openDate.getMonth(), openDate.getYear());
        m_depInfo = new DepositInfo(depInfo.getTransit(), depInfo.getInstitution(), depInfo.getAccount());
    }

    BankAccount::~BankAccount() {
        delete m_openDate;
        delete m_depInfo;

        m_openDate = nullptr;
        m_depInfo = nullptr;
    }

    /**
     * A query that inserts into out the content of the object as formatted
     * below. The method will use writeCurrency() to output the account balance.
     * 
     * ```
     * >> [Name] | [Balance] | [Date Opened] | [Deposit Info]
     * ```
    */
    ostream& BankAccount::write(ostream& out) const {
        out << ">> " << m_name << "|";
        writeCurrency(out, m_balance);
        out << " | ";
        m_openDate->write(out);
        out << " | ";
        m_depInfo->write(out);
        return out;
    }

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
    istream& BankAccount::read(istream& in) {
        cout << "Name: ";
        in >> m_name;

        cout << "Opening Balance: ";
        in >> m_balance;

        cout << "Date Opened ";
        m_openDate->read(in);

        m_depInfo->read(in);
        return in;
    }

    /**
     *  Overload the extraction operator to extract a `BankAccount` from a stream.
     * The extraction operator will call the `read` member function in the class
     * `BankAccount`.
    */
    istream& operator>>(istream& in, BankAccount& acct) {
        return acct.read(in);
    }

    /**
     * Overload the insertion operator to insert a `BankAccount` into a stream.
     * The insertion operator will call the `write` member function in the class
     * `BankAccount`.
    */
    ostream& operator<<(ostream& out, const BankAccount& acct) {
        return acct.write(out);
    }
}
