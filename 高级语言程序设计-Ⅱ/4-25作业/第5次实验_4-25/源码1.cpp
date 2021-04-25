//(Account类的派生类）在程序设计练习9.3中，我们创建了Account类来建模银行账户。一个
//账户有账号、余额、年利率和账户创建时间等属性，还有存款和取款函数。创建它的两个派生类
//一一支票账户和储蓄账户，前者有一个透支额度，后者不允许透支。定义Account类的一个
//常量虚函数toString()，并在派生类覆盖它，用来以字符串形式返回账号的余额。
//画出这些类的UML图，实现该类，并编写一个测试程序，它创建一个Account、一个
//SavingsAccount和一个CheckingAccount账户，并调用它们的toString()函数
//另外增加的一个要求：
//定义一个普通函数function（），函数体中能够通过一行代码（对toString（）的调用），
//来获得字符串类型的支票或储蓄账户余额，从而实现动态绑定；为function（）编写测试代码并输出结果。
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

class Account
{
	public:
		int zhanghu;
		double yue;
		double nianlilv;
		int shijian[3];
		Account(int zh,double y,double n,int year,int month,int day):
			zhanghu(zh),yue(y),nianlilv(n)
		{
			shijian[0]=year;
			shijian[1]=month;
			shijian[2]=day;
		};
		virtual void toString(){};
		virtual void cun(float a)
		{
			yue+=a;
		}
		virtual void qu(float a)
		{
			yue-=a;
		}
		
};

class CheckingAccount:public Account
{
	public:
		CheckingAccount(int zh,double y,double n,int year,int month,int day,int ad):
			Account(zh,y,n,year,month,day),Overdraft(ad){ }
		int Overdraft;
		void toString()
		{
			char s[1000];
			sprintf(s,"%.0f",yue);
			cout<<"余额为"<<s<<"元"<<endl;
		}
} ;

class SavingAccount:public Account
{
	public:
		SavingAccount(int zh,double y,double n,int year,int month,int day):
			Account(zh,y,n,year,month,day){	}
		void toString()
		{
			char s[1000];
			sprintf(s,"%.0f",yue);
			cout<<"余额为"<<s<<"元"<<endl;
		}
};

void function(Account &a)
{
	a.toString();
}
int main()
{
	Account ac(123,200000,0.005,2020,7,4); 
	CheckingAccount ca(789,40000.0,0.0003,2021,1,1,200000);
	SavingAccount sa(456,300000.0,0.0001,2019,9,9);
	cout<<"直接调用toString："<<endl;
	ac.toString();
	ca.toString();
	sa.toString();
	cout<<endl<<endl<<"用function调用toString:"<<endl;
	function(ac);
	function(ca);
	function(sa);
	system("PAUSE");
	return 0;
}
