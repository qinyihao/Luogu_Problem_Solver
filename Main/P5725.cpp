#include<bits/stdc++.h>
using namespace std;
int n,i,cnt;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n*n;i++){
		if(i%n==1&&i!=1){
			printf("\n");
		}
		if(i<10){
			printf("0");
		}
		printf("%d",i);
	}
	printf("\n\n");
	i=2*n;
	while(i>0){ 
		i-=2;
		for(int j=0;j<i;j++){
			printf(" ");
		}
		for(int j=0;j<(2*n-i)/2;j++){
			cnt++;
			if(cnt<10){
				printf("0");
			}
			printf("%d",cnt);
		}
		printf("\n");
	}
} 
