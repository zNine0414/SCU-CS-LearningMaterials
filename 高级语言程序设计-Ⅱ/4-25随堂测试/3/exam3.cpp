//3�����ö�����������ָ����ʵ��
//��ѧ��ѡ�Ρ���ѯ������ͳ��ȫ��ѧ������߷֡���ͷ��Լ���Ӧ��ѧ����Ϣ��
//ͳ��ƽ���֡��߷ֶΣ�85���ϣ������Լ�ѧ��������Ϣ�������������Լ�ѧ��������Ϣ��
//����ӡ���ϸ������ݡ�


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
	Student("qwe","C++","���",89),
	Student("e","C++","�����߼�",85),
	Student("qs","C++","����ԭ��",78),
	Student("svd","C++","���ݽṹ",78),
	Student("vsv","C++","java",78),
	Student("EV","C++","python",78),
	Student("J.H","C++","web",78),
	Student("EFE","C++","php",78),
	Student("tc","C++","go",78),
	Student("sd","C++","offic",59)};

	cout<<"��������Ҫ��ѯ��ѧ��������"<<endl;
	cin>>testname;
	for(i=0;i<10;i++)
	{
		if (stu[i].name==testname)
		{
			cout<<"��ĵ�һ�ſγ̣�"<<stu[i].kec1<<endl;
			cout<<"��ĵڶ��ſγ̣�"<<stu[i].kec2<<endl;
			cout<<"��ķ�����"<<stu[i].score<<endl;
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
	cout<<"��߷���"<<highstu<<"��"<<hightest<<"��"<<endl;
	cout<<"��ͷ���"<<lowstu<<"��"<<lowtest<<"��"<<endl;

	cout<<"ƽ������"<<sum/count<<"��"<<endl;
	cout<<"������"<<count<<endl;
	cout<<"�߷ֶε�ͬѧ��"<<endl;
	for(i=0;i<10;i++)
	{
		if (stu[i].score>=85)  
		{
			cout<< stu[i].name<<"��"<<stu[i].score<<"��"<<endl;
			highsc++;
		} 
		
	};
	cout<<"�߷ֶ�һ����"<<highsc<<"��"<<endl;
	cout<<"�������ͬѧ��"<<endl;
	for(i=0;i<10;i++)
	{
		if (stu[i].score<60)
		{
			cout<< stu[i].name<<"��"<<stu[i].score<<"��"<<endl;
			lowsc++;
		}
	};
	cout<<"������һ����"<<lowsc<<"��"<<endl;
	system("PAUSE");
	return 0;
 } 
