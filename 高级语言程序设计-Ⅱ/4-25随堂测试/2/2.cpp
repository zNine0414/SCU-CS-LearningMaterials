//2、编程实现两个3*3矩阵的相乘、自减（前、后缀）运算，
//并重载判断两个矩阵是否相等的比较运算符，支撑直接输出矩阵对象。
//最后为该类编写测试代码，测试以上所有行为并输出结果。
#include <iostream>
using namespace std;
 
class juzhen33
{
	public:
		int a11,a12,a13,a21,a22,a23,a31,a32,a33;
		juzhen33(int a=0,int b=0,int c=0,int d=0,int e=0,int f=0,int g=0,int h=0,int i=0):
			a11(a),a12(b),a13(c),a21(d),a22(e),a23(f),a31(g),a32(h),a33(i)
		{};
		bool operator==(const juzhen33 &d)
	    {
	         int test=1;
	         if (this->a11==d.a11&&this->a12==d.a12&&this->a13==d.a13&&
			 		this->a21==d.a21&&this->a22==d.a22&&this->a23==d.a23&&
					 this->a31==d.a31&&this->a32==d.a32&&this->a33==d.a33)
	        {return true;}
			else return false;
	    };
	    juzhen33 operator*(const juzhen33 &a)//实现相乘 
	    {
	    	juzhen33 b;
	    	b.a11=this->a11*a.a11+this->a12*a.a21+this->a13*a.a31;
	    	b.a12=this->a11*a.a12+this->a12*a.a22+this->a13*a.a32;
	    	b.a13=this->a11*a.a13+this->a12*a.a23+this->a13*a.a33;
	    	b.a21=this->a21*a.a11+this->a22*a.a21+this->a33*a.a31;
	    	b.a22=this->a21*a.a12+this->a22*a.a22+this->a33*a.a32;
	    	b.a23=this->a21*a.a13+this->a22*a.a23+this->a33*a.a33;
	    	b.a31=this->a31*a.a11+this->a22*a.a21+this->a33*a.a31;
	    	b.a32=this->a31*a.a12+this->a22*a.a22+this->a33*a.a32;
	    	b.a33=this->a31*a.a13+this->a22*a.a23+this->a33*a.a33;
	    	return b;
		};
		friend ostream &operator<<(ostream &cout,juzhen33 &a)
		{
			cout<<a.a11<<a.a12<<a.a13<<endl;
			cout<<a.a21<<a.a22<<a.a23<<endl;
			cout<<a.a31<<a.a32<<a.a33<<endl;
			
			return cout;
		};
		// 重载前缀运算符（ -- ）
      	juzhen33 operator-- ()  
      	{
         	--a11;
			 --a22;
			 --a33;           // 对象加 1
         	
         	
         	return juzhen33(a11,a12,a13,a21,a22,a23,a31,a32,a33);
      	}
      	// 重载后缀运算符（ -- ）
      	juzhen33 operator--( int )         
      	{
         // 保存原始值
         	juzhen33 T(a11,a12,a13,a21,a22,a23,a31,a32,a33);
         	--a11;
			 --a22;
			 --a33;                    
         // 返回旧的原始值
         	return T; 
      	}
      	
	
};

int main()
{
	juzhen33 ju1(1,1,1,1,1,1,1,1,1);
	juzhen33 ju2(1,1,1,1,1,1,1,1,1);
	cout<<"矩阵ju1:"<<endl<<ju1<<endl;
	cout<<"矩阵ju2:"<<endl<<ju2<<endl;
	if (ju1==ju2) cout<<"判断出ju1和ju2相等"<<endl<<endl;
	ju1--;
	--ju2;
	juzhen33 ju3;
	ju3=ju1*ju2;
	cout<<ju1<<endl;
	cout<<ju2<<endl;
	cout<<ju3<<endl;
	system("PAUSE");
	return 0;
 } 
