//设计一个日期类Date, 要求：
//（1）包含年(year)、月(month)和日(day)私有数据成员。
//（2）包含构造函数，重载关于一日期加上天数的加法运算符+、重载关于一日期减去天数的减加运算符-、重载输出运算符<<与输入运算符>>等。
 
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
			cout<<"现在是"<<a.year<<"年"<<a.month<<"月"<<a.day<<"日"<<endl;
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
	cout<<"输入原日期，用空格隔开："<<endl; 
	cin>>chuang3;
	
	chuang3+28; 
	cout<<"原日期+28="<<chuang3<<endl; 
	chuang3-30;
	cout<<"原日期-30="<<chuang3<<endl; 
	system("PAUSE");
	return 0;
}

