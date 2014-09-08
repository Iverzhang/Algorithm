#include <iostream>
using namespace std;
template <class T>
void swap(T A[],int i,int j)
{
	T temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}

template <class T>
void max_heapify(T A[],int i,int length)
{
    int largest;
	if(2*i+1 <= length-1)
	{
		if(A[i] < A[2*i+1])
            largest=2*i+1;
        else largest=i;
		if((2*i < length - 2) && A[largest] < A[2*i+2])
            largest=2*i+2;
    }
	else largest=i;
	if(largest != i)
	{
        swap(A,i,largest);
        max_heapify(A,largest,length);
	}
	return;
}
template <class T>
void build_max_heap(T A[],int length)
{
	for(int i=length/2-1;i>=0;i--)
		max_heapify(A,i,length);
	return;
}
template <class T>
void heapsort(T A[],int length)
{
    build_max_heap(A,length);
    for(int i=length-1;i>0;i--)
    {
        swap(A,0,i);
        --length;
        max_heapify(A,0,length);
    }
    return;
}
int main()
{
	int a[8]={1,2,3,4,5,6,7,8};
	heapsort(a,8);
	for(int i=0;i<8;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

