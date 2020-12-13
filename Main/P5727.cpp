#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n; 
	vector<long long> a;
	a.push_back(n);
	while(n!=1)
	{
		if(n%2==0)
		{
			n/=2;
			a.push_back(n);
		}
		else
		{
			n=n*3+1;
			a.push_back(n);
		}
	}
	for(int s=a.size()-1;s>=0;s--)
	{
		cout<<a[s]<<" ";
	}
	
}
