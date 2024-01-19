#include "file.h"
#include "io.h"
#include "graph.h"

#include <iostream>
using namespace std;

#define NUM_INTVLS 10

namespace seneca {

    /**
     * Sort the Array "studentArray" with the array size kept in "size" as follows:
     *   loop with i from 0  up to  i less than size - 1
     *     loop with j from 0 up to j less than size - i - 1
     *       if  mark of studentArray[j] is less than  mark of studentArray[j + 1]
     *         swap them
     *       end if
     *     end loop
     *    end loop
     *  end sort
    */
    void sort(StMark records[], int arrSize) {
        for (int i = 0; i < arrSize - 1; ++i) {
            for (int j = 0; j < arrSize - i - 1; ++j) {
                if (records[j].mark < records[j + 1].mark) {
                    StMark temp = records[j];
                    records[j] = records[j + 1];
                    records[j + 1] = temp;
                }
            }
        }
    }

    /**
     * [91, 100]
     * [81, 90]
     * [71, 80]
     * ...
     * [0, 10]
     */
    void intvlSum(StMark records[], int arrSize) {
        int intervals[NUM_INTVLS] = {0};

        for (int i = 0; i < arrSize; ++i) {
            int tens = (records[i].mark - 1) / NUM_INTVLS;
            ++intervals[9 - tens];
        }
        
        printGraph(intervals, NUM_INTVLS, "Students' mark distribution");
    }

    void displayDetail(StMark records[], int arrSize) {
        for (int i = 0; i < arrSize; ++i) {
            printInt(i + 1, 3);
            cout << ": [";
            printInt(records[i].mark, 3);
            cout << "] " << records[i].name << " ";
            cout << records[i].surname << endl;
        }
        cout << "----------------------------------------" << endl;
    }

    bool printReport(const char* filename) {
        StMark records[MAX_NO_RECS];
        int numRecs = 0;

        if (openFile(filename)) {
            numRecs = readMarks(records);

            // Sort
            sort(records, numRecs);

            // Calculate and display interval sum
            intvlSum(records, numRecs);

            // Display
            displayDetail(records, numRecs);

            closeFile();
            return true;
        }
        return false;
    }
}
