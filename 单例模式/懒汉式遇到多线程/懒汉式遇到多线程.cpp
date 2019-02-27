static Singleton *getSingleton()
	{
		if(m_Singleton == NULL)  //double check 
		{   
			QMutex.lock(); //只有当pInstance等于null时，才开始使用加锁机制 二次检查
			if(m_Singleton == NULL)
			{
				m_Singleton = new Singleton(); 
			}
			QMutex.unlock();
		}
		return m_Singleton;
	}
	static Singleton *m_Singleton;
	
};

Singleton* Singleton::m_Singleton = 0;
