#include "mystl.h"

MyString::MyString(const char* word) {
	while (word[m_length] != '\0') {
		m_chain[m_length] = word[m_length];
		m_length++;
	}
	m_chain[m_length] = '\0';
}

void MyString::ClearTab()
{
	m_chain[0] = '\0';
	m_length = 0;
}

int MyString::Lenght()
{
	return m_length;
}

MyString MyString::Substr(int begin, int offset)
{
	MyString objectToReturn;
	while (objectToReturn.m_length < offset) {
		objectToReturn.m_chain[objectToReturn.m_length] = m_chain[begin + objectToReturn.m_length];
		objectToReturn.m_length++;
	}
	objectToReturn.m_chain[objectToReturn.m_length] = '\0';
	return objectToReturn;
}

MyString::MyString()
{
}

unsigned int MyString::Rfind(char key)
{
	char cur = 0;
	unsigned int pos = m_length;
	while (pos > 0) {	
		cur = m_chain[pos];
		if (cur != key) {
			pos--;
		}
		else
			break;
	}
	return pos;
}

bool MyString::Compare(const char* word)
{
	int difference = 0;
	while (word[difference] != '\0') {
		difference++;
	}
	if (difference == m_length) return true;
	else return false;
}

MyString& MyString::operator+=(const char cur)
{
	m_chain[m_length] = cur;
	m_length++;
	m_chain[m_length] = '\0';
	return *this;
}

std::ostream& operator<<(std::ostream out, const MyString& thing)
{
	out << thing.m_chain;
	return out;
}
