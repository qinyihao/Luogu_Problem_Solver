#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
#define ll long long int
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll pre[5*100000+5];


void solve()
{
    ll n,k;cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    
    for(ll i=0;i<=2*k+10;i++)pre[i]=0;
    
    map<long long int,long long int> mpp;
    vector<pair<long long int,long long int>> v;
    for(ll i=0;i<n/2;i++)
    {
        v.push_back(make_pair(min(a[i],a[n-i-1]),max(a[i],a[n-i-1])));
    }
    for(auto it:v)
    {
        ll l=it.first+1;
        ll r=it.second+k;
        
        pre[l]+=1;
        pre[r+1]-=1;
        
        mpp[it.first+it.second]++;
        
    }
    
    ll sum=0;
    for(ll i=1;i<=2*k+10;i++)
    {
        sum+=pre[i];
        pre[i]=sum;
    }
    
    ll mini=n;
    for(ll i=2;i<=2*k;i++)
    {
       ll cnt0=mpp[i];
       ll cnt1=pre[i]-cnt0;
       ll cnt2=(n/2)-cnt1-cnt0;
       
       mini=min(mini,2*cnt2+cnt1);
    }
    
    cout<<mini<<endl;
    
}

int main() {
    FAST
    ll t;
    cin>>t;
    // scanf("%lld",&t);
    while(t--)
        solve();
	return 0;
}
