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
	unsigned int m_length = 0;

public:
	MyString(const char* );
	MyString();
	MyString substr(int, int);
	void clear();
	unsigned int rfind(char) const;
	int length() const;
	bool compare(MyString) const;
	MyString& operator+=(const char);
	MyString operator+(const MyString&);
	operator const char* () { return m_chain; }
	bool empty() const;
	void reverse();

};

class MyPair
{
protected:
	MyString m_pairWord;
	unsigned int m_pairOccurency = 0;
public:
	MyPair();
	MyPair make_pair(const MyString&, int);
};

class MyVector : public MyPair
{
protected:
	MyPair* m_ptVectorTab = nullptr;
	int m_maxCount = 2;
	int m_count = 0;
	void _resize();
public:
	~MyVector() { delete[] m_ptVectorTab; }
	void push_back(const MyPair&);
	int find_if(int, int);
	void sort();
	int begin() { return 0; }
	int end() { return m_count; }
};
#endif MYSTL_H
