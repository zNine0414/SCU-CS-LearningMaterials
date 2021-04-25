//1����д��ͨ����function()���������ͷ���ֵ�����Զ���
//���ܣ������˾��������Ա��������Ա�����۾���ȸ�����Ա��ʵ�ʷ��Ź������
//����д���Դ��롣


#include <iostream>
#include<cstring>
using namespace std;


class Staff
{
	public:
	Staff(int nm,int bsc,int prz,char nam[18],float rOA):num(nm),basicSal(bsc),prize(prz),rateOfAttend(rOA)
	{
		strcpy(name,nam);
	}
	public:
		int num,basicSal,prize;//���,��������,����
		char name[18];//���� 
		float rateOfAttend;//������
		void Output();
		float OutputWage();
		
};
void Staff::Output()
{
	cout<<"��ţ�"<<num<<endl;
	cout<<"������"<<name<<endl;
	cout<<"�����ʣ�"<<rateOfAttend<<endl;
	cout<<"�������ʣ�"<<basicSal<<endl;
	cout<<"����"<<prize<<endl;
	
}
float Staff::OutputWage()
{//Ա��ʵ������ = �������� + ���� * ������
	float test;
	test=basicSal+prize*rateOfAttend;
	cout<<test<<endl;
	return test;
}

class Saleman:virtual public Staff
{
	public:
		Saleman(int nm,int bsc,int prz,char nam[18],float rOA,float dR,float pA):
		Staff(nm, bsc, prz,nam, rOA),deductRate(dR),personAmount(pA)
		{
			
		}
		float deductRate;//����Ա��ɱ���
		float personAmount;//�������۶�
		void Output();
		float OutputWage();
};
void Saleman::Output()
{
	cout<<"����Ա��ɱ�����"<<deductRate<<endl;
	cout<<"�������۶"<<personAmount<<endl;
}
float Saleman::OutputWage()
{//����Աʵ������ = �������� + ���� * ������ + �������۶� * ����Ա��ɱ���
	float test;
	test = basicSal+prize*rateOfAttend+personAmount*deductRate;
	cout<<test<<endl;
	return test;
}
class Manager:virtual public Staff
{
	public:
		Manager(int nm,int bsc,int prz,char nam[18],float rOA,float tDe,float tAm):
		Staff(nm, bsc, prz,nam, rOA),totalDeductRate(tDe),totalAmount(tAm)
		{
			
		}
		float totalDeductRate;//������ɱ���
		float totalAmount;//�����۶�
		void Output();
		float OutputWage();
};


void Manager::Output()
{
	cout<<"������ɱ�����"<<totalDeductRate<<endl;
	cout<<"�����۶"<<totalAmount<<endl;
};
float Manager::OutputWage()
{//����ʵ������ = �������� + ���� * ������ + �����۶� * ������ɱ���
	float test;
	test = basicSal+prize*rateOfAttend+totalAmount*totalDeductRate;
	cout<<test<<endl;
	return test;
};


class SaleManager:virtual public Saleman,virtual public Manager
{
	public:
		SaleManager(int nm,int bsc,int prz,char nam[18],float rOA,float dR,float pA,float tDe,float tAm):
			Staff(nm, bsc, prz,nam, rOA),
			Saleman(nm,bsc,prz,nam,rOA,dR,pA),
			Manager(nm,bsc,prz,nam, rOA,tDe,tAm)
			{
				
			}
		void Output();
		float OutputWage();
};
void SaleManager::Output()
{
	Staff::Output();
	Saleman::Output();
	Manager::Output();
	
	
};
float SaleManager::OutputWage()
{//���۾���ʵ������ =�������� + ���� * ������ + �������۶� * ����Ա��ɱ���+ �����۶� * ������ɱ���
	float test;
	test = basicSal+prize*rateOfAttend+personAmount*deductRate+totalAmount*totalDeductRate;
	cout<<test<<endl;
	return test;
};

void function(Manager &a,Saleman &b,SaleManager &c)
{
	cout<<"������Ա��er�Ĺ�����"<<a.OutputWage()<<"Ԫ"<<endl;
	cout<<"������Ա���ڿ��Ĺ�����"<<b.OutputWage()<<"Ԫ"<<endl;
	cout<<"���۾�����zz�Ĺ�����"<<c.OutputWage()<<"Ԫ"<<endl;
	
	
};
int main()
{
	Manager ma(303,1800,200,"��er",0.9,0.4,25000);
	Saleman sa(202,2000,400,"���ڿ�",1,0.3,15000);
	SaleManager sama(101,1800,500,"��zz",0.9,0.2,16000,0.25,30000);
	
	function(ma,sa,sama);
	
	
	system("PAUSE");
	return 0;
 } 
