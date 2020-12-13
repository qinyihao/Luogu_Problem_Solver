#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=i;j++) cout<<0;
			for(int j=n-i;j>=1;j--) cout<<1;
			cout<<endl;
		}
		else{
			for(int j=1;j<=i;j++) cout<<1;
			for(int j=n-i;j>=1;j--) cout<<0;
			cout<<endl;
		}
	}
	return 0;
}
