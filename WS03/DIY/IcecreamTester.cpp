/***********************************************************************
// OOP244 Workshop #03 p2: tester program 
//
// File	main.cpp
// Version 1.0
// Date: September 28, 2023
// Author: Yosef Ashibani, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-01
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "IceCream.h"
int main() {
   seneca::Icecream I;
   // test one
   I.getOrder();
   I.printOrder();
   // test two
   I.getOrder();
   I.printOrder();
   return 0;
}