//���һ��������Date, Ҫ��
//��1��������(year)����(month)����(day)˽�����ݳ�Ա��
//��2���������캯�������ع���һ���ڼ��������ļӷ������+�����ع���һ���ڼ�ȥ�����ļ��������-��������������<<�����������>>�ȡ�
 
#include <iostream>
using namespace std;

int monthtest(int m)
{
	if (m>12)
	{
		return m-12;
	}
	else if (m<0)
	{
		return m+12;
	}
	else return m;
};
class Date
{
	private:
		int year,month,day;
	public:
		Date(int y=0,int m=0,int d=0):year(y),month(m),day(d){}
		friend ostream &operator<<(ostream &cout,Date &a)
		{
			cout<<"������"<<a.year<<"��"<<a.month<<"��"<<a.day<<"��"<<endl;
			return cout;
		}
		friend istream &operator >> ( istream &cin, Date &a )
		{
			cin>>a.year>>a.month>>a.day;
			return cin; 
		}
		int operator+(int a)
		{
			if(this->month==4||this->month==6||this->month==9||this->month==11)
			{
				if(this->day+a>30)
				{
					this->month++;
					this->month=monthtest(this->month);
					this->day+=a-30;
				}
				else this->day+a;
			}
			else if(this->month==2)
			{
				if(this->day+a>28)
				{
					this->month++;
					this->month=monthtest(this->month);
					this->day+=a-28;
				}
				else this->day+a;
			}
			else 
			{
				if(this->day+a>31)
				{
					this->month++;
					this->month=monthtest(this->month);
					this->day+=a-31;
				}
				else this->day+a;
			}
			return 0;
		}
		int operator-(int a)
		{
			if(this->month==5||this->month==7||this->month==10||this->month==12)
			{
				if(this->day-a<0)
				{
					this->month--;
					this->month=monthtest(this->month);
					this->day+=-a+30;
				}
				else this->day-a;
			}
			else if(this->month==3)
			{
				if(this->day-a<0)
				{
					this->month--;
					this->month=monthtest(this->month);
					this->day+=-a+28;
				}
				else this->day-a;
			}
			else 
			{
				if(this->day-a<0)
				{
					this->month--;
					this->month=monthtest(this->month);
					this->day+=-a+31;
				}
				else this->day+=-a;
			}
			return 0;
		}
};
int main(void)
{
	Date chuang3;
	cout<<"����ԭ���ڣ��ÿո������"<<endl; 
	cin>>chuang3;
	
	chuang3+28; 
	cout<<"ԭ����+28="<<chuang3<<endl; 
	chuang3-30;
	cout<<"ԭ����-30="<<chuang3<<endl; 
	system("PAUSE");
	return 0;
}

