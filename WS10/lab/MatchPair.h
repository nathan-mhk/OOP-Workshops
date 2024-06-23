/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-04-02
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef MATCHPAIR_H
#define MATCHPAIR_H

namespace seneca {

    template<typename T1, typename T2>
    struct Pair {
        T1 first {};
        T2 second {};
    };

    template<typename T, typename U>
    void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size) {
        Pair<T, U>* temp = new Pair<T, U>[size + 1];
        for (int k = 0; pArray && k < size; k++) {
            temp[k] = pArray[k];
        }
        temp[size].first = first;
        temp[size].second = second;
        delete[] pArray;
        pArray = temp;
        size++;
    }

    template<typename T1, typename T2>
    Pair<T1, T2>* matches(T1* arr1, T2* arr2, const int& size1, const int& size2, int& newSize) {
        Pair<T1, T2>* pt = nullptr;
        newSize = 0;

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                if (arr1[i] == arr2[j])
                    addDynamicPairElement(pt, arr1[i], arr2[j], newSize);
            }
        }
        return pt;
    }

    template<typename T>
    void releaseMem(T* ptr) {
        if (ptr) {
            delete[] ptr;
            ptr = nullptr;
        }
    }
}

#endif
