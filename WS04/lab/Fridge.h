/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
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
 * Date: 2024-02-06
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>

#define FRIDGE_CAP 3

namespace seneca{

   const int NAME_LEN = 20;

   class Food {
      char m_name[NAME_LEN]{};
      int m_weight{};
   public:
      const char* name()const;
      int weight()const;
      Food();
      Food(const char* nm, int wei);
   };

   class Fridge {
      Food m_foods[FRIDGE_CAP];
      int m_numFoods;
      char* m_model;

      Fridge();
      Fridge(Food foods[], int numFoods, const char* modelName = "Ice Age");
      ~Fridge();

   public:

      /**
       * This function will attempt to add a Food item to the m_foods array.
       * If the m_numFoods is less than the FRIDGE_CAP then assign the
       * parameter Food item to the m_foods array at the index of m_numFoods.
       * Increment the m_numFoods by 1 to reflect the added Food item.
       * 
       * This function returns true if we have successfully added a Food item
       * and false otherwise.
      */
      bool addFood(const Food& f);

      /**
       * This function will modify the model_name of the Fridge using the
       * parameter provided if it is valid (ie not nullptr or the empty string).
       * 
       * If it is valid then first deallocate the memory of the m_model then
       * allocate enough memory to store the provided value and copy it to m_model.
      */
      void changeModel(const char* m);

      /**
       * This function will return whether or not the Fridge is full. A Fridge is
       * considered to be full if m_numFoods has reached FRIDGE_CAP.
      */
      bool fullFridge() const;

      /**
       * This function will attempt to determine whether this Fridge holds a
       * particular Food item by comparing its name to the parameter value.
       * If a Food item is found with the same name then return true otherwise
       * return false.
      */
      bool findFood(const char* f) const;

      /**
       * This function will display the details of the Fridge to the ostream
       * parameter named os. Instead of printing to cout we will be using this
       * os parameter as the destination (cout << myvar vs os << myvar).
       * 
       * If the current object's m_model is in an empty state then this
       * function will not print anything and only return.
       * 
       * 
       * Otherwise, print the following:
       * 
       * Fridge Model: [m_model]<newline>
       * Food count: [m_numFoods] Capacity: [FRIDGE_CAP]<newline>
       * List of Foods<newline>
       * 
       * If m_numFoods is greater than 0 then loop over the array m_foods
       * and print out each Food item in the following format. The field
       * width for the Food's name should be using the NAME_LEN constant.
       * 
       * [Food.m_name] | [Food.weight]<newline>
       * 
       * This function will return the parameter os.
      */
      std::ostream& display(std::ostream& os = std::cout) const;
   };

}

#endif
