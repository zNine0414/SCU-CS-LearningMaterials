//编写程序，定义抽象基类Shape(形状)，由它派生出3个派生类: 
//Circle(圆形)、Rectangle(矩形)和Square 正止方形)，用函数函数ShowArea()分别显示各种图形的面积，
//最后还要显示所有图形的总面积。要求用基类指针数组，使它的每一个元素指向一一个派生类对象。

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
			cout<<"Circle面积是"<<Sum<<endl;
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
			cout<<"Rectangle面积是"<<Sum<<endl;
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

			cout<<"Square面积是"<<Sum<<endl;
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
	cout<<"总面积是"<<circle.Sum+rectangle.Sum+square.Sum<<endl;
	system("PAUSE");
	return 0;
}
