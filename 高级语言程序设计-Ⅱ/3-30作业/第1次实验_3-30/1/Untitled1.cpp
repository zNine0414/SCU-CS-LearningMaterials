// ��д���һ��People���ˣ��ࡣ
//��������ݳ�Ա������(age)�����(height)������(weight)������(num)��
//��������Ϊ��̬���ݳ�Ա��
//��Ա�����й��캯��(People)����ʳ(Eatting)���˶�(Sporting)��˯��(Sleeping)����ʾ(Show)����ʾ����(ShowNum)��
//���й��캯������֪��������(a)�����(h)������(w)������󣬽�ʳ����ʹ���ؼ�1���˶�����ʹ��߼�1��
//˯�ߺ���ʹ���䡢��ߡ����ظ���1����ʾ����������ʾ�˵����䡢��ߡ����أ���ʾ��������Ϊ��̬��Ա������������ʾ�˵ĸ�����
//��������ĵ�λΪ�꣬��ߵĵ�λΪ���ף����صĵ�λΪ�н
//Ҫ���������ݳ�ԱΪprotected����Ȩ�ޣ����г�Ա����Ϊpublic����Ȩ�ޣ�����������ͨ������ֱ�ӷ���������г�Ա������
											
#include <iostream>							
using namespace std;
class People{
	protected:
		int age;//��λ���� 
		float height;//��λ������ 
		float weight;//��λ���н� 
		static int num;//��̬���� 
	public:
		People(int a,float h,float w):age(a),height(h),weight(w){
			num+=1;
		}
		void Eatting();
		void Sporting();
		void Sleeping();
		void Show();
		static void ShowNum();//��ʾ��������Ϊ��̬��Ա����
		
};	
void People::Eatting(){//��ʳ����ʹ���ؼ�1
	weight+=1;
}
void People::Sporting(){//�˶�����ʹ��߼�1
	height+=1;
}
void People::Sleeping(){//˯�ߺ���ʹ���䡢��ߡ����ظ���1
	age+=1;
	weight+=1;
	height+=1;
}
void People::Show(){
	cout<<"����Ϊ"<<age<<endl;
	cout<<"���Ϊ"<<height<<endl;
	cout<<"����Ϊ"<<weight<<endl;
}
void People::ShowNum(){
	cout<<"������Ϊ"<<num<<endl;
}
int People::num=0;				
main()
{
	People peo1(18,164,110);
	peo1.Eatting();
	peo1.Sleeping();
	peo1.Sporting();
	peo1.Show();
	People::ShowNum();//��̬�������� 
} 
