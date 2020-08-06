#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace HomeMadeString
{
	class String
	{
	private:
		// Number of characters in the string
		unsigned int elementsNum;
		// Pointer to the memory segment containing the characters
		char*pData;

	public:
		// Default constructor (without arguments)
		String();

		// Copy constructor
		String(const String&string);

		// Conversion constructor that expects a char* with '\0' at the end
		// This constructor is responsible for the conversion char*-> String
		String(const char* str);

		// Constructor with a char (c) and an int parameter (times)
		// This constructor creates a string that contains 'times' pieces of the character c
		// e.g. if c='$' and times=5 then String="$$$$$"
		String(char c, unsigned int times);

		// Destructor
		~String() { delete[]pData; }

		// Returns with the string length
		unsigned int getLength()const { return elementsNum; }

		// Returns with the character at the given position, otherwise 0
		char& operator[](unsigned int pos);

		// Overloaded operators
		String operator+(const String& theOther)const;
		const String& operator+=(const String &theOther);
		const String& operator=(const String& theOther);
		bool operator==(const String& theOther)const;
		bool operator!=(const String& theOther)const { return !(*this == theOther); };
		void operator()(const char* str);

		// Returns a read-only access to String
		operator char*()const;



		// --- Static functions. They operate on two strings. ---

		// Concatenates two strings
		static String concatenate(const String& string1, const String& string2);

		// Compares two strings
		static bool compare(const String& string1, const String& string2);

		// Copies the second string to the first one
		static void copy(String& string1, const String &string2);

	};



	// Global function that prints String to stream
	std::ostream& operator << (std::ostream& os, const String& s);
	
}

#endif /* STRING_H */