#include "mystl.h"

MyPair MyPair::make_pair (const MyString& word, int occurrence)
{
	MyPair ObjectToReturn;
	ObjectToReturn.m_pairWord = word;
	ObjectToReturn.m_pairOccurrence = occurrence;
	return ObjectToReturn;
}

void MyPair::IncrementOccurrence()
{
	m_pairOccurrence++;
}

MyPair::MyPair()
{
}

void MyVector::_resize()
{
	//cas 1 => tableau non alloué
	if (m_ptVectorTab == nullptr) { 
		if (m_maxCount == 0) { m_maxCount += 1; }
		MyPair* vectorTab = new MyPair[m_maxCount]; 
		m_ptVectorTab = vectorTab; 
	}
	//cas 2 => tab alloué mais place insuffisante ==> plein
	if (m_ptVectorTab != nullptr && m_count == m_maxCount) {
		m_maxCount *= 2;
		MyPair* newVectorTab = new MyPair[m_maxCount];
		for (int i = 0; i < m_count; i++) { newVectorTab[i] = m_ptVectorTab[i]; }
		delete[] m_ptVectorTab;
		m_ptVectorTab = newVectorTab;
	}
}

void MyVector::push_back(const MyPair& wordToAdd)
{
	if (m_count == m_maxCount) 
		_resize();
	m_ptVectorTab[m_count] = wordToAdd;
	m_count++;
}

int MyVector::find_if(int first, int last, MyString wordToCheck)
{
	for (int i = first; i < last; i++) {
			MyPair stringFromPair = m_ptVectorTab[i];
			if (wordToCheck.equals(stringFromPair.getText())) return i; 
	}
	return -1;
}

MyPair& MyVector::accessMyPairMember(int index)
{
	return m_ptVectorTab[index];
}

void MyVector::sort()
{
	int counter = m_count;
	int inversion;
	do
	{
		inversion = 0;
		for (int i = 0; i < counter - 1; i++)
		{
			if (m_ptVectorTab[i].getOccurrence() > m_ptVectorTab[i + 1].getOccurrence())
			{
				MyPair temp;
				temp = m_ptVectorTab[i + 1];
				m_ptVectorTab[i] = m_ptVectorTab[i + 1];
				m_ptVectorTab[i + 1] = temp;
				inversion = 1;
			}
		}
		counter--;
	} while (inversion);
}
