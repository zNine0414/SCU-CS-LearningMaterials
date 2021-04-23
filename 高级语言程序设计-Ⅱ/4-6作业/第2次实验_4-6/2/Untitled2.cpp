





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
		int num,basicSal,prize;//编号,基本工资,奖金
		char name[18];//姓名 
		float rateOfAttend;//出勤率
		void Output();
		float OutputWage();
		
};
void Staff::Output()
{
	cout<<"编号："<<num<<endl;
	cout<<"姓名："<<name<<endl;
	cout<<"出勤率："<<rateOfAttend<<endl;
	cout<<"基本工资："<<basicSal<<endl;
	cout<<"奖金："<<prize<<endl;
	
}
float Staff::OutputWage()
{//员工实发工资 = 基本工资 + 奖金 * 出勤率
	float test;
	test=basicSal+prize*rateOfAttend;
	cout<<"员工实发工资："<<test<<endl;
	return test;
}

class Saleman:virtual public Staff
{
	public:
		Saleman(int nm,int bsc,int prz,char nam[18],float rOA,float dR,float pA):
		Staff(nm, bsc, prz,nam, rOA),deductRate(dR),personAmount(pA)
		{
			
		}
		float deductRate;//销售员提成比例
		float personAmount;//个人销售额
		void Output();
		float OutputWage();
};
void Saleman::Output()
{
	cout<<"销售员提成比例："<<deductRate<<endl;
	cout<<"个人销售额："<<personAmount<<endl;
}
float Saleman::OutputWage()
{//销售员实发工资 = 基本工资 + 奖金 * 出勤率 + 个人销售额 * 销售员提成比例
	float test;
	test = basicSal+prize*rateOfAttend+personAmount*deductRate;
	cout<<"销售员实发工资："<<test<<endl;
	return test;
}
class Manager:virtual public Staff
{
	public:
		Manager(int nm,int bsc,int prz,char nam[18],float rOA,float tDe,float tAm):
		Staff(nm, bsc, prz,nam, rOA),totalDeductRate(tDe),totalAmount(tAm)
		{
			
		}
		float totalDeductRate;//经理提成比例
		float totalAmount;//总销售额
		void Output();
		float OutputWage();
};


void Manager::Output()
{
	cout<<"经理提成比例："<<totalDeductRate<<endl;
	cout<<"总销售额："<<totalAmount<<endl;
};
float Manager::OutputWage()
{//经理实发工资 = 基本工资 + 奖金 * 出勤率 + 总销售额 * 经理提成比例
	float test;
	test = basicSal+prize*rateOfAttend+totalAmount*totalDeductRate;
	cout<<"经理实发工资："<<test<<endl;
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
{//销售经理实发工资 =基本工资 + 奖金 * 出勤率 + 个人销售额 * 销售员提成比例+ 总销售额 * 经理提成比例
	float test;
	test = basicSal+prize*rateOfAttend+personAmount*deductRate+totalAmount*totalDeductRate;
	cout<<"销售经理实发工资："<<test<<endl;
	return test;
};


int main(void)			
{																
	SaleManager sa1(114514,15000,1000,"打工人",0.95,0.1,20000,0.2,40000);
	sa1.Output();
	sa1.OutputWage();
	system("PAUSE");   	
	return 0;          	
}	
