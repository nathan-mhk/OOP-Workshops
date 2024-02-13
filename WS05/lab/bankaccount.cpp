/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';		// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())					
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);	
		m_monthlyTransactions = 0;	
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
    /**
	 * Returns true if the account isOpen(); false otherwise. This method
	 * does not modify the object.
	 */
	bankAccount::operator bool() const {
		return true;
	}

	/**
	 * Returns the total $ funds held in the account. Does not modify the
	 * object
	 */
	bankAccount::operator double() const {
		return 0;
	}

	/**
	 * Calculates interest (ie: funds x rate) and adds it to existing funds
	 * in the account. Note the rate is based on the account type (see Fees
	 * & Interest above). Interest can only be earned for accounts which
	 * have a positive value and have been opened. Returns reference to the
	 * current object.
	 */
	bankAccount& bankAccount::operator++() {
		return *this;
	}

	/**
	 * Calculates fees (ie: Monthly transactions multiplied by transaction
	 * fee) and subtracts it from existing funds in the account. Note the
	 * transaction fee is based on the account type (see Fees & Interest
	 * above). Can only be used if the account has been opened. Returns
	 * reference to the current object.
	 */
	bankAccount& bankAccount::operator--() {
		return *this;
	}

	/**
	 * Deposits specified value by adding it to existing funds and
	 * increments the number of transactions. `operator+=` Can only be used
	 * if the account has been opened. This method returns true on success;
	 * false otherwise.
	 * 
	 * Application example:
	 * 
	 * Deposit $100.00 for Joe Williams
	 */
	bool bankAccount::operator+=(double) {
		return true;
	}

	/**
	 * Withdraws specified value by subtracting it from existing funds and
	 * increments the number of transactions. It can only be used if the
	 * account has been opened. It returns true on success and outputs
	 * sample text below; false otherwise. It can be implemented by simply
	 * multiplying the specified value by -1 and invoking `operator+=` above.
	 * 
	 * Application example:
	 * 
	 * Withdraw $5.00 for Raya Chandok
	 */
	bool bankAccount::operator-=(double) {
		return true;
	}

	/**
	 * `Operator==` checks if the specified bank account has the same user
	 * name, funds and type as this. It returns true if all 3 are identical;
	 * false otherwise. This method does not modify the object.
	 * 
	 * > Note that the funds are considered the same if their difference is
	 * > less than `0.001`
	 */
	bool bankAccount::operator==(const bankAccount&) const {
		return true;
	}

	/**
	 * Returns true if funds in account > specified value. `operator>` can
	 * only be used if the account has been opened. This method does not
	 * modify the object.
	 */
	bool bankAccount::operator>(double) const {
		return true;
	}

	/**
	 * Returns true if funds in account <= specified value. It can only be
	 * used if the account has been opened. `operator<=` Does not modify
	 * the object. It can be implemented by simply invoking `operator>` from
	 * above and reversing the result.
	 */
	bool bankAccount::operator<=(double) const {
		return true;
	}

	/**
	 * Transfer all funds from the specified account to this account. First,
	 * check if both this account and the source account are open, and if
	 * the source account has positive funds. Then display Formatted output
	 * as per the example below. Finally use `operator+=` and `operator-=`
	 * (ie: what you just implemented above) to perform a transfer of funds.
	 * This method returns true on success; false otherwise.
	 * 
	 * Application example:
	 * 
	 * Transfer $100.00 from Joe Williams to Cindy Kofler
	 */
	bool bankAccount::operator<<(bankAccount&) {
		return true;
	}

	/**
	 * Display formatted output for this object as per the
	 * sample output below.
	 * 
	 * If the account is open:
	 * 
	 * Display Account -> User:----Cindy Kofler |  Savings | Balance: $  -52.00 | Transactions:012
	 * 
	 * If the account is not open:
	 * 
	 * Display Account -> User:------- NOT OPEN
	 */
	void bankAccount::display(void) const {
		return;
	}

	// ADD: Global Helper Functions
   /**
    * You will need to implement this global helper operator
    * to support the case where the lhs (ie: left operand)
    * is not a class (it is a primitive data type) and
    * therefore not capable of having a method. Use the
    * (bool) cast operator to confirm the rhs account is
    * open and the (double) cast operator to get the funds
    * from the rhs account, then return the result of the
    * comparison.
   */
   bool operator>(double lhs, const bankAccount& rhs) {
	return true;
   }

   /**
    * This global helper is required for the same reasons
    * as above. It can be implemented by simply invoking
    * the above global helper `operator>` and reversing
    * the result.
   */
   bool operator<=(double lhs, const bankAccount& rhs) {
	return true;
   }
}
