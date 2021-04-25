//编写程序，定义抽象基类Shape(形状)，由它派生出2个派生类：
//Circle(圆形) 和Rectangle(矩形)，用函数Show()分别显示各种图形的相关信息，最后还要显示所有图形的总面积。

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
			cout<<"半径是"<<R<<endl;
			cout<<"面积是"<<Sum<<endl;
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
			cout<<"长是"<<Long<<endl;
			cout<<"宽是"<<Wide<<endl;
			cout<<"面积是"<<Sum<<endl;
		}
};
int main(void)
{
	Circle cc(2);
	Rectangle rr(2,2);
	cc.Show();
	rr.Show();
	cout<<"总面积是"<<cc.Sum+rr.Sum<<endl;
	system("PAUSE");
	return 0;
}


