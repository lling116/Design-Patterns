#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include "string"


class Person
{
public:
	virtual Person* clone() = 0;
	virtual void printT() = 0;
};

class  CPlusPlusProgrammer : public Person
{
public:
	CPlusPlusProgrammer()
	{
		m_name = "";
		m_age = 0;
	}
	CPlusPlusProgrammer(string name, int age)
	{
		m_name = name;
		m_age = age;
	}

	virtual void printT()
	{
		cout << "m_name" << m_name << " m_age" << m_age<< endl;
	}
	virtual Person* clone()
	{
		CPlusPlusProgrammer *tmp = new CPlusPlusProgrammer;
		//tmp->m_name = this->m_name;
		*tmp = *this; //可能会出现深拷贝和浅拷贝的问题
		return tmp;
	}
protected:
private:
	string	m_name;
	int		m_age ;
		
};