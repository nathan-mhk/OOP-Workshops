/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
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
 * Date: 2024-03-05
 * 
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

   Email::~Email() {
      delete[] m_name;
      delete[] m_email;
   }

    void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

            return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }

    /**
     * Load the file m_filename into a dynamic array of Emails pointed by m_emailLines:
     * 
     * If the m_filename is null, this function does nothing.
     * 
     * If the m_filename is not null (EmailFile is not in a safe empty state),
     * loadEmails() will dynamically allocate an array of Emails pointed by
     * m_emailLines with the size kept in m_noOfEmails. Hint: Make sure m_emailLines
     * is deleted before this to prevent memory leaks.
     * 
     * Open a file for reading by creating an ifstream object, using the file name
     * stored in m_filename. Start a loop that will read the file one line at a time,
     * where each line represents a single email record. For every line read, call the
     * Email::load function to process and store the data in a new Email object.
     * 
     * If a line cannot be correctly processed and turned into an Email object, perhaps
     * because of incorrect formatting, stop reading any further by breaking the loop.
     * After finishing the file reading, adjust m_noOfEmails to reflect the actual
     * number of emails read from the file, ensuring it accounts for the scenario
     * where there might be an extra empty line at the file's end that shouldn't be
     * considered a valid email record.
    */
    void EmailFile::loadEmails() {
        if (!m_filename) return;

        delete[] m_emailLines;
        m_emailLines = new Email[m_noOfEmails];

        ifstream ifs(m_filename);
        if (!ifs.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
            return;
        }

        int i = 0;
        for (; i < m_noOfEmails && !ifs.eof(); ++i) {
            if (!m_emailLines[i].load(ifs)) {
                break;
            }
        }
        m_noOfEmails = i;
        ifs.close();
    }

    /**
     * Returns true if the EmailFile is not in an empty state and returns false if it is.
    */
    EmailFile::operator bool() const {
        return m_emailLines && m_filename && m_noOfEmails;
    }

    /**
     * Copy Assignment
     * 
     * Overwrite the current data by the content of the incoming EmailFile.
     * 
     * - Check self-assignment and check if the source object is valid
     * 
     * - If the source and destination objects are different, the function removes the old
     *   data from the destination object.
     * 
     * - Create a new memory space in the current object and then take each piece of data
     *   in the source object and copy it over to the destination object.
    */
    EmailFile& EmailFile::operator=(const EmailFile& e) {
        if (*this != e && e) {
            setEmpty();

            setFilename(e.m_filename);

            m_noOfEmails = e.m_noOfEmails;
            
            m_emailLines = new Email[m_noOfEmails];

            for (int i = 0; i < m_noOfEmails; ++i) {
                m_emailLines[i] = e.m_emailLines[i];
            }
        }
        return *this;
    }

    /**
     * If the input argument is nullptr sets the EmailFile object to a safe empty state.
     * Otherwise, it will set the filename, set the m_noOfEmails and finally load the
     * Emails (using the corresponding private methods.)
    */
   EmailFile::EmailFile(const char* fileName) {
    if (fileName) {
        setFilename(fileName);
        if (setNoOfEmails()) {
            loadEmails();
            return;
        }
    }
    setEmpty();
   }

    /**
     * Start by setting the object to a safe empty state. If the provided EmailFile object
     * is correct and usable, do these steps to make a safe copy of the EmailFile and its
     * details:
     * 
     * - Copy the File Name: Take the file name from the given EmailFile object and use it
     *   as the file name for the new one.
     * 
     * - Record the Email Count: Make a note of the number of emails from the original
     *   EmailFile object.
     * 
     * - Copy Each Email: For the emails in the original EmailFile, create new memory
     *   spaces and fill them with the exact content from the old emails.
    */
    EmailFile::EmailFile(const EmailFile& e) {
        setEmpty();
        *this = e;
    }

    // Destructor
    EmailFile::~EmailFile() {
        setEmpty();
    }

    /**
     * This method takes a Cstring as an input argument and tries to save email information
     * to this file. It gives back a simple 'yes' (true) or 'no' (false) if it could open
     * the file or not.
     * 
     * - First, it tries to create or open the file.
     * 
     * - If it can't open the file, it reports, "Error: Could not open file: [filename]."
     * 
     * Once the file is open, it proceeds to write the email data:
     * 
     * - It looks at each email saved in its memory (each one is an "Email" object in a big
     *   list called "m_emailLines").
     * 
     * - For every email, it writes down the details following the CSV format to the file.
    */
    bool EmailFile::saveToFile(const char* fileName) const {
        ofstream ofs(fileName, ofstream::out);

        if (ofs.is_open()) {
            for (int i = 0; i < m_noOfEmails; ++i) {
                ofs << m_emailLines[i].m_email << ",";
                ofs << m_emailLines[i].m_name << ",";
                ofs << m_emailLines[i].m_year << endl;
            }
            ofs.close();
            return true;
        }
        cout << "Error: Could not open file: " << fileName << "." << endl;
        return false;
    }

    /**
     * The fileCat method merges emails from another EmailFile object into the current
     * object and optionally renames the resulting file. Here's a breakdown of its actions:
     * 
     * 1. Initial Check: It first ensures both the current EmailFile and the one provided as
     *    an argument is in a valid state. If either doesn't, it exits silently.
     * 
     * 2. Counting Emails: It totals up the number of emails from both files, preparing to
     *    consolidate them.
     * 
     * 3. Preparing Space: If there are emails in either file, it makes room to gather all
     *    emails from both into one combined space.
     * 
     * 4. Combining Emails: The method then brings all emails together. It starts with emails
     *    from the current object, followed by those from the provided object, assembling
     *    them into one comprehensive list.
     * 
     * 5. Cleaning Up: It discards the previous, separate lists since they've been merged
     *    into a larger, unified one.
     * 
     * 6. Handling File Name: If a specific name is provided (meaning the second argument
     *    isn't nullptr), it renames the file accordingly. Otherwise, it retains the original
     *    name.
     * 
     * 7. Saving: To finalize, it saves the unified list of emails under the designated file
     *    name (whether original or newly assigned) to preserve the merged data.
    */
    void EmailFile::fileCat(const EmailFile& obj, const char* name) {
        // Step 1
        if (!*this || !obj) return;

        // Step 2
        const int totalEmails = m_noOfEmails + obj.m_noOfEmails;

        // Step 3
        Email* emails = new Email[totalEmails];

        // Step 4
        int i = 0;
        for (; i < m_noOfEmails; ++i) {
            emails[i] = m_emailLines[i];
        }

        for (int j = 0; j < obj.m_noOfEmails; ++i, ++j) {
            emails[i] = obj.m_emailLines[j];
        }

        // Step 5
        delete[] m_emailLines;
        m_emailLines = emails;
        m_noOfEmails = totalEmails;

        // Step 6
        if (name) setFilename(name);
        
        // Step 7
        saveToFile(m_filename);
    }

}