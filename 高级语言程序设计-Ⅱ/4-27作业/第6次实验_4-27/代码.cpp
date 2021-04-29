//自定义一个MyString类，为该类重载+、-、=、类型转换、[]、<<等运算符函数，
//并为每一个行为编写测试代码。




#include <iostream>
using namespace std;
const int SIZE = 10;



class  MyString
{
	public:
		int test1,test2;
		int arr[SIZE];
		
		//构造函数 
		MyString(int a=0,int b=0):test1(a),test2(b)
		{
			int i;
			for(i = 0; i < SIZE; i++){arr[i] = i;}
		}
		
		
		//对象与数值的加减 
		int operator+(int a)
		{
			return test1+a;
		} 
		
		int operator-(int a)
		{
			return test1-a;
		} 
		//对象的加减 
		MyString operator+(MyString &a)
		{
			MyString b;
			b.test2=test2+a.test2;
			return test2+a.test2;
		} 
		
		MyString operator-(MyString &a)
		{
			return test2-a.test2;
		} 
		
		//赋值运算符重载 
		void operator=(MyString &a )
	    { 
	        test1=a.test1;
	        test2=a.test2;
	    }
		
		
		
		//下标运算符重载 
		int& operator[](int i)
    	{
        	if( i >= SIZE )
        	{
            	cout << "索引超过最大值，返回第一个元素" <<endl; 
              // 返回第一个元素
            	return arr[0];
        	}
          return arr[i];
    	}
		
		
		 //重载强制类型转换运算符 int
		operator int() { return test1; } 
		
		//重载输出 
		friend ostream &operator<<(ostream &cout,MyString &a)
		{
			cout<<"第一个元素是"<<a.test1<<"第二个元素是"<<a.test2<<endl;
			return cout;
		}
};

int main(void)
{
	MyString str1(1,2);
	cout<<"str1的元素："<<endl; 
	cout<<str1<<endl;
	MyString str2(3,4);
	cout<<"str2的元素："<<endl; 
	cout<<str2<<endl;
	cout<<"str1加上2后test1的值为："<<str1+2<<endl;
	cout<<"str1减去2后test1的值为："<<str1-2<<endl;

	cout<<"str1加上str2后test2的值为："<<str1+str2<<endl;

	cout<<"str2减去str1后test2的值为："<<str2-str1<<endl;
	str1=str2;
	cout<<"被str2赋值后的str1的元素是"<<endl<<str1<<endl; 
	cout<<"(int)str1="<<(int)str1<<endl; 
	
	cout<<"正常访问str1的数组arr[3]："<<endl;
	cout <<str1[3]<<endl;
	cout<<"越界访问str1的数组str1.arr[11]："<<endl;
	cout <<str1[11]<<endl;
	
	
	
	system("PAUSE");
	return 0;
}
