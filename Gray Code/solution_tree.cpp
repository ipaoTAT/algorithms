#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<char> &res)
{
    for(vector<char>::iterator it = res.begin(); it != res.end(); it++)
    {
	cout << *it << " ";
    }
    cout << endl;
}

void generate(vector<char> &res, int n, char cur, bool left)
{
    res.push_back(cur);
    if(res.size() == n)
    {
	print_vector(res);
    }else{

    	char first = '0';
   	char second = '1';
   	if(!left)
   	{
   	    first = '1';
   	    second = '0';
   	}
   	generate(res, n, first, true);
   	generate(res, n, second, false);
   }
   res.pop_back();
}

int graycode(int n)
{
    vector<char> res;
    generate(res, n, '0', true);
    generate(res, n, '1', false);
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    graycode(n);
}
