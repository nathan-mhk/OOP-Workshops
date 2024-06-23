/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-03
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef UTILS_H
#define UTILS_H

#include <string>

#define LEFT_WIDTH 27
#define RIGHT_WIDTH 8

namespace seneca {
    void printShortBar();

    void printLongBar();

    void clearCin();

    int getInt(const int minVal, const int maxVal);

    bool getYNInput();

    void printRow(const std::string label, const double value);
}

#endif
