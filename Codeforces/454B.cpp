#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lld long double
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define repi(i, a, b) for(int i=(a); i>(b); i--)
#define all(x) x.begin(), x.end()
#define db(x) (cout<<#x<<":"<<(x)<<'\n')
#define pi 3.141592653589
#define lb lower_bound
#define ub upper_bound
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;
const ll mod=1000000007;


template<typename T>
void printv(const vector<T>& v) { for(auto i:v) cout<<i<<' '; cout<<'\n'; }
template<typename T>
void printv(const vector<pair<T, T>>& v) { for(auto p:v) cout<<"("<<p.first<<","<<p.second<<"),"; cout<<'\n'; }


int main(){
    fastio;
    ll tc =1;
    //cin>>tc;
    for(ll t=0;t<tc;t++)
    {
         ll n;
         cin >> n;
         ll a[n];
         rep(i,0,n)
         {
             cin >> a[i];
         }
         if(n==2)
         {
             if (is_sorted(a, a + n))
                 cout << 0 << endl;
             else
             {
                 cout << 1 << endl;
             }
                 
         }
         else if(is_sorted(a,a+n))
             cout <<0<<endl;
         else if(is_sorted(a,a+n, greater<ll>()))
             cout << - 1 << endl;
         else
         {
             ll i = 1;
             for (; i < n;i++)
             {
                 if(a[i]<a[i-1])
                     break;
             }
             if(is_sorted(a+i,a+n) && a[n-1]<=a[0])
                 cout << n  - i << endl;
             else
             {
                 cout << -1 << endl;
             }
                 

         }
             
    }
    return 0;
}
