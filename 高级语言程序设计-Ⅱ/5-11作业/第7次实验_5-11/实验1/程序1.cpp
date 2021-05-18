#include <iostream>
#include <vector>
using namespace std;
template<typename T> 
class Array {
	private:
		T *arr;
		int size;
	public:
		Array(){}
		Array(int n)
		{
			size = n;
			arr = new T[n];
			memset(arr, 0, sizeof(T)*n);
		}
		Array(T *p, int n)
		{
			size = n;
			arr = new T[n];
			for (int i=0; i<n; i++)
			arr[i] = p[i];
		}
		void sort();
		T sum();
		void print();
		void printmax();
		virtual ~Array()
		{
			delete []arr;
		}
};
template<typename T>
void Array<T>::sort()
{
	T temp;
	for (int i=0; i<size; i++)
	for (int j=i+1; j<size; j++)
	if (arr[i] > arr[j]) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

template<typename T>
T Array<T>::sum()
{
	T sum=0;
	for (int i=0; i<size; i++)
	sum += arr[i];
	cout<<sum<<endl;
}
template<typename T>
void Array<T>::print()
{
	for (int i=0; i<size; i++)
	cout << arr[i] << ' ';
	cout << endl;
}
template<typename T>
void Array<T>::printmax()
{
	cout<<arr[size-1]<<endl;
}
int main(void)
{
	int a[] = {1,8,5,13,66,50};
	double b[] = {6,6,6,5,3,6,8,1,9,78,13};
	Array<int> arr1(a, sizeof(a)/sizeof(a[0]));
	arr1.print();
	arr1.sort();
	arr1.print();
	arr1.sum();
	arr1.printmax();
	cout<<endl;
	Array<double> arr2(b, sizeof(b)/sizeof(b[0]));
	arr2.print();
	arr2.sort();
	arr2.print();
	arr2.sum();
	arr2.printmax();
	system("PAUSE");
	return 0;
}

