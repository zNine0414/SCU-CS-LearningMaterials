// 编写设计一个People（人）类。
//该类的数据成员有年龄(age)、身高(height)、体重(weight)和人数(num)，
//其中人数为静态数据成员，
//成员函数有构造函数(People)、进食(Eatting)、运动(Sporting)、睡眠(Sleeping)、显示(Show)和显示人数(ShowNum)。
//其中构造函数由已知参数年龄(a)、身高(h)和体重(w)构造对象，进食函数使体重加1，运动函数使身高加1，
//睡眠函数使年龄、身高、体重各加1，显示函数用于显示人的年龄、身高、体重，显示人数函数为静态成员函数，用于显示人的个数。
//假设年龄的单位为岁，身高的单位为厘米，体重的单位为市斤，
//要求所有数据成员为protected访问权限，所有成员函数为public访问权限，在主函数中通过对象直接访问类的所有成员函数。
											
#include <iostream>							
using namespace std;
class People{
	protected:
		int age;//单位是岁 
		float height;//单位是厘米 
		float weight;//单位是市斤 
		static int num;//静态数据 
	public:
		People(int a,float h,float w):age(a),height(h),weight(w){
			num+=1;
		}
		void Eatting();
		void Sporting();
		void Sleeping();
		void Show();
		static void ShowNum();//显示人数函数为静态成员函数
		
};	
void People::Eatting(){//进食函数使体重加1
	weight+=1;
}
void People::Sporting(){//运动函数使身高加1
	height+=1;
}
void People::Sleeping(){//睡眠函数使年龄、身高、体重各加1
	age+=1;
	weight+=1;
	height+=1;
}
void People::Show(){
	cout<<"年龄为"<<age<<endl;
	cout<<"身高为"<<height<<endl;
	cout<<"体重为"<<weight<<endl;
}
void People::ShowNum(){
	cout<<"总人数为"<<num<<endl;
}
int People::num=0;				
main()
{
	People peo1(18,164,110);
	peo1.Eatting();
	peo1.Sleeping();
	peo1.Sporting();
	peo1.Show();
	People::ShowNum();//静态函数调用 
} 
