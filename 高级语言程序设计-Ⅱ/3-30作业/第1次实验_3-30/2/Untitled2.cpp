//定义一个描述学生(Student)基本情况的类，//
//数据成员包括姓名(name)、学号(num)、
//数学成绩(mathScore)、英语成绩(englishScore)、人数(count)、数学总成绩(mathTotalScore)和英语总成绩(englishTotalScore)。
//其中姓名定义为长度为18的字符数组，其它数据成员类型为整型，数学总成绩、英语总成绩和人数为静态数据成员，
//函数成员包括构造函数、显示基本数据函数(ShowBase)和显示静态数据函数(ShowStatic)，
//其中构造函数由已知参数姓名(nm)、学号(nu)、数学成绩(math)和英语成绩(english)构造对象，
//显示基本数据函数用于显示学生的姓名、学号、数学成绩、英语成绩，
//显示静态数据函数为静态成员函数，用于显示人数，数学总成绩，英语总成绩；
//要求所有数据成员为private访问权限，所有成员函数为public访问权限，
//在主函数中定义若干个学生对象，分别显示学生基本信息，以及显示学生人数，数学总成绩与英语总成绩。

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
void Student::show(){//显示基本数据函数用于显示学生的姓名、学号、数学成绩、英语成绩，
	cout<<"姓名："<<name<<endl;
	cout<<"学号："<<num<<endl;
	cout<<"数学成绩："<<mathScore<<endl;
	cout<<"英语成绩："<<englishScore<<endl;
}
void Student::showStatic(){//显示静态数据函数为静态成员函数，用于显示人数，数学总成绩，英语总成绩；
	cout<<"人数："<<count<<endl;
	cout<<"数学总成绩："<<mathTotalScore<<endl;
	cout<<"英语总成绩："<<englishTotalScore<<endl;

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
