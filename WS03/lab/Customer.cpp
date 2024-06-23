/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-01
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Customer.h"
#include <cstring>
#include <iostream>

namespace seneca {
    /**
     * This query method checks if the object is in a safe empty state.
     * A customer is considered empty if the name pointer is null or
     * empty cString or the car pointer is null.
    */
    bool Customer::isEmpty() const {
        return (m_name == nullptr || strcmp(m_name, "") == 0) &&
        m_car == nullptr;
    }

    /**
     * This method sets the customer to a safe empty state by setting
     * the pointers to null and the id to 0.
    */
    void Customer::setEmpty() {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }

    /**
     * This Member function deallocates the dynamically allocated
     * memory for the m_name member variable.
    */
    void Customer::deallocateMemory() {
        delete[] m_name;
    }

    /**
     * Member function to Set the Customer name, ID and Car.
     * - Deallocates existing memory and then sets it to a safe empty
     *   state.
     * - If the incoming information is valid (i.e. the name is not
     *   null and not empty and the Car pointer is not null. The ID
     *   is not validated)
     *     - Copies the corresponding argument to the ID attribute
     *     - Allocates memory and copies the data for the name of the
     *       customer
     *     - Assigns the Car pointer attribute to the corresponding
     *       argument
    */
    void Customer::set(int customerId, const char* name, const Car* car) {
        if (m_car != nullptr) {
            m_car->deallocateMemory();
        }
        deallocateMemory();
        
        if (m_car != nullptr) {
            m_car->setEmpty();
        }
        setEmpty();

        if (
            name != nullptr && strcmp(name, "") != 0 && car != nullptr
        ) {
            m_id = customerId;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_car = const_cast<Car*>(car);
        }
    }

    /**
     * This function displays the Customer in the following format:
     * - The labels of the data are left justified in 15 spaces.
     * - The data of the attributes are right justified in 20 spaces.
     *   After the customer information is printed, the Car will be
     *   displayed.
     * 
     * Sample output:
     * Customer ID:                   1005
     * First Name:              Jane Smith
     * License Plate:                  ABC
     * Model:                 Toyota Camry
     * Service Name:     Engine oil change
     * Service Cost:                 50.00
    */
    void Customer::display() const {
        if (isEmpty() || m_car->isEmpty()) {
            return;
        }

        std::cout.width(15);
        std::cout << std::left << "Customer ID:";
        std::cout.width(20);
        std::cout << std::right << m_id << std::endl;

        std::cout.width(15);
        std::cout << std::left << "First Name:";
        std::cout.width(20);
        std::cout << std::right << m_name << std::endl;
        
        m_car->display();
    }

    /**
     * This function returns the car object pointed to by m_car
     * pointer by dereferencing it. There is no need to validate
     * the pointer prior to dereferencing. It can be assumed to be
     * valid.
    */
    const Car& Customer::car() const {
        return *m_car;
    }
}
