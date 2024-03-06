/***********************************************************************
// OOP244 Workshop # 6
//
// File:	EmailFile.h
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

#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca{

	const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

	class EmailFile;
	class Email
	{
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{'\0'};
		Email() {};
		Email& operator=(const Email&);
		bool load(std::ifstream& in);
		~Email();
		// Prohibit the copy constructor for this class:
		Email(const Email& e) = delete;

		// Make the EmailFile class a "friend" of the Email class
		friend EmailFile;
	};

	
	class EmailFile
	{
		Email* m_emailLines{ nullptr };
		char* m_filename{};
		int m_noOfEmails{ 0 }; 
		void setFilename(const char* filename);
		void setEmpty();
		bool setNoOfEmails();

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
		void loadEmails();

		/**
		 * Returns true if the EmailFile is not in an empty state and returns false if it is.
		*/
		operator bool()const;

	public:
		
		std::ostream& view(std::ostream& ostr) const;

		// Creates an empty EmailFile and sets it to a safe empty state.
		EmailFile() {};

		/**
		 * If the input argument is nullptr sets the EmailFile object to a safe empty state.
		 * Otherwise, it will set the filename, set the m_noOfEmails and finally load the
		 * Emails (using the corresponding private methods.)
		*/
		EmailFile(const char* fileName);

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
		EmailFile& operator=(const EmailFile& e);

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
		EmailFile(const EmailFile& e);

		// Destructor
		~EmailFile();

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
		bool saveToFile(const char* fileName) const;

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
		void fileCat(const EmailFile& obj, const char* name = nullptr);
	};

	std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);

}
#endif // !SENECA_EMAILFILE_H
