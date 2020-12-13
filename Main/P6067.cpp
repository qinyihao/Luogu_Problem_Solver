#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
   int s = 0,w = 1;
   char ch = getchar();
   while(ch < '0' || ch > '9'){if(ch == '-')w = -1;ch = getchar();}
   while(ch >= '0' && ch <= '9')s = s * 10 + ch - '0',ch = getchar();
   return s * w;
}

int n;
int a[100010];
int pre[100010];
int ans;

bool cmp(int x,int y){
    return x > y;
} 

signed main(){
    cin>>n;
    for(int i = 1;i <= n;i ++)a[i] = read();
    sort(a + 1,a + n + 1,cmp);
    for(int i = 1;i <= n;i ++)pre[i] = pre[i - 1] + a[i];
    for(int i = 1;i <= n;i ++)ans += a[i] * (i - 1) - pre[i - 1];
    cout<<abs(ans * 2);
    return 0;
}
