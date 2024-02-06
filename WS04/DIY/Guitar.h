/***********************************************************************
// OOP244 Workshop #4 p2: tester program
// File  main.cpp
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
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>

namespace seneca{

  const int MAT_LEN = 10;
  const int NAME_LEN = 15;

  class GuitarStr {
     char m_material[MAT_LEN]{};
     double m_gauge{};
  public:
     const char* material()const;
     double gauge()const;
     GuitarStr();
     GuitarStr(const char* ma, double ga);
  };

   class Guitar {
      GuitarStr* m_strings;
      int m_numStrings;
      char m_model[NAME_LEN];

   public:
      /**
       * Initializes the current object to an empty state except
       * for the model name which will be initialized by the
       * value of the parameter. The parameter will also have
       * a default value of "Stratocaster".
      */
      Guitar(const char* mod = "Stratocaster");

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
      Guitar(GuitarStr strs[], int ns, const char* mod);

      /**
       * The destructor deallocates any resources stored by
       * the current object.
      */
      ~Guitar();

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
      bool changeString(const GuitarStr& gs, int sn);

      /**
       * This function restrings the Guitar with a new set of
       * GuitarStr provided through the parameters (an array of
       * GuitarStr and an integer representing the size of that
       * array). Take note to carefully manage any
       * allocation/deallocation of dynamic memory when replacing
       * the GuitarStr array.
      */
      void reString(GuitarStr strs[], int ns);

      /**
       * This function will de-string the Guitar of all of its
       * GuitarStr. This means to deallocate all resources
       * currently held by the Guitar and to then set the
       * m_numStrings to an empty state.
      */
      void deString();

      /**
       * This function will return true if the Guitar has
       * GuitarStr and false otherwise.
      */
      bool strung() const;

      /**
       * This function will return true if any GuitarStr on the
       * Guitar has a matching gauge value to the provided
       * parameter and false otherwise.
      */
      bool matchGauge(double ga) const;

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
      std::ostream& display(std::ostream& os = std::cout) const;
   };
}

#endif
