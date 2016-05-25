/**
 * Source:	CLRS
 * Author: 	HanfengChi
 * Date:	2016-05-25
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

template<typename T>
void swap(std::vector<T>& a, int i, int j)
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

template<typename T>
int Partition(std::vector<T>& a, int lo, int hi)
{
	T pivot_value = a[hi];
	int i = lo - 1;
	for (int j = lo; j <= hi - 1; j++)
	{
		if (a[j] < pivot_value)
		{
			i = i + 1;
			swap(a, i, j);
		}
	}
	swap(a, i + 1, hi);
	return i + 1;
}

template<typename T>
void QuickSort(std::vector<T>& a, int lo, int hi)
{
	if (lo <= hi)
	{
		int q = Partition(a, lo, hi);
		QuickSort(a, lo, q-1);
		QuickSort(a, q+1, hi);
	}		

}

template<typename T>
int RandomPatition(std::vector<T>& a, int lo, int hi)
{
	random_device rd;

	int rand = rd() % (hi - lo) + lo;

	swap(a, rand, hi);
	return Partition(a, lo, hi);
}

template<typename T>
void RandomQuickSort(std::vector<T>& a, int lo, int hi)
{
	if (lo < hi)
	{
		int q = RandomPatition(a, lo, hi);
		RandomQuickSort(a, lo, q - 1);
		RandomQuickSort(a, q + 1, hi);
	}
}

int main()
{
	cout<<"Success"<<endl;

	int n = 10;
	std::vector<int> v;
	
	for(int i = 0; i < n; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(),v.end());

	for(int value:v)
	{
		cout<<value<<"\t";
	}
	cout<<endl;

	//QuickSort(v,0,n-1);
	RandomQuickSort(v, 0, n - 1);

	for(int value:v)
	{
		cout<<value<<"\t";
	}
	cout<<endl;
	return 0;	
}

