/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-06
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca{
   const char* GuitarStr::material() const {
      return m_material;
   }
   double GuitarStr::gauge() const {
      return m_gauge;
   }
   GuitarStr::GuitarStr() {};

   GuitarStr::GuitarStr(const char* ma, double ga) {
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   };

   /**
    * Initializes the current object to an empty state except
    * for the model name which will be initialized by the
    * value of the parameter. The parameter will also have
    * a default value of "Stratocaster".
   */
   Guitar::Guitar(const char* mod)
    : m_strings(nullptr), m_numStrings(0) {
      strcpy(m_model, mod);
   }

   /**
    * The three-argument constructor initializes the data
    * members based on the provided parameters:
    * 
    * - `strs` is an array of GuitarStr that will be used to
    *   populate the dynamic array.
    * - `ns` is the size of the array argument (`strs`)
    * - `mod` is a model name for the Guitar
    * 
    * If the parameters are not valid the current object is
    * set to an empty state.
   */
   Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {
      if (!strs || ns < 0 || !mod || !mod[0]) {
         Guitar();
      } else {
         m_numStrings = ns;

         m_strings = new GuitarStr[ns];
         for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];
         }

         strcpy(m_model, mod);
      }
   }

   /**
    * The destructor deallocates any resources stored by
    * the current object.
   */
   Guitar::~Guitar() {
      delete[] m_strings;
      m_strings = nullptr;
   }

   /**
    * This function changes a GuitarStr on the Guitar by
    * passing one in through the parameter `gs`. The `sn`
    * parameter refers to the index in the array (`m_strings`)
    * as to which GuitarStr is going to be changed. If the
    * provided `sn` value is an invalid index for the array
    * then no string change occurs.
    * 
    * This function returns true if a change occurred and
    * false otherwise.
   */
   bool Guitar::changeString(const GuitarStr& gs, int sn) {
      if (sn >= 0 && sn < m_numStrings) {
         m_strings[sn] = gs;
         return true;
      }
      return false;
   }

   /**
    * This function restrings the Guitar with a new set of
    * GuitarStr provided through the parameters (an array of
    * GuitarStr and an integer representing the size of that
    * array). Take note to carefully manage any
    * allocation/deallocation of dynamic memory when replacing
    * the GuitarStr array.
   */
   void Guitar::reString(GuitarStr strs[], int ns) {
      deString();
      
      m_numStrings = ns;
      m_strings = new GuitarStr[ns];

      for (int i = 0; i < ns; ++i) {
         m_strings[i] = strs[i];
      }
   }

   /**
    * This function will de-string the Guitar of all of its
    * GuitarStr. This means to deallocate all resources
    * currently held by the Guitar and to then set the
    * m_numStrings to an empty state.
   */
   void Guitar::deString() {
      delete[] m_strings;
      m_strings = nullptr;
      m_numStrings = 0;
   }

   /**
    * This function will return true if the Guitar has
    * GuitarStr and false otherwise.
   */
   bool Guitar::strung() const {
      return m_strings;
   }

   /**
    * This function will return true if any GuitarStr on the
    * Guitar has a matching gauge value to the provided
    * parameter and false otherwise.
   */
   bool Guitar::matchGauge(double ga) const {
      for (int i = 0; i < m_numStrings; ++i) {
         if (m_strings[i].gauge() == ga) {
            return true;
         }
      }
      return false;
   }

   /**
    * This function will display the details of a Guitar to
    * the ostream via the parameter os.
    * 
    * If the Guitar is in an empty state print out the
    * following:
    * 
    * ***Empty Guitar***<newline>
    * 
    * Otherwise, print out the Guitar details as follows:
    * 
    * Guitar Model: [m_model]<newline>
    * Strings: [m_numStrings]<newline>
    * 
    * If the Guitar is strung/has GuitarStr then print out
    * each string using this format:
    * 
    * #1 [string1.m_material] | [string1.gauge]<newline>
    * #2 [string2.m_material] | [string2.gauge]<newline>
    * ...
    * 
    * For the GuitarStr material use a field width of
    * MAT_LEN. For the gauge use 1 decimal place precision.
    * 
    * Return the parameter os at the end of this function
    * regardless of what is printed out.
   */
   std::ostream& Guitar::display(std::ostream& os) const {
      if (!m_numStrings) {
         os << "***Empty Guitar***" << std::endl;
      } else {
         os << "Guitar Model: " << m_model << std::endl;
         os << "Strings: " << m_numStrings << std::endl;

         if (strung()) {
            for (int i = 0; i < m_numStrings; ++i) {
               os << "#" << i + 1;

               os.width(MAT_LEN);
               os << std::right << m_strings[i].material() << " | ";

               os.precision(PREC);
               os << std::fixed << m_strings[i].gauge() << std::endl;
            }
         }
      }
      return os;
   }
}
