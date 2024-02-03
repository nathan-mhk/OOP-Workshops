/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-03
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Utils.h"
#include <iostream>
#include <limits>

#define PRECISION 2

using namespace std;

namespace seneca {
    void printShortBar() {
        cout << "----------------" << endl;
    }

    void printLongBar() {
        cout << "-----------------------------------" << endl;
    }

    void clearCin() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int getInt(const int minVal, const int maxVal) {
        int res = minVal - 1;

        while (true) {
            cout << "> ";

            if (!(cin >> res)) {
                cout << "Invalid entry, retry" << endl;
                clearCin();
                continue;
            }

            if (res < minVal || res > maxVal) {
                cout << "Invlid value(1<=val<=" << maxVal << ")" << endl;
                clearCin();
                continue;
            }
            return res;
        }
    }

    bool getYNInput() {
        string res = "";
        while (true) {
            cout << "> ";

            if ((cin >> res) && (res == "Y" || res == "y" || res == "N" || res == "n")) {
                return res == "Y" || res == "y";
            }
            
            cout << "Only Y or N are acceptable:" << endl;
            clearCin();
        }
    }

    void printRow(const string label, const double value) {
        cout.width(LEFT_WIDTH);
        cout << left << label;

        cout.width(RIGHT_WIDTH);
        cout.precision(PRECISION);
        cout << right << fixed << value << endl;
    }
}
