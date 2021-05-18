#include<iostream>

using namespace std;

template<class T>

class Array{
	private:
		T *item;
		int size;
	public:
		Array(int a[],int s):item(a),size(s){}
		static T Max(T item[],int size);
		static T Sum(T item[],int size);
		static void Sort(T item[],int size);
		static void Show(T item[],int size);
};
template <class T>
T Array<T>::Max(T item[],int size){ 
	T max=item[0];
	for(int i=1;i<size;i++)
	{
		if(max<item[i]) max=item[i];
	}
	return max;
}

template <class T>
T Array<T>::Sum(T item[],int size)
{   
   T sum=0;
   for(int i=0;i<size;i++)
   { sum+=item[i]; }
	return sum;
}

template<class T>
void Array<T>::Sort(T item[],int size)
{ 
	for(int i=0;i<size-1;i++)
	{  
		int k=i;
		for(int j=i+1;j<size;j++)
   		if(item[k]>item[j]) k=j;
   		if(k!=i)
   		{   
		    int test;
   			test=item[i];
       		item[i]=item[k];
   			item[k]=test;
   		}
	}
}

template <class T>
void Array<T>::Show(T item[],int size)
{
	for(int i=0;i<size;i++)
	   cout<<" "<<item[i];
	cout<<endl;
}

int main(void)
{ 
	int a[]={1,8,5,13,66,50,6,9,5,12};
	Array<int>arr1(a,10);
	cout<<"各元素的值：";
	arr1.Show(a,10);
	cout<<"最大值是:"<<arr1.Max(a,10)<<endl;
	cout<<"元素总和:"<<arr1.Sum(a,10)<<endl;
	arr1.Sort(a,10);
	cout<<"排序后:";
	arr1.Show(a,10);
	system("PAUSE");
	return 0;
}

