//��д���򣬶���������Shape(��״)������������3��������: 
//Circle(Բ��)��Rectangle(����)��Square ��ֹ����)���ú�������ShowArea()�ֱ���ʾ����ͼ�ε������
//���Ҫ��ʾ����ͼ�ε��������Ҫ���û���ָ�����飬ʹ����ÿһ��Ԫ��ָ��һһ�����������

#include<iostream>
using namespace std;
const float pai=3.14;
class Shape
{
	public:	
		Shape(){}; 
		virtual void ShowArea()=0;
};

class Circle:public Shape
{
	
	public:
		Circle(float r):R(r){}
		float R; 
		float Sum=pai*R*R;
		void ShowArea()
		{
			cout<<"Circle�����"<<Sum<<endl;
		}
};


class Rectangle:public Shape
{
	
	public:
		Rectangle(float l,float w):Long(l),Wide(w){}
		float Long,Wide;
		float Sum=Long*Wide;
		void ShowArea()
		{
			cout<<"Rectangle�����"<<Sum<<endl;
		}
};


class Square:public Shape
{
	
	public:
		Square(float los):Length(los){}
		float Length;
		float Sum=Length*Length;
		void ShowArea()
		{

			cout<<"Square�����"<<Sum<<endl;
		}
};


int main(void)
{
	Circle circle(2);
	Rectangle rectangle(2,3);
	Square square(2);
	Shape *p[3]={&circle,&rectangle,&square};
	for(int i=0;i<3;i++)
	{
		p[i]->ShowArea();
	}
	cout<<"�������"<<circle.Sum+rectangle.Sum+square.Sum<<endl;
	system("PAUSE");
	return 0;
}
