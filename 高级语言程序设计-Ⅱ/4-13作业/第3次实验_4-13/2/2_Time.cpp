//设计一个时间类Time，要求：
//（1）包含时(hour)、分(minute)和秒(second)私有数据成员。
//（2）包含构造函数，重载关于一时间加上另一时间的加法运算符+、重载关于一时间减去另一时间的减加运算符-、重载输出运算符<<与输入运算符>>等。

#include <iostream>
using namespace std;
class Time
{
	private:
		int hour,minute,second;
	public:
		Time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){}
		friend ostream &operator<<(ostream &cout,Time &a)
		{
			cout<<"现在是"<<a.hour<<"时"<<a.minute<<"分"<<a.second<<"秒"<<endl;
			return cout;
		}
		friend istream &operator >> ( istream &cin, Time &a )
		{
			cin>>a.hour>>a.minute>>a.second;
			return cin; 
		}
		Time operator+(const Time &a)
		{
			Time b;
			b.second=this->second+a.second;
			b.minute=this->minute+a.minute;
			b.hour=this->hour+a.hour;
			if(b.second>=60)
			{
				b.second-=60;
				b.minute++;
			}
			if(b.minute>=60)
			{
				b.minute-=60;
				b.hour++;
			}
			return b;
		};
		Time operator-(const Time &a)
		{
			Time b;
			b.second=this->second-a.second;
			b.minute=this->minute-a.minute;
			b.hour=this->hour-a.hour;
			if(b.second<0)
			{
				b.second+=60;
				b.minute--;
			}
			if(b.minute<0)
			{
				b.minute+=60;
				b.hour--;
			}
			return b;
		};
};



int main(void)
{
	Time test1,test2;
	Time today,tomo;
	cin>>today;
	cin>>tomo;
	cout<<"today:"<<today<<endl;
	cout<<"tomo:"<<tomo<<endl;
	test1=tomo+today;
	test2=tomo-today;
	cout<<"tomo+today=test:"<<test1<<endl;
	cout<<"tomo-today=test:"<<test2<<endl;
	system("PAUSE");
	return 0;
}
