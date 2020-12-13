#include<iostream>    
using namespace std;    
int main()    
{    
   int a[10]={1},w;  
   for (int q=1;q<=10;q++) {cin >>a[q]; if (a[q]==0){w=q; break;}}  
   for (int q=w-1;q>=1;q--) cout <<a[q]<<" ";    
   return 0;    
   }    
