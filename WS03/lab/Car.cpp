/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-01
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Car.h"
#include <cstring>
#include <iostream>

namespace seneca {
    /**
     * Member function to check if the object is in a safe recognizable
     * empty state. A car is considered empty if the either
     * "make and model" or "service description" is either null or an
     * empty cstring.
    */
    bool Car::isEmpty() const {
        return (m_makeModel == nullptr || strcmp(m_makeModel, "") == 0) &&
            (m_makeModel == nullptr || strcmp(m_serviceDesc, "") == 0);
    }

    /**
     * Member function sets the object a safe recognizable empty state.
     * setEmpty accomplishes this by setting the attributes to empty
     * cstring, nullptr and 0.0.
    */
    void Car::setEmpty() {
        strcpy(m_licencePlate, "");
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
        m_cost = 0;
    }

    /**
     * Member function to deallocate dynamically allocated memory for
     * "make and model" and "service description" member variables.
    */
    void Car::deallocateMemory() {
        delete[] m_makeModel;
        delete[] m_serviceDesc;
    }

    /**
     * Member function to Set car information and service details as follows.
     * - Deallocates existing memory and then sets it to a safe empty state.
     * - If the incoming information is valid (license plate is not empty
     *   and "make and model" and "description" are not null and not empty.
     *   note: the cost is not validated)
     *     - Copies the corresponding argument to the license plate attribute
     *     - Allocates memory and copies the data for car make and model
     *     - Allocates memory and copies the date for the service description
     *     - Assigns the 'serviceCost' value to the corresponding argument value.
    */
    void Car::set(
        const char plateNo[],
        const char* carMakeModel,
        const char* serviceDesc,
        double serviceCost
    ){
        deallocateMemory();
        setEmpty();

        if (
            strlen(plateNo) != 0 &&
            (carMakeModel != nullptr && strcmp(carMakeModel, "") != 0) &&
            (serviceDesc != nullptr && strcmp(serviceDesc, "") != 0)
        ) {
            strcpy(m_licencePlate, plateNo);

            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);

            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);

            m_cost = serviceCost;
        }
    }

    /**
     * This function displays the car in the following format:
     * - The labels of the data are left justified in 15 spaces.
     * - The data of the attributes are right justified in 20 spaces.
     * - The cost is displayed with 2 digits after the decimal point.
     * 
     * Sample output: 
     * 
     * License Plate:                  ABC
     * Model:                 Toyota Camry
     * Service Name:     Engine oil change
     * Service Cost:                 50.00
    */
    void Car::display() {
        if (isEmpty()) {
            return;
        }

        std::cout.width(15);
        std::cout << std::left << "License Plate:";
        std::cout.width(20);
        std::cout << std::right << m_licencePlate << std::endl;

        std::cout.width(15);
        std::cout << std::left << "Model:";
        std::cout.width(20);
        std::cout << std::right << m_makeModel << std::endl;

        std::cout.width(15);
        std::cout << std::left << "Service Name:";
        std::cout.width(20);
        std::cout << std::right << m_serviceDesc << std::endl;

        std::cout.width(15);
        std::cout << std::left << "Service Cost:";
        std::cout.width(20);
        std::cout.precision(2);
        std::cout << std::right << std::fixed << m_cost << std::endl;
    }
}
