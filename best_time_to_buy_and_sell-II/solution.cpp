#include<iostream>
using namespace std;

int max_benifit_II(int prices[], int n)
{
    int front[] = new int[n];
    int back[] = new int[n];
    int min_price, max_price;
    front[0] = back[n - 1] = 0;
    min_price = prices[0]; max_price = prices[n-1];
    for(int i = 1; i < n; i++)
    {
	if(prices[i] < min_price)min_price = prices[i];
	if(prices[i] - min_price > front[i-1]){
	    front[i] = prices[i] - min_price;
	}else{
	    front[i] = front[i-1];
	}
    }

    for(int i = n - 2; i >= 0; i--)
    {
	if(prices[i] > max_price)max_price = prices[i];
	if(max_price - prices[i] > back[i+1])
	{
	    back[i] = max_price - prices[i];
	}else{
	    back[i] = back[i+1];
	}
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
	if(ans < front[i] + back[i])ans = front[i] + back[i];
    }
    return ans;
}

int main()
{
    int a[] = {1,3,2,6,5,8,1,10,8};
    cout << max_benifit_II(a, sizeof(a)/sizeof(a[0])) << endl;
}
