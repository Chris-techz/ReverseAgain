#include "mystl.h"

MyString::MyString(const char* word) {
	while (word[m_length] != '\0') {
		m_chain[m_length] = word[m_length];
		m_length++;
	}
	m_chain[m_length] = '\0';
}

void MyString::clear(){
	m_chain[0] = '\0';
	m_length = 0;
}

int MyString::length() const
{
	return m_length;
}

MyString MyString::substr(int begin, int count)
{
	MyString objectToReturn;
	while (objectToReturn.m_length < count) {
		objectToReturn.m_chain[objectToReturn.m_length] = m_chain[begin + objectToReturn.m_length];
		objectToReturn.m_length++;
	}
	objectToReturn.m_chain[objectToReturn.m_length] = '\0';
	return objectToReturn;
}

MyString::MyString()
{
}

unsigned int MyString::rfind(char key) const
{
	char cur = 0;
	int pos = m_length;	
	while (pos >= 0) {	
		cur = m_chain[pos];
		if (cur != key) {
			pos--;
		}
		else
			break;
	}
	return pos;
}

bool MyString::equals(const MyString& word) const
{
	for (int i = 0; i <= length(); i++) 
		if (word.m_chain[i] != m_chain[i]) 
			return false;
	return true;
}

MyString& MyString::operator+=(const char cur)
{
	m_chain[m_length] = cur;
	m_length++;
	m_chain[m_length] = '\0';
	return *this;
}

MyString MyString::operator+(const MyString& toAdd)
{
	MyString result;
	result = *this;
	for (int i = 0; i < toAdd.m_length; i++) {
		result += *(toAdd.m_chain + i);
	}

	return result.m_chain;
}

bool MyString::empty() const
{
	return (m_length == 0);
}

void MyString::reverse()
{
	for (int i = 0; i < m_length / 2; i++) {
		char temp = m_chain[i];
		m_chain[i] = m_chain[m_length - 1 - i];
		m_chain[m_length - 1 - i] = temp;
	}
}