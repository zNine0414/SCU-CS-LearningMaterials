//��д���򣬶���������Shape(��״)������������2�������ࣺ
//Circle(Բ��) ��Rectangle(����)���ú���Show()�ֱ���ʾ����ͼ�ε������Ϣ�����Ҫ��ʾ����ͼ�ε��������

#include<iostream>
using namespace std;
const float pai=3.14;
class Shape
{
	public:	
		Shape(){}; 
		virtual void Show()=0;
};

class Circle:public Shape
{
	
	public:
		Circle(float r):R(r){}
		float R; 
		float Sum=pai*R*R;
		void Show()
		{
			cout<<"�뾶��"<<R<<endl;
			cout<<"�����"<<Sum<<endl;
		}
};
class Rectangle:public Shape
{
	
	public:
		Rectangle(float l,float w):Long(l),Wide(w){}
		float Long,Wide;
		float Sum=Long*Wide;
		void Show()
		{
			cout<<"����"<<Long<<endl;
			cout<<"����"<<Wide<<endl;
			cout<<"�����"<<Sum<<endl;
		}
};
int main(void)
{
	Circle cc(2);
	Rectangle rr(2,2);
	cc.Show();
	rr.Show();
	cout<<"�������"<<cc.Sum+rr.Sum<<endl;
	system("PAUSE");
	return 0;
}


