#include<iostream>
using namespace std;
int n,k,total,tim,mid;
const int N=1e5+10;
int a[N];
inline bool judge(int x,int a[]){
    for(int i=0;i<n;i++){
        if(total+a[i]<=x)total+=a[i];
        else{
            total=a[i];
            tim++;
        }
    }
    return tim>=k;
}

int main(){
    int left=0,right=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        left<a[i]?left=a[i]:left;
        right+=a[i];
    }
    while(left<=right){
        total=0,tim=0;
         mid=(left+right)/2;
        if(judge(mid,a))left=mid+1;
        else{
            right=mid-1;
        }
    }
    cout<<left;
    return 0;
}
