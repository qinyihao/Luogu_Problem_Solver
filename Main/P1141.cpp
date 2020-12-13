#include<bits/stdc++.h>
using namespace std;
#define REG register
#define IN inline

int n,m,ans[1005][1005],cnt[100005]={0};
bool Map[1005][1005];
int fx[4][2]={1,0,-1,0,0,1,0,-1};

void dfs(int x,int y,int t)
{
    ans[x][y]=t;
    cnt[t]++;
    for(int i=0;i<4;i++)
    {
        int X=x+fx[i][0];
        int Y=y+fx[i][1];

        if(X<1||X>n||Y<1||Y>n||Map[x][y]==Map[X][Y]||ans[X][Y]) continue;
        dfs(X,Y,t);
    }
}

int main()
{
    cin>>n>>m;

    for(REG int i=1;i<=n;i++)
        for(REG int j=1;j<=n;j++)
            scanf("%1d",&Map[i][j]);

    while(m)
    {
        int x,y;

        cin>>x>>y;

        if(ans[x][y])
            printf("%d\n",cnt[ans[x][y]]);
        else
        {
            dfs(x,y,m);
            printf("%d\n",cnt[m]);
        }
        m--;
    }

    return 0;
}
