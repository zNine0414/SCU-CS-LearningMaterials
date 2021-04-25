//���һ��ʱ����Time��Ҫ��
//��1������ʱ(hour)����(minute)����(second)˽�����ݳ�Ա��
//��2���������캯�������ع���һʱ�������һʱ��ļӷ������+�����ع���һʱ���ȥ��һʱ��ļ��������-��������������<<�����������>>�ȡ�

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
			cout<<"������"<<a.hour<<"ʱ"<<a.minute<<"��"<<a.second<<"��"<<endl;
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
