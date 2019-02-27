#include<iostream>
using namespace std;

class Singelton{

private:
	Singelton(){
		cout << "单列构造函数" << endl;
	}
public:
	static Singelton* getSingelton(){
		  if(m_Singelton == NULL)
		  {
			  m_Singelton = new Singelton;
		  }

		  return m_Singelton;
   }

	static void Singelton::FreeInstance()
	{
		if (m_Singelton != NULL)
		{
			delete m_Singelton;
			m_Singelton = NULL;
			
		}
	}

private:
	static Singelton *m_Singelton;
};
Singelton *Singelton::m_Singelton = NULL;//初始化静态变量

void showSingelton()
{
	cout << "演示 懒汉式" << endl;
	Singelton *p1 = Singelton::getSingelton(); //只有在使用的时候，才去创建对象。
	Singelton *p2 = Singelton::getSingelton();
	if (p1 != p2)
	{
		cout << "不是同一个对象" << endl;
	}
	else
	{
		cout << "是同一个对象" << endl;
	}

	Singelton::FreeInstance();
	return;
}

void main()
{
	showSingelton();
	cout << "hello" << endl;
	system("pause");
}