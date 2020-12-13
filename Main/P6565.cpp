#include<bits/stdc++.h>
using namespace std;
string name[109],s[109];
int cnt[109];
int main(){
	
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cnt[i]=0;
		cin>>name[i]>>s[i];
		for(int j=2;j<=s[i].size();j++){
			string q;
			q=s[i][j-2]+s[i][j-1]+s[i][j];
			if(s[i][j-2]=='s'&&s[i][j-1]=='o'&&s[i][j]=='s') cnt[i]++;
		}
		ans=max(ans,cnt[i]);
	}
	for(int i=0;i<n;i++){
		if(cnt[i]==ans) cout<<name[i]<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
	return 0;
}
