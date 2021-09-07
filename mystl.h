#ifndef MYSTL_H
#define MYSTL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_CHAR 100

//redefine string class
class MyString
{
private:
	char m_chain[MAX_CHAR] = { 0 };
	unsigned int m_length = 0;

public:
	//constructor
	MyString(const char* );
	MyString();
	MyString Substr(int, int);
	void ClearTab();
	unsigned int Rfind(char);
	int Lenght();
	bool Compare(const char*);
	MyString& operator+=(const char);
	friend std::ostream& operator<<(std::ostream, const MyString&); //Need to be finished

};


#endif MYSTL_H
