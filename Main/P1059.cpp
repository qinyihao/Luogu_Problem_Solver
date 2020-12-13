#include <bits/stdc++.h>
using namespace std;
int a[100+10], b[100+10], he, n;
int main() 
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
    	cin >> a[i];
    }
    
	for(int i = 1; i <= n; i++)
	{
		int temp = a[i], j;
		for(j = i - 1; j >= 1 && a[j] > temp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
	
    for(int i = 1; i <= n-1; i++)
    {
    	if(a[i] == a[i+1]) a[i]=-1;
    }
    
    for(int i = 1; i <= n; i++)
    {
    	if(a[i] != -1) he++;
    }
    
    cout << he << endl;
    
    for(int i = 1; i <= n; i++)
    {
    	if(a[i] != -1) cout<<a[i]<<" ";
    }
    return 0;
}
