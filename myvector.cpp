#include "mystl.h"

MyPair MyPair::make_pair (const MyString& word, int occurency)
{
	m_pairWord = word;
	m_pairOccurency = occurency;
}

MyPair::MyPair()
{
}

void MyVector::_resize()
{
	MyPair* tab = new MyPair[m_maxCount];
	m_ptVectorTab = &tab[0];
	if (m_maxCount == m_count) {
		int oldMaxCount = m_maxCount;
		MyPair* tempTab = new MyPair[m_maxCount];
		tempTab = tab;
		m_maxCount *= 2;
		delete[] tab;
		MyPair* tab = new MyPair[m_maxCount];
		m_ptVectorTab = &tab[0];
	}
}

void MyVector::push_back(const MyPair& wordToAdd)
{
	*(m_ptVectorTab + m_count) = wordToAdd;
	m_count++;
}

int MyVector::find_if(int first, int last)
{
	for (int i = first; i < last; i++) {

	}
	return 0;
}

void MyVector::sort()
{

}

