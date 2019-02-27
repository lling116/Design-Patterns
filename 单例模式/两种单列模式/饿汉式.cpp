#include<iostream>
using namespace std;
class  Singelton2
{
private:
	Singelton2()
	{
		m_singer = NULL;
		cout << "构造函数Singelton ... do" << endl;
	}

public:
	static Singelton2 *getInstance()
	{
		return m_singer;
	}
	static void Singelton2::FreeInstance()
	{
		if (m_singer != NULL)
		{
			delete m_singer;
			m_singer = NULL;
		}
	}


private:
	static Singelton2 *m_singer;
};

Singelton2 *Singelton2::m_singer = new Singelton2; //不管你创建不创建实例，均把实例new出来