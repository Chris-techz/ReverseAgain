#ifndef MYSTL_H
#define MYSTL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_CHAR 100

class MyString
{
private:
	char m_chain[MAX_CHAR] = { 0 };
	int m_length = 0;

public:
	MyString(const char* );
	MyString();
	MyString substr(int, int);
	void clear();
	unsigned int rfind(char) const;
	int length() const;
	bool equals(const MyString&) const;
	MyString& operator+=(const char);
	MyString operator+(const MyString&);
	operator const char* () { return m_chain; }
	operator const char* () const { return m_chain; }
	bool empty() const;
	void reverse();

};

class MyPair
{
protected:
	MyString m_pairWord;
	unsigned int m_pairOccurrence = 0;
public:
	MyPair();
	static MyPair make_pair(const MyString&, int);
	//method to acces members from find_if
	MyString& getText() { return m_pairWord; }
	int getOccurrence() { return m_pairOccurrence; }
	void IncrementOccurrence();

};

class MyVector
{
protected:
	MyPair* m_ptVectorTab = nullptr;
	int m_maxCount = 0;
	int m_count = 0;
	void _resize();
public:
	~MyVector() { delete[] m_ptVectorTab; }
	void push_back(const MyPair&);
	int find_if(int, int, MyString wordToCheck);
	MyPair& accessMyPairMember(int);
	//void print();
	void sort();
	int begin() { return 0; }
	int end() { return m_count; }
};
#endif MYSTL_H
