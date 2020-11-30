#define    ll           long long
#define    dn           double
#define    mp           make_pair
#define    pb           push_back
#define    se           second
#define    fi           first
#define    mod          1000000007
#define    sob(v)       v.begin(),v.end()
#define    sobr(v)      v.rbegin(),v.rend()
#define    fr(i,a,b)    for(int i=a;i<=b;++i)
#define    frr(i,a,b)   for(int i=a;i>=b;--i)
#define    pi           acos(-1.00)
#define    inf          1e9
#define    check        cout<<"*"<<endl
#define    ffix(x)      cout<<fixed<<setprecision(x)
#define    fast         ios_base::sync_with_stdio(false);cill n.tie(NULL);cout.tie(NULL)

#include<bits/stdc++.h>
#include<string.h>
using namespace std;

typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<ll,int> pii;
typedef pair<int,vi> pp;
typedef pair<pair<int,int>,int> pain;

int dr[8]= {-1,0,+1,0,-1,-1,+1,+1};
int dc[8]= {0,+1,0,-1,-1,+1,-1,+1};

int kx[8]= {-1,+1,+1,-1,+2,+2,-2,-2};
int ky[8]= {+2,+2,-2,-2,-1,+1,+1,-1};


const int N=100005;

int n,m,k,ans[10],a[N][10];
multiset<int>st[N];

void add(int x)
{
    fr(i,1,m)
    st[i].insert(a[x][i]);
}

void bad(int x)
{
    ///cout<<x<<endl;
    fr(i,1,m)
    st[i].erase(st[i].find(a[x][i]));
}

bool ok()
{
    int sum=0;
    fr(i,1,m)
    {
        sum+=*st[i].rbegin();
    }
    return (sum<=k);
}

int main()
{
    int mx=0;
    cin>>n>>m>>k;
    int l1,r1;
    int l=1;
    fr(r,1,n)
    {
        fr(i,1,m)cin>>a[r][i];
        add(r);
        while(l<=r && !ok())bad(l++);
        ///cout<<r<<'*'<<l<<endl;
        if(r-l+1>mx)
        {
            mx=r-l+1;
            l1=l;
            r1=r;
        }
    }
    fr(i,l1,r1)
    {
        fr(j,1,m)
        {
            ans[j]=max(ans[j],a[i][j]);
        }
    }
    fr(i,1,m)cout<<ans[i]<<' ';cout<<endl;
    return 0;
}
