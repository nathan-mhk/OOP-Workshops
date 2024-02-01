/**
 * Name: Nathan Kong
 * Email: nkong@myseneca.ca
 * ID: 150950236
 * Date: 2024-02-01
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Customer.h"

namespace seneca {
    /**
     * This query method checks if the object is in a safe empty state.
     * A customer is considered empty if the name pointer is null or
     * empty cString or the car pointer is null.
    */
    bool Customer::isEmpty() const {
        return true;
    }

    /**
     * This method sets the customer to a safe empty state by setting
     * the pointers to null and the id to 0.
    */
    void Customer::setEmpty() {

    }

    /**
     * This Member function deallocates the dynamically allocated
     * memory for the m_name member variable.
    */
    void Customer::deallocateMemory() {

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
