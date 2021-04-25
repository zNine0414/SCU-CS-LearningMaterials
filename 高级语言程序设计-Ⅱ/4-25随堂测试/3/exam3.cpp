//3、利用对象数组或对象指针来实现
//对学生选课、查询分数、统计全班学生的最高分、最低分以及对应的学生信息，
//统计平均分、高分段（85以上）人数以及学生具体信息、不及格人数以及学生具体信息，
//并打印以上各项数据。


#include <iostream>
#include<cstring>
using namespace std;
int i;
class Student
{
	public:
		char name[10],kec1[10],kec2[10];
		float score;
	Student(char nam[10]=0,char kc1[10]=0,char kc2[10]=0,float sc=0):score(sc)
	{
		strcpy(name,nam);
		strcpy(kec1,kc1);
		strcpy(kec2,kc2);
	}
	
};

int main()
{
	char testname[10];
	Student stu[10]={
	Student("qwe","C++","汇编",89),
	Student("e","C++","数字逻辑",85),
	Student("qs","C++","编译原理",78),
	Student("svd","C++","数据结构",78),
	Student("vsv","C++","java",78),
	Student("EV","C++","python",78),
	Student("J.H","C++","web",78),
	Student("EFE","C++","php",78),
	Student("tc","C++","go",78),
	Student("sd","C++","offic",59)};

	cout<<"请输入想要查询的学生姓名："<<endl;
	cin>>testname;
	for(i=0;i<10;i++)
	{
		if (stu[i].name==testname)
		{
			cout<<"你的第一门课程："<<stu[i].kec1<<endl;
			cout<<"你的第二门课程："<<stu[i].kec2<<endl;
			cout<<"你的分数："<<stu[i].score<<endl;
			break;
		}
	};
	
	
	float hightest=-1;
	float lowtest=101;
	float sum=0;
	float count=1;
	char highstu[10];
	char lowstu[10];
	float highsc=0;
	float lowsc=0;
	for(i=0;i<10;i++)
	{
		
		if (stu[i].score<lowtest) {
			lowtest=stu[i].score;
			strcpy(lowstu,stu[i].name);
		}
		if (stu[i].score>hightest) 
		{
			hightest=stu[i].score;
			strcpy(highstu,stu[i].name);
		}
		sum+=stu[i].score;
		count++;
		
	}
	cout<<"最高分是"<<highstu<<"的"<<hightest<<"分"<<endl;
	cout<<"最低分是"<<lowstu<<"的"<<lowtest<<"分"<<endl;

	cout<<"平均分是"<<sum/count<<"分"<<endl;
	cout<<"人数是"<<count<<endl;
	cout<<"高分段的同学："<<endl;
	for(i=0;i<10;i++)
	{
		if (stu[i].score>=85)  
		{
			cout<< stu[i].name<<"的"<<stu[i].score<<"分"<<endl;
			highsc++;
		} 
		
	};
	cout<<"高分段一共有"<<highsc<<"人"<<endl;
	cout<<"不及格的同学："<<endl;
	for(i=0;i<10;i++)
	{
		if (stu[i].score<60)
		{
			cout<< stu[i].name<<"的"<<stu[i].score<<"分"<<endl;
			lowsc++;
		}
	};
	cout<<"不及格一共有"<<lowsc<<"人"<<endl;
	system("PAUSE");
	return 0;
 } 
