#include <iostream>
using namespace std;

//抽象产品
class Fruit
{
public:
	virtual void SayName() = 0;
};

//抽象工厂
class AbstractFactory
{
public:
	virtual Fruit* CreateBanana() = 0;
	virtual Fruit* CreateApple() = 0;
};

class NorthBanana : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "我是北方香蕉" << endl;
	}
};

class NorthApple : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "我是北方苹果" << endl;
	}
};


class SourthBanana : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "我是南方香蕉" << endl;
	}
};


class SourthApple : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "我是南方苹果" << endl;
	}
};

class NorthFacorty : public AbstractFactory
{
	virtual Fruit * CreateBanana()
	{
		return new NorthBanana;
	}
	virtual Fruit * CreateApple()
	{
		return new NorthApple;
	}
};

class SourthFacorty : public AbstractFactory
{
	virtual Fruit * CreateBanana()
	{
		return new SourthBanana;
	}
	virtual Fruit * CreateApple()
	{
		return new SourthApple;
	}
};


void main()
{
	Fruit			*fruit = NULL;
	AbstractFactory *af = NULL;

	///--------------
	af = new SourthFacorty;
	fruit = af->CreateApple();
	fruit->SayName();
	delete fruit;
	fruit = af->CreateBanana();
	fruit->SayName();
	delete fruit;

	///我们想吃北方的水果，只要把南方工厂改为北方工厂就行了，这体现了解耦合
	af = new NorthFacorty;
	fruit = af->CreateApple();
	fruit->SayName();
	delete fruit;
	fruit = af->CreateBanana();
	fruit->SayName();
	delete fruit;

	delete af;
	system("pause");
	return ;
}