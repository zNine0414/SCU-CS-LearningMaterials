#include <iostream>	
#include<cstring>			
using namespace std;
class Person
{
	public:
	Person(char nm[18],int ag,char sx[2]):age(ag)
	{
		strcpy(name,nm);
		strcpy(sex,sx);
	}
	public:
		char name[18];
		int age;
		char sex[2];
		void Show()
		{
			cout<<"名字："<<name<<endl;
			cout<<"年龄："<<age<<endl;//
			cout<<"性别："<<sex<<endl;//
		 };
 } ;

class Teacher:virtual public Person
{
	public:
	Teacher(char nm[18],int ag,char sx[2],char ttl[18]):
	Person( nm,ag,sx)
	{
		strcpy(title,ttl);
	}
	public:
		char title[18];
		void Show()
		{
			
			cout<<"职称："<<title<<endl;//
		 } ;
};
	
class Cadre:virtual public Person
{
	public:
	Cadre(char nm[18],int ag,char sx[2],char pst[18]):
	Person(nm,ag,sx)
	{
		strcpy(post,pst);
	}
	public:
		char post[18];
		void Show()
		{
			
			cout<<"职务："<<post<<endl;//
		 };
};

class TeacherCadre:virtual public Teacher,virtual public Cadre
{
	public:
		TeacherCadre(char nm[18],int ag,char sx[2],char ttl[18],char pst[18],float wags):
		
		Teacher(nm, ag, sx,ttl),
		Cadre(nm,  ag,sx,  pst),
		Person( nm,ag,sx)
		
		{
			wages=wags;
		}
	
		float wages;
		void Show()
		{
			Person::Show();
			Teacher::Show();
			Cadre::Show();
			cout<<"工资："<<wages<<endl;//
		 }; 		
};

								
int main(void)			
{																
	TeacherCadre tea1("张三",18,"女","教授","院长",10000);
	tea1.Show(); 
	system("PAUSE");   	
	return 0;          	
}	

