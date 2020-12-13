#include<bits/stdc++.h>
using namespace std;
int a, n, m, x, ans;
int ontrain[21], geton[21], getdown[21];
int main(){
    cin>>a>>n>>m>>x;
    geton[1] = a;
    ontrain[1] = a;
    for(int i=0; ; i++){
        geton[2] = i;
        getdown[2] = i;
        for(int j=2; j<=n-1; j++){
            ontrain[j] = ontrain[j-1]+geton[j]-getdown[j];
            geton[j+1] = geton[j]+geton[j-1];
            getdown[j+1] = geton[j];
        }
        if(ontrain[n-1]==m) break;
    }
    cout<<ontrain[x]<<endl;
    return 0;
}
