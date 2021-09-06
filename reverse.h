#ifndef REVERSE_H
#define REVERSE_H

#define MAX_CHAR 64
//redefine string class
class MyString
{
private:
	char m_tab[MAX_CHAR];
	unsigned int m_lenght;

public:
	//constructor
	String(char*);
	void Substr(int a, int b);
	void clearTab();

};


#endif REVERSE_H
