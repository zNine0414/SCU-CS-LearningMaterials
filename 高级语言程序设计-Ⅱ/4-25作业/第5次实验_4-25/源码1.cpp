//(Account��������ࣩ�ڳ��������ϰ9.3�У����Ǵ�����Account������ģ�����˻���һ��
//�˻����˺š��������ʺ��˻�����ʱ������ԣ����д���ȡ�����������������������
//һһ֧Ʊ�˻��ʹ����˻���ǰ����һ��͸֧��ȣ����߲�����͸֧������Account���һ��
//�����麯��toString()�����������า�������������ַ�����ʽ�����˺ŵ���
//������Щ���UMLͼ��ʵ�ָ��࣬����дһ�����Գ���������һ��Account��һ��
//SavingsAccount��һ��CheckingAccount�˻������������ǵ�toString()����
//�������ӵ�һ��Ҫ��
//����һ����ͨ����function���������������ܹ�ͨ��һ�д��루��toString�����ĵ��ã���
//������ַ������͵�֧Ʊ�����˻����Ӷ�ʵ�ֶ�̬�󶨣�Ϊfunction������д���Դ��벢��������
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
			cout<<"���Ϊ"<<s<<"Ԫ"<<endl;
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
			cout<<"���Ϊ"<<s<<"Ԫ"<<endl;
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
	cout<<"ֱ�ӵ���toString��"<<endl;
	ac.toString();
	ca.toString();
	sa.toString();
	cout<<endl<<endl<<"��function����toString:"<<endl;
	function(ac);
	function(ca);
	function(sa);
	system("PAUSE");
	return 0;
}
