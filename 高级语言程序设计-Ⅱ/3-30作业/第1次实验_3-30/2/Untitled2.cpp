//����һ������ѧ��(Student)����������࣬//
//���ݳ�Ա��������(name)��ѧ��(num)��
//��ѧ�ɼ�(mathScore)��Ӣ��ɼ�(englishScore)������(count)����ѧ�ܳɼ�(mathTotalScore)��Ӣ���ܳɼ�(englishTotalScore)��
//������������Ϊ����Ϊ18���ַ����飬�������ݳ�Ա����Ϊ���ͣ���ѧ�ܳɼ���Ӣ���ܳɼ�������Ϊ��̬���ݳ�Ա��
//������Ա�������캯������ʾ�������ݺ���(ShowBase)����ʾ��̬���ݺ���(ShowStatic)��
//���й��캯������֪��������(nm)��ѧ��(nu)����ѧ�ɼ�(math)��Ӣ��ɼ�(english)�������
//��ʾ�������ݺ���������ʾѧ����������ѧ�š���ѧ�ɼ���Ӣ��ɼ���
//��ʾ��̬���ݺ���Ϊ��̬��Ա������������ʾ��������ѧ�ܳɼ���Ӣ���ܳɼ���
//Ҫ���������ݳ�ԱΪprivate����Ȩ�ޣ����г�Ա����Ϊpublic����Ȩ�ޣ�
//���������ж������ɸ�ѧ�����󣬷ֱ���ʾѧ��������Ϣ���Լ���ʾѧ����������ѧ�ܳɼ���Ӣ���ܳɼ���

#include <iostream>	
#include<cstring>						
using namespace std;
class Student{
	private:
		char name[18];
		int num;
		int mathScore;
		int englishScore;
		static int count;
		static int mathTotalScore;
		static int englishTotalScore;
	public:
		Student(char nm[18],int nu,int math,int english):num(nu),mathScore(math),englishScore(english){
			strcpy(name,nm);
			count+=1;
			mathTotalScore+=math;
			englishTotalScore+=english;
			Student::show();
			cout<<""<<endl;
			cout<<""<<endl;

		};
		void show();
		static void showStatic();
};
void Student::show(){//��ʾ�������ݺ���������ʾѧ����������ѧ�š���ѧ�ɼ���Ӣ��ɼ���
	cout<<"������"<<name<<endl;
	cout<<"ѧ�ţ�"<<num<<endl;
	cout<<"��ѧ�ɼ���"<<mathScore<<endl;
	cout<<"Ӣ��ɼ���"<<englishScore<<endl;
}
void Student::showStatic(){//��ʾ��̬���ݺ���Ϊ��̬��Ա������������ʾ��������ѧ�ܳɼ���Ӣ���ܳɼ���
	cout<<"������"<<count<<endl;
	cout<<"��ѧ�ܳɼ���"<<mathTotalScore<<endl;
	cout<<"Ӣ���ܳɼ���"<<englishTotalScore<<endl;

}
int Student::count=0;
int Student::mathTotalScore=0;
int Student::englishTotalScore=0;
int main(void){
	
	Student stu2("xlnyg",001,96,91);
	Student stu3("zy",002,95,19);
	Student stu4("wyj",003,92,124);
	Student stu5("czx",004,150,150);
	Student stu6("znx",005,123,123);
	Student stu7("lxn",006,125,126);
	Student stu8("xyy",007,150,150); 

	Student::showStatic();	
	
	system("PAUSE");
	return 0;
}
