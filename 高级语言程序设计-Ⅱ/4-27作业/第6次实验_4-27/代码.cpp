//�Զ���һ��MyString�࣬Ϊ��������+��-��=������ת����[]��<<�������������
//��Ϊÿһ����Ϊ��д���Դ��롣




#include <iostream>
using namespace std;
const int SIZE = 10;



class  MyString
{
	public:
		int test1,test2;
		int arr[SIZE];
		
		//���캯�� 
		MyString(int a=0,int b=0):test1(a),test2(b)
		{
			int i;
			for(i = 0; i < SIZE; i++){arr[i] = i;}
		}
		
		
		//��������ֵ�ļӼ� 
		int operator+(int a)
		{
			return test1+a;
		} 
		
		int operator-(int a)
		{
			return test1-a;
		} 
		//����ļӼ� 
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
		
		//��ֵ��������� 
		void operator=(MyString &a )
	    { 
	        test1=a.test1;
	        test2=a.test2;
	    }
		
		
		
		//�±���������� 
		int& operator[](int i)
    	{
        	if( i >= SIZE )
        	{
            	cout << "�����������ֵ�����ص�һ��Ԫ��" <<endl; 
              // ���ص�һ��Ԫ��
            	return arr[0];
        	}
          return arr[i];
    	}
		
		
		 //����ǿ������ת������� int
		operator int() { return test1; } 
		
		//������� 
		friend ostream &operator<<(ostream &cout,MyString &a)
		{
			cout<<"��һ��Ԫ����"<<a.test1<<"�ڶ���Ԫ����"<<a.test2<<endl;
			return cout;
		}
};

int main(void)
{
	MyString str1(1,2);
	cout<<"str1��Ԫ�أ�"<<endl; 
	cout<<str1<<endl;
	MyString str2(3,4);
	cout<<"str2��Ԫ�أ�"<<endl; 
	cout<<str2<<endl;
	cout<<"str1����2��test1��ֵΪ��"<<str1+2<<endl;
	cout<<"str1��ȥ2��test1��ֵΪ��"<<str1-2<<endl;

	cout<<"str1����str2��test2��ֵΪ��"<<str1+str2<<endl;

	cout<<"str2��ȥstr1��test2��ֵΪ��"<<str2-str1<<endl;
	str1=str2;
	cout<<"��str2��ֵ���str1��Ԫ����"<<endl<<str1<<endl; 
	cout<<"(int)str1="<<(int)str1<<endl; 
	
	cout<<"��������str1������arr[3]��"<<endl;
	cout <<str1[3]<<endl;
	cout<<"Խ�����str1������str1.arr[11]��"<<endl;
	cout <<str1[11]<<endl;
	
	
	
	system("PAUSE");
	return 0;
}
