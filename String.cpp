#include <iostream>
#include "String.h"

using namespace HomeMadeString;
String::String()
{
	pData=NULL;
	elementsNum=0;
}

String::String(const String& string)
{
	pData=NULL;
	copy(*this,string);
}

String::String(const char* str)
{
	unsigned int len=0;
	while (str[len] != '\0')
	{
		len++;
	}
	elementsNum = len;
	pData = new char[elementsNum + 1];

	for (unsigned int i = 0; i <= elementsNum; i++)
	{
		pData[i] = str[i];
	}

}
String::String(const char c, unsigned int times)
{
	elementsNum=times;

	if(elementsNum==0)
	{
		pData=NULL;
		return;
	}

	pData=new char[elementsNum+1];
	for(unsigned int i=0;i<elementsNum;i++)
	{
		pData[i]=c;
	}
	pData[elementsNum]='\0';
}


char& String::operator[](unsigned int pos)
{
	return pData[pos < elementsNum ? pos : 0];
}

//const char& String::operator[](unsigned int pos)const
//{
//	return pData[pos < elementsNum ? pos : 0];
//}

String String::operator+(const String& theOther)const
{
	return concatenate(*this, theOther);
}

const String& String::operator+=(const String &theOther)
{
	*this = *this + theOther;
	return *this;
}


const String& String::operator=(const String& theOther)
{
	copy(*this, theOther);
	return *this;
}


bool String::operator==(const String& theOther)const
{
	return compare(*this, theOther);
}


String::operator char*()const {
	return pData;
}

void String::operator()(const char* str)
{
	unsigned int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	elementsNum = len;
	pData = new char[elementsNum + 1];

	for (unsigned int i = 0; i <= elementsNum; i++)
	{
		pData[i] = str[i];
	}
}

String String::concatenate(const String & string1, const String & string2)
{
	String s;
	s.elementsNum=string1.elementsNum+string2.elementsNum;

	if(s.elementsNum==0)
	{
		s.pData=NULL;
		return s;
	}

	s.pData=new char[s.elementsNum+1];

	for(unsigned int i=0;i<string1.elementsNum;i++)
	{
		s.pData[i]=string1.pData[i];
	}
	for(unsigned int j=string1.elementsNum;j<s.elementsNum;j++)
	{
		s.pData[j]=string2.pData[j-string1.elementsNum];
	}

	s.pData[s.elementsNum]='\0';
	return s;
}

bool String::compare(const String & string1, const String & string2)
{
	if(string1.elementsNum!=string2.elementsNum)return false;

	for(unsigned int i=0;i<string1.elementsNum;i++)
	{
		if(string1.pData[i]!=string2.pData[i]) return false;
	}
	return true;
}

void String::copy(String &string1, const String &string2)
{
	delete string1.pData;	
	string1.elementsNum=string2.elementsNum;
	if(string1.elementsNum==0)
	{
		string1.pData=NULL;
		return;
	}
	string1.pData=new char[string1.elementsNum+1];
	for(unsigned int i=0;i<string1.elementsNum;i++)
	{
		string1.pData[i]=string2.pData[i];
	}
	string1.pData[string1.elementsNum]='\0';
}



namespace HomeMadeString
{
	std::ostream& operator << (std::ostream& os, const String& s)
	{
		for (unsigned int i = 0; i < s.getLength(); i++) {
			os << s[i];
		}
		return os;
	}
}