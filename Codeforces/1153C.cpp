#include "bits/stdc++.h"
using namespace std;

#define fast ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define fl(i,a,n) for(int i=a; i<=n; i++)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define test()  int tt;  cin>>tt;  while(tt--)
#define nl  cout<<"\n"
#define pii pair<int,int>
#define sz(v) ((int)(v).size())
#define get(a,st,en)  fl(i,st,en)       cin>>a[i]
#define pr(a,st,en)     fl(i,st,en)     cout<<a[i]<<" \n"[i==en]

const int MOD = 1e9+7;
void solve()    {
      int n;      cin>>n;
      string s;   cin>>s;
      int cnt[3] = {0, 0, 0};
      for(auto &i: s)   {
            if(i == '(')      cnt[0]++;
            else if(i == ')') cnt[1]++;
            else              cnt[2]++;
      }
      if(cnt[0] > n/2 or cnt[1] > n/2)    {
            cout<<":(";       return;
      }
      int a = n/2 - cnt[0], b = n/2 - cnt[1], t = 0;
      for(auto &i: s)   {
            if(i == '?')      {
                  if(a)       a--, i = '(';
                  else        b--, i = ')';
            }
      }
      vector<char> v;
      for(int i=0; i<n; i++)  {
            if(s[i] == '(')         v.push_back(s[i]);
            else if(s[i] == ')')    {
                  if(v.empty())     {
                        cout<<":("; return;
                  }
                  v.pop_back();
            }
            //for(auto j: v)    cout<<j;    nl;
            if(v.empty() and i != n-1)    {
                  cout<<":("; return;
            }
      }
      cout<<(v.empty() ? s : ":(");
}
int main()  {
      fast;
      #ifndef ONLINE_JUDGE
      freopen("inputf.in", "r", stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      //test()
            solve();
    return 0;
}
