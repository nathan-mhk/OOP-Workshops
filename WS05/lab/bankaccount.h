/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
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
 * Date: 2024-02-13
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_



namespace seneca
{
   const int	 ACCT_MAXLEN_USER = 16;					// Max Length of user name
   const int    PRECISION = 2;
   const double DIFF = 0.001;
   const int NAME_WIDTH = ACCT_MAXLEN_USER;
   const int TYPE_WIDTH = 8;
   const int BAL_WIDTH = 7;
   const int TRANSCAC_WIDTH = 3;

   // Class Definition
   class bankAccount
   {

   private:
      // Data Members
      char	m_userName[ACCT_MAXLEN_USER];
      double	m_funds;
      bool	m_checking;
      int		m_monthlyTransactions;

      const double m_checkTransacFee = 1.25;
      const double m_checkIntRate = 0.005;
      const double m_savinTransacFee = 3.5;
      const double m_savinIntRate = 0.025;

      bool isOpen() const;
   public:
      bankAccount(const char* name = nullptr, bool checking = false);
      bool setup(const char* name, bool checking);

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods

      // Accessors
      const char* getUserName() const;
      const bool isChecking() const;

      
      /**
       * Returns true if the account isOpen(); false otherwise. This method
       * does not modify the object.
      */
      operator bool() const;

      /**
       * Returns the total $ funds held in the account. Does not modify the
       * object
      */
      operator double() const;

      /**
       * Calculates interest (ie: funds x rate) and adds it to existing funds
       * in the account. Note the rate is based on the account type (see Fees
       * & Interest above). Interest can only be earned for accounts which
       * have a positive value and have been opened. Returns reference to the
       * current object.
      */
      bankAccount& operator++();

      /**
       * Calculates fees (ie: Monthly transactions multiplied by transaction
       * fee) and subtracts it from existing funds in the account. Note the
       * transaction fee is based on the account type (see Fees & Interest
       * above). Can only be used if the account has been opened. Returns
       * reference to the current object.
      */
      bankAccount& operator--();

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
      bool operator+=(double);

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
      bool operator-=(double);

      /**
       * `Operator==` checks if the specified bank account has the same user
       * name, funds and type as this. It returns true if all 3 are identical;
       * false otherwise. This method does not modify the object.
       * 
       * > Note that the funds are considered the same if their difference is
       * > less than `0.001`
      */
      bool operator==(const bankAccount&) const;

      /**
       * Returns true if funds in account > specified value. `operator>` can
       * only be used if the account has been opened. This method does not
       * modify the object.
      */
      bool operator>(double) const;

      /**
       * Returns true if funds in account <= specified value. It can only be
       * used if the account has been opened. `operator<=` Does not modify
       * the object. It can be implemented by simply invoking `operator>` from
       * above and reversing the result.
      */
      bool operator<=(double) const;

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
      bool operator<<(bankAccount&);

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
      void display(void) const;
   };

   // ADD: Global helpers
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
   bool operator>(double lhs, const bankAccount& rhs);

   /**
    * This global helper is required for the same reasons
    * as above. It can be implemented by simply invoking
    * the above global helper `operator>` and reversing
    * the result.
   */
   bool operator<=(double lhs, const bankAccount& rhs);
}
#endif

