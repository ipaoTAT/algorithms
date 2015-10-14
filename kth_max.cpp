#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    if(*a == *b)return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void print_arr(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
	cout << a[i] << " ";
    }
    cout << endl;
}

void adjdown(int *heap, int n, int i)
{
    int index = (i << 1) + 1; 	//left child

    while(index < n)
    {
    	if(index + 1 < n && heap[index + 1] < heap[index])index++;
    	if(heap[index] < heap[i])
    	{
		swap(&heap[i], &heap[index]);
		i = index;
    	}else break;
    }

    return;
}


int kth_max(int a[], int n , int k)
{
    for(int i = k - 1; i >= 0; i--)
    {
	adjdown(a, k, i);
    }
    print_arr(a, n);
    for(int i = k; i < n; i++)
    {
	if(a[i] > a[0])
	{
	    swap(&a[i], &a[0]);
	    adjdown(a, k, 0);
	}
    }

    //return a[0];

    for(int i = k - 1; i > 0; i--)
    {
	swap(&a[i], &a[0]);
	adjdown(a, i, 0);
    }

    print_arr(a, k);
    return a[k - 1];
}


int main()
{
    int a[] = {3,2,4,1,5,7,6,8, 9, -1 ,20, 10};
    cout << kth_max(a, sizeof(a)/sizeof(a[0]), 6) << endl;
}
