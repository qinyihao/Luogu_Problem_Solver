#include<bits/stdc++.h>
using namespace std;
int main()
{
	string isbn;
	int i,j,k;
	vector<int> a;
	cin>>isbn;
	for(i = 0; i < isbn.size();i++)
		if(isbn[i]!='-'){
			if(isbn[i]=='X')
				a.push_back(10);
			else
				a.push_back(isbn[i]-'0');
		}
			
	int sum = 0;
	for(i = 1; i <= 9; i++)
		sum += a[i-1]*i;
	if(sum % 11 == a[9])
		cout<<"Right";
	else	 if(sum % 11 == 10){
		isbn[12] = 'X';
		cout<<isbn;
	}
	else{
		isbn[12] = sum % 11 + '0';
		cout<<isbn;
	}
	return 0;			
}
