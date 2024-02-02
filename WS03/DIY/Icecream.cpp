/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-01
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "IceCream.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

/**
 * - Each scoop costs $5
 * - Vanilla wafer cone costs $5 extra
 * - Chocolate Icecream costs $1 extra per scoop
 * - Displays a menu asking the customer for their flavour choice,
 *   the number of scoops, and whether they want to add a vanilla wafer:
 * - Displays the final payable amount, along with detailed pricing.
*/
#define SCOOP_COST 5
#define WAFER_CONE_COST 5
#define CHOCO_EXTRA_COST 1
#define CHOCO_OPT 0

#define LEFT_WIDTH 27
#define RIGHT_WIDTH 8
#define PRECISION 2

namespace seneca {
    void displayShortBar() {
        cout << "----------------" << endl;
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

    void printRow(string label, double value) {
        cout.width(LEFT_WIDTH);
        cout << left << label;

        cout.width(RIGHT_WIDTH);
        cout.precision(PRECISION);
        cout << right << fixed << value << endl;
    }

    // Icecream Private Member Functions
    // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

    void Icecream::displayFlavs() const {
        for (int i = 0; i < NUM_FLAVS; ++i) {
            cout << i + 1 << ": " << flavStr[i] << endl;
        }
    }

    void Icecream::calTotalPrice() {
        scoopsPrice = numScoops * SCOOP_COST;

        if (isChoco) {
            totalPrice += numScoops * CHOCO_EXTRA_COST;
        }

        if (waferCone) {
            totalPrice += WAFER_CONE_COST;
        }
        totalPrice += scoopsPrice;
    }

    // ʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌ
    
    // Icecream Public Member Functions
    // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

    void Icecream::setEmpty() {
        flavOpt = -1;
        numScoops = 0;
        waferCone = false;
        isChoco = false;
        scoopsPrice = 0;
        totalPrice = 0;
    }

    void Icecream::getOrder() {
        setEmpty();
        cout << "Select flavour:" << endl;
        displayShortBar();
        displayFlavs();
        displayShortBar();

        flavOpt = getInt(1, NUM_FLAVS) - 1;
        isChoco = flavOpt == CHOCO_OPT;

        cout << "Number of Scoops (max " << MAX_SCOOPS << ")" << endl;
        numScoops = getInt(1, MAX_SCOOPS);

        cout << "Vanilla wafer cone?" << endl;
        cout << "(Y)es/(N)o ";
        waferCone = getYNInput();

        calTotalPrice();
    }

    void Icecream::printOrder() const {
        cout.width(LEFT_WIDTH);
        cout << left << "Order details: ";

        cout.width(RIGHT_WIDTH);
        cout << right << "Price" << endl;

        cout << "-----------------------------------" << endl;

        printRow(
            "Number of scoops, " + to_string(numScoops) + " total: ",
            scoopsPrice
        );

        if (isChoco) {
            printRow(
                "Chocolate flavour: ",
                (double)(numScoops * CHOCO_EXTRA_COST)
            );
        } else {
            cout << string(flavStr[flavOpt]) + " flavour" << endl;
        }

        printRow(
            "Vanilla Wafer: ",
            (double)(waferCone ? WAFER_CONE_COST : 0)
        );

        printRow(
            "Price: ",
            totalPrice
        );
    }
    // ʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌʌ

}
