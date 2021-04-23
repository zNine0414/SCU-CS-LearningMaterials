





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
	cout<<"Ա��ʵ�����ʣ�"<<test<<endl;
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
	cout<<"����Աʵ�����ʣ�"<<test<<endl;
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
	cout<<"����ʵ�����ʣ�"<<test<<endl;
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
	cout<<"���۾���ʵ�����ʣ�"<<test<<endl;
	return test;
};


int main(void)			
{																
	SaleManager sa1(114514,15000,1000,"����",0.95,0.1,20000,0.2,40000);
	sa1.Output();
	sa1.OutputWage();
	system("PAUSE");   	
	return 0;          	
}	
