#include<iostream>
using namespace std;

int max_benifit(int prices[], int n)
{
    int min_price = prices[0];
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
	if(prices[i] < min_price) min_price = prices[i];
	if(prices[i] - min_price > ans)ans = prices[i] - min_price;
    }

    return ans;
}

int main()
{
    int a[] = {1,3,2,6,5,8,1,10,8};
    cout << max_benifit(a, sizeof(a)/sizeof(a[0])) << endl;
}
